// The network card and its bridge together, for tb_net.cpp: the NIC's
// register port and the bridge's DDR port come out, and the C++ is the
// driver on one side and the MiSTer's daemon (and its memory) on the other.
`default_nettype none
module tb_net (
    input  wire        clk, rst_n, enable,
    input  wire        acc, we, wide,
    input  wire [4:0]  port,
    input  wire [15:0] wdata,
    output wire [15:0] rdata,
    output wire        irq,
    input  wire        ddr_busy,
    output wire [28:0] ddr_addr,
    output wire        ddr_rd, ddr_we,
    output wire [63:0] ddr_din,
    input  wire [63:0] ddr_dout,
    input  wire        ddr_dout_ready,
    output wire        link,
    output wire [31:0] frames_tx, frames_rx,
    output wire        cen_o
);
    reg cen;
    always @(posedge clk or negedge rst_n) if (!rst_n) cen <= 1'b0; else cen <= ~cen;
    assign cen_o = cen;
    wire        tx_req, tx_done, tx_ok, rx_offer, rx_answer, rx_take, rx_byte, rx_busy;
    wire [13:0] tx_base, b_addr;
    wire [10:0] tx_len, rx_len;
    wire [47:0] rx_dst;
    wire [7:0]  rx_data, b_q;
    dr840_ne2000 nic (.clk(clk), .cen(cen), .rst_n(rst_n), .acc(acc & cen), .we(we), .port(port), .wide(wide),
        .wdata(wdata), .rdata(rdata), .board_reset(1'b0), .irq(irq),
        .tx_req(tx_req), .tx_base(tx_base), .tx_len(tx_len), .tx_done(tx_done), .tx_ok(tx_ok),
        .rx_offer(rx_offer), .rx_len(rx_len), .rx_dst(rx_dst), .rx_answer(rx_answer), .rx_take(rx_take),
        .rx_byte(rx_byte), .rx_data(rx_data), .rx_busy(rx_busy), .b_addr(b_addr), .b_q(b_q),
        .dbg_tx(), .dbg_rx());
    dr840_netbridge br (.clk(clk), .cen(cen), .rst_n(rst_n), .enable(enable),
        .tx_req(tx_req), .tx_base(tx_base), .tx_len(tx_len), .tx_done(tx_done), .tx_ok(tx_ok),
        .rx_offer(rx_offer), .rx_len(rx_len), .rx_dst(rx_dst), .rx_answer(rx_answer), .rx_take(rx_take),
        .rx_byte(rx_byte), .rx_data(rx_data), .rx_busy(rx_busy), .b_addr(b_addr), .b_q(b_q),
        .ddr_busy(ddr_busy), .ddr_addr(ddr_addr), .ddr_rd(ddr_rd), .ddr_we(ddr_we), .ddr_din(ddr_din),
        .ddr_dout(ddr_dout), .ddr_dout_ready(ddr_dout_ready), .trace_stb(1'b0), .trace_word(64'd0),
        .link(link), .dbg_tx(frames_tx), .dbg_rx(frames_rx));
endmodule
`default_nettype wire
