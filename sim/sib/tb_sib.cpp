// The codec, asked the questions the ROM's pen driver asks, with the pen
// where the reference's --tap-px 240 160 puts it. The reference answered
// AA00 A7C0 B9A0 B5E0 A3C0 A640 -- four cross-driven pressures and the two
// coordinates -- and so must this.
#include "Vdr840_sib.h"
#include "verilated.h"
#include <cstdio>
static Vdr840_sib *d;
static void clocks(int n) { while (n--) { d->clk = 0; d->eval(); d->clk = 1; d->eval(); } }
static void sf0(uint32_t cmd) { d->wr = 1; d->off = 0x080; d->wdata = cmd; clocks(1); d->wr = 0; clocks(40); }
static uint32_t stat() { d->off = 0x088; d->eval(); return d->rdata; }
int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    d = new Vdr840_sib;
    d->rst_n = 0; d->wr = 0; d->off = 0; d->wdata = 0; d->pen_down = 0; d->pen_x = 0; d->pen_y = 0;
    clocks(4); d->rst_n = 1; clocks(4);
    d->pen_down = 1; d->pen_x = 461; d->pen_y = 431;          // (240,160) on the reference's calibration
    clocks(64);
    struct { uint16_t ts, cr; uint16_t want; } q[] = {
        {0x0982, 0xD001, 0xAA00}, {0x0918, 0xD009, 0xA7C0}, {0x0A12, 0xD00D, 0xB9A0},
        {0x0A48, 0xD005, 0xB5E0}, {0x0941, 0xD005, 0xA3C0}, {0x0924, 0xD00D, 0xA640},
    };
    int bad = 0;
    for (auto &t : q) {
        sf0((9u << 27) | (1u << 26) | t.ts);                  // W TS_CR
        sf0((10u << 27) | (1u << 26) | t.cr);                 // W ADC_CR
        sf0((10u << 27) | (1u << 26) | (t.cr | 0x80));        // W ADC_CR, START
        clocks(64);
        sf0(11u << 27);                                       // R ADC_DATA
        uint16_t got = stat() & 0xFFFF;
        printf("TS_CR %04X ADC_CR %04X -> %04X (want %04X) %s\n", t.ts, t.cr, got, t.want, got == t.want ? "" : "<-- WRONG");
        if (got != t.want) bad++;
    }
    // And the idle-mode touch source.
    sf0((9u << 27) | (1u << 26) | 0x0000);                    // TS_CR: idle
    clocks(8);
    sf0(4u << 27);                                            // R IE_STATUS
    uint16_t ie = stat() & 0xFFFF;
    printf("IE_STATUS with the pen down in idle mode: %04X (want 1000) %s\n", ie, (ie & 0x1000) ? "" : "<-- WRONG");
    if (!(ie & 0x1000)) bad++;
    printf(bad ? "FAIL\n" : "PASS\n");
    delete d; return bad ? 1 : 0;
}
