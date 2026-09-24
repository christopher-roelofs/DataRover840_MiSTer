// The NE2000 against the reference emulator's own model, access for access.
//
// Both are given the same traffic -- the Ne2000 driver's initialisation as
// the reference's trace has it, the station PROM read, packets written by
// remote DMA and transmitted, frames received of every size and address,
// the ring read back and its boundary moved, overruns, and random register
// traffic besides -- and every read, every transmitted frame, and every
// receive's acceptance must agree.
//
//   tb_ne2000 [seed] [rounds]
#include "Vdr840_ne2000.h"
#include "verilated.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
// Compiled as C++ along with this, so no C linkage.
#include "devices/ne2000/ne2000.h"

static Vdr840_ne2000 *dut;
static ne2000 ref;
static std::vector<uint8_t> ref_sent;
static bool ref_send(void *, const uint8_t *f, size_t n) { ref_sent.assign(f, f + n); return true; }
static long fails = 0, reads = 0;
static uint64_t now_ns = 0;

static void tick() { dut->clk = 0; dut->eval(); dut->clk = 1; dut->eval(); }
static void step(int n = 1) { for (int i = 0; i < n; i++) tick(); }

// The bridge's side: a transmit request is copied out and acknowledged.
static std::vector<uint8_t> rtl_sent;
static bool rtl_sent_new = false;
static void service_tx()
{
    if (!dut->tx_req) return;
    unsigned base = dut->tx_base, len = dut->tx_len;
    rtl_sent.clear();
    for (unsigned i = 0; i < len; i++) {
        dut->b_addr = (base + i) & 0x3FFF;
        tick();
        dut->eval();
        rtl_sent.push_back(dut->b_q);
    }
    dut->tx_done = 1; dut->tx_ok = 1; tick(); dut->tx_done = 0;
    rtl_sent_new = true;
}

static uint32_t access(bool we, unsigned port, bool wide, uint32_t v)
{
    dut->acc = 1; dut->we = we; dut->port = port; dut->wide = wide;
    // A word: first byte high on the RTL's side, low on the reference's.
    dut->wdata = wide ? (((v & 0xFF) << 8) | ((v >> 8) & 0xFF)) : (v & 0xFF);
    dut->eval();
    uint32_t rv = dut->rdata;
    tick();
    dut->acc = 0; dut->we = 0;
    step(2);
    uint32_t cv = 0;
    if (we) mrc_ne2000_write(&ref, port, wide ? 2 : 1, v);
    else {
        cv = mrc_ne2000_read(&ref, port, wide ? 2 : 1);
        uint32_t expect = wide ? (((cv & 0xFF) << 8) | ((cv >> 8) & 0xFF)) : (cv & 0xFF);
        reads++;
        if (rv != expect) {
            if (fails++ < 20)
                printf("MISMATCH read port %02X%s: rtl %04X ref %04X (CR %02X)\n",
                       port, wide ? " (word)" : "", rv, expect, ref.cr);
        }
        return expect;
    }
    return 0;
}
static void w(unsigned port, unsigned v) { access(true, port, false, v); }
static unsigned r(unsigned port) { return access(false, port, false, 0); }

// Let a transmit finish on both sides, and compare the frames: ours is
// copied out as the bridge would, and given its frame time (1542 bytes at
// 37 edges is the longest); the reference's clock is then moved past its own.
static void finish_tx()
{
    for (int i = 0; i < 100 && !dut->tx_req; i++) tick();
    bool had = dut->tx_req;
    service_tx();
    step(60000);
    now_ns += 1000000000ull;
    mrc_ne2000_tick(&ref, now_ns);
    if (had && rtl_sent != ref_sent && fails++ < 20)
        printf("MISMATCH transmitted frame: %zu vs %zu bytes\n", rtl_sent.size(), ref_sent.size());
    rtl_sent_new = false;
}

// A frame arrives: both are offered it.
static void receive(const std::vector<uint8_t> &f)
{
    while (dut->rx_busy) tick();
    uint64_t dst = 0;
    for (int i = 0; i < 6; i++) dst = (dst << 8) | (i < (int)f.size() ? f[i] : 0);
    dut->rx_offer = 1; dut->rx_len = f.size(); dut->rx_dst = dst;
    tick(); dut->rx_offer = 0;
    int guard = 0;
    while (!dut->rx_answer && guard++ < 10) tick();
    bool take = dut->rx_take;
    tick();
    if (take) {
        for (size_t i = 0; i < f.size(); i++) { dut->rx_byte = 1; dut->rx_data = f[i]; tick(); }
        dut->rx_byte = 0;
        while (dut->rx_busy) tick();
    }
    static int wraps = 0;
    uint8_t before = ref.curr;
    bool ref_take = mrc_ne2000_receive(&ref, f.data(), f.size());
    if (ref.curr < before) { wraps++; if (wraps % 5 == 1) printf("ring wrapped (%d so far)\n", wraps); }
    if (take != ref_take && fails++ < 20)
        printf("MISMATCH receive of %zu bytes to %012llX: rtl %d ref %d\n", f.size(), (unsigned long long)dst, take, ref_take);
    step(3);
}

int main(int argc, char **argv)
{
    Verilated::commandArgs(argc, argv);
    unsigned seed = argc > 1 ? atoi(argv[1]) : 1;
    int rounds = argc > 2 ? atoi(argv[2]) : 400;
    srand(seed);
    static const uint8_t mac[6] = {0x02, 0x00, 0x00, 0x84, 0x00, 0x01};
    mrc_ne2000_init(&ref, mac);
    ref.send = ref_send;

    dut = new Vdr840_ne2000;
    dut->cen = 1; dut->rst_n = 0; dut->acc = 0; dut->board_reset = 0;
    dut->tx_done = 0; dut->tx_ok = 0; dut->rx_offer = 0; dut->rx_byte = 0; dut->b_addr = 0;
    step(4); dut->rst_n = 1; step(2);

    // ---- the driver's initialisation, as the reference trace has it
    r(0x1F); w(0x1F, 0);
    w(0x00, 0x21); w(0x0E, 0x49); w(0x0A, 0); w(0x0B, 0); w(0x0C, 0x20); w(0x0D, 0x02);
    // the PROM: 32 bytes by remote DMA, as words
    w(0x08, 0); w(0x09, 0); w(0x0A, 32); w(0x0B, 0); w(0x00, 0x0A);
    for (int i = 0; i < 16; i++) access(false, 0x10, true, 0);
    r(0x07); w(0x07, 0x40);
    w(0x01, 0x46); w(0x02, 0x80); w(0x03, 0x46); w(0x07, 0xFF); w(0x0F, 0x3F);
    w(0x00, 0x61);
    for (int i = 0; i < 6; i++) w(1 + i, mac[i]);
    for (int i = 0; i < 8; i++) w(8 + i, 0);
    w(0x07, 0x47);
    w(0x00, 0x22); w(0x0C, 0x04); w(0x0D, 0x00);

    int tx = 0, rx = 0;
    for (int round = 0; round < rounds; round++) {
        int what = rand() % 10;
        if (what < 3) {
            // A packet: written by remote DMA as words, then transmitted.
            unsigned len = 60 + rand() % 1400;
            if (len & 1) len++;
            w(0x00, 0x22);
            w(0x08, 0x00); w(0x09, 0x40); w(0x0A, len & 0xFF); w(0x0B, len >> 8);
            w(0x00, 0x12);
            for (unsigned i = 0; i < len; i += 2) access(true, 0x10, true, rand() & 0xFFFF);
            r(0x07); w(0x07, 0x40);
            w(0x04, 0x40); w(0x05, len & 0xFF); w(0x06, len >> 8);
            w(0x00, 0x26);
            finish_tx();
            r(0x07); r(0x04); w(0x07, 0x0A);
            tx++;
        } else if (what < 7) {
            // A frame for us, the world, or someone else.
            unsigned len = 14 + rand() % 1505;
            std::vector<uint8_t> f(len);
            for (auto &b : f) b = rand();
            int who = rand() % 4;
            if (who == 0) memcpy(f.data(), mac, 6);
            else if (who == 1) memset(f.data(), 0xFF, 6);
            else if (who == 2) f[0] |= 1;   // multicast
            receive(f);
            rx++;
            // Sometimes the driver takes one out of the ring: the header,
            // the frame, and the boundary moved to the page before next.
            if (rand() % 2) {
                w(0x00, 0x22);
                unsigned isr = r(0x07);
                if (isr & 0x10) { w(0x07, 0x10); }
                w(0x00, 0x62); unsigned cur = r(0x07); w(0x00, 0x22);
                unsigned bnry = r(0x03);
                unsigned page = bnry + 1 >= 0x80 ? 0x46 : bnry + 1;
                if (page != cur) {
                    w(0x08, 0); w(0x09, page); w(0x0A, 4); w(0x0B, 0); w(0x00, 0x0A);
                    unsigned h0 = access(false, 0x10, true, 0), h1 = access(false, 0x10, true, 0);
                    unsigned next = h0 & 0xFF, count = ((h1 >> 8) & 0xFF) | ((h1 & 0xFF) << 8);
                    (void)next;
                    if (count > 4 && count < 1600) {
                        w(0x08, 4); w(0x09, page); w(0x0A, (count) & 0xFF); w(0x0B, (count) >> 8); w(0x00, 0x0A);
                        for (unsigned i = 0; i < count; i += 2) access(false, 0x10, true, 0);
                        r(0x07); w(0x07, 0x41);
                        unsigned nb = h0 & 0xFF;        // the header's next page
                        nb = nb == 0x46 ? 0x7F : nb - 1;
                        w(0x03, nb);
                    }
                }
            }
        } else {
            // Register traffic: every page, reads and harmless writes.
            unsigned page = rand() % 3;
            w(0x00, 0x22 | (page << 6));
            for (int k = 0; k < 6; k++) {
                unsigned p = 1 + rand() % 15;
                // Page 1's writes to the multicast filter only: PAR and CURR
                // are the ring's, and a random one just stops reception.
                if (rand() % 3 == 0 && page == 1 && p >= 8) w(p, rand() & 0xFF);
                else r(p);
            }
            w(0x00, 0x22);
            r(0x07); r(0x03); r(0x0C);
        }
    }
    // A burst with nobody reading: the ring fills and overflows, and then
    // the overflow is acknowledged and the ring emptied, and it takes more.
    for (int k = 0; k < 30; k++) {
        std::vector<uint8_t> f(1000 + rand() % 500);
        for (auto &b : f) b = rand();
        memcpy(f.data(), mac, 6);
        receive(f);
    }
    w(0x00, 0x22); r(0x07); w(0x07, 0x10); w(0x00, 0x62); { unsigned c = r(0x07); w(0x00, 0x22); w(0x03, c == 0x46 ? 0x7F : c - 1); }
    for (int k = 0; k < 5; k++) {
        std::vector<uint8_t> f(60 + rand() % 200);
        for (auto &b : f) b = rand();
        memcpy(f.data(), mac, 6);
        receive(f);
    }
    // The whole packet RAM, by remote DMA, at the end.
    w(0x00, 0x22); w(0x08, 0x00); w(0x09, 0x40); w(0x0A, 0x00); w(0x0B, 0x40); w(0x00, 0x0A);
    for (int i = 0; i < 8192; i++) access(false, 0x10, true, 0);
    printf("reference: %llu stored, %llu filtered, %llu overruns, %llu sent, %llu unsupported\n",
           (unsigned long long)ref.rx_packets, (unsigned long long)ref.rx_filtered,
           (unsigned long long)ref.rx_overruns, (unsigned long long)ref.tx_packets,
           (unsigned long long)ref.unsupported);
    printf("%s: %ld reads compared, %d transmitted, %d offered, %ld mismatches (seed %u)\n",
           fails ? "FAIL" : "PASS", reads, tx, rx, fails, seed);
    delete dut;
    return fails ? 1 : 0;
}
