# RI: an encoding neither core implements. It must trap, not quietly become
# a NOP -- the two have to refuse exactly the same things.
# expect-exceptions: 2
        addiu   $s7, $zero, 0x1111
        .word   0xFC000000              # opcode 0x3F, unused
        .word   0x00000005              # SPECIAL funct 0x05, unused
        addiu   $s6, $zero, 0x2222
spin:   j       spin
        nop

        .org    0xBFC00180
handler:
        mfc0    $k0, 14
        mfc0    $s1, 13
        addiu   $s5, $s5, 1
        addiu   $k0, $k0, 4
        jr      $k0
        rfe
