mTravel MACRO
Local L

mov eax,10
call RandomRange 

cmp eax,3 ;// 30% chance for shop
jl shop&L
jmp combat&L
shop&L:
	mShop
combat&L:
	mCombat
endm