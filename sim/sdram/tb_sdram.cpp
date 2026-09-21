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

    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "--state") && i + 1 < argc) state_path = argv[++i];
        else if (!strcmp(argv[i], "--bus") && i + 1 < argc) bus_path = argv[++i];
        else if (!strcmp(argv[i], "--rom") && i + 1 < argc) rom_path = argv[++i];
        else if (!strcmp(argv[i], "-n") && i + 1 < argc) limit = strtoull(argv[++i], nullptr, 0);
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
    if (limit && limit < n_state) n_state = limit;
    printf("reference: %" PRIu64 " instructions, %zu device access(es) of "
           "%" PRIu64 " total\n", n_state, IO.size(), (uint64_t)bs.count);

    Vtb_sdram *dut = new Vtb_sdram;

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
    dut->rst_n = 0; dut->irq_in = 0;
    dut->io_ack = 0; dut->io_err = 0;
    for (int i = 0; i < 8; i++) { dut->clk = 0; dut->eval(); dut->clk = 1; dut->eval(); }
    dut->rst_n = 1;

    uint64_t idx = 0, ioidx = 0, cycles = 0;
    int failures = 0, dbgn = 0;
    const uint64_t BUDGET = n_state * 200 + 100000;

    while (idx < n_state && cycles < BUDGET) {
        dut->eval();

        // The SDRAM answers for itself now; only the peripheral bus is
        // still the testbench's job.
        // ---- peripherals, replayed in order
        dut->io_ack = 0; dut->io_err = 0;
        bool io_fire = false;
        if (dut->io_req) {
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
                            idx, S[idx].pc, ioidx, wr ? "write" : "read",
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
                                idx, S[idx].pc, b.value, got);
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

        dut->eval();
        dut->clk = 1; dut->eval();
        if (io_fire)  ioidx++;
        dut->clk = 0; dut->eval();
        cycles++;
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

        if (dut->retire_valid) {
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

    printf("\nmatched %" PRIu64 " of %" PRIu64 " instructions, %zu device "
           "access(es), %" PRIu64 " cycles (%.3f IPC)\n",
           idx, n_state, ioidx, cycles,
           cycles ? (double)idx / (double)cycles : 0.0);
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
