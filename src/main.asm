;// Main.asm - The file that contains the main game loop and launcher
;// Authors: Thomas and Ben
;// Since: 3/16/18



.386
.model stdcall, flat
.stack 8192
include irvine32.inc

include characterHeader.inc
include enemyHeader.inc
include itemHeader.inc

.data
include getItemName.inc
include getEnemyName.inc
include input_data.inc
include get_input.inc

include character.inc
include enemy.inc
include combat.inc
include levelUp.inc
include inventory.inc
include shop.inc
include travel.inc
include rest.inc
include damageTypes.inc

WriteDec proto
ReadDec proto
ExitProcess proto, dwExitCode:dword

mainMenuTitle    byte "Main Menu", 13, 10, 0
quitTitle        byte "909 Quit", 13, 10, 0
characterSheet   byte "1 Character Sheet", 13, 10, 0
combatTitle      byte "2 Combat", 13, 10, 0
levelUpTitle     byte "3 Level Up", 13, 10, 0
inventoryTitle   byte "4 Inventory", 13, 10, 0
dequipTitle      byte "5 Unequip", 13, 10, 0
shopTitle        byte "6 Shop", 13, 10, 0
travelTitle      byte "7 Travel", 13, 10, 0
restTitle        byte "8 Rest", 13, 10, 0

continueCommand byte "Press Enter to Continue", 13, 10, 0



exitTitle    byte "909 Exit: ", 13, 10, 0

introTitle1 byte "You awaken to the smell of death and burnt flesh."   , 13, 10, 0
introTitle2 byte "Around you lies the corpses of your fallen party."   , 13, 10, 0
introTitle3 byte "You are stranded in the swamps of the Sudlands."     , 13, 10, 0
introTitle4 byte "You have nothing."                                   , 13, 10, 0



load_prompt byte "Load?(y/n)", 13, 10, 0
entry_invalid byte "entry invalid", 13, 10, 0



blank byte " ", 13, 10, 0

save_character proto C character : ptr byte, filename : ptr byte
load_character proto C character : ptr byte, filename : ptr byte
test_print_num proto C




include save_vars.inc

loadTitle1 byte "You awaken from your short but needed rest", 13, 10, 0

.code

main proc C

;// ask if load or new

if_new:
	mov edx, offset load_prompt
	call WriteString
	call ReadChar
	or al, 00100000b ;// upper to lower
	cmp al, "n"
	je then_new
	cmp al, "y"
	je else_new
	jmp err_new
then_new:
	mGetCharacterName
	mInitializeCharacter
	
	mov edx, offset introTitle1
	invoke WriteString
	mov edx, offset introTitle2
	invoke WriteString
	mov edx, offset introTitle3
	invoke WriteString
	mov edx, offset introTitle4
	invoke WriteString
	mov edx, offset continueCommand
	invoke WriteString
	
	_get_input
	
	call clrscr
	
	jmp end_new
else_new:
	mInitializeCharacter
	_load_from_buffer

	call clrscr

	mov edx, offset loadTitle1
	invoke WriteString
	

	_get_input

	call clrscr
	jmp end_new
err_new:
	mov edx, offset entry_invalid
	invoke WriteString
	jmp if_new
end_new:
	nop
	
	





mov ecx, 1
while_main:;//while( ecx != 0 )
call clrscr

mov edx, offset mainMenuTitle;//Main Menu Display Start
call WriteString
mov edx, offset quitTitle
call WriteString
mov edx, offset characterSheet
call WriteString
mov edx, offset combatTitle
call WriteString
mov edx, offset levelUpTitle
call WriteString
mov edx, offset inventoryTitle
call WriteString
mov edx, offset dequipTitle
call WriteString
mov edx, offset shopTitle
call WriteString
mov edx, offset travelTitle
call WriteString
mov edx, offset restTitle
call WriteString

_get_input

call Clrscr

cmp ecx, 909;//switch
je endwhile_main
cmp ecx, 1
je character_sheet
cmp ecx, 2
je combat
cmp ecx, 3
je levelUp
cmp ecx, 4
je inventory
cmp ecx, 5
je dequip
cmp ecx, 6
je shop
cmp ecx, 7
je travel
cmp ecx, 8
je rest
jmp end_switch

character_sheet :
mPrintCharacterSheet
jmp end_switch
combat :
mCombat
jmp end_switch
levelUp :
mLevelUp
jmp end_switch
inventory :
mInventory
jmp end_switch
dequip :
mDequip
jmp end_switch
shop :
mShop
jmp end_switch
travel :
mTravel
jmp end_switch
rest:
mRest
jmp end_switch
end_switch :
_save_char
jmp while_main;//default



endwhile_main:



invoke ExitProcess, 0

main endp

end