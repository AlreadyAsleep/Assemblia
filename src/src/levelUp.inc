;//level up class
notEnoughResponse byte "Not enough experience", 13, 10, 0
leveledUpResponse byte "You leveled up!"      , 13, 10, 0

mLevelUp MACRO
pushAD

mov eax,c1.exp
mov ebx,c1.expToNext
cmp eax,ebx
jl notEnough

inc c1.level
mInitializeCharacter

mov eax,c1.exp
mov ebx,c1.expToNext
sub eax,ebx
mov c1.exp,eax

mov edx,offset leveledUpResponse
invoke WriteString

mov eax,2000
call Delay

jmp leveledUp

notEnough:

mov edx,offset notEnoughResponse
invoke WriteString

mov eax,2000
call Delay



leveledUp:

call Clrscr

popAD
endm