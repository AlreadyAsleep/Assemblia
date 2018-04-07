enemyName1 byte "Boglin" , 0 , 10, 0
enemyName2 byte "Necromancer" , 0 , 10, 0
enemyName3 byte "Golem" , 0 , 10, 0
enemyName4 byte "Bogmen" , 0 , 10, 0
enemyName5 byte "Zombie" , 0 , 10, 0

mSetEnemyName MACRO
mov eax,5
call RandomRange
inc eax
mov e1.enemyNameCode,eax
endm

mGetEnemyName MACRO
Local L
mov eax, e1.enemyNameCode

cmp eax,1
je enemyName1&L
cmp eax,2
je enemyName2&L
cmp eax,3
je enemyName3&L
cmp eax,4
je enemyName4&L
cmp eax,5
je enemyName5&L


enemyName1&L:
mov edx, offset enemyName1
jmp print&L
enemyName2&L:
mov edx, offset enemyName2
jmp print&L
enemyName3&L:
mov edx, offset enemyName3
jmp print&L
enemyName4&L:
mov edx, offset enemyName4
jmp print&L
enemyName5&L:
mov edx, offset enemyName5
jmp print&L

print&L:
invoke WriteString
endm