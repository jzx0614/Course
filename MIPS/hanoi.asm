    .globl main
main:	addu	$s7,$0,$ra
        .text
	li	$v0,4		#
        la	$a0,InMsg	# print_string(¡§Enter number of disks>¡¨);
        syscall			#

        li	$v0,5		# read_int()
	syscall			#

        add	$a0,$0,$v0	#
        addi    $a1,$0,1	#
        addi    $a2,$0,2	# hanoi(n, 1, 2, 3);
        addi    $a3,$0,3	#
	jal	hanoi		#

        addu    $ra,$0,$s7	#
	jr	$ra		# return 0
        add	$0,$0,$0	#
#----------------------------------------------------------------------------
hanoi:	beq	$a0,$0,h_exit	# if (n==0) return
        addi    $sp,$sp,-20
	sw	$ra,16($sp)
        sw	$a0,12($sp) 
	sw	$a1, 8($sp)
        sw	$a2, 4($sp)
	sw	$a3, 0($sp)
    
        addi    $a0,$a0,-1	#
	lw	$a2,0($sp)	# hanoi(n-1, start, extra, finish);
        lw	$a3,4($sp)	# 
        jal	hanoi		#
#----------------------------------------------------------------------------
        lw	$t0,12($sp)

        li	$v0,4		#
        la	$a0,MoveMsg	# print_string(¡§Move disk¡¨);
        syscall			#

        li	$v0,1		# 
        add	$a0,$0,$t0	# print_int(n);
        syscall			#

        li	$v0,4		#
        la	$a0,FromMsg	# print_string(¡§from peg¡¨);
        syscall			#	

        li	$v0,1		#
        add	$a0,$0,$a1	# print_int(start);
        syscall			#

        li	$v0,4		#
        la	$a0,ToMsg	# print_string(¡§to peg¡¨);
        syscall			#

        li	$v0,1		#
	add	$a0,$0,$a2	# print_int(finish);
        syscall			#

        li	$v0,4		#
	la	$a0,Enter	# print_string ("\n");
        syscall			#

#----------------------------------------------------------------------------
        lw	$a3, 8($sp) 
	lw	$a1, 4($sp) 
        lw	$a2, 0($sp) 
	addi    $a0,$t0,-1	# hanoi(n-1,extra, finish, start);
        jal	hanoi		#	
#----------------------------------------------------------------------------
        lw	$a3, 0($sp)
        lw	$a2, 4($sp)
	lw      $a1, 8($sp)
        lw	$a0,12($sp)
	lw	$ra,16($sp)
        addi    $sp,$sp,20
h_exit:	jr  $ra
#----------------------------------------------------------------------------
    .data
    .globl InMsg
InMsg:	.asciiz "Enter number of disks> "
    .globl MoveMsg
MoveMsg:.asciiz "Move disk "
    .globl FromMsg
FromMsg:.asciiz " from peg "
    .globl ToMsg
ToMsg:	.asciiz " to peg "
    .globl Enter
Enter:	.asciiz ".\n"
