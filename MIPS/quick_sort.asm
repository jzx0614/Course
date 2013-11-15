	.text
	.globl	main
main:	addu	$s7,$0,$ra

	la	$s0,array	# s0 =array[]
	addi	$s1,$0,16	
	sll	$s1,$s1,2

	jal	P_a		# print_array

	addi	$a0,$0,0
	addi	$a1,$0,60	# qsort(0,15)
	jal	Qsort

	jal	P_a		# print_array

	addu 	$ra,$0,$s7
	jr	$ra
	add	$0,$0,$0
#--------------------Print Array--------------------------
P_a:
	add	$t0,$0,$0
LOOP:	add	$t2,$s0,$t0
	lw	$t2,0($t2)

	li	$v0,1
	add	$a0,$0,$t2
	syscall

	li	$v0,4
	la	$a0,Space
	syscall

	addi	$t0,$t0,4
	bne	$t0,$s1,LOOP
	
	li	$v0,4
	la	$a0,Enter
	syscall
	jr	$ra
#---------------------------------------------------------
swap:	add	$t0,$s0,$a0
	add	$t1,$s0,$a1
	lw	$t2,0($t0)
	lw	$t3,0($t1)
	sw	$t2,0($t1)
	sw	$t3,0($t0)
	jr	$ra
#---------------------------------------------------------
Qsort:	addi	$sp,$sp,-16
	sw	$ra,12($sp)
	sw	$a0,8($sp)
	sw	$a1,4($sp)

	slt	$t0,$a0,$a1	#if(left<right)
	beq	$t0,$0,Qexit	

	add	$s2,$a0,$0	# i=left
	addi	$s3,$a1,4	# j=right+1	
	add	$s4,$s0,$a0	# pivot = array[left]
	lw	$s4,0($s4)	#

LOOP2:				# do{
	addi	$s2,$s2,4	#     do{  i++	
	add	$t4,$s0,$s2	#          t4=array[i]
	lw	$t4,0($t4)	#
	slt	$t0,$s4,$t4	#     }while(pivot>array[i])	
	beq	$t0,$0,LOOP2	#

LOOP3:	addi	$s3,$s3,-4	#     do{  j--
	add	$t4,$s0,$s3	#	   t4=array[j]
	lw	$t4,0($t4)	#
	slt	$t0,$s4,$t4	#     }while(poivot<array[j])
	bne	$t0,$0,LOOP3	#


	slt	$t4,$s2,$s3	# if(i<j)
	beq	$t4,$0,IF	#
	add	$a0,$0,$s2
	add	$a1,$0,$s3	# swap(i,j)
	jal	swap	
	j	LOOP2		# }while(i<j)

IF:	sw	$s2,0($sp)
	lw	$a0,8($sp)	#
	add	$a1,$0,$s3	# swap(left,j)
	jal	swap

	jal	P_a
	
	lw	$a0,8($sp)
	addi	$a1,$s3,-4	# Qsort(left,j-1)
	jal	Qsort		#

	lw	$a0,0($sp)	#
	lw	$a1,4($sp)	# Qsort(i,right)
	jal	Qsort

Qexit:	lw	$a1,4($sp)
	lw	$a0,8($sp)
	lw	$ra,12($sp)
	addi	$sp,$sp,16
	jr	$ra
#---------------------------------------------------------
		.data
	.globl	array
array:	.word	10,3,5,8,7,1,2,9,11,12,27,7,2,9,4,85

	.globl	Enter
Enter:	.asciiz	"\n"
	.globl	Space
Space:	.asciiz	" "
#---------------------------------------------------------