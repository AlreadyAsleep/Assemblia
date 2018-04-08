escape         byte 0
playerDefeated byte 0
enemyDefeated  byte 0

combatMenuTitle  byte "--COMBAT--"   , 13, 10, 0
enemyNameTitle   byte "Enemy Name:"  , 0 , 10, 0
enemyHPTitle     byte "Enemy HP:"    , 0 , 10, 0
enemyDamageTitle byte "Enemy Damage:", 0 , 10, 0


combatOptionsMenuTitle byte "--Combat Options--", 13, 10, 0
attackTitle            byte "0: Attack"         , 13, 10, 0
fleeTitle              byte "1: Flee"           , 13, 10, 0

escapeEvent          byte "You Escaped!"          , 13, 10, 0
playerDefeatedEvent  byte "You were defeated"     , 13, 10, 0
enemyDefeatedEvent   byte "You Defeated the Enemy", 13, 10, 0
takeGoldEvent        byte "They took your gold"   , 13, 10, 0

youGotTitle     byte "You recieved "    , 0,10,0
goldRewardTitle byte " gold"       ,13,10,0
expRewardTitle  byte " experience" ,13,10,0

youFoundTitle byte "You found a(n) ",0,10,0

youTookTitle  byte "You took "  , 0,10,0
damageCombatTitle   byte " damage"    ,13,10,0
youDealtTitle byte "You dealt " , 0,10,0

attackedResponse byte "You are attacked!",13,10,0

mCombat MACRO
Local L
pushAD

mov edx, offset attackedResponse
invoke WriteString
mov edx, offset continueCommand
invoke WriteString

_get_input
call clrscr

mInitializeEnemy



mov escape        ,0 ;//combat end conditions
mov playerDefeated,0
mov enemyDefeated ,0

WHILE_COMBAT&L:    ;//disgusting triple & while statement
cmp escape,0       ;//while &
je AND_COMBAT1&L
jmp AND_FALSE_COMBAT&L
AND_COMBAT1&L: cmp playerDefeated,0
je AND_COMBAT2&L
jmp AND_FALSE_COMBAT&L
AND_COMBAT2&L: cmp enemyDefeated,0
je AND_COMBAT_TRUE&L
jmp AND_FALSE_COMBAT&L
AND_COMBAT_TRUE&L:
	
	mov edx, offset combatMenuTitle
	invoke WriteString

	mov edx, offset enemyNameTitle ;//prints enemy name
	invoke WriteString
	
	mGetEnemyName

	mov edx, offset blank
	invoke WriteString

	mov edx, offset enemyHpTitle ;//prints enemy hp
	invoke WriteString
	mov eax, e1.hp
	call WriteDec
	mov eax,'/'
	call WriteChar
	mov eax, e1.hpMax
	call WriteDec
	mov edx, offset blank
	invoke WriteString

	mov edx, offset enemyDamageTitle ;//prints enemy damage
	invoke WriteString
	mov eax, e1.damageMin
	call WriteDec
	mov eax,'-'
	call WriteChar
	mov eax, e1.damageMax
	call WriteDec
	mov edx, offset blank
	invoke WriteString

	mov edx, offset combatAttributesTitle ;//prints primary attributes header
invoke WriteString

	mov edx, offset hpTitle ;//prints character hp
	invoke WriteString
	mov eax, c1.hp
	call WriteDec
	mov eax,'/'
	call WriteChar
	mov eax, c1.hpMax
	call WriteDec
	mov edx, offset blank
	invoke WriteString

	mov edx, offset damageTitle ;//prints character damage
	invoke WriteString
	mov eax, c1.damageMin
	call WriteDec
	mov eax,'-'
	call WriteChar
	mov eax, c1.damageMax
	call WriteDec
	mov edx, offset blank
	invoke WriteString

	mov edx, offset combatOptionsMenuTitle ;//prints combat Options
	invoke WriteString

	mov edx,offset attackTitle
	invoke WriteString

	mov edx,offset fleeTitle
	invoke WriteString

	_get_input
	
	call Clrscr

	
		cmp ecx, 0 ;//switch
		je attack&L
		cmp ecx, 1
		je flee&L
	
		jmp end_switch&L

		attack&L:
			mov eax,c1.damageMax;//player attacks
			mov ebx,c1.damageMin
			sub eax,ebx
			inc eax
			call RandomRange
			add eax,ebx
			sub e1.hp,eax

			mov edx, offset youDealtTitle
			invoke WriteString
			call WriteDec
			mov edx, offset damageCombatTitle
			invoke WriteString

			mov edx, offset continueCommand
			invoke WriteString
			_get_input

			cmp e1.hp,0 ;//check to see if enemy died
			jle enemy_dead&L
			jmp end_switch&L
			enemy_dead&L:
				mov enemyDefeated,1
				jmp AND_FALSE_COMBAT&L
		flee&L:
			mov escape,1
			jmp AND_FALSE_COMBAT&L
			
		end_switch&L:

			mov eax,e1.damageMax;//enemy attacks
			mov ebx,e1.damageMin
			sub eax,ebx
			inc eax
			call RandomRange
			add eax,ebx
			sub c1.hp,eax

			mov edx, offset youTookTitle
			invoke WriteString
			call WriteDec
			mov edx, offset damageCombatTitle
			invoke WriteString

			mov edx, offset continueCommand
			invoke WriteString
			_get_input

			call Clrscr

			cmp c1.hp,0    ;// checking to see if character died
			jle character_dead&L
			jmp character_not_dead&L
			character_dead&L:
				mov playerDefeated,1
			character_not_dead&L:

		jmp WHILE_COMBAT&L;//default

AND_FALSE_COMBAT&L:

cmp escape,0
je not_escape&L

mov edx, offset escapeEvent;//will print if player fleed
invoke WriteString
jmp eventDetermined&L

not_escape&L:
cmp playerDefeated,0
je not_playerDefeated&L

mov edx, offset playerDefeatedEvent;//will print if player was defeated
invoke WriteString
mov edx, offset takeGoldEvent
invoke WriteString

mov c1.gold,0

mov eax, c1.hpMax
mov c1.hp,eax



jmp eventDetermined&L

not_playerDefeated&L:

mov edx,offset enemyDefeatedEvent;//will print if enemy was defeated
invoke WriteString


mInitializeItem
mov eax, offset t1 ;//adds axe to inventory
mAddItem

mov edx, offset youFoundTitle
invoke WriteString
mov eax, t1.item.itemcode
mGetItemName

call crlf


mov eax, c1.level
mov ecx,10
mul ecx
call RandomRange
mov ebx,c1.gold
add ebx,eax
mov c1.gold,ebx


mov edx,offset youGotTitle
invoke WriteString
call WriteDec
mov edx,offset goldRewardTitle
invoke WriteString

mov eax,e1.expReward ;//rewarding player exp
add c1.exp,eax

mov edx,offset youGotTitle
invoke WriteString
call WriteDec
mov edx,offset expRewardTitle
invoke WriteString



eventDetermined&L:

mov edx, offset continueCommand
invoke WriteString

_get_input






call Clrscr

popAD
endm