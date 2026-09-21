# The integer instructions the ROM never executes in ten million
# instructions, so the RTL has them but has never run them: ADD, SUB, MULTU,
# signed DIV including both of its special cases, the variable shifts, the
# linking conditional branches, and MTHI/MTLO.
# expect-exceptions: 0
        addiu   $t0, $zero, 7
        addiu   $t1, $zero, 3
        add     $s0, $t0, $t1           # 10
        sub     $s1, $t0, $t1           # 4
        sub     $s2, $t1, $t0           # -4

        lui     $t2, 0xFFFF
        ori     $t2, $t2, 0xFFFF        # -1 / 0xFFFFFFFF
        multu   $t2, $t2                # 0xFFFFFFFE00000001
        mfhi    $s3
        mflo    $s4

        mult    $t2, $t0                # -7
        mfhi    $s5
        mflo    $s6

        addiu   $t3, $zero, -20
        addiu   $t4, $zero, 6
        div     $t3, $t4                # -20/6: -3 rem -2, truncating
        mfhi    $s7
        mflo    $t5

        div     $t3, $zero              # divide by zero
        mfhi    $t6
        mflo    $t7

        lui     $t8, 0x8000             # 0x80000000
        div     $t8, $t2                # 0x80000000 / -1: the overflow case
        mfhi    $t9
        mflo    $a0

        divu    $t3, $zero              # unsigned divide by zero
        mfhi    $a1
        mflo    $a2

        addiu   $a3, $zero, 5
        sllv    $v0, $t0, $a3
        srlv    $v1, $t2, $a3
        srav    $gp, $t2, $a3

        addiu   $t0, $zero, 0x77
        mthi    $t0
        mtlo    $t1
        mfhi    $s0
        mflo    $s1

        addiu   $t1, $zero, -1
        bltzal  $t1, l1                 # taken, links
        nop
l1:     addiu   $t2, $zero, 1
        bgezal  $t2, l2                 # taken, links
        nop
l2:     bltzal  $t2, l3                 # not taken, still links
        nop
l3:     addiu   $s2, $zero, 0x4444
spin:   j       spin
        nop
