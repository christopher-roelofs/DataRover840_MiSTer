# Ov, three ways: ADD, ADDI and SUB. Each handler return goes to the next,
# so one run covers all three arithmetic overflow sites.
# expect-exceptions: 3
        lui     $t0, 0x7FFF
        ori     $t0, $t0, 0xFFFF        # 0x7FFFFFFF
        addiu   $t1, $zero, 1
        addiu   $s5, $zero, 0           # which fault we are on

        add     $t2, $t0, $t1           # -> Ov
        addi    $t3, $t0, 1             # -> Ov
        lui     $t4, 0x8000             # 0x80000000
        sub     $t5, $t4, $t1           # -> Ov
        addiu   $s7, $zero, 0x1234      # reached only if all three returned
spin:   j       spin
        nop

        .org    0xBFC00180
handler:
        mfc0    $k0, 14                 # EPC of the faulting instruction
        mfc0    $s1, 13
        mfc0    $s3, 12
        addiu   $s5, $s5, 1
        addiu   $k0, $k0, 4             # step over it
        jr      $k0
        rfe
