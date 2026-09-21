//
// dr840_sdram.sv - the memory port the caches present, onto the SDRAM
// controller's channels.
//
// Three impedance mismatches to bridge, and each one is the reason for a
// piece of this:
//
//  - **A refill is 16 bytes, a burst read returns 8.** So a line is two
//    transactions, and the four words are handed back one per acknowledge
//    because that is how the cache counts them in.
//
//  - **Halfword order.** The controller returns the lowest-addressed
//    halfword in the low bits, and this machine is big-endian, so a 32-bit
//    word is the two halves the other way round. The same swap applies to
//    writes, which keeps the ROM the HPS loads readable by the core: both
//    go through here.
//
//  - **No byte enables.** The controller drives both byte masks from the
//    same bits, so a 32-bit write is all-or-nothing. A store narrower than
//    a word therefore reads the word, merges, and writes it back. That is
//    two transactions instead of one, for 43,126 of the first ten million
//    instructions -- every SB and SH the ROM executes. Adding byte masking
//    to a controller that is otherwise proven is the worse trade.
//
`default_nettype none

module dr840_sdram (
    input  wire        clk,            // the SDRAM clock, faster than the CPU
    input  wire        rst_n,

    // ---- the memory port from dr840_mem
    input  wire [24:0] ram_addr,
    input  wire        ram_req,
    input  wire        ram_burst,
    input  wire        ram_we,
    input  wire [3:0]  ram_be,
    input  wire [31:0] ram_wdata,
    output reg         ram_ack,
    output reg  [31:0] ram_rdata,
    // High from the moment a transaction is taken until the last beat of it
    // has been handed back. The arbiter needs it: an acknowledgement has to
    // reach whoever asked, and a requester can stop asking while its access
    // is still in the memory.
    output wire        ram_busy,

    // Debug only: what a transaction was started for, and which kind.
    output reg         dbg_start,
    output reg  [24:0] dbg_start_addr,
    output reg  [1:0]  dbg_start_kind,   // 0 single rd, 1 wr, 2 rmw, 3 burst
    output wire [3:0]  dbg_state,

    // ---- the controller's channels
    output reg  [26:1] ch1_addr,       // 64-bit burst reads, for refills
    input  wire [63:0] ch1_dout,
    output reg         ch1_req,
    input  wire        ch1_ready,

    output reg  [26:1] ch2_addr,       // 32-bit, read and write
    input  wire [31:0] ch2_dout,
    output reg  [31:0] ch2_din,
    output reg         ch2_req,
    output reg         ch2_rnw,
    input  wire        ch2_ready
);

    // Lowest-addressed halfword in the low bits, big-endian word: the two
    // halves are the other way round.
    function [31:0] swap(input [31:0] x);
        swap = {x[15:0], x[31:16]};
    endfunction

    localparam S_IDLE   = 4'd0,
               S_RD     = 4'd1,   // a single word read
               S_WR     = 4'd2,   // a whole-word write
               S_RMW_R  = 4'd3,   // narrower than a word: read,
               S_RMW_W  = 4'd4,   //   merge and write back
               S_B_LO   = 4'd5,   // first half of a line: issue
               S_B_LO_0 = 4'd6,   //   hand back word 0
               S_B_LO_1 = 4'd7,   //   hand back word 1
               S_B_HI   = 4'd8,   // second half: issue
               S_B_HI_0 = 4'd9;

    reg [3:0]  state;
    assign ram_busy = (state != S_IDLE);
    assign dbg_state = state;
    reg [31:0] hold;               // the other word of a burst, or the
                                   // word being merged into
    reg [24:0] line;

    wire [31:0] merged = {
        ram_be[3] ? ram_wdata[31:24] : hold[31:24],
        ram_be[2] ? ram_wdata[23:16] : hold[23:16],
        ram_be[1] ? ram_wdata[15:8]  : hold[15:8],
        ram_be[0] ? ram_wdata[7:0]   : hold[7:0]
    };

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state   <= S_IDLE;
            dbg_start <= 1'b0;
            ch1_req <= 1'b0;
            ch2_req <= 1'b0;
            ram_ack <= 1'b0;
        end else begin
            ch1_req <= 1'b0;
            ch2_req <= 1'b0;
            ram_ack <= 1'b0;
            dbg_start <= 1'b0;
            if (state == S_IDLE && ram_req && !ram_ack) begin
                dbg_start      <= 1'b1;
                dbg_start_addr <= ram_addr;
                dbg_start_kind <= ram_burst ? 2'd3
                                : (ram_we && (&ram_be)) ? 2'd1
                                : ram_we ? 2'd2 : 2'd0;
            end

            case (state)
            // Not while acknowledging: ram_ack is registered, so the
            // requester still has its old request up on the cycle it sees
            // the reply. Starting on that would run the same access twice
            // and leave the next one holding the previous one's data.
            S_IDLE: if (ram_req && !ram_ack) begin
                if (ram_burst) begin
                    line     <= {ram_addr[24:4], 4'd0};
                    ch1_addr <= {2'b00, ram_addr[24:4], 3'd0};
                    ch1_req  <= 1'b1;
                    state    <= S_B_LO;
                end else if (ram_we && (&ram_be)) begin
                    ch2_addr <= {2'b00, ram_addr[24:1]};
                    ch2_din  <= swap(ram_wdata);
                    ch2_rnw  <= 1'b0;
                    ch2_req  <= 1'b1;
                    state    <= S_WR;
                end else if (ram_we) begin
                    ch2_addr <= {2'b00, ram_addr[24:1]};
                    ch2_rnw  <= 1'b1;
                    ch2_req  <= 1'b1;
                    state    <= S_RMW_R;
                end else begin
                    ch2_addr <= {2'b00, ram_addr[24:1]};
                    ch2_rnw  <= 1'b1;
                    ch2_req  <= 1'b1;
                    state    <= S_RD;
                end
            end

            S_RD: if (ch2_ready) begin
                ram_rdata <= swap(ch2_dout);
                ram_ack   <= 1'b1;
                state     <= S_IDLE;
            end

            S_WR: if (ch2_ready) begin
                ram_ack <= 1'b1;
                state   <= S_IDLE;
            end

            S_RMW_R: if (ch2_ready) begin
                hold    <= swap(ch2_dout);
                ch2_rnw <= 1'b0;
                state   <= S_RMW_W;
            end

            S_RMW_W: begin
                // merged reads `hold`, which landed last cycle.
                ch2_din <= swap(merged);
                ch2_req <= 1'b1;
                state   <= S_WR;
            end

            // A line is two 8-byte bursts, four words handed back one at a
            // time because that is how the cache counts them in.
            //
            // The top halfword of a burst is written on the cycle ch1_ready
            // is asserted, so it is not readable until the cycle after.
            // Sampling all 64 bits when ready first goes high gets the last
            // word of every burst from the previous one.
            S_B_LO: if (ch1_ready) begin
                ram_rdata <= swap(ch1_dout[31:0]);
                ram_ack   <= 1'b1;
                state     <= S_B_LO_0;
            end
            S_B_LO_0: begin
                ram_rdata <= swap(ch1_dout[63:32]);
                ram_ack   <= 1'b1;
                state     <= S_B_LO_1;
            end
            S_B_LO_1: begin
                ch1_addr <= {2'b00, line[24:4], 3'd4};   // +8 bytes
                ch1_req  <= 1'b1;
                state    <= S_B_HI;
            end
            S_B_HI: if (ch1_ready) begin
                ram_rdata <= swap(ch1_dout[31:0]);
                ram_ack   <= 1'b1;
                state     <= S_B_HI_0;
            end
            S_B_HI_0: begin
                ram_rdata <= swap(ch1_dout[63:32]);
                ram_ack   <= 1'b1;
                state     <= S_IDLE;
            end

            default: state <= S_IDLE;
            endcase
        end
    end

endmodule

`default_nettype wire
