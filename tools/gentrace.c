/*
 * gentrace.c - run a directed test program on magicrecomp's core and record
 * the same two traces the DataRover ROM runs produce.
 *
 * The ROM is an excellent test of the paths it uses and no test at all of
 * the ones it does not: in ten million instructions from reset it takes zero
 * exceptions and never executes ADD, SUB, MULTU, signed DIV, BLTZAL or
 * BGEZAL. Those paths exist in the RTL and have never run. This builds a
 * machine minimal enough to aim at them deliberately, and keeps the
 * reference as the arbiter, so the tests say what the hardware does rather
 * than what I believed when I wrote them.
 *
 * The machine is two RAMs and nothing else:
 *
 *   0x00000000  64 KB  data, and the BEV=0 exception vector at 0x80000080
 *   0x1FC00000  64 KB  the test image; reset lands here at 0xBFC00000, and
 *                      the BEV=1 vector is at 0xBFC00180
 *
 * Reset is the architectural one, so the RTL side needs no special setup:
 * same reset PC, same Status, same PRId. Everything above 0x20000000 that
 * is not those two windows is unmapped, which is how a test reaches a bus
 * error on purpose.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "core/bus/bus.h"
#include "cpu/mips/r3900.h"

#define LOW_BASE   0x00000000u
#define LOW_SIZE   0x00010000u
#define CODE_BASE  0x1FC00000u
#define CODE_SIZE  0x00010000u

static void usage(void)
{
    fprintf(stderr,
        "usage: gentrace <image> <out-prefix> [-n insns] [-v]\n"
        "  <image>       raw big-endian image loaded at physical 0x1FC00000\n"
        "  <out-prefix>  writes <prefix>.trc and <prefix>.bus\n");
    exit(2);
}

int main(int argc, char **argv)
{
    if (argc < 3) usage();
    const char *image_path = argv[1];
    const char *prefix     = argv[2];
    uint64_t    insns      = 20000;
    int         verbose    = 0;

    for (int i = 3; i < argc; i++) {
        if (!strcmp(argv[i], "-n") && i + 1 < argc)
            insns = strtoull(argv[++i], NULL, 0);
        else if (!strcmp(argv[i], "-v"))
            verbose = 1;
        else usage();
    }

    uint8_t *low  = calloc(1, LOW_SIZE);
    uint8_t *code = calloc(1, CODE_SIZE);
    if (!low || !code) { perror("calloc"); return 1; }

    FILE *f = fopen(image_path, "rb");
    if (!f) { perror(image_path); return 1; }
    size_t n = fread(code, 1, CODE_SIZE, f);
    if (ferror(f)) { perror(image_path); return 1; }
    if (!feof(f)) {
        fprintf(stderr, "gentrace: %s is larger than the %u-byte code window\n",
                image_path, CODE_SIZE);
        return 1;
    }
    fclose(f);

    mrc_bus bus;
    mrc_bus_init(&bus);
    mrc_bus_add_ram(&bus, "low",  LOW_BASE,  low,  LOW_SIZE,  LOW_SIZE);
    mrc_bus_add_ram(&bus, "code", CODE_BASE, code, CODE_SIZE, CODE_SIZE);

    r3900 cpu;
    mrc_cpu_init(&cpu, &bus);
    /* The TMPR3902U has no TLB; mrc_cpu_init defaults to the architectural
     * TLB and boards override it. Getting this wrong would make kuseg
     * accesses fault here and not on the RTL side. */
    cpu.has_mmu = false;
    mrc_cpu_reset(&cpu, 0xBFC00000u);

    char path[4096];
    snprintf(path, sizeof path, "%s.trc", prefix);
    mrc_cpu_trace_state(path, insns);
    snprintf(path, sizeof path, "%s.bus", prefix);
    mrc_cpu_trace_bus(path, insns * 4);

    for (uint64_t i = 0; i < insns && !cpu.halted; i++)
        mrc_cpu_step(&cpu);

    mrc_cpu_trace_state_close();
    mrc_cpu_trace_bus_close();

    if (verbose) {
        fprintf(stderr, "gentrace: %s, %zu bytes\n", image_path, n);
        fprintf(stderr, "  %llu instructions, %llu exceptions\n",
                (unsigned long long)cpu.insn_count,
                (unsigned long long)cpu.exc_count);
        mrc_cpu_dump(&cpu, stderr);
    }
    /* A test that takes no exception when it meant to is a test that proved
     * nothing, so the count is part of the output and the runner checks it. */
    printf("%llu %llu\n", (unsigned long long)cpu.insn_count,
           (unsigned long long)cpu.exc_count);
    return 0;
}
