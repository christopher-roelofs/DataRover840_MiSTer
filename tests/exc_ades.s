# AdES: a halfword store to an odd address.
# expect-exceptions: 1
        lui     $t0, 0x8000
        addiu   $t0, $t0, 1
        addiu   $t1, $zero, 0x55
        sh      $t1, 0($t0)             # -> AdES
        j       fail
        nop
fail:   j       fail
        nop

        .org    0xBFC00180
handler:
        mfc0    $s0, 14
        mfc0    $s1, 13
        mfc0    $s2, 8
        mfc0    $s3, 12
done:   j       done
        nop
