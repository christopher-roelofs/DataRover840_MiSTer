#include <fstream>
#include <iterator>
#include <string>
//
// tb_sdram.cpp - the same lockstep comparison, one level further out.
//
// tb_r3900 proves the core and its caches. This proves the board around
// them: that the address decode sends each access where the reference's own
// map says it goes, and that the arbiter putting two cache ports onto one
// memory never loses or reorders anything.
//
// The split here is the board's, not a guess. Whatever the decode calls
// memory is served from a model of the SDRAM, with the ROM loaded at its
// base exactly as the HPS will load it. Whatever the decode calls a
// peripheral is replayed from the reference's bus trace in order, because
// that is behaviour no model here could invent. If the decode sends an
// access to the wrong side, it shows up immediately as a device access that
// does not match, or as a wrong instruction retired.
//
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cinttypes>
#include <vector>
#include <map>
#include <algorithm>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>

#include "Vtb_sdram.h"
#include "Vtb_sdram_tb_sdram.h"
#include "Vtb_sdram_sdram_mt48lc16m16a2.h"
#include "Vtb_sdram_tb_sdram.h"
// Verilator mangles per-module class headers with a suffix that depends on
// how many variants of the module it generated, so it is not stable across
// builds. Pick whichever it produced rather than pinning one.
#if __has_include("Vtb_sdram_r3900_cached__Cz1.h")
#include "Vtb_sdram_r3900_cached__Cz1.h"
#else
#include "Vtb_sdram_r3900_cached__Cz2.h"
#endif
#if __has_include("Vtb_sdram_r3900__Cz1.h")
#include "Vtb_sdram_r3900__Cz1.h"
#else
#include "Vtb_sdram_r3900__Cz2.h"
#endif
#include "verilated.h"
#include "goldtrace.h"

#define CPU(d) ((d)->tb_sdram->cpu->cpu)

static const char *REGNAME[32] = {
    "zero","at","v0","v1","a0","a1","a2","a3","t0","t1","t2","t3",
    "t4","t5","t6","t7","s0","s1","s2","s3","s4","s5","s6","s7",
    "t8","t9","k0","k1","gp","sp","s8","ra"
};

// Where things sit in the SDRAM. Must match dr840_mem.
static const uint32_t ROM_BASE  = 0x0000000u;
static const uint32_t DRAM_BASE = 0x0800000u;
static const size_t   SDRAM_SZ  = 12u << 20;

// The same decode the board does, so the harness can tell which side of it
// an access from the reference belongs on.
static bool decodes_to_io(uint32_t pa) {
    if (pa < 0x03C00000u) return false;
    if (pa < 0x04400000u) return false;
    if (pa >= 0x13C00000u && pa < 0x14400000u) return false;
    if (pa >= 0x1FC00000u && pa < 0x20000000u) return false;
    if (pa >= 0x10400000u && pa < 0x10C00400u) return true;
    if (pa >= 0x08000000u && pa < 0x10000000u) return true;
    if (pa >= 0x24000000u && pa < 0x2C000000u) return true;
    if (pa >= 0xFF000000u && pa < 0xFF001000u) return true;
    return false;                 // unmapped: the board faults it itself
}

struct Mapped {
    const uint8_t *base = nullptr;
    size_t len = 0, count = 0;
    const void *recs = nullptr;
    bool open(const char *path, uint32_t magic, size_t recsize) {
        int fd = ::open(path, O_RDONLY);
        if (fd < 0) { perror(path); return false; }
        struct stat st;
        if (fstat(fd, &st)) { perror(path); ::close(fd); return false; }
        len = st.st_size;
        base = (const uint8_t *)mmap(nullptr, len, PROT_READ, MAP_PRIVATE, fd, 0);
        ::close(fd);
        if (base == MAP_FAILED) { perror("mmap"); return false; }
        const trace_hdr *h = (const trace_hdr *)base;
        if (h->magic != magic || h->record_size != recsize) {
            fprintf(stderr, "%s: not the expected trace\n", path);
            return false;
        }
        recs  = base + sizeof(trace_hdr);
        count = (len - sizeof(trace_hdr)) / recsize;
        return true;
    }
};

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    const char *state_path = nullptr, *bus_path = nullptr, *rom_path = nullptr;
    uint64_t limit = 0;
    int clk_div = 1;
    bool stub = false;
    bool tx39 = false, monitor = false;
    // Replay: the peripherals answer from the reference's own trace, so
    // both machines see the same devices at the same moments and stay in
    // step. Then the first access of mine that is not the reference's next
    // one is where this machine went wrong -- which is the only way to
    // compare two machines whose interrupts do not arrive together.
    bool replay = false;
    // Check: this machine's own peripherals answer, and every access is
    // compared against the reference's trace anyway. The two must agree
    // access for access until one of these devices says something the
    // reference's did not -- and that is the difference that matters,
    // because everything after it is this machine believing it.
    bool check = false; int checked_bad = 0;
    // The reference's interrupts, at the instruction counts it took them.
    // Replaying the devices is not enough to keep two machines in step:
    // what a device says is only half of it, and when the line went up is
    // the other half. With both, they run the same instructions and the
    // first access that differs is a real difference.
    const char *irq_path = nullptr;
    std::vector<std::pair<uint32_t,uint32_t>> IRQ;
    size_t irqidx = 0;
    // The core takes an interrupt in ID, with instructions already behind
    // it that will retire first; the reference takes it between two
    // instructions. So the line goes up this many retirements early.
    uint64_t irq_lead = 0;
    // --record prefix: this machine's device answers and interrupt level,
    // in the reference's trace format, for the reference to replay.
    FILE *rec_dev = nullptr, *rec_irq = nullptr, *rec_take = nullptr;
    uint32_t rec_last_irq = 0xFFFFFFFFu;
    bool io_req_d = false;
    int  iolog = 0, iolog_max = 0, iolog_rep = 0;
    long watch_write = -1;         // a physical address whose stores to report
    const char *dump_fb = nullptr; uint64_t fb_every = 0, fb_next = 0; int fb_n = 0;
    // --tap x,y,at,len: press the pen at panel pixel (x,y) from instruction
    // `at` for `len` instructions, in the converter's counts on the
    // reference's calibration -- the same numbers its --tap-px produces.
    long tap_x = -1, tap_y = -1; uint64_t tap_at = 0, tap_len = 2000000;
    // Several, separated by ';', for a sequence such as a calibration.
    struct tap_t { long x, y; uint64_t at, len; };
    std::vector<tap_t> taps;
    // --button at,len: the ON button, held from instruction `at`.
    uint64_t btn_at = 0, btn_len = 0;
    // --wav path: the sound, a sample a frame, as a 16-bit mono WAV at the
    // nominal 11025 Hz.
    // --keyboard attaches one; --keys "code,ext,down,at;..." presses them
    // (AT set 2 codes, hex), at those instruction counts.
    bool kbd = false;
    struct key_t { unsigned code; bool ext, down; uint64_t at; };
    std::vector<key_t> keys; size_t keyidx = 0; int key_tog = 0;
    // --card path: a memory card in slot 2, its image put into the SDRAM's
    // card region as the loader will; --card-out path writes it back.
    const char *card_path = nullptr, *card_out = nullptr; uint32_t card_size = 0;
    const char *ram_path = nullptr, *pkg_path = nullptr; uint32_t pkg_size = 0;
    const uint32_t PKG_BASE = 0x1000000;
    const uint32_t CARD2_BASE = 0x0E00000;
    const char *wav_path = nullptr; FILE *wav = nullptr; uint32_t wav_n = 0; int wav_tog = -1;
    // --trace-after pc,hit,n: print n retired instructions from the hit-th
    // execution of pc, the reference's option of the same name.
    uint32_t ta_pc = 0; uint64_t ta_hit = 0, ta_hits = 0, ta_n = 0, ta_left = 0;
    uint64_t tf_from = 0;          // --trace-from n,count: by instruction index
    uint32_t last_pc = 0;
    uint64_t exc_taken = 0, exc_last_report = 0, exc_spurious = 0;
    // The last instructions before a fault. A fault names the load that
    // could not be done; what is wanted is how the machine came to ask.
    struct { uint32_t pc, insn, a0, v0; } hist[256];
    unsigned hist_n = 0; int faults_shown = 0;
    char iolog_last[96] = "";
    std::map<uint64_t,uint64_t> io_seen;

    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "--state") && i + 1 < argc) state_path = argv[++i];
        else if (!strcmp(argv[i], "--bus") && i + 1 < argc) bus_path = argv[++i];
        else if (!strcmp(argv[i], "--rom") && i + 1 < argc) rom_path = argv[++i];
        else if (!strcmp(argv[i], "-n") && i + 1 < argc) limit = strtoull(argv[++i], nullptr, 0);
        else if (!strcmp(argv[i], "--div") && i + 1 < argc) clk_div = atoi(argv[++i]);
        // Answer devices the way dr840_io_stub does instead of replaying the
        // reference. The guest then goes wherever the hardware sends it,
        // which is the only way to predict what the board is doing.
        else if (!strcmp(argv[i], "--stub")) stub = true;
        // Let the real TX39 block answer the peripheral bus, and print
        // whatever the guest hands to the UART. This is the machine
        // speaking for itself.
        else if (!strcmp(argv[i], "--tx39")) tx39 = true;
        else if (!strcmp(argv[i], "--monitor")) monitor = true;
        else if (!strcmp(argv[i], "--iolog") && i + 1 < argc) iolog_max = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--watch-write") && i + 1 < argc) watch_write = strtol(argv[++i], nullptr, 16);
        else if (!strcmp(argv[i], "--dump-fb") && i + 1 < argc) dump_fb = argv[++i];
        else if (!strcmp(argv[i], "--tap") && i + 1 < argc) {
            const char *a = argv[++i];
            while (a && *a) {
                tap_t t = {-1, -1, 0, 2000000};
                t.x = strtol(a, nullptr, 10);
                const char *c = strchr(a, ','); if (c) { t.y = strtol(c + 1, nullptr, 10); c = strchr(c + 1, ',');
                if (c) { t.at = strtoull(c + 1, nullptr, 10); c = strchr(c + 1, ','); if (c) t.len = strtoull(c + 1, nullptr, 10); } }
                taps.push_back(t);
                a = strchr(a, ';'); if (a) a++;
            }
            tap_x = taps[0].x; tap_y = taps[0].y; tap_at = taps[0].at; tap_len = taps[0].len;
        }
        else if (!strcmp(argv[i], "--trace-from") && i + 1 < argc) {
            const char *a = argv[++i]; tf_from = strtoull(a, nullptr, 10);
            const char *c = strchr(a, ','); ta_n = c ? strtoull(c + 1, nullptr, 10) : 100;
        }
        else if (!strcmp(argv[i], "--trace-after") && i + 1 < argc) {
            const char *a = argv[++i]; ta_pc = strtoul(a, nullptr, 16);
            const char *c = strchr(a, ','); if (c) { ta_hit = strtoull(c + 1, nullptr, 10); c = strchr(c + 1, ','); if (c) ta_n = strtoull(c + 1, nullptr, 10); }
        }
        else if (!strcmp(argv[i], "--fb-every") && i + 1 < argc) fb_every = strtoull(argv[++i], nullptr, 10);
        else if (!strcmp(argv[i], "--free")) stub = true;
        else if (!strcmp(argv[i], "--replay")) replay = true;
        else if (!strcmp(argv[i], "--check")) check = true;
        else if (!strcmp(argv[i], "--wav") && i + 1 < argc) wav_path = argv[++i];
        else if (!strcmp(argv[i], "--keyboard")) kbd = true;
        else if (!strcmp(argv[i], "--card") && i + 1 < argc) card_path = argv[++i];
        else if (!strcmp(argv[i], "--ram") && i + 1 < argc) ram_path = argv[++i];
        else if (!strcmp(argv[i], "--install") && i + 1 < argc) pkg_path = argv[++i];
        else if (!strcmp(argv[i], "--card-out") && i + 1 < argc) card_out = argv[++i];
        else if (!strcmp(argv[i], "--keys") && i + 1 < argc) {
            const char *a = argv[++i]; kbd = true;
            while (a && *a) {
                key_t k = {0, false, true, 0};
                k.code = strtoul(a, nullptr, 16);
                const char *c = strchr(a, ','); if (c) { k.ext = strtoul(c + 1, nullptr, 10) != 0; c = strchr(c + 1, ',');
                if (c) { k.down = strtoul(c + 1, nullptr, 10) != 0; c = strchr(c + 1, ','); if (c) k.at = strtoull(c + 1, nullptr, 10); } }
                keys.push_back(k);
                a = strchr(a, ';'); if (a) a++;
            }
        }
        else if (!strcmp(argv[i], "--button") && i + 1 < argc) {
            const char *a = argv[++i]; btn_at = strtoull(a, nullptr, 10);
            const char *c = strchr(a, ','); btn_len = c ? strtoull(c + 1, nullptr, 10) : 2000000;
        }
        else if (!strcmp(argv[i], "--irq") && i + 1 < argc) irq_path = argv[++i];
        else if (!strcmp(argv[i], "--irq-lead") && i + 1 < argc) irq_lead = strtoull(argv[++i], nullptr, 10);
        else if (!strcmp(argv[i], "--record") && i + 1 < argc) {
            std::string p = argv[++i];
            rec_dev = fopen((p + ".bus").c_str(), "wb");
            rec_irq = fopen((p + ".irq").c_str(), "wb");
            rec_take = fopen((p + ".take").c_str(), "wb");
            uint32_t hdr[4] = {0, 0, 0, 0};
            fwrite(hdr, sizeof hdr, 1, rec_dev);
        }
    }
    if (!state_path || !bus_path || !rom_path) {
        fprintf(stderr, "usage: Vtb_sdram --state F --bus F --rom F "
                        "[-n N]\n");
        return 2;
    }

    Mapped st, bs;
    if (!st.open(state_path, TRACE_STATE_MAGIC, sizeof(state_rec))) return 2;
    if (!bs.open(bus_path,   BUS_TRACE_MAGIC,   sizeof(bus_rec)))   return 2;
    const state_rec *S = (const state_rec *)st.recs;
    const bus_rec   *Ball = (const bus_rec *)bs.recs;

    std::vector<uint8_t> rom;
    {
        FILE *f = fopen(rom_path, "rb");
        if (!f) { perror(rom_path); return 2; }
        uint8_t buf[65536]; size_t n;
        while ((n = fread(buf, 1, sizeof buf, f)) > 0)
            rom.insert(rom.end(), buf, buf + n);
        fclose(f);
    }

    // Only the device accesses are replayed; the rest is memory.
    std::vector<bus_rec> IO;
    for (uint64_t i = 0; i < bs.count; i++)
        if (!(Ball[i].flags & BUS_F_IFETCH) && decodes_to_io(Ball[i].addr))
            IO.push_back(Ball[i]);

    uint64_t n_state = st.count;
    if (stub || replay || check) n_state = limit ? limit : n_state;  // free-running
    else if (limit && limit < n_state) n_state = limit;
    printf("reference: %" PRIu64 " instructions, %zu device access(es) of "
           "%" PRIu64 " total\n", n_state, IO.size(), (uint64_t)bs.count);

    Vtb_sdram *dut = new Vtb_sdram;

    dut->card_present = 0; dut->card_log2_0 = 21; dut->card_log2_1 = 21;
    if (card_path) {
        FILE *cf = fopen(card_path, "rb");
        if (!cf) { fprintf(stderr, "cannot open %s\n", card_path); return 1; }
        std::vector<uint8_t> img((std::istreambuf_iterator<char>(*new std::ifstream(card_path, std::ios::binary))), std::istreambuf_iterator<char>());
        fclose(cf);
        card_size = img.size();
        unsigned lg = 0; while ((1u << lg) < card_size) lg++;
        if ((1u << lg) != card_size || lg < 16 || lg > 21) { fprintf(stderr, "card: size must be a power of two, 64 KiB..2 MiB\n"); return 1; }
        for (uint32_t i = 0; i + 1 < card_size; i += 2)
            dut->tb_sdram->chip->mem[(CARD2_BASE + i) >> 1] = (uint16_t)(img[i] << 8 | img[i + 1]);
        dut->card_present = 2; dut->card_log2_1 = lg;
        printf("card: %s in slot 2, %u bytes (log2 %u)\n", card_path, card_size, lg);
    }
    // A RAM image: the machine starts warm, as it does from the MiSTer's
    // save, and the ROM's "Cleaning up" takes it to where it was.
    if (ram_path) {
        std::ifstream rf(ram_path, std::ios::binary);
        std::vector<uint8_t> img((std::istreambuf_iterator<char>(rf)), std::istreambuf_iterator<char>());
        if (img.size() != 4u << 20) { fprintf(stderr, "%s: not a 4 MB RAM image\n", ram_path); return 1; }
        for (size_t i = 0; i + 1 < img.size(); i += 2)
            dut->tb_sdram->chip->mem[(DRAM_BASE + i) >> 1] = (uint16_t)(img[i] << 8 | img[i + 1]);
        printf("ram: %s loaded, warm start\n", ram_path);
    }
    // A package, where the OSD's loader would put it; offered once the
    // machine is out of reset.
    if (pkg_path) {
        std::ifstream pf(pkg_path, std::ios::binary);
        std::vector<uint8_t> img((std::istreambuf_iterator<char>(pf)), std::istreambuf_iterator<char>());
        if (img.empty() || img.size() > 8u << 20) { fprintf(stderr, "%s: not a package\n", pkg_path); return 1; }
        pkg_size = (uint32_t)img.size();
        img.resize((img.size() + 3) & ~3u, 0);
        for (size_t i = 0; i + 1 < img.size(); i += 2)
            dut->tb_sdram->chip->mem[(PKG_BASE + i) >> 1] = (uint16_t)(img[i] << 8 | img[i + 1]);
        printf("install: %s, %u bytes, offered on the serial port\n", pkg_path, pkg_size);
    }
    // Load the ROM into the chip model the way the HPS will load it: a
    // halfword holds the two bytes at its address, most significant first,
    // and the index is the halfword address. Writes from the core use the
    // same convention, so a mistake here shows up as the very first
    // instruction being wrong rather than as a subtle drift later.
    for (size_t i = 0; i + 1 < rom.size(); i += 2)
        dut->tb_sdram->chip->mem[(ROM_BASE + i) >> 1] =
            (uint16_t)((rom[i] << 8) | rom[i + 1]);
    printf("sdram: %zu-byte ROM at %06X, DRAM at %06X\n",
           rom.size(), ROM_BASE, DRAM_BASE);
    dut->clk_div = clk_div;
    dut->tx39_en = tx39;
    dut->boot_monitor = monitor;
    dut->pen_down = 0; dut->pen_px = 0; dut->pen_py = 0;
    dut->rst_n = 0; dut->irq_in = 0;
    dut->pkg_go_tog = 0; dut->pkg_len = pkg_size;
    dut->io_ack = 0; dut->io_err = 0;
    for (int i = 0; i < 8; i++) { dut->clk = 0; dut->eval(); dut->clk = 1; dut->eval(); }
    dut->rst_n = 1;
    if (pkg_size) dut->pkg_go_tog = 1;
    int pkg_state_seen = 0;
    static const char *pkg_state_name[] = { "no package", "offered", "linked, sending", "taken", "refused", "?", "?", "?" };

    // The framebuffer as the reference's --dump-fb writes it: a PGM, ink
    // complemented to grey, from VIDEOCTRL2/3 as the guest left them.
    auto write_fb = [&](const char *path) {
        uint32_t c1 = dut->dbg_vid_ctrl1, c3 = dut->dbg_vid_ctrl3;
        uint32_t pa = ((c3 >> 20) & 0xFFF) << 20 | ((c3 >> 4) & 0xFFFF) << 4;
        unsigned w = 480, h = 320, stride = w / 4;
        bool invert = (c1 & 4) != 0;
        FILE *f = fopen(path, "wb");
        if (!f) return;
        fprintf(f, "P5\n%u %u\n255\n", w, h);
        for (unsigned y = 0; y < h; y++)
            for (unsigned x = 0; x < w; x++) {
                uint32_t byte_addr = DRAM_BASE + pa + y * stride + x / 4;
                uint16_t hw = dut->tb_sdram->chip->mem[byte_addr >> 1];
                uint8_t bv = (byte_addr & 1) ? (hw & 0xFF) : (hw >> 8);
                unsigned v = (bv >> (6 - 2 * (x % 4))) & 3;
                if (invert) v = 3 - v;
                fputc((int)(255 - v * 85), f);
            }
        fclose(f);
        printf("fb: %s (base %06X, ctrl1 %08X)\n", path, pa, c1);
    };
    if (irq_path) {
        FILE *f = fopen(irq_path, "rb");
        if (!f) { fprintf(stderr, "cannot open %s\n", irq_path); return 1; }
        uint32_t rec[2];
        while (fread(rec, sizeof rec, 1, f) == 1) IRQ.push_back({rec[0], rec[1]});
        fclose(f);
        printf("%zu interrupts to replay\n", IRQ.size());
    }
    uint64_t idx = 0, ioidx = 0, cycles = 0;
    // A request is answered on the core's edge after the one it was first
    // seen on, never the same one: the board decides which reply to hand
    // back from a register, and the real block cannot answer sooner either.
    bool io_pending = false;
    std::map<uint32_t, uint64_t> pc_seen;
    int failures = 0, dbgn = 0;
    const uint64_t BUDGET = n_state * 200 + 100000;

    while (idx < n_state && cycles < BUDGET) {
        dut->eval();

        // The SDRAM answers for itself now; only the peripheral bus is
        // still the testbench's job.
        // ---- peripherals, replayed in order
        dut->io_ack = 0; dut->io_err = 0;
        bool io_fire = false;
        // The peripheral bus is in the core's clock domain: it answers on
        // the core's edges, not the memory's. Answering between them would
        // be an acknowledgement the core never sees.
        if (tx39) {
            // The block answers for itself; nothing to do here.
        } else if (stub && !replay && dut->io_req && dut->dbg_cen && io_pending) {
            bool tx39 = (dut->io_addr >= 0x10C00000u) && (dut->io_addr < 0x10C00400u);
            dut->io_rdata = tx39 ? 0u : 0xFFFFFFFFu;
            dut->io_err   = 0;
            dut->io_ack   = 1;
            ioidx++;
        } else if (!stub && dut->io_req && dut->dbg_cen && io_pending) {
            if (ioidx >= IO.size()) {
                // Near the end the pipeline holds instructions past the last
                // retire; let them finish rather than call it a failure.
                if (idx + 16 >= n_state) { dut->io_rdata = 0; dut->io_ack = 1; }
                else {
                    fprintf(stderr, "\n*** device access past the end of the "
                            "reference (instruction %" PRIu64 ", addr %08X)\n",
                            idx, dut->io_addr);
                    failures++; break;
                }
            } else {
                const bus_rec &b = IO[ioidx];
                unsigned size = BUS_SIZE(b.flags);
                bool wr = BUS_IS_WRITE(b.flags);
                uint32_t word = b.addr & ~3u;
                unsigned lane = 3u - (b.addr & 3u);
                if (dut->io_addr != word || (bool)dut->io_we != wr) {
                    fprintf(stderr, "\n*** device access diverged at "
                            "instruction %" PRIu64 " (pc %08X), record %"
                            PRIu64 "\n    reference %s %u byte(s) at %08X\n"
                            "    board     %s at %08X be=%X\n",
                            idx, (idx < st.count ? S[idx].pc : last_pc), ioidx, wr ? "write" : "read",
                            size, b.addr, dut->io_we ? "write" : "read",
                            dut->io_addr, dut->io_be);
                    failures++; break;
                }
                if (wr) {
                    uint32_t got = (size == 4) ? dut->io_wdata
                                 : (size == 2) ? ((b.addr & 2) ? (dut->io_wdata & 0xFFFF)
                                                               : (dut->io_wdata >> 16))
                                 : ((dut->io_wdata >> (lane * 8)) & 0xFF);
                    if (got != b.value) {
                        fprintf(stderr, "\n*** device write diverged at "
                                "instruction %" PRIu64 " (pc %08X): "
                                "reference %08X, board %08X\n",
                                idx, (idx < st.count ? S[idx].pc : last_pc), b.value, got);
                        failures++; break;
                    }
                } else {
                    dut->io_rdata = (size == 4) ? b.value
                                  : (size == 2) ? ((b.addr & 2) ? b.value : (b.value << 16))
                                  : (b.value << (lane * 8));
                }
                dut->io_err = BUS_IS_ERROR(b.flags) ? 1 : 0;
                dut->io_ack = 1;
                io_fire = true;
            }
        }

        // The core only moves on an enabled edge, so its retire pulse
        // stands for a whole core period. Counting it per memory clock
        // would retire every instruction twice over at a divider of two.
        bool cen_now = dut->dbg_cen, req_now = dut->io_req;
        // Hold the line up from the instruction the reference took it on
        // until this machine has taken it too.
        // The trace is the line's level each time it changed: follow it.
        if (!IRQ.empty()) {
            while (irqidx + 1 < IRQ.size() && idx + irq_lead >= IRQ[irqidx + 1].first)
                irqidx++;
            dut->irq_in = (IRQ[irqidx].second >> 2) & 0x3F;
        }
        dut->eval();
        dut->clk = 1; dut->eval();
        if (cen_now) io_pending = req_now && !io_fire;
        if (io_fire)  ioidx++;
        dut->clk = 0; dut->eval();
        cycles++;
        // What the guest is touching on the peripheral bus, and in what
        // order. Guessing which register a poll loop is reading wastes more
        // time than printing it.
        // Logged as the reference's --log-mmio prints it, so the two boots
        // diff directly. Taken at the acknowledgement, when a read's value
        // exists; a transaction is one acknowledgement.
        if (rec_dev && dut->io_req && dut->dbg_io_ack && dut->dbg_cen) {
            uint32_t a = dut->io_addr, be = dut->io_be;
            unsigned size = (be == 0xF) ? 4 : ((be == 0xC || be == 0x3) ? 2 : 1);
            uint32_t v = dut->io_we ? dut->io_wdata : dut->dbg_io_rdata;
            if (size == 2) { v = (be == 0xC) ? (v >> 16) : (v & 0xFFFF); a += (be == 0xC) ? 0 : 2; }
            else if (size == 1) { int lane = (be == 8) ? 0 : (be == 4) ? 1 : (be == 2) ? 2 : 3; v = (v >> (24 - lane * 8)) & 0xFF; a += lane; }
            uint32_t r[4] = { (uint32_t)idx, a, v, size | (dut->io_we ? 0x100u : 0u) };
            fwrite(r, sizeof r, 1, rec_dev);
        }
        // The level, shifted by the pipeline: this core takes an interrupt
        // in ID, three instructions ahead of the one retiring, and the
        // reference takes it before the instruction its count names.
        if (rec_irq && cen_now) {
            uint32_t lv = ((uint32_t)dut->dbg_irq << 2) & 0xFC;
            if (lv != rec_last_irq) {
                uint32_t r[2] = { (uint32_t)idx, lv };
                fwrite(r, sizeof r, 1, rec_irq);
                rec_last_irq = lv;
            }
        }
        if (check && dut->io_req && dut->dbg_io_ack && dut->dbg_cen && checked_bad < 12) {
            uint32_t a = dut->io_addr, be = dut->io_be;
            unsigned size = (be == 0xF) ? 4 : ((be == 0xC || be == 0x3) ? 2 : 1);
            uint32_t v = dut->io_we ? dut->io_wdata : dut->dbg_io_rdata;
            if (size == 2) { v = (be == 0xC) ? (v >> 16) : (v & 0xFFFF); a += (be == 0xC) ? 0 : 2; }
            else if (size == 1) { int lane = (be == 8) ? 0 : (be == 4) ? 1 : (be == 2) ? 2 : 3; v = (v >> (24 - lane * 8)) & 0xFF; a += lane; }
            if (ioidx >= IO.size()) {
                printf("[check] past the end of the reference at access %" PRIu64 "\n", ioidx);
                checked_bad = 12;
            } else {
                const bus_rec &b = IO[ioidx];
                unsigned rsize = BUS_SIZE(b.flags);
                bool rwr = BUS_IS_WRITE(b.flags);
                if (b.addr != a || rwr != (bool)dut->io_we || rsize != size || b.value != v) {
                    printf("[check] access %" PRIu64 " at insn %" PRIu64 ": reference %s%u %08X = %08X,"
                           " this machine %s%u %08X = %08X\n", ioidx, idx,
                           rwr ? "W" : "R", rsize * 8, b.addr, b.value,
                           dut->io_we ? "W" : "R", size * 8, a, v);
                    checked_bad++;
                }
            }
            ioidx++;
        }
        if (iolog_max && dut->io_req && dut->dbg_io_ack && dut->dbg_cen) {
            uint32_t a = dut->io_addr;
            const char *dev; uint32_t base;
            if      (a >= 0x10C00000u && a < 0x10C00400u) { dev = "tx39";      base = 0x10C00000u; }
            else if (a >= 0x10400000u && a < 0x10800000u) { dev = "pcmcia0";   base = 0x10400000u; }
            else if (a >= 0x10800000u && a < 0x10C00000u) { dev = "pcmcia1";   base = 0x10800000u; }
            else if (a >= 0xFF000000u && a < 0xFF001000u) { dev = "kseg3-dev"; base = 0xFF000000u; }
            else                                          { dev = "";          base = 0; }
            uint32_t be = dut->io_be;
            int size = (be == 0xF) ? 32 : ((be == 0xC || be == 0x3) ? 16 : 8);
            uint32_t v = dut->io_we ? dut->io_wdata : dut->dbg_io_rdata;
            if (size == 16) { uint32_t o = (be == 0xC) ? 0 : 2; v = (be == 0xC) ? (v >> 16) : (v & 0xFFFF); a += o; }
            else if (size == 8) { int lane = (be == 8) ? 0 : (be == 4) ? 1 : (be == 2) ? 2 : 3; v = (v >> (24 - lane * 8)) & 0xFF; a += lane; }
            // In the reference's own shape, so the two collapse and diff.
            if (getenv("ACC")) {
                printf("%s%d %08X %08X\n", dut->io_we ? "W" : "R", size, a, v);
                iolog++;
                goto acc_done;
            }
            char line[96];
            if (*dev) snprintf(line, sizeof line, "[mmio] %c%d %s+%03X = %08X%s", dut->io_we ? 'W' : 'R', size, dev, a - base, v,
                               getenv("IOLOG_CYCLES") ? "" : "");
            if (*dev && getenv("IOLOG_CYCLES")) printf("[cyc %" PRIu64 " insn %" PRIu64 "] ", cycles, idx);
            else      snprintf(line, sizeof line, "[mmio] %c%d %08X = %08X", dut->io_we ? 'W' : 'R', size, a, v);
            // A poll is one line with a count, not a thousand lines: the
            // log is for comparing the order of events against the
            // reference, and the count of a poll is timing, not order.
            if (!strcmp(line, iolog_last)) iolog_rep++;
            else {
                if (iolog_rep > 1) printf("  x%d", iolog_rep);
                if (iolog_last[0]) printf("\n");
                printf("%s", line);
                strcpy(iolog_last, line); iolog_rep = 1; iolog++;
            }
            acc_done: ;
        }
        if (tx39 && dut->io_req && !io_req_d)
            io_seen[(uint64_t)dut->io_addr | (dut->io_we ? (1ull<<32) : 0)]++;
        io_req_d = dut->io_req;
        if (pkg_size && dut->dbg_pkg_state != pkg_state_seen) {
            pkg_state_seen = dut->dbg_pkg_state;
            printf("\ninstall: %s (%u of %u bytes) at %llu\n", pkg_state_name[pkg_state_seen & 7],
                   dut->dbg_pkg_sent, pkg_size, (unsigned long long)idx);
        }
        if (dut->dbg_tx_stb) {
            int c = dut->dbg_tx_data;
            fputc(c, stdout);
            fflush(stdout);
        }
        if (watch_write >= 0 && dut->dbg_start && dut->dbg_start_kind != 0 && dut->dbg_start_kind != 3 &&
            (dut->dbg_start_addr & ~3u) == ((DRAM_BASE + (uint32_t)watch_write) & ~3u)) {
            printf("[watch-write] %08lX <- %08X be=%X at insn %" PRIu64 " last pc %08X\n",
                   watch_write, dut->dbg_ram_wdata, dut->dbg_ram_be, idx, last_pc);
        }
        if (dut->retire_valid && cen_now) {
            hist[hist_n++ & 255] = {dut->retire_pc, dut->retire_insn, dut->dbg_r4, dut->dbg_r2};
            last_pc = dut->retire_pc;
            if (last_pc == 0x80000080u || last_pc == 0xBFC00180u) {
                exc_taken++;
                // The instruction this interrupt was taken in front of:
                // idx is the count retired before the vector. Exact, where
                // a lead guessed from the pipeline slipped by one in a few
                // million.
                if (rec_take && dut->dbg_exc_code == 0) {
                    uint32_t t = (uint32_t)idx;
                    fwrite(&t, sizeof t, 1, rec_take);
                }

                // An interrupt taken with nothing enabled and pending is
                // one the guest cannot account for.
                if (!dut->dbg_pending) exc_spurious++;
            }
        }
        // Every fault -- an exception that is not an interrupt -- by name.
        if (dut->dbg_exc_valid && cen_now && dut->dbg_exc_code != 0) {
            printf("\n[fault] code %u epc %08X bad %08X at insn %" PRIu64
                   "  v0=%08X a0=%08X a1=%08X s0=%08X\n",
                   dut->dbg_exc_code, dut->dbg_exc_epc, dut->dbg_exc_bad, idx,
                   dut->dbg_r2, dut->dbg_r4, dut->dbg_r5, dut->dbg_r16);
            if (dut->dbg_exc_code != 9 && faults_shown++ < 2) {
                unsigned n = hist_n < 200 ? hist_n : 200;
                for (unsigned k = n; k > 0; k--) {
                    auto &h = hist[(hist_n - k) & 255];
                    printf("[path] %08X %08X  a0=%08X v0=%08X\n", h.pc, h.insn, h.a0, h.v0);
                }
            }
        }
        // Exceptions per ten million instructions: a storm is a number.
        if (idx >= exc_last_report + 10000000) {
            printf("[exc] %" PRIu64 " taken by insn %" PRIu64 "\n", exc_taken, idx);
            exc_last_report = idx;
        }
        if (tf_from && dut->retire_valid && cen_now && idx == tf_from) ta_left = ta_n;
        if ((ta_pc || tf_from) && dut->retire_valid && cen_now) {
            if (ta_pc && dut->retire_pc == ta_pc && ++ta_hits == ta_hit) ta_left = ta_n;
            if (ta_left) { printf("[trace] %08X %08X\n", dut->retire_pc, dut->retire_insn); ta_left--; }
        }
        if (getenv("DBG") && idx > 81280 && dut->dbg_start && dbgn < 30) {
            static const char *k[] = {"read ", "write", "rmw  ", "BURST"};
            printf("[start] cycle %6" PRIu64 " %s addr %07X\n",
                   cycles, k[dut->dbg_start_kind], dut->dbg_start_addr);
        }
        if (getenv("DBG") && idx > 81280 && (dut->dbg_dack || dut->dbg_iack)
            && dbgn < 30) {
            printf("[ack] cycle %6" PRIu64 " %s%s ireq=%d dreq=%d burst=%d addr %07X data %08X\n",
                   cycles, dut->dbg_dack ? "D" : " ", dut->dbg_iack ? "I" : " ",
                   dut->dbg_ireq, dut->dbg_dreq, dut->dbg_ram_burst, dut->dbg_ram_addr, dut->dbg_ram_rdata);
            dbgn++;
        }
        if (0) {
            printf("[ram] cycle %6" PRIu64 " addr %07X %s -> %08X\n",
                   cycles, dut->dbg_ram_addr,
                   dut->dbg_ram_burst ? "burst" : "single", dut->dbg_ram_rdata);
            printf("      ch2_addr %07X\n", dut->dbg_ch2_addr);
            printf("      chip: index %07X col %03X row %04X A %04X\n",
                   dut->dbg_last_index, dut->dbg_last_col,
                   dut->dbg_last_row, dut->dbg_last_a);
            dbgn++;
        }

        dut->on_button = btn_len && idx >= btn_at && idx < btn_at + btn_len;
        dut->kbd_attached = kbd;
        if (keyidx < keys.size() && idx >= keys[keyidx].at && cen_now) {
            dut->key_code = keys[keyidx].code; dut->key_ext = keys[keyidx].ext;
            dut->key_down = keys[keyidx].down; key_tog ^= 1; dut->key_tog = key_tog;
            keyidx++;
        }
        if (wav_path && cen_now && (int)dut->dbg_snd_tog != wav_tog) {
            if (!wav) { wav = fopen(wav_path, "wb"); uint8_t hdr[44] = {0}; fwrite(hdr, 1, 44, wav); }
            wav_tog = dut->dbg_snd_tog;
            int16_t v = (int16_t)dut->dbg_audio; fwrite(&v, 2, 1, wav); wav_n++;
        }
        if (tap_x >= 0) {
            // The tap in progress, if any, is the one whose window holds idx;
            // between taps the pen stays where it last was, up.
            bool down = false;
            for (const tap_t &t : taps)
                if (idx >= t.at && idx < t.at + t.len) { down = true; tap_x = t.x; tap_y = t.y; }
            if (down != (bool)dut->pen_down) printf("[pen] %s at insn %" PRIu64 "\n", down ? "down" : "up", idx);
            dut->pen_down = down;
            dut->pen_px = tap_x;      // pixels; the machine's own converter makes counts
            dut->pen_py = tap_y;
        }
        if (dump_fb && fb_every && idx >= fb_next) {
            char path[512]; snprintf(path, sizeof path, "%s.%04d.pgm", dump_fb, fb_n++);
            write_fb(path); fb_next += fb_every;
        }
        if (dut->retire_valid && cen_now && (stub || replay || check)) {
            // Nothing to compare against: the reference saw real devices
            // and this did not, so they part company at the first one.
            // Record where it goes instead.
            idx++;
            pc_seen[dut->retire_pc]++;
            if (idx <= 30)
                printf("  %6" PRIu64 "  pc %08X  insn %08X\n",
                       idx, dut->retire_pc, dut->retire_insn);
            continue;
        }
        if (dut->retire_valid && cen_now) {
            const state_rec &e = S[idx];
            bool bad = false;
            if (dut->retire_pc != e.pc || dut->retire_insn != e.insn) {
                fprintf(stderr, "\n*** retired the wrong instruction at %"
                        PRIu64 "\n    reference %08X: %08X\n"
                        "    board     %08X: %08X\n",
                        idx, e.pc, e.insn, dut->retire_pc, dut->retire_insn);
                bad = true;
            }
            for (int r = 1; r < 32 && !bad; r++)
                if (CPU(dut)->regs[r] != e.r[r - 1]) {
                    fprintf(stderr, "\n*** $%s diverged after instruction %"
                            PRIu64 " (pc %08X insn %08X): reference %08X, "
                            "board %08X\n", REGNAME[r], idx, e.pc, e.insn,
                            e.r[r - 1], CPU(dut)->regs[r]);
                    bad = true;
                }
            if (!bad && (CPU(dut)->hi != e.hi || CPU(dut)->lo != e.lo)) {
                fprintf(stderr, "\n*** hi/lo diverged after instruction %"
                        PRIu64 ": reference %08X/%08X, board %08X/%08X\n",
                        idx, e.hi, e.lo, CPU(dut)->hi, CPU(dut)->lo);
                bad = true;
            }
            if (bad) { failures++; break; }
            idx++;
            if ((idx % 1000000) == 0) {
                printf("  %" PRIu64 "M instructions matched (%.2f cycles/insn)\n",
                       idx / 1000000, (double)cycles / (double)idx);
                fflush(stdout);
            }
        }
    }

    // The core's own cycles are what matter: its clock is what Fmax caps,
    // and the memory's being faster is the whole point of the divider.
    uint64_t core_cycles = cycles / (clk_div < 1 ? 1 : clk_div);
    if (dump_fb) write_fb(dump_fb);
    if (rec_dev) fclose(rec_dev);
    if (rec_irq) fclose(rec_irq);
    if (rec_take) fclose(rec_take);
    if (card_out && card_size) {
        FILE *cf = fopen(card_out, "wb");
        for (uint32_t i = 0; i < card_size; i += 2) {
            uint16_t w = dut->tb_sdram->chip->mem[(CARD2_BASE + i) >> 1];
            fputc(w >> 8, cf); fputc(w & 0xFF, cf);
        }
        fclose(cf); printf("card: written back to %s\n", card_out);
    }
    if (wav) {
        uint32_t rate = 11025, data = wav_n * 2, riff = 36 + data;
        uint8_t h[44] = {'R','I','F','F',0,0,0,0,'W','A','V','E','f','m','t',' ',16,0,0,0,1,0,1,0,
                         0,0,0,0, 0,0,0,0, 2,0,16,0, 'd','a','t','a',0,0,0,0};
        memcpy(h + 4, &riff, 4); memcpy(h + 24, &rate, 4); uint32_t br = rate * 2; memcpy(h + 28, &br, 4);
        memcpy(h + 40, &data, 4);
        fseek(wav, 0, SEEK_SET); fwrite(h, 1, 44, wav); fclose(wav);
        printf("wav: %u samples -> %s\n", wav_n, wav_path);
    }
    printf("interrupts: %" PRIu64 " taken, %" PRIu64 " with nothing pending\n",
           exc_taken, exc_spurious);
    printf("stalls: %u waiting on a store, %u on a load, %u on an instruction"
           " (of %" PRIu64 " core clocks)\n",
           dut->dbg_stall_store, dut->dbg_stall_load, dut->dbg_stall_fetch, core_cycles);
    printf("\nmatched %" PRIu64 " of %" PRIu64 " instructions, %zu device "
           "access(es), %" PRIu64 " memory clocks, %" PRIu64
           " core clocks (%.3f IPC at core rate, divider %d)\n",
           idx, n_state, ioidx, cycles, core_cycles,
           core_cycles ? (double)idx / (double)core_cycles : 0.0, clk_div);
    if (tx39) {
        printf("\n%u byte(s) written to UART A\n", dut->dbg_tx_bytes);
        if (pkg_size) printf("install: %s (%u of %u bytes)\n", pkg_state_name[dut->dbg_pkg_state & 7],
                             dut->dbg_pkg_sent, pkg_size);
        printf("peripheral registers, most used first:\n");
        std::vector<std::pair<uint64_t,uint64_t> > iv;
        for (std::map<uint64_t,uint64_t>::iterator it = io_seen.begin();
             it != io_seen.end(); ++it)
            iv.push_back(std::make_pair(it->second, it->first));
        std::sort(iv.rbegin(), iv.rend());
        for (size_t i = 0; i < iv.size() && i < 10; i++)
            printf("   %s %08X  %" PRIu64 " times\n",
                   (iv[i].second >> 32) ? "write" : "read ",
                   (uint32_t)iv[i].second, iv[i].first);
    }
    if (stub) {
        printf("\n%zu distinct addresses executed; the ones it spends its "
               "time on:\n", pc_seen.size());
        std::vector<std::pair<uint64_t,uint32_t> > top;
        for (std::map<uint32_t,uint64_t>::iterator it = pc_seen.begin();
             it != pc_seen.end(); ++it)
            top.push_back(std::make_pair(it->second, it->first));
        std::sort(top.rbegin(), top.rend());
        for (size_t i = 0; i < top.size() && i < 12; i++)
            printf("   pc %08X  %" PRIu64 " times\n", top[i].second, top[i].first);
    }
    printf("sdram chip: %u read(s), %u write(s), %u refresh(es), "
           "worst refresh gap %u clk, %u violation(s)\n",
           dut->dbg_reads, dut->dbg_writes, dut->dbg_refreshes,
           dut->dbg_max_refresh_gap, dut->dbg_violations);
    if (dut->dbg_violations) failures++;
    printf("icache %u hit / %u miss, dcache %u hit / %u miss\n",
           dut->ihit_count, dut->imiss_count, dut->dhit_count, dut->dmiss_count);
    bool ok = !failures && idx == n_state;
    delete dut;
    printf(ok ? "PASS\n" : "FAIL\n");
    return ok ? 0 : 1;
}
