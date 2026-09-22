// dr840_sib.sv -- the TX39's serial interface bus, and the UCB1100 codec on
// the other end of it.
//
// The SIB is a continuously clocked frame bus: once enabled it runs a frame
// every sample period whether or not software has anything to say, and each
// subframe latches its completion source as it goes by. Subframe 0 carries
// the codec's control registers; software uses it as an indexed port:
//
//     write:  SIBSF0CTRL = REGADDR<<27 | WRITE | data
//     read:   SIBSF0CTRL = REGADDR<<27
//             INTRCLEAR1 = SIBSF0INT           (clear AFTER starting)
//             poll INTRSTATUS1 for SIBSF0INT   (the next frame)
//             take the data from SIBSF0STAT
//
// So SIBSF0INT is periodic, not raised by the write that starts a transfer.
// Raise it in the write and the clear that follows wipes it, and the wait
// never ends. The sound and telecom channels carry a sample per frame while
// enabled, so SNDININT and TELININT are periodic in exactly the same way;
// Magic Cap's boot waits on SNDININT and does not come back without it.
//
// The frame rate is the sound sample rate, 36.864 MHz / (128 * (SNDFSDIV+1))
// -- the ROM's own table at 0x83C210A8 maps 11025 Hz to a divisor of 25.
// The reference has no frame-rate model and completes a frame every tick;
// this runs at the rate, which is the one thing here the reference cannot
// confirm.
//
// The sound DMA ring is consumed at that rate too, and its pointer is
// reported in SIBDMACTRL with the half-way and wrap interrupts software
// refills on. Nothing is fetched from memory for it: the codec plays
// silence, and the ring exists for the OS to see it move.
//
// The codec is sixteen 16-bit registers, a touchscreen ADC with four plates
// and four auxiliary inputs, and an interrupt pin. AD2 and AD3 carry the
// main and backup battery; 900 of 1023 is inside the band the OS calls
// healthy (the reference's choice, for the same reason). No pen yet: the
// ADC reports what a resting panel reads.
`default_nettype none

module dr840_sib #(
    parameter CLK_HZ = 92_000_000
) (
    input  wire        clk,
    input  wire        rst_n,

    // One access at a time, decoded by the caller. `off` is the register
    // offset within the TX39 block; only 0x060..0x090 are ours.
    input  wire        wr,             // one cycle, on the transaction edge
    input  wire [11:0] off,
    input  wire [31:0] wdata,
    output reg  [31:0] rdata,          // combinational on `off`

    // Bits to set in INTRSTATUS1 this cycle.
    output reg  [31:0] int1_set,

    // The pen, in the converter's own counts: 0..1023 across each layer.
    input  wire        pen_down,
    input  wire [9:0]  pen_x,
    input  wire [9:0]  pen_y
);
    // ------------------------------------------------------------ registers
    localparam [11:0] SIBSIZE = 12'h060, SNDRXSTART = 12'h064, SNDTXSTART = 12'h068;
    localparam [11:0] TELRXSTART = 12'h06C, TELTXSTART = 12'h070, SIBCTRL = 12'h074;
    localparam [11:0] SNDHOLD = 12'h078, TELHOLD = 12'h07C;
    localparam [11:0] SF0CTRL = 12'h080, SF1CTRL = 12'h084, SF0STAT = 12'h088;
    localparam [11:0] SF1STAT = 12'h08C, DMACTRL = 12'h090;

    localparam [31:0] CTRL_SIBIRQ = 32'h8000_0000;
    localparam [31:0] CTRL_ENTEL = 32'h20, CTRL_ENSND = 32'h10;
    localparam [31:0] CTRL_ENSIB = 32'h01;
    localparam [31:0] DMA_ENDMATXSND = 32'h0001_0000;
    localparam [31:0] DMA_PTR_MASK   = 32'h3FFC_0000;      // [29:18]

    localparam [31:0] INT1_SND0_5 = 32'h0040_0000, INT1_SND1_0 = 32'h0020_0000;
    localparam [31:0] INT1_SNDDMACNT = 32'h0004_0000;
    localparam [31:0] INT1_SNDIN = 32'h0400, INT1_TELIN = 32'h0200;
    localparam [31:0] INT1_SF0 = 32'h0100, INT1_SF1 = 32'h0080;
    localparam [31:0] INT1_IRQPOS = 32'h0040, INT1_IRQNEG = 32'h0020;

    reg [31:0] size, sndrx, sndtx, telrx, teltx, ctrl, sndhold, telhold;
    reg [31:0] sf0ctrl, sf1ctrl, sf0stat, sf1stat, dmactrl;

    // ------------------------------------------------------------ the codec
    localparam [3:0] U_IO_DATA = 4'd0, U_IO_DIR = 4'd1, U_IE_RIS = 4'd2;
    localparam [3:0] U_IE_FAL = 4'd3, U_IE_STATUS = 4'd4, U_TS_CR = 4'd9;
    localparam [3:0] U_ADC_CR = 4'd10, U_ADC_DATA = 4'd11;
    localparam [15:0] AUX_MAIN_BATTERY = 16'd900, AUX_BACKUP_BATTERY = 16'd900;

    reg [15:0] ureg [0:15];
    integer k;

    // What the converter sees. A four-wire panel is two resistive layers
    // that touch at one point. To read a coordinate the ROM puts a voltage
    // gradient across one layer and measures the other, which floats to
    // the potential at the contact; so the axis measured is set by which
    // plates are driven, in TS_CR, not by which pin the converter is on.
    // With no pen the undriven layer reads zero and a plate on the driven
    // layer reads its rail.
    //
    // The ROM's pressure readings are cross-driven: one plate of each
    // layer, so the only path runs along one layer to the contact, through
    // it, and along the other to ground, and the powered pin reads a
    // divider between the bias resistor and that path. It takes all four
    // diagonals and adds them, which cancels position and leaves contact
    // resistance, and rejects the set unless every reading is under 500.
    // The resistances are the reference's model of an undocumented panel:
    // a firm touch near 310 mid-panel, the worst corner near 465.
    wire [15:0] ts  = ureg[U_TS_CR];
    wire [2:0]  inp = ureg[U_ADC_CR][4:2];
    wire ts_pow_mx = ts[0], ts_pow_x = ts[1], ts_pow_my = ts[2], ts_pow_y = ts[3];
    wire ts_gnd_mx = ts[4], ts_gnd_x = ts[5], ts_gnd_my = ts[6], ts_gnd_y = ts[7];
    wire x_driven = ts_pow_x && ts_gnd_mx;
    wire y_driven = ts_pow_y && ts_gnd_my;
    wire meas_x   = (inp == 3'd0) || (inp == 3'd1);      // TSPX, TSMX

    // Distance along each layer from each plate to the contact, on the
    // layer's 400 units of resistance; the contact itself is 50.
    localparam [11:0] LAYER_R = 12'd400, CONTACT_R = 12'd50, BIAS_R = 12'd1023;
    // In stages, because none of it is in a hurry and all of it in one
    // clock was not going to close.
    reg  [19:0] xr, yr;
    reg  [11:0] d_tsmx, d_tspx, d_tsmy, d_tspy;
    reg  [11:0] path_a, path_b, path;
    always @(posedge clk) begin
        xr     <= pen_x * 10'd400;                        // /1024 below
        yr     <= pen_y * 10'd400;
        d_tsmx <= {2'd0, xr[19:10]}; d_tspx <= LAYER_R - {2'd0, xr[19:10]};
        d_tsmy <= {2'd0, yr[19:10]}; d_tspy <= LAYER_R - {2'd0, yr[19:10]};
        path_a <= (ts_pow_mx ? d_tsmx : 12'd0) + (ts_pow_x ? d_tspx : 12'd0)
                + (ts_pow_my ? d_tsmy : 12'd0) + (ts_pow_y ? d_tspy : 12'd0);
        path_b <= (ts_gnd_mx ? d_tsmx : 12'd0) + (ts_gnd_x ? d_tspx : 12'd0)
                + (ts_gnd_my ? d_tsmy : 12'd0) + (ts_gnd_y ? d_tspy : 12'd0);
        path   <= CONTACT_R + path_a + path_b;
    end

    // 1023 * path / (1023 + path), by a bit-serial divider that runs all
    // the time. Its inputs change with the pen or a TS_CR write, and a
    // conversion is read through a frame of the bus, thousands of clocks
    // later; the twelve clocks this takes are invisible.
    reg [21:0] div_n;                   // numerator remainder
    reg [12:0] div_d;
    reg [9:0]  div_q, press_q;
    reg [3:0]  div_i;
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            div_n <= 22'd0; div_d <= 13'd0; div_q <= 10'd0; press_q <= 10'd0; div_i <= 4'd0;
        end else if (div_i == 4'd0) begin
            div_n <= {path, 10'd0} - {10'd0, path};        // 1023 * path
            div_d <= BIAS_R + path;
            div_q <= 10'd0;
            div_i <= 4'd10;
        end else begin
            // Restoring division, one quotient bit per clock, MSB first.
            if (div_n >= ({9'd0, div_d} << (div_i - 4'd1))) begin
                div_n <= div_n - ({9'd0, div_d} << (div_i - 4'd1));
                div_q <= {div_q[8:0], 1'b1};
            end else
                div_q <= {div_q[8:0], 1'b0};
            // The last bit is being decided this clock; take it with it.
            if (div_i == 4'd1) press_q <= {div_q[8:0], (div_n >= {9'd0, div_d})};
            div_i <= div_i - 4'd1;
        end
    end

    reg  [9:0] adc_sample;
    always @(*) begin
        case (inp)
        3'd4, 3'd5: adc_sample = 10'd0;
        3'd6:       adc_sample = AUX_MAIN_BATTERY[9:0];
        3'd7:       adc_sample = AUX_BACKUP_BATTERY[9:0];
        default:
            if (!pen_down && ((x_driven && !meas_x) || (y_driven && meas_x)))
                adc_sample = 10'd0;                       // the floating layer
            else if (x_driven && !meas_x)
                adc_sample = pen_x;                       // Y layer floats to X
            else if (y_driven && meas_x)
                adc_sample = pen_y;                       // X layer floats to Y
            else if (x_driven && meas_x)
                adc_sample = (inp == 3'd0) ? 10'h3FF : 10'd0;
            else if (y_driven && !meas_x)
                adc_sample = (inp == 3'd2) ? 10'h3FF : 10'd0;
            else if (!pen_down)                           // cross-driven, open
                adc_sample = ((inp == 3'd0 && ts_pow_x)  || (inp == 3'd1 && ts_pow_mx) ||
                              (inp == 3'd2 && ts_pow_y)  || (inp == 3'd3 && ts_pow_my))
                             ? 10'h3FF : 10'd0;
            else
                adc_sample = press_q;                     // cross-driven, touched
        endcase
    end

    wire [3:0]  sf0_reg  = wdata[30:27];
    wire        sf0_wr   = wdata[26];
    wire [15:0] sf0_data = wdata[15:0];
    reg  [15:0] ucb_rd;
    always @(*) begin
        case (sf0_reg)
        U_IO_DATA: ucb_rd = (ureg[U_IO_DATA] & ureg[U_IO_DIR]) & 16'h03FF;
        U_ADC_DATA: ucb_rd = ureg[U_ADC_CR][15] ? {1'b1, adc_sample, 5'd0} : 16'd0;
        default:   ucb_rd = ureg[sf0_reg];
        endcase
    end

    // The codec's interrupt pin: an enabled source that is asserted. The
    // SIB shows it as a level in SIBCTRL and as edges in INTRSTATUS1.
    wire irq_out = |(ureg[U_IE_STATUS] & (ureg[U_IE_RIS] | ureg[U_IE_FAL]));
    reg  irq_seen;

    // ------------------------------------------------------------ the frame
    // 36.864 MHz / 128 is 288 kHz; a frame is (SNDFSDIV + 1) of those.
    localparam [19:0] FRAME_MUL = 20'(CLK_HZ / 288_000);
    reg [19:0] frame_clocks;
    reg [19:0] frame_cnt;
    always @(posedge clk) frame_clocks <= FRAME_MUL * ({13'd0, ctrl[14:8]} + 20'd1);
    wire frame = ctrl[0] && (frame_cnt >= frame_clocks);

    // The sound ring: SIBSIZE's SND field counts 4-byte blocks, the pointer
    // reports the same blocks, and a sample is two bytes.
    wire [13:0] ring_bytes = {(size[29:18] + 12'd1), 2'b00};
    wire        ring_run   = (ctrl & CTRL_ENSND) != 0 && (dmactrl & DMA_ENDMATXSND) != 0
                             && sndtx != 32'd0;
    reg  [13:0] ring_off;

    // Sources are collected in a blocking temporary within the edge, so
    // several can raise in one cycle without one overwriting another.
    reg  [31:0] set_now;
    wire [31:0] frame_bits = INT1_SF0 | INT1_SF1
                           | ((ctrl & CTRL_ENSND) != 0 ? INT1_SNDIN : 32'd0)
                           | ((ctrl & CTRL_ENTEL) != 0 ? INT1_TELIN : 32'd0);

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            size <= 0; sndrx <= 0; sndtx <= 0; telrx <= 0; teltx <= 0; ctrl <= 0;
            sndhold <= 0; telhold <= 0; sf0ctrl <= 0; sf1ctrl <= 0;
            sf0stat <= 0; sf1stat <= 0; dmactrl <= 0;
            for (k = 0; k < 16; k = k + 1) ureg[k] <= 16'd0;
            irq_seen <= 1'b0; frame_cnt <= 20'd0; ring_off <= 14'd0;
            int1_set <= 32'd0;
        end else begin
            set_now = 32'd0;

            // The codec's pin reaches the ICU whether or not the bus is
            // clocked: once sound has finished the OS turns the bus off and
            // waits on SIBIRQPOSINT alone to be woken by a touch.
            // In the idle mode the panel sits biased and a touch pulls
            // TSPX down, which is a source: that is how the OS hears of a
            // touch without polling. Held while the pen is down; the OS
            // clears it and, if the pen is still there, it is set again.
            if (ts[9:8] == 2'd0 && pen_down)
                ureg[U_IE_STATUS] <= ureg[U_IE_STATUS] | 16'h1000;

            if (irq_out != irq_seen) begin
                irq_seen <= irq_out;
                set_now = set_now | (irq_out ? INT1_IRQPOS : INT1_IRQNEG);
            end

            if (!ctrl[0]) frame_cnt <= 20'd0;
            else if (frame) begin
                frame_cnt <= 20'd0;
                set_now = set_now | frame_bits;
                if (ring_run) begin
                    if (ring_off + 14'd2 >= ring_bytes) begin
                        ring_off <= 14'd0;
                        set_now  = set_now | INT1_SND1_0 | INT1_SNDDMACNT;
                    end else begin
                        ring_off <= ring_off + 14'd2;
                        if (ring_off < {1'b0, ring_bytes[13:1]} &&
                            ring_off + 14'd2 >= {1'b0, ring_bytes[13:1]})
                            set_now = set_now | INT1_SND0_5;
                    end
                end
            end else frame_cnt <= frame_cnt + 20'd1;
            if (!ring_run) ring_off <= 14'd0;
            int1_set <= set_now;

            if (wr) begin
                case (off)
                SIBSIZE:    size    <= wdata;
                SNDRXSTART: sndrx   <= wdata;
                SNDTXSTART: sndtx   <= wdata;
                TELRXSTART: telrx   <= wdata;
                TELTXSTART: teltx   <= wdata;
                SIBCTRL:    ctrl    <= wdata & ~CTRL_SIBIRQ;
                SNDHOLD:    sndhold <= wdata;
                TELHOLD:    telhold <= wdata;
                SF1CTRL:    sf1ctrl <= wdata;
                DMACTRL:    dmactrl <= wdata & ~DMA_PTR_MASK;   // the pointer is ours
                SF0CTRL: begin
                    sf0ctrl <= wdata;
                    // The transaction, and the status register echoing it.
                    if (sf0_wr) begin
                        sf0stat <= {1'b0, sf0_reg, 1'b1, 10'd0, sf0_data};
                        case (sf0_reg)
                        U_IE_STATUS: ureg[U_IE_STATUS] <= ureg[U_IE_STATUS] & ~sf0_data;
                        U_ADC_DATA:  ;                          // read-only
                        default:     ureg[sf0_reg] <= sf0_data;
                        endcase
                    end else begin
                        sf0stat <= {1'b0, sf0_reg, 1'b0, 10'd0, ucb_rd};
                    end
                end
                default: ;
                endcase
            end
        end
    end

    always @(*) begin
        case (off)
        SIBSIZE:    rdata = size;
        SNDRXSTART: rdata = sndrx;
        SNDTXSTART: rdata = sndtx;
        TELRXSTART: rdata = telrx;
        TELTXSTART: rdata = teltx;
        SIBCTRL:    rdata = irq_out ? (ctrl | CTRL_SIBIRQ) : (ctrl & ~CTRL_SIBIRQ);
        SNDHOLD:    rdata = sndhold;
        TELHOLD:    rdata = telhold;
        SF0CTRL:    rdata = sf0ctrl;
        SF1CTRL:    rdata = sf1ctrl;
        SF0STAT:    rdata = sf0stat;
        SF1STAT:    rdata = sf1stat;
        DMACTRL:    rdata = (dmactrl & ~DMA_PTR_MASK) | {2'b00, ring_off[13:2], 18'd0};
        default:    rdata = 32'd0;
        endcase
    end

endmodule

`default_nettype wire
