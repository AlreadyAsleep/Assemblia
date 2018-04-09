;// gets items name based off code and prints it
itemName1 byte "Dagger" , 0 , 10, 0
itemName2 byte "Halberd"  , 0 , 10, 0
itemName3 byte "Sword", 0 , 10, 0
itemName4 byte "Axe"  , 0 , 10, 0
itemName5 byte "Spear"  , 0 , 10, 0
itemName6 byte "Katana"  , 0 , 10, 0
itemName7 byte "Bow"  , 0 , 10, 0

elementalType1 byte "Fire " , 0 , 10, 0
elementalType2 byte "Ice " , 0 , 10, 0
elementalType3 byte "Lightning " , 0 , 10, 0

noElementalType byte NULL , 0 , 10, 0

defaultName   byte "Empty Slot", 0 , 10, 0

mGetItemName MACRO
Local L


;//item code stored in eax

cmp eax,1
je item0&L
cmp eax,2
je item1&L
cmp eax,3
je item2&L
cmp eax,4
je item3&L
cmp eax,5
je item4&L
cmp eax,6
je item5&L
cmp eax,7
je item6&L

jmp default&L



item0&L:
	mov edx, offset itemName1

	jmp print&L
item1&L:
	mov edx, offset itemName2

	jmp print&L
item2&L:
	mov edx, offset itemName3
	
	jmp print&L
item3&L:
	mov edx, offset itemName4
	
	jmp print&L
item4&L:
	mov edx, offset itemName5
	
	jmp print&L
item5&L:
	mov edx, offset itemName6
	
	jmp print&L
item6&L:
	mov edx, offset itemName7
	
	jmp print&L

default&L:
	mov edx, offset defaultName

print&L:
	invoke WriteString


endm

mInitializeItem MACRO
Local L

mov eax,7 ;//generating item name
call RandomRange
inc eax

mov t1.itemCode,eax 

mov eax,2 ;//generating combatValue
call RandomRange
inc eax

mul c1.level

mov t1.combatValue,eax

inc eax ;//generating buyValue
mov t1.buyValue,eax

dec eax ;//generating sellValue
dec eax
mov t1.sellValue,eax

mov eax,4 ;//generating elementalType
call RandomRange
mov t1.elementalType,eax

endm

mGetElementalType MACRO
Local L

;//code is in eax

cmp eax,1
je elementalType1&L
cmp eax,2
je elementalType2&L
cmp eax,3
je elementalType3&L
jmp nothing&L

elementalType1&L:
	mov edx,offset elementalType1
	jmp print&L
elementalType2&L:
	mov edx,offset elementalType2
	jmp print&L
elementalType3&L:
	mov edx,offset elementalType3
	jmp print&L
nothing&L:
	mov edx, offset noElementalType
	

print&L:
	invoke WriteString

endm