#!/usr/bin/env python3
#
# vpad.py -- a virtual gamepad on the MiSTer, for testing the core's joystick
# path remotely. Runs on the MiSTer; reads commands on stdin, one a line:
#
#   btn CODE 0|1     a key (hex or decimal: 0x130 BTN_SOUTH, 0x131 BTN_EAST...)
#   abs AXIS VALUE   an axis (0 X, 1 Y: -32768..32767; 16 HAT0X, 17 HAT0Y: -1..1)
#   sleep S          seconds
#
# It reports as an Xbox-style pad (045e:02e0 by default, or VID:PID as the
# first argument), so Main applies that pad's saved button map to it.
import fcntl, os, struct, sys, time

UI_SET_EVBIT, UI_SET_KEYBIT, UI_SET_ABSBIT = 0x40045564, 0x40045565, 0x40045567
UI_DEV_CREATE, UI_DEV_DESTROY = 0x5501, 0x5502
EV_SYN, EV_KEY, EV_ABS = 0, 1, 3
vid, pid = (int(x, 16) for x in (sys.argv[1] if len(sys.argv) > 1 else "045e:02e0").split(":"))

fd = os.open("/dev/uinput", os.O_WRONLY | os.O_NONBLOCK)
for ev in (EV_KEY, EV_ABS, EV_SYN):
    fcntl.ioctl(fd, UI_SET_EVBIT, ev)
for k in list(range(0x130, 0x13F)):
    fcntl.ioctl(fd, UI_SET_KEYBIT, k)
AXES = {0: (-32768, 32767), 1: (-32768, 32767), 3: (-32768, 32767), 4: (-32768, 32767),
        2: (0, 1023), 5: (0, 1023), 16: (-1, 1), 17: (-1, 1)}
absmax, absmin = [0] * 64, [0] * 64
for a, (lo, hi) in AXES.items():
    fcntl.ioctl(fd, UI_SET_ABSBIT, a)
    absmin[a], absmax[a] = lo, hi
dev = struct.pack("80sHHHHi", b"DataRover remote pad", 3, vid, pid, 0x114, 0)
dev += struct.pack("64i", *absmax) + struct.pack("64i", *absmin) + b"\0" * (2 * 64 * 4)
os.write(fd, dev)
fcntl.ioctl(fd, UI_DEV_CREATE)
time.sleep(1.5)

def emit(t, c, v):
    os.write(fd, struct.pack("llHHi", 0, 0, t, c, v))
    os.write(fd, struct.pack("llHHi", 0, 0, EV_SYN, 0, 0))

for line in sys.stdin:
    w = line.split()
    if not w: continue
    if w[0] == "btn": emit(EV_KEY, int(w[1], 0), int(w[2]))
    elif w[0] == "abs": emit(EV_ABS, int(w[1], 0), int(w[2]))
    elif w[0] == "sleep": time.sleep(float(w[1]))
    print("ok", flush=True)
fcntl.ioctl(fd, UI_DEV_DESTROY)
