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

mCombat MACRO
Local L
pushAD

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

	mov edx, offset combatOptionsMenuTitle
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
			dec e1.hp
			jmp end_switch&L
		flee:
			mov escape,1
			
		end_switch&L:
		jmp WHILE_COMBAT&L;//default




AND_FALSE_COMBAT&L:
popAD
endm