// The package link on its own, against a port of the reference's PC side.
//
// The engine is given a package in a model of the memory and a guest that
// says what Magic Cap says -- "ChMa", Cnct, a Ping, and a Pong to the
// engine's own -- and everything it sends back is compared byte for byte
// with what pclink.c's emit() would have queued: the same blocks, the same
// quoting, the same CRCs. Then it must report the package taken.
//
//   tb_pclink <package> [bit_clocks]
//
#include "Vdr840_pclink.h"
#include "verilated.h"
#include <cstdio>
#include <cstring>
#include <fstream>
#include <vector>
#include <string>

static std::vector<uint8_t> expected;   // what the PC side sends, in order
static std::vector<uint8_t> got;

static uint32_t crc32_of(const uint8_t *d, size_t n)
{
    uint32_t c = 0xFFFFFFFFu;
    for (size_t i = 0; i < n; i++) {
        c ^= d[i];
        for (int k = 0; k < 8; k++) c = (c & 1) ? 0xEDB88320u ^ (c >> 1) : c >> 1;
    }
    return c;
}

// pclink.c's emit(): quote, cut into blocks, checksum each.
static void emit(std::vector<uint8_t> &out, const uint8_t *data, size_t len)
{
    uint8_t quoted[256];
    size_t at = 0, i = 0;
    while (i < len || at) {
        while (i < len && at + 2 <= 256) {
            uint8_t b = data[i++];
            if (b == 0x0E || b == 0x0F || b == 0x10) quoted[at++] = 0x10;
            quoted[at++] = b;
        }
        out.push_back((uint8_t)(at >> 8)); out.push_back((uint8_t)at);
        uint32_t c = crc32_of(quoted, at);
        out.insert(out.end(), quoted, quoted + at);
        out.push_back(c >> 24); out.push_back(c >> 16); out.push_back(c >> 8); out.push_back(c);
        at = 0;
        if (i >= len) break;
    }
}

static void command(std::vector<uint8_t> &out, const char *tag, const uint8_t *payload, uint32_t len)
{
    std::vector<uint8_t> buf(8 + len);
    memcpy(buf.data(), tag, 4);
    buf[4] = len >> 24; buf[5] = len >> 16; buf[6] = len >> 8; buf[7] = len;
    if (len) memcpy(buf.data() + 8, payload, len);
    emit(out, buf.data(), buf.size());
}

int main(int argc, char **argv)
{
    Verilated::commandArgs(argc, argv);
    if (argc < 2) { fprintf(stderr, "usage: tb_pclink <package> [bit_clocks]\n"); return 2; }
    std::ifstream pf(argv[1], std::ios::binary);
    std::vector<uint8_t> pkg((std::istreambuf_iterator<char>(pf)), std::istreambuf_iterator<char>());
    if (pkg.empty()) { fprintf(stderr, "%s: empty\n", argv[1]); return 2; }
    unsigned bit_clocks = argc > 2 ? atoi(argv[2]) : 4;
    const uint32_t PKG_BASE = 0x1000000;

    // The memory: the package at its base, big-endian words.
    std::vector<uint8_t> mem(pkg);
    mem.resize((mem.size() + 3) & ~3u, 0);

    // What the PC says, in order: Cntd twice, the offer, the package, the
    // zeros; then a Pong to the guest's Ping; then its own Ping.
    {
        command(expected, "Cntd", nullptr, 0);
        command(expected, "Cntd", nullptr, 0);
        uint8_t info[1028] = {0};
        uint32_t words[8] = { (uint32_t)pkg.size(), (uint32_t)pkg.size(), 0, 0, 0, 0x80000000u, 0, 7 };
        for (unsigned i = 0; i < 8; i++) {
            info[i*4] = words[i] >> 24; info[i*4+1] = words[i] >> 16; info[i*4+2] = words[i] >> 8; info[i*4+3] = words[i];
        }
        const char *name = "Package";
        for (unsigned i = 0; i < 7; i++) { info[32 + i*2] = 0; info[32 + i*2 + 1] = name[i]; }
        command(expected, "SPkg", info, 1028);
        emit(expected, pkg.data(), pkg.size());
        static const uint8_t zero[4] = {0};
        emit(expected, zero, 4);
        command(expected, "Pong", nullptr, 0);
        command(expected, "Ping", nullptr, 0);
    }

    // What the guest says: the greeting and Cnct in one block stream, a
    // Ping after the package, and a Pong to the PC's Ping.
    std::vector<uint8_t> guest_cnct, guest_ping, guest_pong;
    {
        const char *g = "ChMa";
        guest_cnct.insert(guest_cnct.end(), g, g + 4);
        uint8_t body[1028];
        for (unsigned i = 0; i < 1028; i++) body[i] = (uint8_t)(i * 7 + 3);   // includes 0E/0F/10
        command(guest_cnct, "Cnct", body, 1028);
        command(guest_ping, "Ping", nullptr, 0);
        command(guest_pong, "Pong", nullptr, 0);
    }

    Vdr840_pclink *dut = new Vdr840_pclink;
    dut->clk = 0; dut->cen = 1; dut->rst_n = 0;
    dut->go_tog = 0; dut->pkg_len = pkg.size();
    dut->wr_addr = 0; dut->wr_data = 0; dut->wr_req = 0;
    dut->pmem_ack = 0; dut->pmem_rdata = 0;
    dut->gtx_tog = 0; dut->gtx_data = 0; dut->grx_full = 0; dut->uart_on = 1; dut->bit_clocks = bit_clocks;
    dut->speed = argc > 3 ? atoi(argv[3]) : 0;
    for (int i = 0; i < 4; i++) { dut->clk = 0; dut->eval(); dut->clk = 1; dut->eval(); }
    dut->rst_n = 1;

    // The guest's side of the wire.
    std::vector<uint8_t> *sending = &guest_cnct; size_t send_at = 0; unsigned send_gap = 0;
    bool ping_sent = false, pong_sent = false;
    unsigned rx_hold = 0;              // cycles until the guest reads its holding register
    int grx_q = 0;
    uint64_t cycles = 0, done_at = 0;
    bool offered = false;
    int last_state = -1;
    bool ok = true;
    bool ack_next = false;
    // Cntd, Cntd, SPkg, the package, the zeros: everything before the Pong.
    size_t pkg_end;
    {
        std::vector<uint8_t> tail; command(tail, "Pong", nullptr, 0); command(tail, "Ping", nullptr, 0);
        pkg_end = expected.size() - tail.size();
    }

    // Every second edge is the core's; the engine runs on those.
    for (;;) {
        // rising edge
        dut->clk = 1; dut->eval();
        cycles++;
        if (cycles == 10) dut->go_tog = 1;
        if (cycles == 40) offered = true;

        // The memory: one cycle later, and the package at its base.
        if (ack_next) { dut->pmem_ack = 0; ack_next = false; }
        if (dut->pmem_req && !dut->pmem_ack) {
            uint32_t a = dut->pmem_addr;
            if (a < PKG_BASE || a - PKG_BASE + 4 > mem.size()) { printf("FAIL: read outside the package at %08X\n", a); ok = false; break; }
            if (dut->pmem_we) { printf("FAIL: a write while sending\n"); ok = false; break; }
            uint32_t o = a - PKG_BASE;
            dut->pmem_rdata = (uint32_t)mem[o] << 24 | (uint32_t)mem[o+1] << 16 | (uint32_t)mem[o+2] << 8 | mem[o+3];
            dut->pmem_ack = 1; ack_next = true;
        }

        // A byte for the guest: full until it reads it, a few cycles on.
        if (dut->grx_tog != grx_q) {
            grx_q = dut->grx_tog;
            if (dut->grx_full) { printf("FAIL: a byte while the holding register was full\n"); ok = false; break; }
            got.push_back(dut->grx_data);
            size_t i = got.size() - 1;
            if (i >= expected.size() || got[i] != expected[i]) {
                printf("FAIL: byte %zu: got %02X, expected %02X\n", i, got[i], i < expected.size() ? expected[i] : 0);
                ok = false; break;
            }
            dut->grx_full = 1; rx_hold = 3 + (cycles % 5);
        }
        if (dut->grx_full && rx_hold && --rx_hold == 0) dut->grx_full = 0;

        // The guest speaking, a byte every few cycles.
        if (offered && sending && send_at < sending->size()) {
            if (send_gap) send_gap--;
            else { dut->gtx_data = (*sending)[send_at++]; dut->gtx_tog ^= 1; send_gap = 6; }
        }
        // After the package and its zeros: a Ping. After the PC's Ping: a Pong.
        if (!ping_sent && got.size() == pkg_end && send_at >= sending->size()) {
            sending = &guest_ping; send_at = 0; ping_sent = true;
        }
        if (ping_sent && !pong_sent && got.size() == expected.size() && send_at >= sending->size()) {
            sending = &guest_pong; send_at = 0; pong_sent = true;
        }

        if (dut->state != last_state) {
            last_state = dut->state;
            printf("state %d at %llu (%zu bytes received)\n", last_state, (unsigned long long)cycles, got.size());
            if (last_state == 3) { done_at = cycles; break; }
            if (last_state == 4) { printf("FAIL: refused\n"); ok = false; break; }
        }
        if (cycles > 40000000) { printf("FAIL: timed out with %zu of %zu bytes, state %d\n", got.size(), expected.size(), dut->state); ok = false; break; }

        dut->clk = 0; dut->eval();
    }
    if (ok && got.size() != expected.size()) { printf("FAIL: %zu of %zu bytes\n", got.size(), expected.size()); ok = false; }
    if (ok && dut->sent != pkg.size()) { printf("FAIL: sent %u of %zu\n", dut->sent, pkg.size()); ok = false; }
    printf("%s: %zu wire bytes for a %zu-byte package, %llu cycles\n", ok ? "PASS" : "FAIL",
           expected.size(), pkg.size(), (unsigned long long)done_at);
    delete dut;
    return ok ? 0 : 1;
}
