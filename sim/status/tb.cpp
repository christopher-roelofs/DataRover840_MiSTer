#include "Vdr840_status.h"
#include "verilated.h"
#include <cstdio>
int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    Vdr840_status *d = new Vdr840_status;
    d->rst_n = 0; d->clk = 0; d->eval(); d->clk = 1; d->eval(); d->rst_n = 1;
    d->v0 = 1; d->v1 = 0x3A7F; d->v2 = 0xBE3686B1; d->v3 = 0x13C213F0; d->v4 = 0x0BEBC200; d->v5 = 0x04000012; d->v6 = 0x13C0D170; d->v7 = 0xFF000FF0; d->v8 = 0; d->v9 = 0xFFFFFFFF;
    const int BIT = 100000000 / 38400;
    int txd_d = 1, cnt = 0, bit = -1; unsigned char byte = 0; int got = 0;
    for (long c = 0; c < 130000000 && got < 113; c++) {
        d->clk = 0; d->eval(); d->clk = 1; d->eval();
        if (bit < 0) { if (txd_d && !d->txd) { bit = 0; cnt = BIT / 2; } }
        else { if (--cnt == 0) { cnt = BIT; if (bit >= 1 && bit <= 8) byte |= (d->txd << (bit - 1)); if (bit == 9) { putchar(byte); got++; byte = 0; bit = -1; continue; } bit++; } }
        txd_d = d->txd;
    }
    printf("\n[%d bytes]\n", got); delete d; return 0;
}
