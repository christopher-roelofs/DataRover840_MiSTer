# A software interrupt, and RFE returning from it.
#
# Cause.IP[1:0] are the two bits software can set itself, so this needs no
# external line and both cores see exactly the same thing. It exercises the
# one exception that replaces an instruction rather than being raised by one.
# expect-exceptions: 1
        lui     $t0, 0x0040             # keep BEV set: vector at 0xBFC00180
        ori     $t0, $t0, 0x0101        # IM0 (bit 8) | IEc (bit 0)
        mtc0    $t0, 12
        ori     $t1, $zero, 0x0100      # Cause.IP0: request it
        addiu   $s7, $zero, 0x1111
        mtc0    $t1, 13                 # -> Int, taken in place of the next
        addiu   $s6, $zero, 0x2222      # runs after RFE returns
        addiu   $s4, $zero, 0x3333
spin:   j       spin
        nop

        .org    0xBFC00180
handler:
        mfc0    $k0, 14                 # EPC: the instruction displaced
        mfc0    $s1, 13
        mfc0    $s3, 12                 # IEc cleared, old state pushed
        mtc0    $zero, 13               # drop the request
        addiu   $s5, $s5, 1
        jr      $k0                     # resume the displaced instruction
        rfe                             # in the delay slot, the MIPS-I idiom
