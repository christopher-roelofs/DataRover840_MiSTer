#!/usr/bin/env python3
#
# drive.py -- drive Magic Cap on the MiSTer from here: taps at panel pixels
# through a virtual mouse (scripts/vmouse.py, run on the MiSTer), the pen's
# position read back from the status line, and screenshots fetched and then
# removed from the card.
#
#   drive.py [host] script.txt      one command a line:
#       tap X Y            touch the panel at X,Y (0..479, 0..319)
#       otap X Y           the same with the option key held (right button)
#       wait S             seconds
#       shot NAME          a screenshot to NAME.png (here)
#       pen                print where the core has the pen
#       load MGL           load_core that .mgl (a path on the MiSTer)
#       key K K*N ...      keys on a virtual keyboard (f12, up, down, enter,
#                          letters...), for the OSD
#
import os, re, subprocess, sys, time

HOST = "192.168.86.171"
PASS = os.environ.get("MISTER_PASS", "1")
SSH = ["sshpass", "-p", PASS, "ssh", "-o", "StrictHostKeyChecking=no",
       "-o", "UserKnownHostsFile=/dev/null", "-o", "LogLevel=ERROR", "root@" + HOST]
HERE = os.path.dirname(os.path.abspath(__file__))

def ssh(cmd, timeout=60):
    return subprocess.run(SSH + [cmd], capture_output=True, text=True, timeout=timeout).stdout

def pen():
    out = ssh("stty -F /dev/ttyS1 38400 raw -echo cs8 -parenb -cstopb; timeout 3 cat /dev/ttyS1", 20)
    for l in reversed(re.sub(r"[^\x20-\x7e\n]", "", out).splitlines()):
        f = dict(re.findall(r"([A-Z])=([0-9A-F]{8})", l))
        if "M" in f:
            m = int(f["M"], 16)
            # Converter counts (dr840_pen.sv): 85 + x*401/256, 69 + y*579/256.
            cx, cy = (m >> 16) & 0x3FF, m & 0x3FF
            return (m >> 31) & 1, round((cx - 85) * 256 / 401), round((cy - 69) * 256 / 579)
    return None

def shot(name):
    ssh("mkdir -p /media/fat/screenshots; echo screenshot > /dev/MiSTer_cmd; sleep 3")
    f = ssh("ls -t /media/fat/screenshots/DataRover840/ | head -1").strip()
    if not f: return
    subprocess.run(["sshpass", "-p", PASS, "scp", "-o", "StrictHostKeyChecking=no",
                    "-o", "UserKnownHostsFile=/dev/null", "-o", "LogLevel=ERROR",
                    "root@%s:/media/fat/screenshots/DataRover840/%s" % (HOST, f), name + ".png"])
    ssh("rm -f '/media/fat/screenshots/DataRover840/%s'" % f)
    print("shot", name + ".png", flush=True)

def main():
    args = sys.argv[1:]
    global HOST
    if args and re.match(r"^\d+\.\d+\.\d+\.\d+$", args[0]): HOST = args.pop(0); SSH[-1] = "root@" + HOST
    subprocess.run(["sshpass", "-p", PASS, "scp", "-o", "StrictHostKeyChecking=no",
                    "-o", "UserKnownHostsFile=/dev/null", "-o", "LogLevel=ERROR",
                    os.path.join(HERE, "vmouse.py"), "root@%s:/tmp/vmouse.py" % HOST])
    vm = subprocess.Popen(SSH + ["python3 /tmp/vmouse.py"], stdin=subprocess.PIPE,
                          stdout=subprocess.PIPE, text=True, bufsize=1)
    def send(*cmds):
        for c in cmds:
            vm.stdin.write(c + "\n"); vm.stdin.flush(); vm.stdout.readline()
    time.sleep(2)
    for line in open(args[0]):
        w = line.split()
        if not w or w[0].startswith("#"): continue
        c = w[0]
        if c in ("tap", "otap"):
            x, y = int(w[1]), int(w[2])
            d, u = ("down", "up") if c == "tap" else ("rdown", "rup")
            send("home", "move %d %d" % (x, y), "sleep 0.3", d, "sleep 0.2", u, "sleep 0.3")
        elif c == "drag":     # drag X1 Y1 X2 Y2: pressed at one, released at the other
            x1, y1, x2, y2 = map(int, w[1:5])
            send("home", "move %d %d" % (x1, y1), "sleep 0.3", "down", "sleep 0.4")
            steps = 12
            for i in range(steps):
                send("move %d %d" % ((x2 - x1) * (i + 1) // steps - (x2 - x1) * i // steps,
                                     (y2 - y1) * (i + 1) // steps - (y2 - y1) * i // steps), "sleep 0.05")
            send("sleep 0.4", "up", "sleep 0.5")
        elif c == "wait": time.sleep(float(w[1]))
        elif c == "shot": shot(w[1])
        elif c == "pen": print("pen", pen(), flush=True)
        elif c == "load":
            ssh("echo load_core '%s' > /dev/MiSTer_cmd" % " ".join(w[1:])); time.sleep(3)
        elif c == "key":      # key f12 up*30 down*10 enter p ...
            send(line.strip())
        elif c == "hold":     # move there and leave the pen up, for pen readings
            send("home", "move %s %s" % (w[1], w[2]))
    vm.stdin.close(); vm.wait(timeout=10)

if __name__ == "__main__":
    main()
