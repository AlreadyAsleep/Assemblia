;//level up class
notEnoughResponse byte "Not enough experience"  , 13, 10, 0
leveledUpResponse byte "You leveled up!"        , 13, 10, 0
attributeSelection byte "Increase an attribute" , 13, 10, 0

brawnAttribute   byte "0 Brawn"   ,13,10,0
agilityAttribute byte "1 Agility" ,13,10,0
mindAttribute    byte "2 Mind"    ,13,10,0
fortuneAttribute byte "3 Fortune" ,13,10,0

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


mov edx, offset attributeSelection
invoke WriteString
mov edx, offset brawnAttribute
invoke WriteString
mov edx, offset agilityAttribute
invoke WriteString
mov edx, offset mindAttribute
invoke WriteString
mov edx, offset fortuneAttribute
invoke WriteString

_get_input

invalidAttribute:
cmp ecx,0
je brawn
cmp ecx,1
je agility
cmp ecx,2
je mind
cmp ecx,3
je fortune
jmp invalidAttribute

brawn:
	inc c1.brawn
	jmp validAttribute
agility:
	inc c1.agility
	jmp validAttribute
mind:
	inc c1.mind
	jmp validAttribute
fortune:
	inc c1.fortune
	jmp validAttribute


	validAttribute:
call clrscr

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