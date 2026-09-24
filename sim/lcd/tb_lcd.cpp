// Does the pixel on the screen come from the right place in memory?
//
// A framebuffer is filled with a pattern whose every line is different from
// every other, the controller scans it out, and the raster is captured the
// way a monitor would: pixels on the clock enable, while data is enabled.
// Then the capture is compared against the framebuffer, pixel by pixel.
//
// A wrong line mapping shows up as a list of which source line each screen
// line actually came from, which is what makes this worth building rather
// than staring at the RTL.
//
//   ./obj_dir/Vtb_lcd [--latency N] [--gap N] [--pgm out.pgm]
//
// --latency is memory clocks before a burst's first beat; --gap is clocks
// stolen between bursts, which is what an arbiter that keeps losing to the
// core looks like from in here.
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdint>
#include <vector>
#include "Vtb_lcd.h"
#include "verilated.h"

static const unsigned PANEL_W = 480, PANEL_H = 320;
static unsigned RAST_W = 640, RAST_H = 480;      // or the panel's own, with --native
static const uint32_t FB_PA = 0x3F6A00;      // where Magic Cap puts it

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    unsigned latency = 12, gap = 0;
    const char *pgm = nullptr;
    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "--latency") && i + 1 < argc) latency = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--gap") && i + 1 < argc) gap = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--pgm") && i + 1 < argc) pgm = argv[++i];
    }

    // The framebuffer: 2 bits per pixel, four pixels per byte, most
    // significant first. Every line carries its own number as a run of
    // marks, so a line that lands in the wrong place says which it is.
    const unsigned stride = PANEL_W / 4;              // 120 bytes
    std::vector<uint8_t> fb(stride * PANEL_H, 0);
    auto put = [&](unsigned x, unsigned y, unsigned v) {
        uint8_t &byte = fb[(size_t)y * stride + x / 4];
        unsigned sh = 6 - 2 * (x % 4);
        byte = (uint8_t)((byte & ~(3u << sh)) | ((v & 3u) << sh));
    };
    for (unsigned y = 0; y < PANEL_H; y++)
        for (unsigned x = 0; x < PANEL_W; x++) {
            // A 9-bit line number along the top of each line, then a
            // shade that walks with the line, so both the mapping and the
            // pixel packing are visible.
            unsigned v;
            if (x < 18)       v = ((y >> (8 - x / 2)) & 1) ? 3 : 0;
            else if (x < 24)  v = 3;
            else              v = ((x + y) / 8) & 3;
            put(x, y, v);
        }

    bool native = false;
    for (int i = 1; i < argc; i++) if (!strcmp(argv[i], "--native")) native = true;
    if (native) { RAST_W = PANEL_W; RAST_H = PANEL_H; }
    Vtb_lcd *dut = new Vtb_lcd;
    dut->native = native;
    dut->blank = 0; dut->progress = 0;
    int bar = -1;
    for (int i = 1; i < argc; i++) if (!strcmp(argv[i], "--bar") && i + 1 < argc) bar = atoi(argv[i + 1]);
    if (bar >= 0) { dut->blank = 1; dut->progress = bar; }
    dut->ctrl1 = 0x00035A4B;                       // ENVID, 2bpp, as the ROM writes
    dut->ctrl2 = ((PANEL_W / 4 - 1) << 12) | (PANEL_H - 1);
    dut->ctrl3 = ((FB_PA >> 20) << 20) | (((FB_PA >> 4) & 0xFFFF) << 4);
    dut->rst_n = 0;
    dut->vmem_ack = 0; dut->vmem_rdata = 0;
    for (int i = 0; i < 8; i++) { dut->clk = 0; dut->eval(); dut->clk = 1; dut->eval(); }
    dut->rst_n = 1;

    // The captured screen, and where the capture is up to.
    std::vector<uint8_t> shot((size_t)RAST_W * RAST_H, 0);
    unsigned cx = 0, cy = 0;
    bool de_d = false, vs_d = false;
    unsigned frames = 0;

    // The memory: a burst of four words, answered one beat at a time.
    unsigned wait_left = 0, beats_left = 0;
    uint32_t burst_addr = 0;
    bool req_d = false;
    uint64_t served = 0, stall_clocks = 0;

    const uint64_t BUDGET = (uint64_t)840 * 525 * 8 * 3;   // three frames, at either pixel rate
    for (uint64_t c = 0; c < BUDGET && frames < 3; c++) {
        dut->clk = 0; dut->eval();

        // ---- memory
        //
        // Replies land on the core's enabled edges, because that is where
        // the real adapter puts them: it raises a reply only on a cen edge
        // so the far side has a whole core period to take it. Answering on
        // every edge here made three beats in four vanish into a machine
        // that was not looking, which is a good demonstration of why the
        // adapter does it but a poor model of the board.
        dut->vmem_ack = 0;
        if (dut->vmem_req && dut->dbg_cen) {
            if (!req_d || beats_left == 0) {
                if (wait_left == 0 && beats_left == 0) {
                    burst_addr = dut->vmem_addr & ~0xFu;
                    wait_left = latency + gap;
                    beats_left = 4;
                }
            }
            if (wait_left) { wait_left--; stall_clocks++; }
            else if (beats_left) {
                unsigned word = 4 - beats_left;
                uint32_t a = burst_addr + word * 4 - FB_PA;
                uint32_t v = 0;
                for (int k = 0; k < 4; k++) {
                    size_t o = (size_t)a + k;
                    v = (v << 8) | (o < fb.size() ? fb[o] : 0);
                }
                dut->vmem_rdata = v;
                dut->vmem_ack = 1;
                beats_left--;
                served++;
                if (beats_left == 0 && gap) wait_left = 0;
            }
        } else if (!dut->vmem_req) { wait_left = 0; beats_left = 0; }
        req_d = dut->vmem_req;

        dut->eval();
        dut->clk = 1; dut->eval();

        // ---- the screen, as a monitor would take it
        if (dut->vs && !vs_d) { cy = 0; frames++; }
        vs_d = dut->vs;
        if (!dut->de && de_d) { cx = 0; if (cy + 1 < RAST_H) cy++; }
        de_d = dut->de;
        if (dut->de && dut->ce_pix) {
            if (cx < RAST_W && cy < RAST_H) shot[(size_t)cy * RAST_W + cx] = dut->r;
            cx++;
        }
    }

    printf("served %llu beats, %llu clocks waiting, %u frames\n",
           (unsigned long long)served, (unsigned long long)stall_clocks, frames);

    if (pgm) {
        FILE *f = fopen(pgm, "wb");
        fprintf(f, "P5\n%u %u\n255\n", RAST_W, RAST_H);
        fwrite(shot.data(), 1, shot.size(), f);
        fclose(f);
        printf("wrote %s\n", pgm);
    }

    // ---- what landed where
    //
    // For each screen line inside the panel, find the framebuffer line whose
    // pixels it matches. Anything other than "screen line k is source line
    // k" is the bug, and naming it costs nothing here.
    auto shade = [&](unsigned v) { return (uint8_t)(255 - v * 85); };
    unsigned x0 = (RAST_W - PANEL_W) / 2, y0 = (RAST_H - PANEL_H) / 2;
    int wrong = 0, blank = 0;
    std::vector<int> from(PANEL_H, -1);
    for (unsigned sy = 0; sy < PANEL_H; sy++) {
        const uint8_t *row = &shot[(size_t)(y0 + sy) * RAST_W + x0];
        bool any = false;
        for (unsigned x = 0; x < PANEL_W; x++) if (row[x]) any = true;
        if (!any) { blank++; continue; }
        for (unsigned fy = 0; fy < PANEL_H; fy++) {
            bool same = true;
            for (unsigned x = 0; x < PANEL_W && same; x++) {
                unsigned v = (fb[(size_t)fy * stride + x / 4] >> (6 - 2 * (x % 4))) & 3;
                if (row[x] != shade(v)) same = false;
            }
            if (same) { from[sy] = (int)fy; break; }
        }
        if (from[sy] != (int)sy) wrong++;
    }
    printf("%u screen lines: %d wrong, %d blank\n", PANEL_H, wrong, blank);
    if (wrong || blank) {
        printf("screen line -> source line (first 24, and every 16th):\n ");
        for (unsigned y = 0; y < PANEL_H; y++)
            if (y < 24 || y % 16 == 0) printf(" %u:%d", y, from[y]);
        printf("\n");
    }
    printf(wrong == 0 && blank == 0 ? "PASS\n" : "FAIL\n");
    delete dut;
    return (wrong == 0 && blank == 0) ? 0 : 1;
}
