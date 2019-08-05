#ProgrammingAssignment2
#Jacob Maraffi
#811571598

	.data
search: .asciiz "Enter a number to search for: "
foundat: .asciiz "\nNumber found at index: "
numbernotfound: .asciiz "\nNumber not found in array"
array: .word 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40

	.text
main:
	la $s1, array					#$s1 == address of array
	
	li $t1, 0 					#counter == 0
	li $t2, 1 					#bool found/notfound  == 1
	li $t3, 20 					#length == 20

	la $a0, search
	li $v0, 4 					#print out search statement
	syscall

	li $v0, 5 					#user input
	syscall
	move $t0, $v0					#store user input into $t0

	j loop

loop:
	beq $t1, $t3, notfound 				#if the end of the array is reached go to notfound
	lw $t4, 0($s1) 					#store array element into $t4
	beq $t0, $t4, found 				#if the number is found go to found

iterate:
	addi $s1, $s1, 4				#go to the next element of array
	addi $t1, $t1, 1 				#counter++

	j loop

found:
	la $a0, foundat
	li $v0, 4 					#print found statement
	syscall

	move $a0, $t1
	li $v0, 1 					#print out target's index
	syscall

	li $t5, 1 					#numberfound == 1

	j iterate

notfound:
	beq $t5, $t2, exit 				#if numberfound == 1 (number in array = number in user input) jump to exit

	la $a0, numbernotfound
	li $v0, 4 					#print notfound statement
	syscall
	
	j exit

exit:
	li $v0, 10
	syscall