# The other exception vector. Status.BEV selects 0xBFC00180 at reset and
# 0x80000080 once cleared. The second one is in RAM, so the handler is
# copied there first -- which also means it has to be position independent,
# hence the branch-to-self rather than a jump: J carries an absolute target
# and would still name the address it was assembled at.
# expect-exceptions: 1
        lui     $t0, %hi(bev0_handler)
        ori     $t0, $t0, %lo(bev0_handler)
        lui     $t1, 0x8000
        ori     $t1, $t1, 0x0080        # the BEV=0 general vector

        lw      $t2, 0($t0)
        sw      $t2, 0($t1)
        lw      $t2, 4($t0)
        sw      $t2, 4($t1)
        lw      $t2, 8($t0)
        sw      $t2, 8($t1)

        mtc0    $zero, 12               # BEV=0, interrupts off, kernel mode
        lui     $t3, 0x8000
        addiu   $t3, $t3, 2
        addiu   $s7, $zero, 0x1111
        lw      $t4, 0($t3)             # -> AdEL, vectors to 0x80000080
        j       fail
        nop
fail:   j       fail
        nop

# Copied to 0x80000080, so nothing here may name an absolute address.
bev0_handler:
        mfc0    $s0, 14
hspin:  beq     $zero, $zero, hspin
        nop
