#!/usr/bin/env python3
#
# vmouse.py -- a virtual mouse on the MiSTer, for driving Magic Cap remotely.
#
# Runs on the MiSTer (copied over by scripts/drive). Creates a uinput mouse
# that the MiSTer's input layer hands to the core like any other, and reads
# commands on stdin, one a line:
#
#   move DX DY        relative motion, in panel pixels (the core adds them 1:1)
#   home              far up and to the left: the pen at 0,0
#   down / up         the left button (a touch)
#   rdown / rup       the right button (a touch with the option key)
#   sleep S           seconds
#
import fcntl, os, struct, sys, time

UI_SET_EVBIT, UI_SET_KEYBIT, UI_SET_RELBIT = 0x40045564, 0x40045565, 0x40045566
UI_DEV_CREATE, UI_DEV_DESTROY = 0x5501, 0x5502
EV_SYN, EV_KEY, EV_REL = 0, 1, 2
REL_X, REL_Y = 0, 1
BTN_LEFT, BTN_RIGHT = 0x110, 0x111

fd = os.open("/dev/uinput", os.O_WRONLY | os.O_NONBLOCK)
for ev in (EV_KEY, EV_REL, EV_SYN):
    fcntl.ioctl(fd, UI_SET_EVBIT, ev)
for k in (BTN_LEFT, BTN_RIGHT):
    fcntl.ioctl(fd, UI_SET_KEYBIT, k)
for r in (REL_X, REL_Y):
    fcntl.ioctl(fd, UI_SET_RELBIT, r)
# struct uinput_user_dev: name[80], id (4 x u16), ff_effects_max, abs arrays
dev = struct.pack("80sHHHHi", b"DataRover remote mouse", 3, 0x1234, 0x5678, 1, 0) + b"\0" * (4 * 64 * 4)
os.write(fd, dev)
fcntl.ioctl(fd, UI_DEV_CREATE)

# And a keyboard, for the OSD: its own device, so the MiSTer takes it as one.
kfd = os.open("/dev/uinput", os.O_WRONLY | os.O_NONBLOCK)
for ev in (EV_KEY, EV_SYN):
    fcntl.ioctl(kfd, UI_SET_EVBIT, ev)
for k in range(1, 128):
    fcntl.ioctl(kfd, UI_SET_KEYBIT, k)
os.write(kfd, struct.pack("80sHHHHi", b"DataRover remote keyboard", 3, 0x1234, 0x5679, 1, 0) + b"\0" * (4 * 64 * 4))
fcntl.ioctl(kfd, UI_DEV_CREATE)
time.sleep(1.5)          # for the MiSTer to find them
KEYS = {"f12": 88, "up": 103, "down": 108, "left": 105, "right": 106, "enter": 28, "esc": 1,
        "backspace": 14, "home": 102, "end": 107, "dot": 52, "slash": 53, "space": 57, "minus": 12}
for i, ch in enumerate("qwertyuiop"): KEYS[ch] = 16 + i
for i, ch in enumerate("asdfghjkl"): KEYS[ch] = 30 + i
for i, ch in enumerate("zxcvbnm"): KEYS[ch] = 44 + i
for i, ch in enumerate("1234567890"): KEYS[ch] = 2 + i
def key(name):
    code = KEYS[name]
    os.write(kfd, struct.pack("llHHi", 0, 0, EV_KEY, code, 1)); os.write(kfd, struct.pack("llHHi", 0, 0, EV_SYN, 0, 0))
    time.sleep(0.05)
    os.write(kfd, struct.pack("llHHi", 0, 0, EV_KEY, code, 0)); os.write(kfd, struct.pack("llHHi", 0, 0, EV_SYN, 0, 0))
    time.sleep(0.12)

def emit(t, c, v):
    os.write(fd, struct.pack("llHHi", 0, 0, t, c, v))
def syn():
    emit(EV_SYN, 0, 0)
def move(dx, dy):
    # In steps a PS/2 packet can carry.
    while dx or dy:
        sx = max(-100, min(100, dx)); sy = max(-100, min(100, dy))
        emit(EV_REL, REL_X, sx); emit(EV_REL, REL_Y, sy); syn()
        dx -= sx; dy -= sy
        time.sleep(0.02)

for line in sys.stdin:
    w = line.split()
    if not w: continue
    c = w[0]
    if c == "move": move(int(w[1]), int(w[2]))
    elif c == "home": move(-700, -500)
    elif c == "down": emit(EV_KEY, BTN_LEFT, 1); syn()
    elif c == "up": emit(EV_KEY, BTN_LEFT, 0); syn()
    elif c == "rdown": emit(EV_KEY, BTN_RIGHT, 1); syn()
    elif c == "rup": emit(EV_KEY, BTN_RIGHT, 0); syn()
    elif c == "sleep": time.sleep(float(w[1]))
    elif c == "key":
        for k in w[1:]:
            n = 1
            if "*" in k: k, n = k.split("*"); n = int(n)
            for _ in range(n): key(k)
    print("ok", flush=True)

fcntl.ioctl(fd, UI_DEV_DESTROY)
