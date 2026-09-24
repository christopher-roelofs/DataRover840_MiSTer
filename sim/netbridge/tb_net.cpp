// The network card and bridge, end to end: the driver's side sends frames
// by remote DMA and reads received ones out of the ring; the daemon's side
// (this, over a model of the shared DDR with a random BUSY and read delay)
// takes the sent frames and supplies received ones. Every frame must arrive
// whole, in order, both ways; and with no daemon, a send must end in a
// lost carrier, not a hang.
#include "Vtb_net.h"
#include "verilated.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <deque>

static Vtb_net *d;
static std::vector<uint8_t> mem(0x11000);      // the DDR region at 0x38000000
static std::deque<std::pair<uint32_t, uint64_t>> rq;   // pending reads: when, word
static uint64_t cyc = 0;
static const uint32_t BASEW = 0x38000000 / 8;

static uint32_t u32(uint32_t o) { uint32_t v; memcpy(&v, &mem[o], 4); return v; }
static void put32(uint32_t o, uint32_t v) { memcpy(&mem[o], &v, 4); }

static void tick()
{
    // The DDR, on the rising edge: BUSY at random; a read's data some
    // cycles later.
    d->ddr_dout_ready = 0;
    if (!rq.empty() && rq.front().first <= cyc) {
        d->ddr_dout = rq.front().second; d->ddr_dout_ready = 1; rq.pop_front();
    }
    bool busy = (rand() % 4) == 0;
    d->ddr_busy = busy;
    d->clk = 0; d->eval();
    if (!busy && (d->ddr_rd || d->ddr_we)) {
        uint32_t w = d->ddr_addr - BASEW;
        if (w * 8 + 8 > mem.size()) { printf("FAIL: DDR access outside the region: %08X\n", d->ddr_addr); exit(1); }
        if (d->ddr_we) memcpy(&mem[w * 8], &d->ddr_din, 8);
        else { uint64_t v; memcpy(&v, &mem[w * 8], 8); rq.push_back({(uint32_t)(cyc + 3 + rand() % 6), v}); }
    }
    d->clk = 1; d->eval();
    cyc++;
}
static void step(int n) { for (int i = 0; i < n; i++) tick(); }

static uint32_t access(bool we, unsigned port, bool wide, uint32_t v)
{
    while (!d->cen_o) tick();          // present it where an enabled edge takes it
    d->acc = 1; d->we = we; d->port = port; d->wide = wide; d->wdata = v;
    d->eval();
    uint32_t r = d->rdata;
    tick(); tick();
    d->acc = 0; d->we = 0;
    step(2);
    return r;
}
static void w(unsigned p, unsigned v) { access(true, p, false, v); }
static unsigned r(unsigned p) { return access(false, p, false, 0) & 0xFF; }

static const uint8_t mac[6] = {2, 0, 0, 0x84, 0, 1};
static uint32_t d_tx_tail = 0, d_rx_head = 0;

// The daemon: take published frames; offer one.
static std::vector<std::vector<uint8_t>> got_tx;
static void daemon_take()
{
    uint32_t head = u32(0x08);
    while (d_tx_tail != head) {
        uint32_t slot = 0x1000 + (d_tx_tail % 16) * 0x800;
        uint16_t n; memcpy(&n, &mem[slot], 2);
        got_tx.emplace_back(mem.begin() + slot + 8, mem.begin() + slot + 8 + n);
        d_tx_tail++; put32(0x10, d_tx_tail);
    }
}
static bool daemon_offer(const std::vector<uint8_t> &f)
{
    if (((d_rx_head - u32(0x20)) & 0xFFFFFFFF) >= 16) return false;
    uint32_t slot = 0x9000 + (d_rx_head % 16) * 0x800;
    memcpy(&mem[slot + 8], f.data(), f.size());
    uint16_t n = f.size(); memcpy(&mem[slot], &n, 2);
    d_rx_head++; put32(0x18, d_rx_head);
    return true;
}

static void send(const std::vector<uint8_t> &f)
{
    unsigned len = f.size();
    w(0x00, 0x22);
    w(0x08, 0x00); w(0x09, 0x40); w(0x0A, (len + 1) & 0xFF); w(0x0B, (len + 1) >> 8);
    w(0x00, 0x12);
    for (unsigned i = 0; i < len; i += 2)
        access(true, 0x10, true, (f[i] << 8) | (i + 1 < len ? f[i + 1] : 0));
    w(0x07, 0x40);
    w(0x04, 0x40); w(0x05, len & 0xFF); w(0x06, len >> 8);
    w(0x00, 0x26);
}
static unsigned wait_tx()
{
    for (int i = 0; i < 400000; i++) {
        tick();
        if (i % 64 == 0) daemon_take();
        if (i % 256 == 0) { unsigned isr = r(0x07); if (isr & 0x0A) { w(0x07, isr & 0x0A); return isr & 0x0A; } }
    }
    return 0;
}

// The driver takes everything in the ring out.
static std::vector<std::vector<uint8_t>> got_rx;
static void drain()
{
    for (;;) {
        w(0x00, 0x62); unsigned cur = r(0x07); w(0x00, 0x22);
        unsigned bnry = r(0x03);
        unsigned page = bnry + 1 >= 0x80 ? 0x46 : bnry + 1;
        if (page == cur) break;
        w(0x08, 0); w(0x09, page); w(0x0A, 4); w(0x0B, 0); w(0x00, 0x0A);
        unsigned h0 = access(false, 0x10, true, 0), h1 = access(false, 0x10, true, 0);
        unsigned next = h0 & 0xFF, count = (h1 >> 8) | ((h1 & 0xFF) << 8);
        std::vector<uint8_t> f;
        w(0x08, 4); w(0x09, page); w(0x0A, count & 0xFF); w(0x0B, count >> 8); w(0x00, 0x0A);
        for (unsigned i = 0; i < count; i += 2) {
            unsigned v = access(false, 0x10, true, 0);
            f.push_back(v >> 8); if (i + 1 < count) f.push_back(v & 0xFF);
        }
        f.resize(count - 4);                  // less the FCS
        got_rx.push_back(f);
        w(0x07, 0x41);
        w(0x03, next == 0x46 ? 0x7F : next - 1);
    }
}

int main(int argc, char **argv)
{
    Verilated::commandArgs(argc, argv);
    srand(argc > 1 ? atoi(argv[1]) : 1);
    d = new Vtb_net;
    d->rst_n = 0; d->enable = 1; d->acc = 0; d->ddr_busy = 0; d->ddr_dout_ready = 0;
    step(4); d->rst_n = 1; step(4);
    int fails = 0;

    // The driver brings the card up.
    r(0x1F); w(0x00, 0x21); w(0x0E, 0x49); w(0x0A, 0); w(0x0B, 0); w(0x0C, 0x04); w(0x0D, 0x00);
    w(0x01, 0x46); w(0x02, 0x80); w(0x03, 0x46); w(0x07, 0xFF); w(0x0F, 0x3F);
    w(0x00, 0x61); for (int i = 0; i < 6; i++) w(1 + i, mac[i]); w(0x07, 0x47); w(0x00, 0x22);

    // No daemon: a send must end in a lost carrier.
    std::vector<uint8_t> f0(60, 0x55); memset(f0.data(), 0xFF, 6);
    send(f0);
    unsigned isr = wait_tx();
    printf("no daemon: ISR %02X, link %d (%s)\n", isr, d->link, isr == 0x08 ? "carrier lost, as wanted" : "WRONG");
    if (isr != 0x08) fails++;

    // The daemon starts: link down, counters zeroed, magic.
    put32(0, 0); step(200000);
    for (uint32_t o : {0x08u, 0x10u, 0x18u, 0x20u}) put32(o, 0);
    memcpy(&mem[0], "DRNE", 4);
    step(200000);
    printf("daemon up: link %d\n", d->link);
    if (!d->link) fails++;

    // Frames both ways, interleaved.
    std::vector<std::vector<uint8_t>> sent, offered;
    for (int k = 0; k < 40; k++) {
        std::vector<uint8_t> f(14 + rand() % 1505);
        for (auto &b : f) b = rand();
        if (rand() % 2) {
            memcpy(f.data(), "\xFF\xFF\xFF\xFF\xFF\xFF", 6);
            send(f); sent.push_back(f);
            if ((wait_tx() & 0x0A) != 0x02) { printf("FAIL: transmit %d did not complete\n", k); fails++; }
        } else {
            memcpy(f.data(), mac, 6);
            if (daemon_offer(f)) offered.push_back(f);
            step(50000 + f.size() * 20);
            drain();
        }
    }
    step(100000); daemon_take(); drain();
    bool tx_ok = got_tx == sent, rx_ok = got_rx.size() == offered.size();
    for (size_t i = 0; rx_ok && i < offered.size(); i++) {
        auto e = offered[i]; if (e.size() < 60) e.resize(60, 0);
        if (got_rx[i] != e) { rx_ok = false; printf("FAIL: received frame %zu differs\n", i); }
    }
    printf("sent %zu, the daemon took %zu: %s\n", sent.size(), got_tx.size(), tx_ok ? "all equal" : "DIFFERENT");
    printf("offered %zu, the driver read %zu: %s\n", offered.size(), got_rx.size(), rx_ok ? "all equal" : "DIFFERENT");
    printf("bridge counters: %u out, %u in\n", d->frames_tx, d->frames_rx);
    if (!tx_ok || !rx_ok) fails++;
    printf(fails ? "FAIL\n" : "PASS\n");
    return fails ? 1 : 0;
}
