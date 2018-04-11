;//inventory using linked list
;//linked list of 10 items 

i10 item {0,0,0,i9,null}
i9 item {0,0,0,i8,i10}
i8 item {0,0,0,i7,i9}
i7 item {0,0,0,i6,i8}
i6 item {0,0,0,i5,i7}
i5 item {0,0,0,i4,i6}
i4 item {0,0,0,i3,i5}
i3 item {0,0,0,i2,i4,0,"W"}
i2 item {0,0,0,i1,i3,0,"W"}
i1 item {0,0,0,null,i2,0,"A"}
t1 item {4,1,2,NULL,NULL,3}

tempString  db    8 dup (?)

selectItemTitle byte "--Select an Item--", 13, 10, 0
noEquip byte "No item equipped", 13, 10, 0


discardTitle byte "1 Discard: "   , 13, 10, 0
equipTitle   byte "2 Equip: "     , 13, 10, 0
infoTitle    byte "3 Item Info "  , 13, 10, 0

itemNameTitle        byte "Item Name: "      , 0, 10, 0
itemSellValueTitle   byte "Sell Value: "     , 0, 10, 0
itemBuyValueTitle    byte "Buy Value: "      , 0, 10, 0
itemCombatValueTitle byte "Combat Value:"    , 0, 10, 0
itemType             byte "Item Type:   "    , 0, 10, 0

inventoryFullTitle   byte "INVENTORY FULL"   , 0, 10, 0

unequipScuccesfulTitle byte "You unequip your items" ,13,10,0

unequipFirst byte "Unequip your items first" ,13,10,0

;//displays inventory
mDisplayInventory MACRO
Local L
pushAD

mov edx, offset exitTitle
invoke WriteString

xor ecx,ecx
DO1&L:

mov eax,ecx
call WriteDec
mov eax, ':'
call WriteChar
mov eax, [ebx].item.elementalType
mGetElementalType
mov eax, [ebx].item.itemCode
mGetItemName
mov edx,offset blank
call WriteString

mov eBx,[ebx].item.next

inc ecx
cmp ebx,null
jne DO1&L

popAD
endm

mInventory MACRO


continueInventory:
call clrscr

mov edx, offset selectItemTitle
call WriteString

mov eBx, offset i1
mDisplayInventory
_get_input

cmp ecx,909
	je endInventory
cmp ecx,0
	je item0
cmp ecx,1
	je item1
cmp ecx,2
	je item2
cmp ecx,3
	je item3
cmp ecx,4
	je item4
cmp ecx,5
	je item5
cmp ecx,6
	je item6
cmp ecx,7
	je item7
cmp ecx,8
	je item8
cmp ecx,9
	je item9

item0:
	mov ebx,offset i1 ;//storing item for use
	mitemOptions
	jmp continueInventory
item1:
	mov ebx,offset i2 ;//storing item for use
	mitemOptions
	jmp continueInventory
item2:
	mov ebx,offset i3 ;//storing item for use
	mitemOptions
	jmp continueInventory
item3:
	mov ebx,offset i4 ;//storing item for use
	mitemOptions
	jmp continueInventory
item4:
	mov ebx,offset i5 ;//storing item for use
	mitemOptions
	jmp continueInventory
item5:
	mov ebx,offset i6 ;//storing item for use
	mitemOptions
	jmp continueInventory
item6:
	mov ebx,offset i7 ;//storing item for use
	mitemOptions
	jmp continueInventory
item7:
	mov ebx,offset i8 ;//storing item for use
	mitemOptions
	jmp continueInventory
item8:
	mov ebx,offset i9 ;//storing item for use
	mitemOptions
	jmp continueInventory
item9:
	mov ebx,offset i10 ;//storing item for use
	mitemOptions
	jmp continueInventory

endInventory:

call clrscr
endm

mitemOptions MACRO
local L

mov edx, offset exitTitle
call WriteString
mov edx, offset discardTitle
call WriteString
mov edx, offset equipTitle
call WriteString
mov edx, offset infoTitle
call WriteString

_get_input

cmp ecx,909
je exit&L
cmp ecx,1
je removeItem&L
cmp ecx,2
je equipItem&L
cmp ecx,3
je infoItem&L
jmp endCase&L

exit&L:
	jmp endCase&L
removeItem&L:
	mRemoveItem
	jmp endCase&L
equipItem&L:
	mEquip
	jmp endCase&L
infoItem&L:
	call clrscr
	mDisplayItemInfo
	mov edx, offset continueCommand
	invoke WriteString
	_get_input

endCase&L:

endm

;//remove an item from inventory
mRemoveItem MACRO

;//ebx is item being removed

mov [ebx].item.itemCode,null
mov [ebx].item.sellValue,0
mov [ebx].item.buyValue,0
mov [ebx].item.elementalType,0

endm;//mRemoveItem

;//equips item
mEquip MACRO
Local L

;//ebx is item being equipped

cmp c1.weaponCode,0
je notEquipped&L
jmp somethingEquiped&L
mov edx,ebx
mDequip
mov ebx,edx

notEquipped&L:
mov edx, [ebx].item.itemCode
mov c1.weaponCode, edx
mov edx, [ebx].item.combatValue
mov c1.weaponDamage, edx
mov edx, [ebx].item.buyValue
mov c1.weaponBuyValue,edx
mov edx,[ebx].item.sellValue
mov c1.weaponsellValue,edx
mov edx,[ebx].item.elementalType
mov c1.weaponElementalType,edx
mRemoveItem
mUpdateWeapon
jmp end&L
somethingEquiped&L:

mov edx, offset unequipFirst
invoke WriteString
mov edx, offset continueCommand
invoke WriteString
_get_input

end&L:

endm;//mEquip



;//displays item Info
mDisplayItemInfo MACRO
;ebx is item Info

mov edx, offset blank
call WriteString

mov edx, offset itemBuyValueTitle ;displays buy value
call WriteString
mov eax, [ebx].item.buyValue
call WriteDec
mov edx, offset blank
call WriteString

mov edx, offset itemSellValueTitle ;displays sell value 
call WriteString
mov eax, [ebx].item.SellValue
call WriteDec
mov edx, offset blank
call WriteString

mov edx, offset itemCombatValueTitle ;displays combat value
call WriteString
mov eax, [ebx].item.combatValue
call WriteDec
mov edx, offset blank
call WriteString

endm ;//mDisplayItemInfo

mDequip MACRO
Local L

cmp c1.weaponCode,0
je nothingEquipped&L

mov ebx, offset i1 ;//getting first item for linked list

notEmpty&L:
cmp [ebx].item.itemCode,0
je isEmpty&L 
cmp [ebx].item.next,null
je inventoryFull&L
mov ebx,[ebx].item.next
jmp notEmpty&L

isEmpty&L:

mov eax, c1.weaponCode
mov [ebx].item.itemCode,eax
mov c1.weaponCode,0

mov eax, c1.weaponBuyValue
mov [ebx].item.buyValue,eax
mov c1.weaponBuyValue,0

mov eax, c1.weaponSellValue
mov [ebx].item.sellValue,eax
mov c1.weaponSellValue,0

mov eax, c1.weaponDamage
mov [ebx].item.combatValue,eax
mov c1.weaponDamage,0

mov eax, c1.weaponElementalType
mov [ebx].item.elementalType,eax
mov c1.weaponElementalType,0

mUpdateWeapon

mov edx, offset unequipScuccesfulTitle
invoke WriteString
mov edx, offset continueCommand
invoke WriteString
_get_input
call clrscr


jmp endUnequip&L



inventoryFull&L:

mov edx, offset inventoryFullTitle
invoke WriteString

mov edx, offset continueCommand
invoke WriteString
_get_input
call clrscr

nothingEquipped&L:

mov edx,offset noEquip
invoke WriteString
mov edx, offset continueCommand
invoke WriteString
_get_input
call clrscr

endUnequip&L:

endm ;//mDequip

mAddItem MACRO
Local L
;//item is in eax

mov ebx, offset i1

notEmpty&L:
cmp [ebx].item.itemCode,0
je isEmpty&L 
cmp [ebx].item.next,null
je inventoryFull&L
mov ebx,[ebx].item.next
jmp notEmpty&L

isEmpty&L:

mov ecx, [eax].item.itemCode
mov [ebx].item.itemCode,ecx

mov ecx, [eax].item.buyValue
mov [ebx].item.buyValue,ecx

mov ecx, [eax].item.sellValue
mov [ebx].item.sellValue,ecx

mov ecx, [eax].item.combatValue
mov [ebx].item.combatValue,ecx

mov ecx, [eax].item.elementalType
mov [ebx].item.elementalType,ecx

jmp end&L

inventoryFull&L:
mov edx, offset inventoryFullTitle
invoke WriteString

mov eax, 1500
call Delay
call clrscr

end&L:

endm;//mAddItem

write_inv_to_buffer macro 
	Local L
	pushAD
	
	mov esi, offset i10
	mov edi, offset save_write_buffer
	add edi, 128	;//see save_vars.inc
	mov al, [esi]	
	mov ecx, 2816 ;// sizeof(inventory)
while1$L:
	stosb ;// inc edi and mov [edi], al
	inc esi
	mov al, [esi]
	loop while1$L

	popAD
	
	
endm


	
