;// Main.asm - The file that contains the main game loop and launcher
;// Authors: Thomas and Ben
;// Since: 3/16/18

.386
.model stdcall, flat
.stack 4096
include irvine32.inc

include characterHeader.inc

.data

include input_data.inc
include get_input.inc

include character.inc

WriteDec proto
ReadDec proto
ExitProcess proto, dwExitCode:dword

mainMenu       byte "Main Menu"        , 13, 10, 0
quit           byte "0 Quit"           , 13, 10, 0
characterSheet byte "1 Character Sheet", 13, 10, 0

blank byte " ", 13, 10, 0




.code

main proc

mov ecx, 1
while_main:						;//while( ecx != 0 )

	
	mov edx, offset mainMenu ;//Main Menu Display Start
	call WriteString
	mov edx, offset quit 
	call WriteString
	mov edx, offset characterSheet
	call WriteString         ;//Main Menu Display End

	_get_input
	
	call Clrscr

	cmp ecx, 0 ;//switch
	je endwhile_main
	cmp ecx, 1
	je character_sheet

	character_sheet:
		mPrintCharacterSheet


	jmp while_main ;//default


endwhile_main:
	
	invoke ExitProcess, 0

main endp

end main