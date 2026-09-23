// dr840_mbus.sv -- the TX39's Magic Bus controller, and the keyboard on it.
//
// The DataRover's accessory bus. NetBSD's port never drove it, so what is
// known is the interrupt controller's documented sources, the SDK's
// register names (Dino.h) and the ROM's own use of the block, all worked
// out in the reference (magicrecomp: tx39_mbus.c, keyboard.c, and
// docs/KEYBOARD.md), and this is that model in hardware.
//
// With nothing attached the bus reads input-high and every transfer
// completes at once. A keyboard pulls the input low, and the ROM finds it:
// a broadcast reset (command 31) makes the device raise the line, an
// address is assigned (24), and 21 asks for the next device, which pulls
// the line low to say there is none. Then the ROM reads the device's ID
// (12) and information block (13) with read command 2, and resets the
// keyboard by writing an eight-byte packet (5). From then on a key raises
// the request line; the ROM asks what is wanted (1: a header saying "keys"),
// then reads up to sixteen scan bytes (2, again) by DMA into memory, and
// each transfer ends with the device's end command latched and MBUSDET
// raised. Commands are XORs of an operation code and an address code, the
// ROM's own wire encoding, written here as literals.
//
// The keyboard is an AT set-2 endpoint: make and break codes, E0 for the
// extended keys, in a queue the reads drain. The MiSTer's PS/2 keyboard
// speaks set 2 already, so its bytes go in as they are.
//
// The controller's writes to the device (the reset, LED and repeat-rate
// packets, by transmit DMA) complete without being read: the reset would
// clear a queue that is empty when it arrives, and the rest set state the
// endpoint keeps for nothing.
`default_nettype none

module dr840_mbus (
    input  wire        clk,
    input  wire        cen,
    input  wire        rst_n,

    input  wire        attached,          // a keyboard is on the bus

    // The registers, 0x0E0..0x0F8, decoded by the caller.
    input  wire        wr,
    input  wire [11:0] off,
    input  wire [31:0] wdata,
    output reg  [31:0] rdata,             // combinational on `off`
    output reg  [31:0] int2_set,          // bits to raise in INTRSTATUS2

    // A key: the toggle says one has happened.
    input  wire        key_tog,
    input  wire [7:0]  key_code,
    input  wire        key_ext,
    input  wire        key_down,

    // Receive DMA writes memory through this; physical addresses, words.
    output reg  [31:0] kmem_addr,
    output reg         kmem_req,
    output reg         kmem_we,
    output reg  [31:0] kmem_wdata,
    input  wire        kmem_ack
);
    // ------------------------------------------------------------ registers
    localparam [11:0] R_CTRL = 12'h0E0, R_CTRL2 = 12'h0E4, R_DMASTART = 12'h0E8;
    localparam [11:0] R_DMALEN = 12'h0EC, R_DMACOUNT = 12'h0F0, R_COMMAND = 12'h0F4;
    localparam [11:0] R_PAYLOAD = 12'h0F8;
    localparam [31:0] C_EN = 32'h1, C_LONG = 32'h2, C_SLAVE = 32'h8;
    localparam [31:0] C_DMA_TX = 32'h8000, C_DMA_RX = 32'h1_0000;
    localparam [31:0] C_ENABLED = 32'h8000_0000, C_EMPTY = 32'h4000_0000;
    localparam [31:0] C_IN_HIGH = 32'h2000_0000, C_BUSY = 32'h8000_0000;
    localparam [31:0] I_TXBUFAVAIL = 32'h800, I_EMPTY = 32'h200, I_RXBUFAVAIL = 32'h100;
    localparam [31:0] I_RXERR = 32'h80, I_DET = 32'h40, I_DMA_END = 32'h20, I_DMA_HALF = 32'h10;
    localparam [31:0] I_POS = 32'h8, I_NEG = 32'h4;
    localparam [31:0] DMA_MASK = 32'hFFFFC;

    reg [31:0] ctrl, ctrl2, dmastart, dmalen, dmacount, command, payload;

    // ------------------------------------------------------------ the device
    reg        input_high;                // the request line
    reg        assigned, notified;
    reg [4:0]  selection;                 // 0, 5, 12, 13
    reg [1:0]  pending_read;              // 0, 1 (request), 2 (read)
    reg [19:0] rx_bytes;
    reg        rx_complete;

    // The key queue: 256 bytes, head and count.
    reg [7:0]  kq [0:255];
    reg [7:0]  head;
    reg [8:0]  count;

    // The ROM's wire encoding: operation codes and address codes.
    function [5:0] op_of(input [15:0] c);
        case (c)
        16'hC018: op_of = 6'd1;
        16'hC024: op_of = 6'd2;
        16'hC028: op_of = 6'd3;
        16'hC030: op_of = 6'd4;
        16'hC03C: op_of = 6'd5;
        16'hC044: op_of = 6'd6;
        16'hC048: op_of = 6'd7;
        16'hC050: op_of = 6'd8;
        16'hC000: op_of = 6'd9;
        16'hC00C: op_of = 6'd10;
        16'hC014: op_of = 6'd11;
        16'hC05C: op_of = 6'd12;
        16'hC060: op_of = 6'd13;
        16'hC06C: op_of = 6'd14;
        16'hC074: op_of = 6'd15;
        16'hC078: op_of = 6'd16;
        16'hC084: op_of = 6'd17;
        16'hC088: op_of = 6'd18;
        16'hC090: op_of = 6'd19;
        16'hC09C: op_of = 6'd20;
        16'hD0E0: op_of = 6'd21;
        16'hD0EC: op_of = 6'd22;
        16'hD0A4: op_of = 6'd23;
        16'hD0A8: op_of = 6'd24;
        16'hD0B0: op_of = 6'd25;
        16'hD0BC: op_of = 6'd26;
        16'hD0C4: op_of = 6'd27;
        16'hD0C8: op_of = 6'd28;
        16'hD0D0: op_of = 6'd29;
        16'hD0DC: op_of = 6'd30;
        16'hD0F4: op_of = 6'd31;
        16'hD0F8: op_of = 6'd32;
        default: op_of = 6'd0;
        endcase
    endfunction
    function [15:0] addr_of(input [2:0] a);
        case (a)
        3'd0: addr_of = 16'h0C00;
        3'd1: addr_of = 16'h0A00;
        3'd2: addr_of = 16'h0804;
        3'd3: addr_of = 16'h0600;
        3'd4: addr_of = 16'h0404;
        3'd5: addr_of = 16'h0204;
        3'd6: addr_of = 16'h0000;
        3'd7: addr_of = 16'h0E04;
        endcase
    endfunction
    // The first address whose operation decodes, as the reference searches.
    reg [5:0] c_op; reg [2:0] c_addr; reg c_hit;
    integer ai;
    always @(*) begin
        c_op = 6'd0; c_addr = 3'd0; c_hit = 1'b0;
        for (ai = 7; ai >= 0; ai = ai - 1)
            if (op_of(wdata[15:0] ^ addr_of(ai[2:0])) != 6'd0) begin
                c_op = op_of(wdata[15:0] ^ addr_of(ai[2:0])); c_addr = ai[2:0]; c_hit = 1'b1;
            end
    end

    // The information block, as the reference constructs it: the ID,
    // the rates, and three names, with the size and a checksum at the end.
    function [7:0] info_byte(input [6:0] i);
        case (i)
        7'd3: info_byte = 8'h7C;
        7'd4: info_byte = 8'h4D;
        7'd5: info_byte = 8'h42;
        7'd6: info_byte = 8'h4B;
        7'd7: info_byte = 8'h42;
        7'd13: info_byte = 8'h03;
        7'd14: info_byte = 8'hE8;
        7'd21: info_byte = 8'h03;
        7'd22: info_byte = 8'hE8;
        7'd29: info_byte = 8'h03;
        7'd30: info_byte = 8'hE8;
        7'd39: info_byte = 8'h10;
        7'd43: info_byte = 8'h10;
        7'd45: info_byte = 8'h98;
        7'd46: info_byte = 8'h96;
        7'd47: info_byte = 8'h80;
        7'd49: info_byte = 8'h98;
        7'd50: info_byte = 8'h96;
        7'd51: info_byte = 8'h80;
        7'd64: info_byte = 8'h10;
        7'd80: info_byte = 8'h14;
        7'd81: info_byte = 8'h45;
        7'd82: info_byte = 8'h6D;
        7'd83: info_byte = 8'h75;
        7'd84: info_byte = 8'h6C;
        7'd85: info_byte = 8'h61;
        7'd86: info_byte = 8'h74;
        7'd87: info_byte = 8'h65;
        7'd88: info_byte = 8'h64;
        7'd89: info_byte = 8'h20;
        7'd90: info_byte = 8'h41;
        7'd91: info_byte = 8'h54;
        7'd92: info_byte = 8'h20;
        7'd93: info_byte = 8'h6B;
        7'd94: info_byte = 8'h65;
        7'd95: info_byte = 8'h79;
        7'd96: info_byte = 8'h62;
        7'd97: info_byte = 8'h6F;
        7'd98: info_byte = 8'h61;
        7'd99: info_byte = 8'h72;
        7'd100: info_byte = 8'h64;
        7'd101: info_byte = 8'h08;
        7'd102: info_byte = 8'h4B;
        7'd103: info_byte = 8'h65;
        7'd104: info_byte = 8'h79;
        7'd105: info_byte = 8'h62;
        7'd106: info_byte = 8'h6F;
        7'd107: info_byte = 8'h61;
        7'd108: info_byte = 8'h72;
        7'd109: info_byte = 8'h64;
        7'd110: info_byte = 8'h0B;
        7'd111: info_byte = 8'h6D;
        7'd112: info_byte = 8'h61;
        7'd113: info_byte = 8'h67;
        7'd114: info_byte = 8'h69;
        7'd115: info_byte = 8'h63;
        7'd116: info_byte = 8'h72;
        7'd117: info_byte = 8'h65;
        7'd118: info_byte = 8'h63;
        7'd119: info_byte = 8'h6F;
        7'd120: info_byte = 8'h6D;
        7'd121: info_byte = 8'h70;
        7'd126: info_byte = 8'h17;
        7'd127: info_byte = 8'h1C;
        default: info_byte = 8'h00;
        endcase
    endfunction

    // ------------------------------------------------------------ reads
    always @(*) begin
        case (off)
        R_CTRL:     rdata = attached
                        ? ((ctrl & ~(C_ENABLED | C_EMPTY | C_IN_HIGH)) | C_EMPTY
                           | (ctrl[0] ? C_ENABLED : 32'd0)
                           | (input_high ? C_IN_HIGH : 32'd0))
                        : ((ctrl & ~C_BUSY) | C_IN_HIGH);
        R_CTRL2:    rdata = ctrl2;
        R_DMASTART: rdata = dmastart;
        R_DMALEN:   rdata = dmalen;
        R_DMACOUNT: rdata = dmacount;
        R_COMMAND:  rdata = command;
        R_PAYLOAD:  rdata = payload;
        default:    rdata = 32'd0;
        endcase
    end

    // ------------------------------------------------------------ the machine
    // A key coming in, byte by byte; a service going out, word by word.
    reg        key_q;
    reg        kin_ext, kin_brk;          // what is still to be queued
    reg [7:0]  kin_code;
    reg        kin_busy;

    localparam [2:0] S_IDLE = 3'd0, S_PREP = 3'd1, S_BYTE = 3'd2, S_WRITE = 3'd3,
                     S_NEXT = 3'd4, S_DONE = 3'd5;
    reg [2:0]  st;
    reg [1:0]  kind;                      // 0 request, 1 id, 2 info, 3 scan
    reg [7:0]  size, at;                  // bytes to send, bytes sent
    reg [3:0]  scan_n;                    // scan bytes in this read
    reg [1:0]  bi;                        // byte within the word
    reg [31:0] word;
    reg [19:0] limit;
    reg        req_line;                  // apply the request line this cycle

    // The byte at `at`, for the word being assembled.
    reg [7:0] cur_byte;
    wire [7:0] qidx = head + at[7:0] - 8'd1;
    always @(*) begin
        case (kind)
        2'd0: cur_byte = (at == 8'd1) ? (count != 9'd0 ? 8'h0E : 8'h00) : 8'h00;
        2'd1: cur_byte = (at == 8'd0) ? 8'h4D : (at == 8'd1) ? 8'h42 : (at == 8'd2) ? 8'h4B : 8'h42;
        2'd2: cur_byte = info_byte(at[6:0]);
        default: cur_byte = (at == 8'd0) ? {4'd0, scan_n} : (at <= {4'd0, scan_n}) ? kq[qidx] : 8'h00;
        endcase
    end

    wire [19:0] capacity = (ctrl & C_DMA_RX) != 32'd0 ? ((dmalen[19:0] & DMA_MASK[19:0]) + 20'd4)
                         : ((ctrl & C_LONG) != 32'd0 ? 20'd4 : 20'd2);
    wire        want_high = (count != 9'd0) && !notified;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            ctrl <= 0; ctrl2 <= 0; dmastart <= 0; dmalen <= 0; dmacount <= 0;
            command <= 0; payload <= 0;
            input_high <= 1'b0; assigned <= 1'b0; notified <= 1'b0;
            selection <= 5'd0; pending_read <= 2'd0; rx_bytes <= 20'd0; rx_complete <= 1'b0;
            head <= 8'd0; count <= 9'd0; key_q <= 1'b0; kin_busy <= 1'b0;
            kin_ext <= 1'b0; kin_brk <= 1'b0; kin_code <= 8'd0;
            st <= S_IDLE; kind <= 2'd0; size <= 8'd0; at <= 8'd0; scan_n <= 4'd0;
            bi <= 2'd0; word <= 32'd0; limit <= 20'd0; req_line <= 1'b0;
            kmem_addr <= 32'd0; kmem_req <= 1'b0; kmem_we <= 1'b0; kmem_wdata <= 32'd0;
            int2_set <= 32'd0;
        end else if (cen) begin
            int2_set <= 32'd0;
            req_line <= 1'b0;

            // ---------------------------------------- the request line
            if (req_line && assigned && attached && want_high != input_high) begin
                input_high <= want_high;
                int2_set <= int2_set | (want_high ? I_POS : I_NEG);
            end

            // ---------------------------------------- a key
            if (key_tog != key_q && !kin_busy) begin
                key_q <= key_tog;
                if (key_code != 8'h00 && key_code != 8'hE0 && key_code != 8'hE1 &&
                    key_code != 8'hF0 && key_code != 8'hF8 &&
                    ({1'b0, count} + 9'd1 + {8'd0, key_ext} + {8'd0, ~key_down}) <= 9'd256) begin
                    kin_ext <= key_ext; kin_brk <= ~key_down; kin_code <= key_code;
                    kin_busy <= 1'b1;
                end
            end else if (kin_busy) begin
                if (kin_ext)      begin kq[head + count[7:0]] <= 8'hE0;    kin_ext <= 1'b0; end
                else if (kin_brk) begin kq[head + count[7:0]] <= 8'hF0;    kin_brk <= 1'b0; end
                else              begin kq[head + count[7:0]] <= kin_code; kin_busy <= 1'b0; req_line <= 1'b1; end
                count <= count + 9'd1;
            end

            // ---------------------------------------- register writes
            if (wr) begin
                case (off)
                R_CTRL: begin
                    ctrl <= attached ? (wdata & ~(C_IN_HIGH | C_ENABLED | C_EMPTY))
                                     : (wdata & ~C_IN_HIGH);
                    // Writing the control word starts a transfer; with
                    // nothing to send it is over at once.
                    int2_set <= int2_set | I_TXBUFAVAIL | I_EMPTY;
                    if (attached) begin
                        if ((wdata & (C_EN | C_SLAVE)) == (C_EN | C_SLAVE) &&
                            (ctrl & (C_EN | C_SLAVE)) != (C_EN | C_SLAVE)) begin
                            rx_bytes <= 20'd0; rx_complete <= 1'b0; dmacount <= 32'd0;
                        end
                        if ((wdata & (C_EN | C_DMA_TX | C_SLAVE | C_LONG)) == (C_EN | C_DMA_TX | C_LONG) &&
                            (ctrl & (C_EN | C_DMA_TX)) != (C_EN | C_DMA_TX)) begin
                            // Transmit DMA: the packet goes unread, but
                            // its arrival ends the write it was selected
                            // for -- the reset, the LEDs, the repeat rate
                            // -- and the device is idle again. Left
                            // selected for writing, the next read found
                            // nothing to give, and the ROM's wait for it
                            // ended in "a problem with an accessory":
                            // Caps Lock, every time.
                            dmacount <= dmalen & DMA_MASK;
                            int2_set <= int2_set | I_TXBUFAVAIL | I_EMPTY | I_DMA_END;
                            if (selection == 5'd5) begin
                                selection <= 5'd0;
                                if (count == 9'd0) notified <= 1'b0;
                                req_line <= 1'b1;
                            end
                        end
                    end
                end
                R_CTRL2:    ctrl2    <= wdata;
                R_DMASTART: dmastart <= wdata;
                R_DMALEN:   dmalen   <= wdata;
                R_DMACOUNT: dmacount <= wdata;
                R_COMMAND: begin
                    command <= wdata;
                    if (attached && ctrl[0] && !ctrl[3] && c_hit) begin
                        if (c_op == 6'd31 && c_addr == 3'd7) begin
                            // Broadcast reset: unassigned, and the line up.
                            assigned <= 1'b0; notified <= 1'b0;
                            selection <= 5'd0; pending_read <= 2'd0;
                            if (!input_high) begin input_high <= 1'b1; int2_set <= int2_set | I_POS; end
                        end else if (c_op == 6'd24 && c_addr == 3'd0) begin
                            assigned <= 1'b1;
                        end else if (assigned && (c_addr == 3'd0 || c_addr == 3'd7)) begin
                            if (c_op == 6'd21 && c_addr == 3'd0) begin
                                // No next device: the line down.
                                if (input_high) begin input_high <= 1'b0; int2_set <= int2_set | I_NEG; end
                            end else if (c_op == 6'd28) begin
                                req_line <= 1'b1;
                            end else if (c_addr == 3'd0) begin
                                case (c_op)
                                6'd1, 6'd2: pending_read <= c_op[1:0];
                                6'd5:       selection <= 5'd5;
                                6'd12, 6'd13: selection <= c_op[4:0];
                                default: ;
                                endcase
                            end
                        end
                    end
                end
                R_PAYLOAD:  payload <= wdata;     // a transmit; unread
                default: ;
                endcase
            end

            // ---------------------------------------- the service
            // What a read asks for, delivered once the controller is
            // enabled and listening.
            case (st)
            S_IDLE: if (attached && pending_read != 2'd0 && ctrl[0] && ctrl[3]) st <= S_PREP;
            S_PREP: begin
                at <= 8'd0; bi <= 2'd0; word <= 32'd0;
                limit <= (dmalen[19:0] & DMA_MASK[19:0]) + 20'd4;
                if (pending_read == 2'd1)       begin kind <= 2'd0; size <= 8'd4; end
                else if (selection == 5'd12)    begin kind <= 2'd1; size <= 8'd4; end
                else if (selection == 5'd13)    begin kind <= 2'd2; size <= 8'd128; end
                else if (selection == 5'd0) begin
                    kind <= 2'd3;
                    scan_n <= (count > 9'd15) ? 4'd15 : count[3:0];
                    size <= ((count > 9'd15) ? 8'd16 : count[7:0] + 8'd1);
                end else begin
                    kind <= 2'd0; size <= 8'd0;   // nothing selected: an error
                end
                st <= S_BYTE;
            end
            S_BYTE: begin
                // The size, rounded to words, against what the controller
                // will take: too much, or not in long words, is an error.
                if (size == 8'd0 || (ctrl & C_LONG) == 32'd0 ||
                    {12'd0, (size + 8'd3) & 8'hFC} > capacity) begin
                    pending_read <= 2'd0; st <= S_IDLE;
                end else begin
                    word <= {word[23:0], (at < size) ? cur_byte : 8'h00};
                    at <= at + 8'd1;
                    if (bi == 2'd3) st <= S_WRITE;
                    bi <= bi + 2'd1;
                end
            end
            S_WRITE: begin
                if ((ctrl & C_DMA_RX) != 32'd0) begin
                    if (rx_complete) begin
                        pending_read <= 2'd0; st <= S_IDLE;        // no room
                    end else if (!kmem_req) begin
                        kmem_addr <= {(dmastart[31:2] + rx_bytes[19:2]), 2'b00};
                        kmem_wdata <= word; kmem_we <= 1'b1; kmem_req <= 1'b1;
                    end else if (kmem_ack) begin
                        kmem_req <= 1'b0; kmem_we <= 1'b0;
                        rx_bytes <= rx_bytes + 20'd4;
                        dmacount <= {12'd0, rx_bytes + 20'd4};
                        if (rx_bytes + 20'd4 >= limit) begin
                            rx_complete <= 1'b1;
                            dmacount <= {12'd0, limit - 20'd4};
                            int2_set <= int2_set | I_DMA_END;
                        end else if (rx_bytes + 20'd4 >= ((limit + 20'd1) >> 1) &&
                                     rx_bytes < ((limit + 20'd1) >> 1))
                            int2_set <= int2_set | I_DMA_HALF;
                        st <= S_NEXT;
                    end
                end else begin
                    payload <= (ctrl & C_LONG) != 32'd0 ? word : {16'd0, word[15:0]};
                    int2_set <= int2_set | I_RXBUFAVAIL;
                    st <= S_NEXT;
                end
            end
            S_NEXT: begin
                if (at >= size) st <= S_DONE;
                else begin bi <= 2'd0; st <= S_BYTE; end
            end
            S_DONE: begin
                // The device's end command, and what the read consumed.
                command <= 32'h0000_DCF8;
                int2_set <= int2_set | I_DET;
                pending_read <= 2'd0;
                if (kind == 2'd0) notified <= 1'b1;
                else begin
                    selection <= 5'd0;
                    if (kind == 2'd3) begin
                        head <= head + {4'd0, scan_n};
                        count <= count - {5'd0, scan_n};
                        notified <= 1'b0;
                    end
                end
                req_line <= 1'b1;
                st <= S_IDLE;
            end
            default: st <= S_IDLE;
            endcase
        end
    end
endmodule

`default_nettype wire
