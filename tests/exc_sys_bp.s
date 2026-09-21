# SYSCALL and BREAK. Both are detected in EX, like overflow, but carry
# different codes and no BadVAddr.
# expect-exceptions: 2
        addiu   $s7, $zero, 0x1111
        syscall
        break
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
