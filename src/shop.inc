s10 item {0,0,0,s9,null}
s9 item {0,0,0,s8,s10}
s8 item {0,0,0,s7,s9}
s7 item {0,0,0,s6,s8}
s6 item {0,0,0,s5,s7}
s5 item {0,0,0,s4,s6}
s4 item {0,0,0,s3,s5}
s3 item {1,1,2,s2,s4,5,"W"}
s2 item {1,1,2,s1,s3,10,"W"}
s1 item {3,1,2,null,s2,3,"A"}

shopMenuTitle    byte "--SHOP--"        , 13, 10, 0

sellModeTitle byte "10 Switch to Sell Mode" , 13, 10, 0
buyModeTitle byte "10 Switch to Buy Mode" , 13, 10, 0
buyTitle      byte "2 Buy:"                 , 13, 10, 0

sellTitle  byte "1 Sell:"  , 13, 10, 0

shopPrompt1 byte "A hooded figure approaches" , 13, 10, 0
shopPrompt2 byte "'Would you like to buy some of my wares?' " , 13, 10, 0

notEnoughGoldTitle byte "Not Enough Gold" , 13, 10, 0

mShop MACRO
Local L

mInitializeShop

mov edx, offset shopPrompt1
invoke WriteString
mov edx, offset shopPrompt2
invoke WriteString

call crlf

mov edx, offset continueCommand
invoke WriteString

_get_input

call clrscr

stillShopping&L:

mov edx, offset shopMenuTitle
invoke WriteString
;mov edx, offset exitTitle
;invoke WriteString

mov ebx, offset s1;//moving first item to read linked list
mDisplayInventory

mov edx,offset sellModeTitle
invoke WriteString

_get_input

cmp ecx,909
	je exitShop&L
cmp ecx,0
	je item0&L
cmp ecx,1
	je item1&L
cmp ecx,2
	je item2&L
cmp ecx,3
	je item3&L
cmp ecx,4
	je item4&L
cmp ecx,5
	je item5&L
cmp ecx,6
	je item6&L
cmp ecx,7
	je item7&L
cmp ecx,8
	je item8&L
cmp ecx,9
	je item9&L
cmp ecx,10
	je sellMode&L
jmp stillShopping&L

item0&L:
	mov ebx,offset s1 ;//storing item for use
	mBuyOptions
	jmp stillShopping&L
item1&L:
	mov ebx,offset s2 ;//storing item for use
	mBuyOptions
	jmp stillShopping&L
item2&L:
	mov ebx,offset s3 ;//storing item for use
	mBuyOptions
	jmp stillShopping&L
item3&L:
	mov ebx,offset s4 ;//storing item for use
	mBuyOptions
	jmp stillShopping&L
item4&L:
	mov ebx,offset s5 ;//storing item for use
	mBuyOptions
	jmp stillShopping&L
item5&L:
	mov ebx,offset s6 ;//storing item for use
	mBuyOptions
	jmp stillShopping&L
item6&L:
	mov ebx,offset s7 ;//storing item for use
	mBuyOptions
	jmp stillShopping&L
item7&L:
	mov ebx,offset s8 ;//storing item for use
	mBuyOptions
	jmp stillShopping&L
item8&L:
	mov ebx,offset s9 ;//storing item for use
	mBuyOptions
	jmp stillShopping&L
item9&L:
	mov ebx,offset s10 ;//storing item for use
sellMode&L:
	call clrscr
	mSellMode
	



jmp stillShopping&L
exitShop&L:

Call clrscr

endm

mBuyOptions MACRO
local L
mov edx, offset exitTitle
invoke WriteString
mov edx, offset buyTitle
call WriteString
mov edx, offset infoTitle
call WriteString

_get_input

cmp ecx,909
je exit&L
cmp ecx,2
je buyItem&L
cmp ecx,3
je infoItem&L
jmp endCase&L

exit&L:
	jmp endCase&L
buyItem&L:

	mov edx, c1.gold ;// making sure player has enough gold for item
	mov eax, [ebx].item.buyValue
	cmp edx,eax
	jb notEnoughGold&L

	sub c1.gold,eax ;//decrease yout gold

	mov eax,ebx ;//moving for add
	mov edx,ebx ;//storing for remove
	mAddItem    ;//adding item to inventory
	mov ebx,edx ;//moving for remove
	mRemoveItem ;//removing item from shop

	jmp endCase&L

	notEnoughGold&L:

	call clrscr
	mov edx, offset notEnoughGoldTitle
	invoke WriteString
	mov edx, offset continueCommand
	invoke WriteString
	_get_input

	jmp endCase&L

infoItem&L:
	call clrscr
	mDisplayItemInfo
	mov edx, offset continueCommand
	invoke WriteString
	_get_input
	
endCase&L:
call clrscr
endm

mSellMode MACRO
Local L

 stillShopping&L:

mov ebx, offset i1



mDisplayInventory

mov edx, offset buyModeTitle
invoke WriteString
_get_input

cmp ecx,909
	jmp while_main
cmp ecx,0
	je item0&L
cmp ecx,1
	je item1&L
cmp ecx,2
	je item2&L
cmp ecx,3
	je item3&L
cmp ecx,4
	je item4&L
cmp ecx,5
	je item5&L
cmp ecx,6
	je item6&L
cmp ecx,7
	je item7&L
cmp ecx,8
	je item8&L
cmp ecx,9
	je item9&L
cmp ecx,10
	je switchToBuyMode&L

item0&L:
	mov ebx,offset i1 ;//storing item for use
	mSellOptions
	jmp stillShopping&L
item1&L:
	mov ebx,offset i2 ;//storing item for use
	mSellOptions
	jmp stillShopping&L
item2&L:
	mov ebx,offset i3 ;//storing item for use
	mSellOptions
	jmp stillShopping&L
item3&L:
	mov ebx,offset i4 ;//storing item for use
	mSellOptions
	jmp stillShopping&L
item4&L:
	mov ebx,offset i5 ;//storing item for use
	mSellOptions
	jmp stillShopping&L
item5&L:
	mov ebx,offset i6 ;//storing item for use
	mSellOptions
	jmp stillShopping&L
item6&L:
	mov ebx,offset i7 ;//storing item for use
	mSellOptions
	jmp stillShopping&L
item7&L:
	mov ebx,offset i8 ;//storing item for use
	mSellOptions
	jmp stillShopping&L
item8&L:
	mov ebx,offset i9 ;//storing item for use
	mSellOptions
	jmp stillShopping&L
item9&L:
	mov ebx,offset i10 ;//storing item for use
	mSellOptions
	jmp stillShopping&L

	
	


switchToBuyMode&L:
call clrscr

endm

mSellOptions MACRO
Local L
call clrscr

mov edx, offset sellTitle
invoke WriteString

_get_input

cmp ecx, 1
je doSell&L

doSell&L:
mov eax,[ebx].item.sellValue ;// giving player gold
mov edx,c1.gold
add edx,eax
mov c1.gold,edx

mRemoveItem

endm

mInitializeShop MACRO
Local L

mov ebx, offset s1


while1&L:
cmp ebx,null
jne do&L
jmp end_while&L
do&L:

mInitializeItem

mov eax, t1.item.itemCode
mov [ebx].item.itemCode, eax
mov eax, t1.item.buyValue
mov [ebx].item.buyValue, eax
mov eax, t1.item.sellValue
mov [ebx].item.sellValue, eax
mov eax, t1.item.combatValue
mov [ebx].item.combatValue, eax
mov eax, t1.item.elementalType
mov [ebx].item.elementalType, eax

mov ebx,[ebx].item.next
inc ecx
jmp while1&L

end_while&L:
endm

