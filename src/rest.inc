restMessageTitle byte "You rest soundly throughout the night" ,13,10,0

mRest MACRO

mov edx, offset restMessageTitle
invoke WriteString

mov eax, c1.hpMax
mov c1.hp,eax

mov edx,offset continueCommand
invoke WriteString

_get_input

call clrscr


endm