e1 enemy{"Boglin",1,1,1,1,1,1}

;//initialize emeny
mInitializeEnemy MACRO
pushAD

mov ebx, c1.level ;//initialize enemy hp
mov eax,3
call RandomRange
inc eax
mul ebx
mov e1.hpMax,eax
mov e1.hp,eax

mov eax, 2 ;//initialize enemy damage
call RandomRange
inc eax
add eax,ebx
mov e1.damageMin,eax
mov ecx,eax
mov eax,2
call RandomRange
inc eax
add eax,ecx
mov e1.damageMax,eax

mov eax,e1.hpMax ;//initialize expReward
mov ebx,10
mul ebx
mov e1.expReward ,eax

popAD
endm