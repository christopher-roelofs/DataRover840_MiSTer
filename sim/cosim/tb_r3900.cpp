//
// tb_r3900.cpp - lockstep comparison of the RTL R3900 against magicrecomp.
//
// The RTL core here has no memory and no devices. It does not need them:
// the reference trace already says what instruction sits at every address
// it will fetch, and the bus trace says what every data read returned. So
// this harness answers one question only -- given the same inputs the
// reference saw, does the RTL produce the same architectural state? -- and
// answers it from the first instruction out of reset, against the device's
// own ROM, before a single peripheral exists.
//
// Divergence is reported at the instruction it happens on, with the
// reference state beside the RTL's, because the first mismatch is the only
// one that means anything: everything after it is downstream of the first.
//
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cinttypes>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>

// One harness, two cores: the bare pipeline and the same pipeline behind
// its caches. The comparison is identical either way -- the caches are
// supposed to be invisible, so the test for them is that nothing here has
// to change.
#ifdef CACHED
#include "Vtb_top.h"
#include "Vtb_top_tb_top.h"
#include "Vtb_top_r3900_cached__Cz1.h"
#include "Vtb_top_r3900__Cz1.h"
typedef Vtb_top Dut;
#define CPU(d) ((d)->tb_top->u->cpu)
#define HAS_CACHE 1
#else
#include "Vr3900.h"
#include "Vr3900_r3900.h"
typedef Vr3900 Dut;
#define CPU(d) ((d)->r3900)
#define HAS_CACHE 0
#endif
#include "verilated.h"
#include "goldtrace.h"

static const char *REGNAME[32] = {
    "zero","at","v0","v1","a0","a1","a2","a3",
    "t0","t1","t2","t3","t4","t5","t6","t7",
    "s0","s1","s2","s3","s4","s5","s6","s7",
    "t8","t9","k0","k1","gp","sp","s8","ra"
};

struct Mapped {
    const uint8_t *base = nullptr;
    size_t         len  = 0;
    const void    *recs = nullptr;
    size_t         count = 0;

    bool open(const char *path, uint32_t magic, size_t recsize) {
        int fd = ::open(path, O_RDONLY);
        if (fd < 0) { perror(path); return false; }
        struct stat st;
        if (fstat(fd, &st) != 0) { perror(path); ::close(fd); return false; }
        len = st.st_size;
        base = (const uint8_t *)mmap(nullptr, len, PROT_READ, MAP_PRIVATE, fd, 0);
        ::close(fd);
        if (base == MAP_FAILED) { perror("mmap"); return false; }
        const trace_hdr *h = (const trace_hdr *)base;
        if (h->magic != magic) {
            fprintf(stderr, "%s: magic %08X, expected %08X\n", path, h->magic, magic);
            return false;
        }
        if (h->record_size != recsize) {
            fprintf(stderr, "%s: record size %u, this build expects %zu\n",
                    path, h->record_size, recsize);
            return false;
        }
        recs  = base + sizeof(trace_hdr);
        count = (len - sizeof(trace_hdr)) / recsize;
        return true;
    }
};

// No TLB: kseg0 and kseg1 mask the top three bits, everything else maps
// straight through. Same rule the core implements; repeated here so the
// harness can say which address it expected.
static inline uint32_t phys(uint32_t va) {
    return (va >= 0x80000000u && va < 0xC0000000u) ? (va & 0x1FFFFFFFu) : va;
}

//
// Modelled memory.
//
// Replaying the reference's bus accesses one for one only works while the
// core makes exactly the same ones. A cache breaks that by design: a read
// that hits never reaches the bus at all. So RAM and ROM are modelled here
// and the core may access them as often or as rarely as it likes, while
// anything outside them -- device registers, and addresses nothing decodes
// -- still comes from the trace in order, because that is behaviour no
// model here could invent.
//
// Stores stay strictly checked either way: the data cache is write-through,
// so every one of them still reaches the bus in program order.
//
struct Region {
    const char *name;
    uint32_t    base, window;   // decoded address range
    std::vector<uint8_t> data;  // backing store; mirrors through the window
};

struct Memory {
    std::vector<Region> regions;

    Region *find(uint32_t pa) {
        for (auto &r : regions)
            if (pa >= r.base && pa - r.base < r.window) return &r;
        return nullptr;
    }

    // A chip select can decode more space than the chips behind it hold, so
    // the contents mirror through the rest. Same rule the reference uses,
    // including that a non-power-of-two size needs a real modulo -- the
    // DataRover's 4,528,151-byte flash is exactly that.
    static uint32_t backing(const Region *r, uint32_t off) {
        uint32_t len = (uint32_t)r->data.size();
        if (off < len) return off;
        if ((len & (len - 1)) == 0) return off & (len - 1);
        return off % len;
    }

    bool read(uint32_t pa, unsigned size, uint32_t *out) {
        Region *r = find(pa);
        if (!r) return false;
        uint32_t off = backing(r, pa - r->base);
        uint32_t v = 0;
        for (unsigned i = 0; i < size; i++)           // big-endian
            v = (v << 8) | r->data[backing(r, pa - r->base + i)];
        (void)off;
        *out = v;
        return true;
    }

    bool write(uint32_t pa, unsigned size, uint32_t val) {
        Region *r = find(pa);
        if (!r) return false;
        for (unsigned i = 0; i < size; i++)
            r->data[backing(r, pa - r->base + i)] =
                (uint8_t)(val >> (8 * (size - 1 - i)));
        return true;
    }

    void add(const char *name, uint32_t base, uint32_t window, size_t len) {
        regions.push_back(Region{name, base, window, std::vector<uint8_t>(len, 0)});
    }

    bool load(const char *name, const char *path) {
        for (auto &r : regions) {
            if (strcmp(r.name, name)) continue;
            FILE *f = fopen(path, "rb");
            if (!f) { perror(path); return false; }
            r.data.clear();
            uint8_t buf[65536];
            size_t n;
            while ((n = fread(buf, 1, sizeof buf, f)) > 0)
                r.data.insert(r.data.end(), buf, buf + n);
            fclose(f);
            if (r.data.empty()) {
                fprintf(stderr, "%s: empty\n", path);
                return false;
            }
            return true;
        }
        return false;
    }
};

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);

    const char *state_path = "../golden/reset-1m.trc";
    const char *bus_path   = "../golden/reset-1m.bus";
    const char *rom_path   = nullptr;        // DataRover board map
    const char *flat_path  = nullptr;        // the directed-test map
    uint64_t    limit      = 0;              // 0 = the whole trace
    bool        verbose    = false;
    // Memory that answers immediately is the one case the core will never
    // meet. SDRAM behind a cache miss takes tens of cycles and does not
    // take the same number twice, so the stall logic has to be right for
    // any latency, not just for none.
    int ilat = 0, dlat = 0, rndlat = 0;
    uint32_t rng = 0x12345678u;

    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "--state") && i + 1 < argc) state_path = argv[++i];
        else if (!strcmp(argv[i], "--bus") && i + 1 < argc) bus_path = argv[++i];
        else if (!strcmp(argv[i], "--rom") && i + 1 < argc) rom_path = argv[++i];
        else if (!strcmp(argv[i], "--flat") && i + 1 < argc) flat_path = argv[++i];
        else if (!strcmp(argv[i], "-n") && i + 1 < argc) limit = strtoull(argv[++i], nullptr, 0);
        else if (!strcmp(argv[i], "-v")) verbose = true;
        else if (!strcmp(argv[i], "--ilat") && i + 1 < argc) ilat = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--dlat") && i + 1 < argc) dlat = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--rndlat") && i + 1 < argc) rndlat = atoi(argv[++i]);
    }

    // The two maps this harness knows. Both are the reference's, copied:
    // getting one wrong here would show up as a divergence in the core,
    // which is the worst possible place to go looking for it.
    Memory mem;
    if (rom_path) {
        mem.add("dram",        0x00000000u, 0x03C00000u, 4u << 20);
        mem.add("flash@3C",    0x03C00000u, 0x00800000u, 1);
        mem.add("flash@13C",   0x13C00000u, 0x00800000u, 1);
        mem.add("flash@reset", 0x1FC00000u, 0x00400000u, 1);
        if (!mem.load("flash@3C",    rom_path)) return 2;
        if (!mem.load("flash@13C",   rom_path)) return 2;
        if (!mem.load("flash@reset", rom_path)) return 2;
        printf("memory: 4 MB DRAM, flash %zu bytes at 03C00000/13C00000/1FC00000\n",
               mem.regions[1].data.size());
    } else if (flat_path) {
        mem.add("low",  0x00000000u, 0x00010000u, 0x10000);
        mem.add("code", 0x1FC00000u, 0x00010000u, 0x10000);
        // The image is shorter than the window; load it and pad back out,
        // because the window still decodes the rest as zeroes rather than
        // mirroring a short image.
        if (!mem.load("code", flat_path)) return 2;
        mem.regions[1].data.resize(0x10000, 0);
        printf("memory: 64 KB at 00000000 and 64 KB at 1FC00000\n");
    }
    const bool modelled = !mem.regions.empty();

    Mapped st, bs;
    if (!st.open(state_path, TRACE_STATE_MAGIC, sizeof(state_rec))) return 2;
    if (!bs.open(bus_path,   BUS_TRACE_MAGIC,   sizeof(bus_rec)))   return 2;
    const state_rec *S = (const state_rec *)st.recs;
    const bus_rec   *Ball = (const bus_rec *)bs.recs;

    // Fetch failures are keyed by address, not by position: a pipelined core
    // fetches ahead of the data accesses around it, so they cannot be
    // replayed from the same in-order stream. Data accesses can, because
    // they all happen in MEM and MEM is in order.
    std::vector<bus_rec>        B;
    std::unordered_set<uint32_t> ifetch_err;
    for (uint64_t i = 0; i < bs.count; i++) {
        if (Ball[i].flags & BUS_F_IFETCH) ifetch_err.insert(Ball[i].addr);
        else                              B.push_back(Ball[i]);
    }

    uint64_t n_state = st.count, n_bus = B.size();
    if (limit && limit < n_state) n_state = limit;
    printf("reference: %" PRIu64 " instructions, %" PRIu64 " bus accesses\n",
           n_state, n_bus);

    // A pipelined core fetches ahead of what it retires, so fetches cannot be
    // served from a retire-ordered index. Build a read-only instruction image
    // from the trace instead: every address the reference executed, with what
    // was there. An address that ever held two different words would mean the
    // ROM was written under us, which this window does not do -- say so
    // rather than silently serving one of them.
    std::unordered_map<uint32_t, uint32_t> imem;
    imem.reserve(n_state);
    for (uint64_t i = 0; i < n_state; i++) {
        uint32_t a = phys(S[i].pc);
        if (ifetch_err.count(a)) continue;
        auto it = imem.find(a);
        if (it == imem.end()) imem.emplace(a, S[i].insn);
        else if (it->second != S[i].insn) {
            fprintf(stderr, "instruction at %08X changed (%08X -> %08X) at %"
                    PRIu64 "; this harness assumes read-only code\n",
                    a, it->second, S[i].insn, i);
            return 2;
        }
    }
    printf("instruction image: %zu distinct addresses\n", imem.size());

    Dut *dut = new Dut;
    // One rate in this harness: the core's clock enable is held high. Left
    // undriven it is zero, the core never moves, and the run times out --
    // which is what happened, silently, when the port was added and this
    // harness went on being run from a binary built before it.
    dut->cen = 1;
    dut->rst_n = 0;
    dut->irq_in = 0;
    dut->ibus_ack = 0;
    dut->dbus_ack = 0;
    dut->ibus_err = 0;
    dut->dbus_err = 0;
    for (int i = 0; i < 8; i++) { dut->clk = 0; dut->eval(); dut->clk = 1; dut->eval(); }
    dut->rst_n = 1;

    uint64_t idx = 0;        // next instruction expected to retire
    uint64_t bidx = 0;       // next bus access expected
    uint64_t fetches = 0;    // instruction fetches served
    uint64_t drains  = 0;    // accesses from instructions past the trace end
    uint64_t flushed = 0;    // fetches the reference never made, i.e. flushed
    int  iwait = 0, dwait = 0;
    bool ibusy = false, dbusy = false;
    // Once a burst's first word has been handed over the rest follow a word
    // per cycle: SDRAM opens the row once.
    bool iburst_run = false, dburst_run = false;
#if HAS_CACHE
#define IBURST(d)     ((d)->ibus_burst)
#define DBURST(d)     ((d)->dbus_burst)
#else
#define IBURST(d)     false
#define DBURST(d)     false
#endif
    uint64_t model_reads = 0; // data reads served from modelled memory
    uint64_t skipped = 0;     // trace reads the core did not need to make
    // Deeper than any pipeline this core will have; only used at the very
    // end of a run.
    const uint64_t DRAIN_SLACK = 16;
    uint64_t cycles = 0;
    int      failures = 0;
    const uint64_t CYCLE_BUDGET = n_state * 64 + 1000;

    auto fail = [&](const char *what) {
        fprintf(stderr, "\n*** %s at instruction %" PRIu64 " (pc %08X, insn %08X)\n",
                what, idx, S[idx].pc, S[idx].insn);
        failures++;
    };

    while (idx < n_state && cycles < CYCLE_BUDGET) {
        // ---- combinational inputs, settled before the rising edge ----
        dut->eval();

        // Instruction fetch. The trace says what is at this address, so a
        // wrong fetch address is caught here rather than as a wrong result
        // three instructions later.
        dut->ibus_ack = 0;
        dut->ibus_err = 0;
        if (dut->ibus_req && (ilat || rndlat) && !(IBURST(dut) && iburst_run)) {
            if (iwait == 0 && !ibusy) {
                ibusy = true;
                iwait = ilat;
                if (rndlat) { rng = rng * 1103515245u + 12345u;
                              iwait += (rng >> 16) % (unsigned)rndlat; }
            }
            if (iwait > 0) { iwait--; goto fetched; }
        }
        if (!dut->ibus_req) { ibusy = false; iburst_run = false; }
        if (dut->ibus_req) {
            ibusy = false;
            if (IBURST(dut)) iburst_run = true;
            uint32_t iw;
            if (modelled && mem.read(dut->ibus_addr, 4, &iw)) {
                dut->ibus_rdata = iw;
                dut->ibus_ack   = 1;
                fetches++;
                goto fetched;
            }
            if (ifetch_err.count(dut->ibus_addr)) {
                // The reference could not fetch this address either.
                dut->ibus_rdata = 0;
                dut->ibus_err   = 1;
                dut->ibus_ack   = 1;
                fetches++;
                goto fetched;
            }
            auto it = imem.find(dut->ibus_addr);
            if (it == imem.end()) {
                // An exception flushes instructions that were already
                // fetched, so near a fault the core legitimately asks for
                // addresses the reference never reached. Serve a NOP and
                // let the retire comparison be the judge: if one of these
                // ever actually retires, its pc will not match and that is
                // caught on the very next retire.
                dut->ibus_rdata = 0;
                dut->ibus_ack   = 1;
                fetches++;
                flushed++;
                goto fetched;
            }
            dut->ibus_rdata = it->second;
            dut->ibus_ack   = 1;
            fetches++;
        }
    fetched:;

        // Data access, replayed from the reference.
        dut->dbus_ack = 0;
        // Only an access actually matched against the trace consumes a
        // record. A read served from the model, or one draining past the
        // end, is acked without advancing anything.
        bool from_trace = false;
        dut->dbus_ack = 0;
        if (dut->dbus_req && (dlat || rndlat) && !(DBURST(dut) && dburst_run)) {
            if (dwait == 0 && !dbusy) {
                dbusy = true;
                dwait = dlat;
                if (rndlat) { rng = rng * 1103515245u + 12345u;
                              dwait += (rng >> 16) % (unsigned)rndlat; }
            }
            if (dwait > 0) { dwait--; goto clocked; }
        }
        if (!dut->dbus_req) { dbusy = false; dburst_run = false; }
        if (dut->dbus_req) {
            dbusy = false;
            if (DBURST(dut)) dburst_run = true;
            uint32_t wa = dut->dbus_addr;
            Region  *mr = modelled ? mem.find(wa) : nullptr;

            if (mr && !dut->dbus_we) {
                // A read the core may or may not have made, depending on
                // what its cache held. Serve it and consume nothing: the
                // trace cannot say whether it should have happened.
                uint32_t v = 0;
                mem.read(wa, 4, &v);
                dut->dbus_rdata = v;
                dut->dbus_err   = 0;
                dut->dbus_ack   = 1;
                model_reads++;
                goto clocked;
            }

            // Everything else still matches the trace in order. Reads that
            // the model serves are stepped over, because the core was free
            // not to make them.
            while (bidx < n_bus && !BUS_IS_WRITE(B[bidx].flags) &&
                   !BUS_IS_ERROR(B[bidx].flags) && modelled &&
                   mem.find(B[bidx].addr)) {
                bidx++;
                skipped++;
            }

            if (bidx >= n_bus) {
                // A pipelined core has instructions in flight past the one
                // it is retiring, and near the end of the trace those are
                // instructions the reference never recorded. Let them
                // complete so the pipeline can drain, but only that close to
                // the end -- anywhere earlier this means the core went
                // somewhere the reference did not.
                if (idx + DRAIN_SLACK >= n_state) {
                    dut->dbus_rdata = 0;
                    dut->dbus_ack   = 1;
                    drains++;
                    goto clocked;
                }
                fail("bus access past the end of the reference bus trace");
                break;
            }
            const bus_rec &b = B[bidx];
            uint32_t word_addr = b.addr & ~3u;
            unsigned size = BUS_SIZE(b.flags);
            bool     wr   = BUS_IS_WRITE(b.flags);
            bool     err  = BUS_IS_ERROR(b.flags);
            (void)err;

            if (dut->dbus_addr != word_addr || (bool)dut->dbus_we != wr) {
                fprintf(stderr, "\n*** bus access diverged at instruction %" PRIu64
                        " (pc %08X insn %08X), bus record %" PRIu64 "\n"
                        "    reference %s %u byte(s) at %08X (word %08X) = %08X\n"
                        "    RTL       %s at %08X be=%X wdata=%08X\n",
                        idx, S[idx].pc, S[idx].insn, bidx,
                        wr ? "write" : "read", size, b.addr, word_addr, b.value,
                        dut->dbus_we ? "write" : "read",
                        dut->dbus_addr, dut->dbus_be, dut->dbus_wdata);
                failures++;
                break;
            }

            // Big-endian lanes: lane 3 is the byte at the word address.
            unsigned lane = 3u - (b.addr & 3u);
            if (BUS_IS_ERROR(b.flags) && !wr) {
                dut->dbus_rdata = 0;
            } else if (!wr) {
                uint32_t w = 0;
                if (size == 4)      w = b.value;
                else if (size == 2) w = (b.addr & 2) ? b.value : (b.value << 16);
                else                w = b.value << (lane * 8);
                dut->dbus_rdata = w;
            } else {
                uint32_t got;
                if (size == 4)      got = dut->dbus_wdata;
                else if (size == 2) got = (b.addr & 2) ? (dut->dbus_wdata & 0xFFFF)
                                                       : (dut->dbus_wdata >> 16);
                else                got = (dut->dbus_wdata >> (lane * 8)) & 0xFF;
                uint8_t want_be = (size == 4) ? 0xF
                                : (size == 2) ? ((b.addr & 2) ? 0x3 : 0xC)
                                : (uint8_t)(1u << lane);
                if (got != b.value || dut->dbus_be != want_be) {
                    fprintf(stderr, "\n*** store diverged at instruction %" PRIu64
                            " (pc %08X insn %08X), bus record %" PRIu64 "\n"
                            "    reference %u byte(s) at %08X = %08X (be %X)\n"
                            "    RTL       %08X (be %X, raw wdata %08X)\n",
                            idx, S[idx].pc, S[idx].insn, bidx, size, b.addr,
                            b.value, want_be, got, dut->dbus_be,
                            dut->dbus_wdata);
                    // The store data came from a register; say which of them
                    // already disagree, because that is where it went wrong.
                    for (int r = 1; r < 32; r++)
                        if (CPU(dut)->regs[r] != S[idx].r[r - 1])
                            fprintf(stderr, "    $%-4s reference %08X  RTL %08X\n",
                                    REGNAME[r], S[idx].r[r - 1],
                                    CPU(dut)->regs[r]);
                    failures++;
                    break;
                }
            }
            dut->dbus_err = BUS_IS_ERROR(b.flags) ? 1 : 0;
            dut->dbus_ack = 1;
            from_trace    = true;

            // A write-through store also lands in the model, so a later
            // read of the same address sees it.
            if (mr && dut->dbus_we && !BUS_IS_ERROR(b.flags)) {
                for (unsigned L = 0; L < 4; L++)
                    if (dut->dbus_be & (8u >> L))
                        mem.write(wa + L, 1,
                                  (dut->dbus_wdata >> (8 * (3 - L))) & 0xFF);
            }
        }

    clocked:
        // ---- clock ----
        // Whether the access was accepted has to be latched before the
        // edge: dbus_req is a registered output and has already dropped by
        // the time the edge has been evaluated.
        bool bus_fire = from_trace && dut->dbus_req && dut->dbus_ack;
        dut->eval();
        dut->clk = 1; dut->eval();
        if (bus_fire) bidx++;
        dut->clk = 0; dut->eval();
        cycles++;

        // ---- retire ----
        if (dut->retire_valid) {
            const state_rec &e = S[idx];
            bool bad = false;

            if (dut->retire_pc != e.pc || dut->retire_insn != e.insn) {
                fprintf(stderr, "\n*** retired the wrong instruction at %" PRIu64 "\n"
                        "    reference %08X: %08X\n    RTL       %08X: %08X\n",
                        idx, e.pc, e.insn, dut->retire_pc, dut->retire_insn);
                bad = true;
            }
            for (int r = 1; r < 32 && !bad; r++) {
                uint32_t got = CPU(dut)->regs[r];
                if (got != e.r[r - 1]) {
                    fprintf(stderr, "\n*** register diverged after instruction %"
                            PRIu64 " (pc %08X insn %08X)\n"
                            "    $%-4s reference %08X   RTL %08X\n",
                            idx, e.pc, e.insn, REGNAME[r], e.r[r - 1], got);
                    bad = true;
                }
            }
            if (!bad && CPU(dut)->hi != e.hi) {
                fprintf(stderr, "\n*** hi diverged after instruction %" PRIu64
                        " (pc %08X insn %08X): reference %08X RTL %08X\n",
                        idx, e.pc, e.insn, e.hi, CPU(dut)->hi);
                bad = true;
            }
            if (!bad && CPU(dut)->lo != e.lo) {
                fprintf(stderr, "\n*** lo diverged after instruction %" PRIu64
                        " (pc %08X insn %08X): reference %08X RTL %08X\n",
                        idx, e.pc, e.insn, e.lo, CPU(dut)->lo);
                bad = true;
            }
            if (!bad && dut->retire_next_pc != e.next_pc) {
                fprintf(stderr, "\n*** next_pc diverged after instruction %" PRIu64
                        " (pc %08X insn %08X): reference %08X RTL %08X\n",
                        idx, e.pc, e.insn, e.next_pc, dut->retire_next_pc);
                bad = true;
            }
            if (bad) { failures++; break; }

            if (verbose && idx < 64)
                printf("%8" PRIu64 "  %08X: %08X\n", idx, e.pc, e.insn);
            idx++;
            if ((idx % 100000) == 0) {
                printf("  %" PRIu64 " instructions matched (%.2f cycles/insn)\n",
                       idx, (double)cycles / (double)idx);
                fflush(stdout);
            }
        }
    }

    printf("\n");
    if (cycles >= CYCLE_BUDGET)
        printf("stalled: %" PRIu64 " cycles without finishing\n", cycles);
    printf("matched %" PRIu64 " of %" PRIu64 " instructions, %" PRIu64
           " bus accesses, %" PRIu64 " cycles (%.2f cycles/insn, %.3f IPC)\n",
           idx, n_state, bidx, cycles, idx ? (double)cycles / (double)idx : 0.0,
           cycles ? (double)idx / (double)cycles : 0.0);
    // A core that fetches much more than it retires is speculating and
    // throwing the work away; this one should not be.
    printf("fetches %" PRIu64 " for %" PRIu64 " retires (%.3f per instruction)\n",
           fetches, idx, idx ? (double)fetches / (double)idx : 0.0);
    if (drains)
        printf("%" PRIu64 " access(es) from instructions still in flight past "
               "the end of the trace\n", drains);
    if (flushed)
        printf("%" PRIu64 " fetch(es) discarded by a flush\n", flushed);
#if HAS_CACHE
    {
        uint64_t ih = dut->ihit_count, im = dut->imiss_count;
        uint64_t dh = dut->dhit_count, dm = dut->dmiss_count;
        printf("icache %" PRIu64 " hit / %" PRIu64 " miss (%.2f%%), "
               "dcache %" PRIu64 " hit / %" PRIu64 " miss (%.2f%%)\n",
               ih, im, (ih + im) ? 100.0 * ih / (ih + im) : 0.0,
               dh, dm, (dh + dm) ? 100.0 * dh / (dh + dm) : 0.0);
    }
#endif
    if (modelled)
        printf("%" PRIu64 " data read(s) from modelled memory; %" PRIu64
               " reference read(s) the core did not need to repeat\n",
               model_reads, skipped);

    delete dut;
    if (failures || idx != n_state) {
        printf("FAIL\n");
        return 1;
    }
    printf("PASS\n");
    return 0;
}
