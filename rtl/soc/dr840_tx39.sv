//
// dr840_tx39.sv - the TX39 interrupt controller and UART A.
//
// Two registers' worth of the on-chip block, chosen because they are what
// the ROM is waiting for. It polls INTRSTATUS2 at 0x10C00104 for UART A's
// transmit bit with a timeout, and without an answer it never gets past
// reset. The layout is magicrecomp's src/soc/tx39/tx39_regs.h, which is
// NetBSD's hpcmips headers plus what the ROM itself establishes.
//
// The transmit-ready semantics are the subtle part, and the prose and the
// code in that project disagree until you read both. docs/HARDWARE.md calls
// transmit-ready a *level* -- "while the UART is enabled and its holding
// register is empty, both stand" -- because that is what the ROM observes:
// it enables the UART and waits for the bit without ever writing a byte.
// But tx39_uart.c does not reassert it every tick, and says why: doing so
// corrupted the guest's PCLink block CRCs. What it does instead is raise
// TXINT and EMPTYINT once, on the transition that enables the UART, and
// then only on real transmit events.
//
// That is what is implemented here. An edge on enable, edges on
// transmission. Reasserting forever would get through reset and break
// something further in; never asserting at all never gets through reset.
//
`default_nettype none

module dr840_tx39 #(
    parameter CLK_HZ = 92_000_000
) (
    input  wire        clk,
    // The requester's clock enable; see the handshake below.
    input  wire        cen,
    input  wire        rst_n,

    // The peripheral bus, physical addresses, never cached.
    input  wire [31:0] io_addr,
    input  wire        io_req,
    input  wire        io_we,
    input  wire [3:0]  io_be,
    input  wire [31:0] io_wdata,
    output wire        io_ack,
    output reg  [31:0] io_rdata,
    output wire        io_err,

    // The debug serial port. UART A is what the IDT monitor prints on.
    output reg         uart_txd,
    input  wire        uart_rxd,

    output wire [5:0]  irq_out,       // IP2..IP7

    output reg  [31:0] dbg_tx_bytes,
    output reg  [31:0] dbg_io_reads,
    // A byte as the guest hands it over, before it is serialised. Watching
    // this says what the machine is trying to print without decoding a
    // waveform to find out.
    output reg         dbg_tx_stb,
    output reg  [7:0]  dbg_tx_data
);

    // ---------------------------------------------------------- decode

    localparam [31:0] TX39_BASE = 32'h10C0_0000;
    wire        is_tx39 = (io_addr >= TX39_BASE) && (io_addr < TX39_BASE + 32'h400);
    wire [11:0] off     = io_addr[11:0];

    // One transaction per request, and the hard part is knowing where one
    // ends. The requester runs on a clock enable and this runs at the full
    // rate, so a write applied on every cycle would be applied several
    // times -- and the interrupt status registers are write-one-to-clear,
    // where that is destructive.
    //
    // Watching io_req rise is not enough either. Back-to-back stores to
    // devices leave it continuously asserted: the ROM writes INTRSTATUS2,
    // then UART A's control register, then memory, on three consecutive
    // instructions, and with no gap between the first two the second write
    // is simply lost. It cost 740,000 instructions of agreement to find,
    // because everything before it was stores whose values nothing read
    // back.
    //
    // So: carry the transaction out once, hold the acknowledgement until an
    // enabled edge takes it, and only then look for the next one.
    reg  served;
    assign io_ack = io_req & served;
    assign io_err = 1'b0;
    wire  io_start = io_req & ~served;

    // ------------------------------------------------- the rest of the block
    //
    // Everything not decoded below is a register that reads back what was
    // written. That is not laziness, it is what the ROM expects: it programs
    // IOMFIODATADIR at 0x188 to F607D002 and reads it back, writes the clock
    // control at 0x1C0 and reads it back, writes IOCTRL at 0x180 during the
    // first hundred instructions and reads it 742,000 later to decide
    // whether to start Magic Cap or the monitor. Returning zero to all of
    // that sends the machine somewhere the hardware never goes.
    //
    // Two have power-on values the ROM reads before writing anything: the
    // power control at 0x1C4, and UART B's control register, whose transmit
    // half is empty because nothing has used it.
    reg [31:0] rf [0:255];
    initial begin : rf_init
        integer i;
        for (i = 0; i < 256; i = i + 1) rf[i] = 32'd0;
        rf[8'h71] = 32'h2000_0000;   // 0x1C4, power control
        rf[8'h32] = 32'h4000_0000;   // 0x0C8, UART B: transmitter empty
    end
    wire [7:0] rf_idx = off[9:2];

    // ------------------------------------------------- interrupt controller

    // Banks 1..6 at 0x100, enables at 0x118. Banks 1-5 drive IP2 and are
    // write-one-to-clear at the same offsets they read from; bank 6 drives
    // IP4 and is read-only.
    reg [31:0] icu_status [0:5];
    reg [31:0] icu_enable [0:5];

    // Status banks are 0x100..0x114, four bytes apart, so off[4:2] is the
    // bank. The enables are 0x118..0x12C, which off[4:2] gets wrong -- it
    // reads 6, 7 and then wraps to 0, putting two of them out of range and
    // the rest on top of the status banks. Subtracting the base first is
    // what makes it an index.
    wire [2:0] en_idx = 3'(off[5:2] - 4'd6);

    // MBUS, with nothing on the bus. The block is at 0x0E0..0x0FC and the
    // ROM will not get past reset without it: it writes the control word to
    // start a transfer and then polls INTRSTATUS2 for completion. With no
    // bus the transfer finishes at once, so the transmit buffer is always
    // available and always empty -- and those are levels, re-asserting
    // after software clears them through INTRCLEAR2, which is why they are
    // ORed into the read rather than stored.
    localparam [11:0] MBUSCTRL          = 12'h0E0;
    localparam [31:0] MBUSCTRL_BUSY     = 32'h8000_0000;
    localparam [31:0] MBUSCTRL_IN_HIGH  = 32'h2000_0000;
    localparam [31:0] INT2_MBUS_LEVEL   = 32'h0000_0A00;  // TXBUFAVAIL|EMPTY

    localparam [31:0] INT2_UARTARXINT   = 32'h8000_0000;
    localparam [31:0] INT2_UARTATXINT   = 32'h0400_0000;
    localparam [31:0] INT2_UARTAEMPTY   = 32'h0100_0000;

    wire ip2 = |((icu_status[0] & icu_enable[0]) | (icu_status[1] & icu_enable[1]) |
                 (icu_status[2] & icu_enable[2]) | (icu_status[3] & icu_enable[3]) |
                 (icu_status[4] & icu_enable[4]));
    wire ip4 = |(icu_status[5] & icu_enable[5]);
    assign irq_out = {3'b000, ip4, 1'b0, ip2};     // IP7..IP2, so [0]=IP2 [2]=IP4

    // ------------------------------------------------------------- UART A

    localparam [11:0] UARTA_CTRL1 = 12'h0B0, UARTA_CTRL2 = 12'h0B4;
    localparam [11:0] UARTA_HOLD  = 12'h0C4;
    localparam [31:0] CTRL1_UARTON = 32'h8000_0000, CTRL1_EMPTY = 32'h4000_0000;
    localparam [31:0] CTRL1_RXFULL = 32'h1000_0000, CTRL1_ENUART = 32'h0000_0001;

    reg [31:0] ua_ctrl1, ua_ctrl2;
    reg [7:0]  ua_rx;
    reg        ua_rx_full;

    // One bit time, from the divisor. NetBSD's tx39uartreg.h: the UART runs
    // at 3.6864 MHz / (16 * (divisor + 1)).
    localparam [19:0] BIT_MUL = 20'((CLK_HZ * 16) / 3686400);
    wire [19:0] bit_clocks = BIT_MUL * ({10'd0, ua_ctrl2[9:0]} + 20'd1);

    // Transmit: a holding register and a shift register, which is the
    // distinction TXINT and EMPTYINT are about.
    reg [7:0]  tx_shift;
    reg [3:0]  tx_bit;
    reg [19:0] tx_cnt;
    reg        tx_busy, tx_hold_full;
    reg [7:0]  tx_hold;

    // Receive.
    reg [7:0]  rx_shift;
    reg [3:0]  rx_bit;
    reg [19:0] rx_cnt;
    reg        rx_busy;
    reg [2:0]  rxd_sync;

    integer k;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            for (k = 0; k < 6; k = k + 1) begin
                icu_status[k] <= 32'd0;
                icu_enable[k] <= 32'd0;
            end
            ua_ctrl1 <= 32'd0; ua_ctrl2 <= 32'd0;
            ua_rx <= 8'd0; ua_rx_full <= 1'b0;
            tx_busy <= 1'b0; tx_hold_full <= 1'b0; tx_bit <= 4'd0; tx_cnt <= 20'd0;
            uart_txd <= 1'b1;
            rx_busy <= 1'b0; rx_bit <= 4'd0; rx_cnt <= 20'd0; rxd_sync <= 3'b111;
            served <= 1'b0;
            dbg_tx_bytes <= 32'd0; dbg_io_reads <= 32'd0;
            dbg_tx_stb <= 1'b0; dbg_tx_data <= 8'd0;
        end else begin
            rxd_sync <= {rxd_sync[1:0], uart_rxd};
            dbg_tx_stb <= 1'b0;
            if (!io_req)        served <= 1'b0;   // idle
            else if (!served)   served <= 1'b1;   // carried out this cycle
            else if (cen)       served <= 1'b0;   // taken; next one may start

            // ---------------------------------------------- transmit
            if (tx_busy) begin
                if (tx_cnt >= bit_clocks) begin
                    tx_cnt <= 20'd0;
                    case (tx_bit)
                    4'd0: uart_txd <= tx_shift[0];
                    4'd1: uart_txd <= tx_shift[1];
                    4'd2: uart_txd <= tx_shift[2];
                    4'd3: uart_txd <= tx_shift[3];
                    4'd4: uart_txd <= tx_shift[4];
                    4'd5: uart_txd <= tx_shift[5];
                    4'd6: uart_txd <= tx_shift[6];
                    4'd7: uart_txd <= tx_shift[7];
                    default: uart_txd <= 1'b1;      // stop bit
                    endcase
                    if (tx_bit == 4'd9) begin
                        // The frame is out. If another byte was waiting it
                        // moves up and that is a TXINT; if not, the
                        // transmitter is empty and that is EMPTYINT.
                        if (tx_hold_full) begin
                            tx_shift     <= tx_hold;
                            tx_hold_full <= 1'b0;
                            tx_bit       <= 4'd0;
                            uart_txd     <= 1'b0;   // next start bit
                            icu_status[1] <= icu_status[1] | INT2_UARTATXINT;
                        end else begin
                            tx_busy <= 1'b0;
                            icu_status[1] <= icu_status[1] | INT2_UARTAEMPTY;
                        end
                    end else tx_bit <= tx_bit + 4'd1;
                end else tx_cnt <= tx_cnt + 20'd1;
            end

            // ---------------------------------------------- receive
            if (!rx_busy) begin
                if (rxd_sync[2:1] == 2'b10) begin   // falling edge: start bit
                    rx_busy <= 1'b1;
                    rx_bit  <= 4'd0;
                    rx_cnt  <= {1'b0, bit_clocks[19:1]};   // sample mid-bit
                end
            end else if (rx_cnt >= bit_clocks) begin
                rx_cnt <= 20'd0;
                if (rx_bit == 4'd8) begin
                    rx_busy    <= 1'b0;
                    ua_rx      <= rx_shift;
                    ua_rx_full <= 1'b1;
                    icu_status[1] <= icu_status[1] | INT2_UARTARXINT;
                end else begin
                    rx_shift <= {rxd_sync[2], rx_shift[7:1]};
                    rx_bit   <= rx_bit + 4'd1;
                end
            end else rx_cnt <= rx_cnt + 20'd1;

            // ---------------------------------------------- register access
            if (io_start && is_tx39 && io_we) begin
                // Everything is remembered; the decoded registers below
                // just also do something about it.
                // Input status comes from the bus, not from the command
                // word; the ROM writes zero here when stopping the block.
                rf[rf_idx] <= (off == MBUSCTRL) ? (io_wdata & ~MBUSCTRL_IN_HIGH)
                                                : io_wdata;
                if (off >= 12'h100 && off < 12'h118) begin
                    // Write-one-to-clear, banks 1..5.
                    icu_status[off[4:2]] <= icu_status[off[4:2]] & ~io_wdata;
                end else if (off >= 12'h118 && off < 12'h130) begin
                    icu_enable[en_idx] <= io_wdata;
                end else if (off == UARTA_CTRL1) begin
                    // UARTON, EMPTY and the full flags are status, not
                    // settable.
                    ua_ctrl1 <= io_wdata & ~(CTRL1_UARTON | CTRL1_EMPTY |
                                             CTRL1_RXFULL | 32'h2000_0000);
                    // The event that gets the ROM through reset: enabling
                    // the UART is itself the first ready.
                    if (!ua_ctrl1[0] && io_wdata[0])
                        icu_status[1] <= icu_status[1] |
                                         INT2_UARTATXINT | INT2_UARTAEMPTY;
                end else if (off == UARTA_CTRL2) begin
                    ua_ctrl2 <= io_wdata;
                end else if (off == UARTA_HOLD) begin
                    dbg_tx_bytes <= dbg_tx_bytes + 32'd1;
                    dbg_tx_stb   <= 1'b1;
                    dbg_tx_data  <= io_wdata[7:0];
                    if (!tx_busy) begin
                        tx_shift <= io_wdata[7:0];
                        tx_busy  <= 1'b1;
                        tx_bit   <= 4'd0;
                        tx_cnt   <= 20'd0;
                        uart_txd <= 1'b0;           // start bit
                        icu_status[1] <= icu_status[1] | INT2_UARTATXINT;
                    end else begin
                        tx_hold      <= io_wdata[7:0];
                        tx_hold_full <= 1'b1;
                    end
                end
            end

            if (io_start && !io_we) begin
                dbg_io_reads <= dbg_io_reads + 32'd1;
                if (is_tx39 && off == UARTA_HOLD) begin
                    ua_rx_full <= 1'b0;
                    icu_status[1] <= icu_status[1] & ~INT2_UARTARXINT;
                end
            end
        end
    end

    // Reads are combinational; the requester holds its address until acked.
    always @(*) begin
        if (!is_tx39) begin
            // Nothing else is modelled. An undriven bus reads all-ones,
            // which for the PC Card detect lines -- active low -- is the
            // right answer for an empty slot.
            io_rdata = 32'hFFFF_FFFF;
        end else if (off == 12'h104) begin
            io_rdata = icu_status[1] | INT2_MBUS_LEVEL;
        end else if (off >= 12'h100 && off < 12'h118) begin
            io_rdata = icu_status[off[4:2]];
        end else if (off == MBUSCTRL) begin
            // Never busy, and the bus reads high because nothing is
            // pulling it down.
            io_rdata = (rf[rf_idx] & ~MBUSCTRL_BUSY) | MBUSCTRL_IN_HIGH;
        end else if (off >= 12'h118 && off < 12'h130) begin
            io_rdata = icu_enable[en_idx];
        end else if (off == UARTA_CTRL1) begin
            io_rdata = ua_ctrl1
                     | (ua_ctrl1[0] ? CTRL1_UARTON : 32'd0)
                     | (tx_busy ? 32'd0 : CTRL1_EMPTY)
                     | (ua_rx_full ? CTRL1_RXFULL : 32'd0);
        end else if (off == UARTA_CTRL2) begin
            io_rdata = ua_ctrl2;
        end else if (off == UARTA_HOLD) begin
            io_rdata = {24'd0, ua_rx};
        end else begin
            io_rdata = rf[rf_idx];
        end
    end

endmodule

`default_nettype wire
