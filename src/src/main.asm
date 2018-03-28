;// Main.asm - The file that contains the main game loop and launcher
;// Authors: Thomas and Ben
;// Since: 3/16/18

.386
.model stdcall, flat
.stack 4096
include irvine32.inc

include characterHeader.inc
include enemyHeader.inc

.data

include input_data.inc
include get_input.inc

include character.inc
include enemy.inc
include combat.inc
include levelUp.inc

WriteDec proto
ReadDec proto
ExitProcess proto, dwExitCode:dword

mainMenuTitle       byte "Main Menu"        , 13, 10, 0
quitTitle           byte "0 Quit"           , 13, 10, 0
characterSheet      byte "1 Character Sheet", 13, 10, 0
combatTitle         byte "2 Combat"         , 13, 10, 0
levelUpTitle        byte "3 Level Up:"      , 13, 10, 0




blank byte " ", 13, 10, 0




.code

main proc

mGetCharacterName
mInitializeCharacter

mov ecx, 1
while_main:						;//while( ecx != 0 )

	
	mov edx, offset mainMenuTitle ;//Main Menu Display Start
	call WriteString
	mov edx, offset quitTitle 
	call WriteString
	mov edx, offset characterSheet
	call WriteString    
	mov edx, offset combatTitle
	call WriteString     
	mov edx, offset levelUpTitle
	call WriteString

	_get_input
	
	call Clrscr

	cmp ecx, 0 ;//switch
	je endwhile_main
	cmp ecx, 1
	je character_sheet
	cmp ecx, 2
	je combat
	cmp ecx, 3
	je levelUp
	jmp end_switch

	character_sheet:
		mPrintCharacterSheet
		jmp end_switch
	combat:
		mCombat
		jmp end_switch
	levelUp:
		mLevelUp
		jmp end_switch

	end_switch:
	jmp while_main ;//default


endwhile_main:
	
	invoke ExitProcess, 0

main endp

end main