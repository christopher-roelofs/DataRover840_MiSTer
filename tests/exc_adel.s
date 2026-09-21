# AdEL: a word load from an address that is not word aligned.
# Checks the vector, EPC, Cause.ExcCode, BadVAddr and the Status stack push.
# expect-exceptions: 1
        lui     $t0, 0x8000
        addiu   $t0, $t0, 2             # deliberately misaligned
        addiu   $s7, $zero, 0x1111      # a witness: must survive the fault
        lw      $t1, 0($t0)             # -> AdEL
        addiu   $s6, $zero, 0x2222      # must NOT run
        j       fail
        nop

fail:   j       fail
        nop

        .org    0xBFC00180
handler:
        mfc0    $s0, 14                 # EPC
        mfc0    $s1, 13                 # Cause
        mfc0    $s2, 8                  # BadVAddr
        mfc0    $s3, 12                 # Status
done:   j       done
        nop
