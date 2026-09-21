# An exception taken by an instruction sitting in a branch delay slot.
# EPC must name the branch, not the faulting instruction, and Cause.BD must
# say so. Getting this wrong is invisible until something tries to resume.
# expect-exceptions: 1
        lui     $t0, 0x8000
        addiu   $t0, $t0, 2
        addiu   $s7, $zero, 0x1111
        beq     $zero, $zero, target    # taken
        lw      $t1, 0($t0)             # in the delay slot -> AdEL
target: addiu   $s6, $zero, 0x2222
spin:   j       spin
        nop

        .org    0xBFC00180
handler:
        mfc0    $s0, 14                 # must be the beq's address
        mfc0    $s1, 13                 # Cause.BD (bit 31) must be set
        mfc0    $s2, 8
done:   j       done
        nop
