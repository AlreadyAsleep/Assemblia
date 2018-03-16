;// Main.asm - The file that contains the main game loop and launcher
;// Authors: Thomas and Ben
;// Since: 3/16/18

.386
.model stdcall, flat
.stack 4096

.data

include input_data.inc
include get_input.inc

WriteDec proto
ReadDec proto
ExitProcess proto, dwExitCode:dword

.code

main proc

mov ecx, 1
while_main:						;//while( ecx != 0 )
	_get_input
	call WriteDec
	cmp ecx, 0
	jnz while_main
endwhile_main:
	
	invoke ExitProcess, 0

main endp

end main