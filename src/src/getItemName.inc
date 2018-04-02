;// gets items name based off code and prints it
itemName1 byte "rope" , 0 , 10, 0
itemName2 byte "gun"  , 0 , 10, 0
itemName3 byte "sword", 0 , 10, 0
itemName4 byte "axe"  , 0 , 10, 0

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

default&L:
	mov edx, offset defaultName

print&L:
	invoke WriteString


endm