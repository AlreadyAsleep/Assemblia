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

mCombat MACRO
Local L
pushAD

mInitializeEnemy

mov eax,c1.hpMax
mov c1.hp,eax

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
	mov edx, offset e1.enemyName
	invoke WriteString
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
		je attack
		cmp ecx, 1
		je flee
	
		jmp end_switch&L

		attack:
			mov eax,c1.damageMax;//player attacks
			mov ebx,c1.damageMin
			sub eax,ebx
			inc eax
			call RandomRange
			add eax,ebx
			sub e1.hp,eax

			cmp e1.hp,0 ;//check to see if enemy died
			jle enemy_dead
			jmp end_switch&L
			enemy_dead:
				mov enemyDefeated,1
				jmp AND_FALSE_COMBAT&L
		flee:
			mov escape,1
			
		end_switch&L:

			mov eax,e1.damageMax;//enemy attacks
			mov ebx,e1.damageMin
			sub eax,ebx
			inc eax
			call RandomRange
			add eax,ebx
			sub c1.hp,eax

			cmp c1.hp,0    ;// checking to see if character died
			jle character_dead
			jmp character_not_dead
			character_dead:
				mov playerDefeated,1
			character_not_dead:

		jmp WHILE_COMBAT&L;//default

AND_FALSE_COMBAT&L:

cmp escape,0
je not_escape

mov edx, offset escapeEvent;//will print if player fleed
invoke WriteString
jmp eventDetermined

not_escape:
cmp playerDefeated,0
je not_playerDefeated

mov edx, offset playerDefeatedEvent;//will print if player was defeated
invoke WriteString
jmp eventDetermined

not_playerDefeated:

mov edx,offset enemyDefeatedEvent;//will print if enemy was defeated
invoke WriteString
mov eax, offset t1
mAddItem

mov eax,e1.expReward ;//rewarding player exp
add c1.exp,eax

eventDetermined:

mov eax,2000
call Delay



call Clrscr

popAD
endm