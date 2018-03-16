_get_input macro

	Local L
	call ReadDec
if$L:
	cmp eax, 0
	jz then$L
	jmp endif$L
then$L:
	mov ecx, eax
endif$L:
	nop

endm