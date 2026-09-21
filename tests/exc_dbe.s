# DBE: a load and a store to an address nothing decodes. This is the only
# exception raised in MEM rather than in EX or IF, so it is the one that
# tests flushing an instruction that has already issued a bus access.
# expect-exceptions: 2
        lui     $t0, 0x9000             # phys 0x10000000: unmapped here
        addiu   $s7, $zero, 0x1111
        lw      $t1, 0($t0)             # -> DBE
        sw      $t1, 4($t0)             # -> DBE
        addiu   $s6, $zero, 0x2222
spin:   j       spin
        nop

        .org    0xBFC00180
handler:
        mfc0    $k0, 14
        mfc0    $s1, 13
        mfc0    $s2, 8
        addiu   $s5, $s5, 1
        addiu   $k0, $k0, 4
        jr      $k0
        rfe
