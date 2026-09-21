# IBE: a jump to an address nothing decodes, so the fetch itself fails.
# Raised in IF, the earliest stage that can raise anything.
# expect-exceptions: 1
        lui     $t0, 0x9000             # phys 0x10000000: unmapped
        addiu   $s7, $zero, 0x1111
        jr      $t0                     # the fetch at the target fails
        nop
        j       fail
        nop
fail:   j       fail
        nop

        .org    0xBFC00180
handler:
        mfc0    $s0, 14
        mfc0    $s1, 13
        mfc0    $s2, 8
done:   j       done
        nop
