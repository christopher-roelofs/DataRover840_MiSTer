#!/usr/bin/env python3
"""
A small big-endian MIPS-I assembler, for the directed tests.

Only what the R3900 core implements, which is MIPS-I plus CACHE and RFE. It
exists so the tests can be read as instructions rather than as hex, and so
that no cross-toolchain has to be installed to run them.

Deliberately strict: an unknown mnemonic or a bad operand is an error, never
a silently-encoded something-else. A test suite that assembles the wrong
instruction proves nothing.
"""
import re
import sys

REGS = {}
for _i, _n in enumerate([
        "zero", "at", "v0", "v1", "a0", "a1", "a2", "a3",
        "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7",
        "s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7",
        "t8", "t9", "k0", "k1", "gp", "sp", "s8", "ra"]):
    REGS["$" + _n] = _i
    REGS["$" + str(_i)] = _i
REGS["$fp"] = 30

# funct codes for the three-register and shift forms
R3 = {"add": 0x20, "addu": 0x21, "sub": 0x22, "subu": 0x23, "and": 0x24,
      "or": 0x25, "xor": 0x26, "nor": 0x27, "slt": 0x2A, "sltu": 0x2B}
RSHIFT  = {"sll": 0x00, "srl": 0x02, "sra": 0x03}          # rd, rt, shamt
RSHIFTV = {"sllv": 0x04, "srlv": 0x06, "srav": 0x07}       # rd, rt, rs
RMULDIV = {"mult": 0x18, "multu": 0x19, "div": 0x1A, "divu": 0x1B}
RMOVE_FROM = {"mfhi": 0x10, "mflo": 0x12}                  # rd
RMOVE_TO   = {"mthi": 0x11, "mtlo": 0x13}                  # rs

IARITH = {"addi": 0x08, "addiu": 0x09, "slti": 0x0A, "sltiu": 0x0B,
          "andi": 0x0C, "ori": 0x0D, "xori": 0x0E}
IMEM = {"lb": 0x20, "lh": 0x21, "lwl": 0x22, "lw": 0x23, "lbu": 0x24,
        "lhu": 0x25, "lwr": 0x26, "sb": 0x28, "sh": 0x29, "swl": 0x2A,
        "sw": 0x2B, "swr": 0x2E}
IBR2 = {"beq": 0x04, "bne": 0x05}                          # rs, rt, label
IBR1 = {"blez": 0x06, "bgtz": 0x07}                        # rs, label
REGIMM = {"bltz": 0x00, "bgez": 0x01, "bltzal": 0x10, "bgezal": 0x11}


class AsmError(Exception):
    pass


def _reg(tok, where):
    r = REGS.get(tok.strip())
    if r is None:
        raise AsmError("%s: not a register: %r" % (where, tok))
    return r


def _imm(tok, labels, where):
    tok = tok.strip()
    # %hi/%lo split a 32-bit address across lui+ori. Paired with ori, which
    # zero-extends, so plain halves are right -- no addiu sign-extension
    # adjustment, and none is wanted.
    m = re.match(r"^%(hi|lo)\s*\(\s*(.+?)\s*\)$", tok)
    if m:
        v = _imm(m.group(2), labels, where)
        return (v >> 16) & 0xFFFF if m.group(1) == "hi" else v & 0xFFFF
    if tok in labels:
        return labels[tok]
    try:
        return int(tok, 0)
    except ValueError:
        raise AsmError("%s: not a number or known label: %r" % (where, tok))


def _mem(tok, labels, where):
    """off(reg), where off may be a number or a label."""
    m = re.match(r"^\s*([^(]*)\(\s*(\$\w+)\s*\)\s*$", tok)
    if not m:
        raise AsmError("%s: not an address: %r" % (where, tok))
    off = m.group(1).strip()
    return (_imm(off, labels, where) if off else 0), _reg(m.group(2), where)


def _R(rs=0, rt=0, rd=0, sa=0, fn=0):
    return (rs << 21) | (rt << 16) | (rd << 11) | (sa << 6) | fn


def _I(op, rs, rt, imm):
    return (op << 26) | (rs << 21) | (rt << 16) | (imm & 0xFFFF)


def assemble(text, base):
    """Assemble `text` starting at address `base`. Returns bytes, big-endian."""
    # Pass one: addresses and labels.
    lines = []
    labels = {}
    addr = base
    for lineno, raw in enumerate(text.splitlines(), 1):
        line = raw.split("#")[0].strip()
        while True:
            m = re.match(r"^([A-Za-z_.][\w.]*)\s*:\s*(.*)$", line)
            if not m:
                break
            labels[m.group(1)] = addr
            line = m.group(2).strip()
        if not line:
            continue
        op = line.split()[0].lower()
        if op == ".org":
            new = int(line.split(None, 1)[1], 0)
            if new < addr:
                raise AsmError("line %d: .org moves backwards" % lineno)
            lines.append((lineno, addr, ".pad", str(new - addr)))
            addr = new
            continue
        if op == ".space":
            n = int(line.split(None, 1)[1], 0)
            lines.append((lineno, addr, ".pad", str(n)))
            addr += n
            continue
        rest = line.split(None, 1)[1] if len(line.split(None, 1)) > 1 else ""
        lines.append((lineno, addr, op, rest))
        addr += 4 * (len(rest.split(",")) if op == ".word" else 1)

    # Pass two: encode.
    out = bytearray()
    for lineno, at, op, rest in lines:
        where = "line %d" % lineno
        args = [a.strip() for a in rest.split(",")] if rest.strip() else []

        if op == ".pad":
            out += b"\x00" * int(rest)
            continue
        if op == ".word":
            for a in args:
                out += (_imm(a, labels, where) & 0xFFFFFFFF).to_bytes(4, "big")
            continue

        w = _encode(op, args, labels, at, where)
        out += (w & 0xFFFFFFFF).to_bytes(4, "big")
    return bytes(out)


def _encode(op, args, labels, at, where):
    def need(n):
        if len(args) != n:
            raise AsmError("%s: %s takes %d operand(s), got %d"
                           % (where, op, n, len(args)))

    # Branch displacement is relative to the delay slot, in words.
    def disp(tok):
        target = _imm(tok, labels, where)
        d = (target - (at + 4)) >> 2
        if not -0x8000 <= d <= 0x7FFF:
            raise AsmError("%s: branch to %s is out of range" % (where, tok))
        return d

    if op == "nop":
        need(0); return 0
    if op in R3:
        need(3); return _R(rs=_reg(args[1], where), rt=_reg(args[2], where),
                           rd=_reg(args[0], where), fn=R3[op])
    if op in RSHIFT:
        need(3); return _R(rt=_reg(args[1], where), rd=_reg(args[0], where),
                           sa=_imm(args[2], labels, where) & 31, fn=RSHIFT[op])
    if op in RSHIFTV:
        need(3); return _R(rs=_reg(args[2], where), rt=_reg(args[1], where),
                           rd=_reg(args[0], where), fn=RSHIFTV[op])
    if op in RMULDIV:
        need(2); return _R(rs=_reg(args[0], where), rt=_reg(args[1], where),
                           fn=RMULDIV[op])
    if op in RMOVE_FROM:
        need(1); return _R(rd=_reg(args[0], where), fn=RMOVE_FROM[op])
    if op in RMOVE_TO:
        need(1); return _R(rs=_reg(args[0], where), fn=RMOVE_TO[op])
    if op == "jr":
        need(1); return _R(rs=_reg(args[0], where), fn=0x08)
    if op == "jalr":
        if len(args) == 1:
            return _R(rs=_reg(args[0], where), rd=31, fn=0x09)
        need(2); return _R(rs=_reg(args[1], where), rd=_reg(args[0], where),
                           fn=0x09)
    if op == "syscall":
        return _R(sa=0, fn=0x0C) | ((_imm(args[0], labels, where) << 6)
                                    if args else 0)
    if op == "break":
        return _R(fn=0x0D) | ((_imm(args[0], labels, where) << 6) if args else 0)
    if op in IARITH:
        need(3); return _I(IARITH[op], _reg(args[1], where),
                           _reg(args[0], where), _imm(args[2], labels, where))
    if op == "lui":
        need(2); return _I(0x0F, 0, _reg(args[0], where),
                           _imm(args[1], labels, where))
    if op in IMEM:
        need(2)
        off, base = _mem(args[1], labels, where)
        return _I(IMEM[op], base, _reg(args[0], where), off)
    if op in IBR2:
        need(3); return _I(IBR2[op], _reg(args[0], where), _reg(args[1], where),
                           disp(args[2]))
    if op in IBR1:
        need(2); return _I(IBR1[op], _reg(args[0], where), 0, disp(args[1]))
    if op in REGIMM:
        need(2); return _I(0x01, _reg(args[0], where), REGIMM[op],
                           disp(args[1]))
    if op in ("j", "jal"):
        need(1)
        t = _imm(args[0], labels, where)
        if (t >> 28) != ((at + 4) >> 28):
            raise AsmError("%s: %s target %08X is not in the delay slot's "
                           "256 MB region" % (where, op, t))
        return ((0x02 if op == "j" else 0x03) << 26) | ((t >> 2) & 0x03FFFFFF)
    if op in ("mfc0", "mtc0"):
        need(2); return _I(0x10, 0x00 if op == "mfc0" else 0x04,
                           _reg(args[0], where), 0) \
                      | (_imm(args[1], labels, where) << 11)
    if op == "rfe":
        return (0x10 << 26) | (0x10 << 21) | 0x10
    if op == "cache":
        need(2)
        off, base = _mem(args[1], labels, where)
        return _I(0x2F, base, _imm(args[0], labels, where) & 31, off)
    raise AsmError("%s: unknown mnemonic %r" % (where, op))


if __name__ == "__main__":
    if len(sys.argv) != 4:
        sys.exit("usage: mipsasm.py <in.s> <out.bin> <base-address>")
    with open(sys.argv[1]) as f:
        src = f.read()
    try:
        img = assemble(src, int(sys.argv[3], 0))
    except AsmError as e:
        sys.exit("mipsasm: %s" % e)
    with open(sys.argv[2], "wb") as f:
        f.write(img)
    print("mipsasm: %s -> %s, %d bytes at %s"
          % (sys.argv[1], sys.argv[2], len(img), sys.argv[3]))
