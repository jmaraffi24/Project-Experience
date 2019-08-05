#Project 1
#Jacob Maraffi
#811-571-598
#9/20/18
.data	

arrayA: .word	1, 3, 5, 7, 9, 11, 13, 15, 17, 19	#creates the first array with 10 elements
arrayB:	.word	2, 4, 6, 8, 10, 12, 14, 16, 18, 20	#creates the second array with 10 elements
arrayC:	.word	0, 0, 0, 0, 0, 0, 0, 0, 0, 0		#creates the third array with 10 elements (result of addition stored here)
length:	.word	10					#sets the length of the arrays to be 10
result: .asciiz "Result Array: "			#creates the string variable
space: .asciiz " "					#creates the string variable

.text

          .globl  main

main:
	la	$t0,arrayA		#memory location of arrayA stored in $t0
	la	$t1,arrayB		#memory location of arrayB stored in $t1
	la	$t2,arrayC		#memory location of arrayC stored in $t2
	li	$t8,0			#i=0
	la	$t3,length
	lw	$t7,0($t3)
	
	li $v0, 4			#load appropriate system call code into register $v0 (printing a string)
	la $a0, result			#load address of string to be printed into $a0
	syscall				#call operating system to perform print operation

loop:
	lw	$t4,0($t0)		#stores the content of arrayA[i] in a temp register 
	lw	$t5,0($t1)		#stores the content of arrayB[i] in a temp register
	add	$t6,$t4,$t5		#adds the contents of the two temp registers and stores it in a temp register
	sw	$t6,0($t2)		#stores the summation in the temp register into arrayC[i]
	addi	$t0,$t0,4		#moving the pointer that points to arrayA to the next element
	addi	$t1,$t1,4		#moving the pointer that points to arrayB to the next element
	addi	$t2,$t2,4		#moving the pointer that points to arrayC to the next element
	addi	$t8,$t8,1		#i++
	li	$v0, 1			#load appropriate system call code into register $v0 (printing a integer)
	move	$a0, $t6		#move integer to be printed into $a0: $a0 = $t2
	syscall				#call operating system to perform print operation
	li $v0, 4			#load appropriate system call code into register $v0 (printing a string)
	la $a0, space			#load address of string to be printed into $a0
	syscall				#call operating system to perform print operation
	blt	$t8,$t7,loop		#jumps back to the beginning of the loop if i < length


# End
	li	$v0, 10
	syscall

