;//Checks to see if damage is super effective based on elemental type

superEffective byte "Your attack is incredibly effective",13,10,0
notEffective byte "Your attack is not effective",13,10,0

;//fire beats ice, ice beats lightning, lightning beats fire
;// 1 is fire, 2 is ice 3, is lightning
mSuperEffective MACRO
Local L

;//eax has damage

mov ecx,c1.weaponElementalType
mov ebx,e1.elementalType
cmp ecx, 1
je fire&L
cmp ecx,2
je ice&L
cmp ecx,3
je lightning&L
jmp neutral&L


fire&L:
	cmp ebx,2
	je superEffective&L

	cmp ebx,3
	je notEffective&L
	jmp neutral&L

ice&L:
	cmp ebx,3
	je superEffective&L

	cmp ebx,1
	je notEffective&L
	jmp neutral&L

lightning&L:
	cmp ebx,1
	je superEffective&L

	cmp ebx,2
	je notEffective&L
	jmp neutral&L

superEffective&L:
	mov edx, offset superEffective
	invoke WriteString
	sal eax,1
	jmp neutral&L

notEffective&L:
	mov edx, offset notEffective
	invoke WriteString
	sar eax,1
	jmp neutral&L
	
neutral&L:
	

endm