.include "macro.inc"

.set noat
.set noreorder
.align 3

glabel _start
    nop
    nop

/* Clear .bss segment */
    lui         $v0, %hi(D_0048DB00)
    lui         $v1, %hi(D_66F018)
    addiu       $v0, $v0, %lo(D_0048DB00)
    addiu       $v1, $v1, %lo(D_66F018)
bssloop:
    sq          $zero, 0x0($v0)
    nop
    sltu        $at, $v0, $v1
    nop
    nop
    bnez        $at, bssloop
    addiu       $v0, $v0, 0x10

/* Initialize main thread */
    lui         $a0, %hi(D_0048DB00)
    lui         $a1, %hi(D_1FE0000)
    lui         $a2, %hi(D_20000)
    lui         $a3, %hi(D_0048DB00)
    lui         $t0, %hi(_root)
    addiu       $a0, $a0, %lo(D_0048DB00)
    addiu       $a1, $a1, %lo(D_1FE0000)
    addiu       $a2, $a2, %lo(D_20000)
    addiu       $a3, $a3, %lo(D_0048DB00)
    addiu       $t0, $t0, %lo(_root)
    daddu       $gp, $a0, $zero
    addiu       $v1, $zero, 60
    syscall
    daddu       $sp, $v0, $zero

/* Initialize heap region */
    lui         $a0, %hi(D_66F018)
    lui         $a1, %hi(D_A000)
    addiu       $a0, $a0, %lo(D_66F018)
    addiu       $a1, $a1, %lo(D_A000)
    addiu       $v1, $zero, 61
    syscall

/* Initialize system */
    jal         _InitSys
    nop
    
/* Flush data cache */
    jal         FlushCache
    daddu       $a0, $zero, $zero

/* Call main program */
    ei
    lui         $v0, %hi(D_0048DB00)
    addiu       $v0, $v0, %lo(D_0048DB00)
    lw          $a0, 0x0($v0)
    jal         main
    addiu       $a1, $v0, 0x4

    j           Exit
    daddu       $a0, $v0, $zero
    nop
.size _start, . - _start

glabel _exit
    j           Exit
    daddu       $a0, $zero, $zero
.size _exit, . - _exit

glabel _root
    addiu       $v1, $zero, 35
    syscall     # ExitThread()
.size _root, . - _root
