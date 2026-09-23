// dr840_snd.sv -- the sound: samples out of the ring and into the codec's
// output stage, and from there to the MiSTer's audio.
//
// The serial bus consumes one sample a frame from a ring in DRAM
// (dr840_sib.sv keeps the pointer and raises the interrupts software refills
// on); this fetches each one -- one word through the board's arbiter every
// ninety microseconds -- and does what the UCB1100 does with it. The codec
// takes left-justified signed 12-bit data (the low four bits are ignored),
// removes DC, attenuates in 3 dB steps by control register B's low five
// bits, mutes on bit 13 and is off altogether unless bit 15 is set. The
// reference reconstructs at twice the rate through a 127-tap filter; this
// holds each sample for its frame and leaves the smoothing to the MiSTer's
// own audio path.
//
// The ring's base is a kuseg alias of the DRAM, bit 30 set; the board
// wants the physical address.
`default_nettype none

module dr840_snd (
    input  wire        clk,
    input  wire        cen,
    input  wire        rst_n,

    // From the serial bus: a toggle per sample consumed, and its address.
    input  wire        snd_tog,
    input  wire [31:0] snd_addr,
    input  wire [15:0] codec_b,          // the codec's control register B

    // The memory port: single words, physical addresses.
    output reg  [31:0] amem_addr,
    output reg         amem_req,
    input  wire        amem_ack,
    input  wire [31:0] amem_rdata,

    output reg  signed [15:0] audio
);
    wire out_ena = codec_b[15];
    wire mute    = codec_b[13];
    wire [4:0] att = codec_b[4:0];

    // 65536 * 10^(-3 s / 20): the 3 dB steps, codes past 23 saturating as
    // the reference has them.
    function [16:0] gain(input [4:0] s);
        case (s)
        5'd0:  gain = 17'd65536; 5'd1:  gain = 17'd46396; 5'd2:  gain = 17'd32846;
        5'd3:  gain = 17'd23253; 5'd4:  gain = 17'd16462; 5'd5:  gain = 17'd11654;
        5'd6:  gain = 17'd8250;  5'd7:  gain = 17'd5841;  5'd8:  gain = 17'd4135;
        5'd9:  gain = 17'd2927;  5'd10: gain = 17'd2072;  5'd11: gain = 17'd1467;
        5'd12: gain = 17'd1039;  5'd13: gain = 17'd735;   5'd14: gain = 17'd521;
        5'd15: gain = 17'd369;   5'd16: gain = 17'd261;   5'd17: gain = 17'd185;
        5'd18: gain = 17'd131;   5'd19: gain = 17'd93;    5'd20: gain = 17'd66;
        5'd21: gain = 17'd46;    5'd22: gain = 17'd33;    default: gain = 17'd23;
        endcase
    endfunction

    reg        tog_q;
    reg        sel;                       // which half of the word
    reg        have;                      // a sample has arrived
    reg signed [15:0] x, xp;              // this sample and the last
    // The DC blocker's state, with eight fractional bits: its leak is a
    // shift by twelve, and without the fraction it was nothing at all once
    // the state was under 4096, so a small residual sat on the output for
    // ever after each sound where the reference's decays away.
    reg signed [27:0] hp;
    reg        s2, s3;                    // the stages behind it
    reg signed [36:0] prod;
    // Signed, by name: a part-select is unsigned whatever it was cut from,
    // and compared against signed limits every small positive value came
    // out "below -32768" and the whole boot sound was one flat rail.
    wire signed [20:0] pq = prod[36:16];

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            tog_q <= 1'b0; amem_req <= 1'b0; amem_addr <= 32'd0; sel <= 1'b0;
            have <= 1'b0; x <= 16'sd0; xp <= 16'sd0; hp <= 20'sd0;
            s2 <= 1'b0; s3 <= 1'b0; prod <= 37'sd0; audio <= 16'sd0;
        end else if (cen) begin
            have <= 1'b0; s2 <= have; s3 <= s2;

            if (snd_tog != tog_q && !amem_req) begin
                tog_q     <= snd_tog;
                amem_addr <= {snd_addr[31], 1'b0, snd_addr[29:2], 2'b00};
                sel       <= snd_addr[1];
                amem_req  <= 1'b1;
            end
            if (amem_req && amem_ack) begin
                amem_req <= 1'b0;
                // Big-endian: the sample at the lower address is the high
                // half. Left-justified 12 bits: the low four are not data.
                x    <= sel ? {amem_rdata[15:4], 4'd0} : {amem_rdata[31:20], 4'd0};
                have <= 1'b1;
            end

            // The stages. Off, the codec is silent and forgets.
            if (!out_ena) begin
                hp <= 20'sd0; xp <= 16'sd0; audio <= 16'sd0;
            end else begin
                if (have) begin
                    // y = (x - x') + 0.99975 y: unity at Nyquist, a pole
                    // near DC.
                    hp <= ((28'(x) - 28'(xp)) <<< 8) + hp - (hp >>> 12);
                    xp <= x;
                end
                if (s2) prod <= (hp >>> 8) * $signed({1'b0, gain(att)});
                if (s3) begin
                    if (mute)                         audio <= 16'sd0;
                    else if (pq > 21'sd32767)  audio <= 16'sd32767;
                    else if (pq < -21'sd32768) audio <= -16'sd32768;
                    else                       audio <= pq[15:0];
                end
            end
        end
    end
endmodule

`default_nettype wire
