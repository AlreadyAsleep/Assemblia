;//inventory using linked list
;//linked list of 10 items 

i10 item {0,0,0,i9,null}
i9 item {0,0,0,i8,i10}
i8 item {0,0,0,i7,i9}
i7 item {0,0,0,i6,i8}
i6 item {0,0,0,i5,i7}
i5 item {0,0,0,i4,i6}
i4 item {0,0,0,i3,i5}
i3 item {1,1,2,i2,i4,5,"W"}
i2 item {2,1,2,i1,i3,10,"W"}
i1 item {3,1,2,null,i2,3,"A"}

t1 item {4,1,2,NULL,NULL}

tempString  db    8 dup (?)

selectItemTitle byte "--Select an Item--", 13, 10, 0

exitTitle    byte "0 Exit: "      , 13, 10, 0
discardTitle byte "1 Discard: "   , 13, 10, 0
equipTitle   byte "2 Equip: "     , 13, 10, 0
infoTitle    byte "3 Item Info "  , 13, 10, 0

itemNameTitle        byte "Item Name: "      , 0, 10, 0
itemSellValueTitle   byte "Sell Value: "     , 0, 10, 0
itemBuyValueTitle    byte "Buy Value: "      , 0, 10, 0
itemCombatValueTitle byte "Combat Value:"    , 0, 10, 0
itemType             byte "Item Type:   "    , 0, 10, 0

;//displays inventory
mDisplayInventory MACRO
Local L
pushAD

xor ecx,ecx
mov eBx, offset i1
DO1&L:

mov eax,ecx
call WriteDec
mov eax, ':'
call WriteChar
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

mov edx, offset selectItemTitle
call WriteString

mDisplayInventory
_get_input

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
	jmp endInventory
item1:
	mov ebx,offset i2 ;//storing item for use
	mitemOptions
	jmp endInventory
item2:
	mov ebx,offset i3 ;//storing item for use
	mitemOptions
	jmp endInventory
item3:
	mov ebx,offset i4 ;//storing item for use
	mitemOptions
	jmp endInventory
item4:
	mov ebx,offset i5 ;//storing item for use
	mitemOptions
	jmp endInventory
item5:
	mov ebx,offset i6 ;//storing item for use
	mitemOptions
	jmp endInventory
item6:
	mov ebx,offset i7 ;//storing item for use
	mitemOptions
	jmp endInventory
item7:
	mov ebx,offset i8 ;//storing item for use
	mitemOptions
	jmp endInventory
item8:
	mov ebx,offset i9 ;//storing item for use
	mitemOptions
	jmp endInventory
item9:
	mov ebx,offset i10 ;//storing item for use
	mitemOptions
	jmp endInventory

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

cmp ecx,0
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
	mov eax,2000
	call Delay

endCase&L:

endm

;//remove an item from inventory
mRemoveItem MACRO

;//ebx is item being removed

mov [ebx].item.itemCode,null
mov [ebx].item.sellValue,0
mov [ebx].item.buyValue,0

endm;//mRemoveItem

;//equips item
mEquip MACRO

;//ebx is item being equipped

mov edx, [ebx].item.itemCode
mov c1.weaponCode, edx
mov edx, [ebx].item.combatValue
mov c1.weaponDamage, edx
mov edx, [ebx].item.buyValue
mov c1.weaponBuyValue,edx
mov edx,[ebx].item.sellValue
mov c1.weaponsellValue,edx
mRemoveItem
mInitializeCharacter

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

endm

mDequip MACRO
Local L

cmp c1.weaponCode,0
je nothingEquipped&L

mov ebx, offset i1

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
mInitializeCharacter

inventoryFull&L:
nothingEquipped&L:

endm

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

inventoryFull&L:

endm

