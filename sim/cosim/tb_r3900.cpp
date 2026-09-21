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

#include "Vr3900.h"
#include "Vr3900_r3900.h"
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

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);

    const char *state_path = "../golden/reset-1m.trc";
    const char *bus_path   = "../golden/reset-1m.bus";
    uint64_t    limit      = 0;              // 0 = the whole trace
    bool        verbose    = false;

    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "--state") && i + 1 < argc) state_path = argv[++i];
        else if (!strcmp(argv[i], "--bus") && i + 1 < argc) bus_path = argv[++i];
        else if (!strcmp(argv[i], "-n") && i + 1 < argc) limit = strtoull(argv[++i], nullptr, 0);
        else if (!strcmp(argv[i], "-v")) verbose = true;
    }

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

    Vr3900 *dut = new Vr3900;
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
        if (dut->ibus_req) {
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
        if (dut->dbus_req) {
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
                        " (pc %08X insn %08X)\n"
                        "    reference %s %u byte(s) at %08X (word %08X) = %08X\n"
                        "    RTL       %s at %08X be=%X wdata=%08X\n",
                        idx, S[idx].pc, S[idx].insn,
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
                            " (pc %08X insn %08X)\n"
                            "    reference %u byte(s) at %08X = %08X (be %X)\n"
                            "    RTL       %08X (be %X, raw wdata %08X)\n",
                            idx, S[idx].pc, S[idx].insn, size, b.addr, b.value,
                            want_be, got, dut->dbus_be, dut->dbus_wdata);
                    failures++;
                    break;
                }
            }
            dut->dbus_err = BUS_IS_ERROR(b.flags) ? 1 : 0;
            dut->dbus_ack = 1;
        }

    clocked:
        // ---- clock ----
        // Whether the access was accepted has to be latched before the
        // edge: dbus_req is a registered output and has already dropped by
        // the time the edge has been evaluated.
        bool bus_fire = dut->dbus_req && dut->dbus_ack;
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
                uint32_t got = dut->r3900->regs[r];
                if (got != e.r[r - 1]) {
                    fprintf(stderr, "\n*** register diverged after instruction %"
                            PRIu64 " (pc %08X insn %08X)\n"
                            "    $%-4s reference %08X   RTL %08X\n",
                            idx, e.pc, e.insn, REGNAME[r], e.r[r - 1], got);
                    bad = true;
                }
            }
            if (!bad && dut->r3900->hi != e.hi) {
                fprintf(stderr, "\n*** hi diverged after instruction %" PRIu64
                        " (pc %08X insn %08X): reference %08X RTL %08X\n",
                        idx, e.pc, e.insn, e.hi, dut->r3900->hi);
                bad = true;
            }
            if (!bad && dut->r3900->lo != e.lo) {
                fprintf(stderr, "\n*** lo diverged after instruction %" PRIu64
                        " (pc %08X insn %08X): reference %08X RTL %08X\n",
                        idx, e.pc, e.insn, e.lo, dut->r3900->lo);
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

    delete dut;
    if (failures || idx != n_state) {
        printf("FAIL\n");
        return 1;
    }
    printf("PASS\n");
    return 0;
}
