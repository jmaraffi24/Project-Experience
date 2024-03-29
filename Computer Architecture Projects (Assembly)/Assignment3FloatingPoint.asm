#ProgrammingAssignment3
#Jacob Maraffi
#811571598
#10/28/18

.data
	arrayA: .float 0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9
	arrayB: .float 9.9, 8.8, 7.7, 6.6, 5.5, 4.4, 3.3, 2.2, 1.1, 0.0
	arrayC: .float 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
	result: .asciiz "Result arrayC:"
	space: .asciiz " ,"
	
.text
main:
	la $s1, arrayA				#$s1 == starting address of arrayA
	la $s2, arrayB				#$s2 == starting address of arrayB
	la $s3, arrayC				#$s3 == starting address of arrayC
	
	li $t1, 0				#counter == 0
	li $t2, 10				#length == 10
	
	la $a0, result
	li $v0, 4
	syscall

loop:
	beq $t1, $t2, exit			#if the end of the array has been reached (counter == length) exit
	lwc1 $f0, 0($s1)			#store arrayA element into $f0
	lwc1 $f1, 0($s2)			#store arrayB element into $f1
	add.s $f2, $f1, $f0			#adding arrayA[counter] + arrayB[counter] = $f2
	mov.s $f12, $f2				#loads the answer into printing register
	li $v0, 2
	syscall
	la $a0, space				#outputting a space and comma after each element of arrayC
	li $v0, 4
	syscall
	swc1 $f2, 0($s3)			#store into arrayC[counter]
	j iterate

iterate:
	addi $s1, $s1, 4			#moves the $s1 pointer to the next element of arrayA
	addi $s2, $s2, 4			#moves the $s2 pointer to the next element of arrayB
	addi $s3, $s3, 4			#moves the $s3 pointer to the next element of arrayC
	addi $t1, $t1, 1			#counter++
	
	j loop

exit:
	li $v0, 10
	syscall