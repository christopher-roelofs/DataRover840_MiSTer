#!/usr/bin/env python3
#
# cardtrace.py -- read the core's slot-1 trace out of the MiSTer's DDR and
# print it the way the reference emulator's --log-card does, to diff.
#
# Runs on the MiSTer: python3 cardtrace.py [first] [count]
#
import mmap, os, struct, sys

BASE = 0x38000000
fd = os.open("/dev/mem", os.O_RDONLY | os.O_SYNC)
hdr = mmap.mmap(fd, 0x1000, mmap.MAP_SHARED, mmap.PROT_READ, offset=BASE)
n = struct.unpack_from("<I", hdr, 0x38)[0]
tr = mmap.mmap(fd, 8192 * 8, mmap.MAP_SHARED, mmap.PROT_READ, offset=BASE + 0x100000)
first = int(sys.argv[1]) if len(sys.argv) > 1 else 0
count = int(sys.argv[2]) if len(sys.argv) > 2 else n
print("# %d accesses logged" % n)
LANE = {0x8: 0, 0x4: 1, 0x2: 2, 0x1: 3}
for i in range(first, min(n, first + count, 8192)):
    w = struct.unpack_from("<Q", tr, i * 8)[0]
    we, gl, be = w >> 63, (w >> 62) & 1, (w >> 58) & 0xF
    addr, data = (w >> 32) & 0xFFFFFF, w & 0xFFFFFFFF
    rw = "W" if we else "R"
    if gl:
        off = addr & 0x3F
        v = data >> 16 if be & 0xC else data & 0xFFFF
        print("[pcmcia0] %s +%02X = %04X" % (rw, off + (0 if be & 0xC else 2), v))
    elif be in LANE:
        lane = LANE[be]
        print("[card1] %s8 window A +%06X = %08X" % (rw, addr + lane, (data >> (24 - 8 * lane)) & 0xFF))
    elif be in (0xC, 0x3):
        print("[card1] %s16 window A +%06X = %08X" % (rw, addr + (0 if be == 0xC else 2),
                                                  data >> 16 if be == 0xC else data & 0xFFFF))
    else:
        print("[card1] %s32 window A +%06X = %08X" % (rw, addr, data))
