
C1 character {0,0,"Name",1,0,100,4,4,4,4,5,5,1,3,}

characterSheetTitle byte "--CharacterSheet--"       , 13, 10, 0
xPosTitle           byte "xPos: "                   , 0 , 10, 0
yPosTitle           byte "yPos: "                   , 0 , 10, 0
nameTitle           byte "Name: "                   , 0 , 10, 0
levelTitle          byte "Level:"                   , 0 , 10, 0
expTitle            byte "Exp:"                     , 0 , 10, 0


primaryAttributesTitle byte "--Primary Attributes--", 13, 10, 0
brawnTitle          byte "Brawn:"                   , 0 , 10, 0
agilityTitle        byte "Agility:"                 , 0 , 10, 0
mindTitle           byte "Mind:"                    , 0 , 10, 0
fortuneTitle        byte "Fortune:"                 , 0 , 10, 0

combatAttributesTitle byte "--Combat Attributes--"  , 13, 10, 0
hpTitle             byte "HP:"                      , 0 , 10, 0
damageTitle         byte "Damage:"                  , 0 , 10, 0
defenceTitle        byte "Defence:"                 , 0 , 10, 0

command1 byte "Enter character name. Up to 8 Characters"  , 13, 10, 0

mPrintCharacterSheet MACRO ;//prints character sheet 
pushAD

mov edx, offset characterSheetTitle ;//prints a header
invoke WriteString

mov edx, offset xPosTitle ;// prints x position
invoke WriteString
mov eax, c1.xPos
call WriteDec
mov edx, offset blank
invoke WriteString

mov edx, offset yPosTitle ;// prints y position
invoke WriteString
mov eax, c1.yPos
call WriteDec
mov edx, offset blank
invoke WriteString

mov edx, offset nameTitle ;// prints character name
invoke WriteString
mov edx, offset c1.CharacterName
Call WriteString
mov edx, offset blank
invoke WriteString

mov edx, offset levelTitle ;//prints character level
invoke WriteString
mov eax, c1.level
call WriteDec
mov edx, offset blank
invoke WriteString

mov edx, offset expTitle ;//prints character exp
invoke WriteString
mov eax, c1.exp
call WriteDec
mov eax,'/'
call WriteChar
mov eax, c1.expToNext
call WriteDec
mov edx, offset blank
invoke WriteString

mov edx, offset primaryAttributesTitle ;//prints primary attributes header
invoke WriteString

mov edx, offset brawnTitle ;//prints character brawn
invoke WriteString
mov eax, c1.brawn
call WriteDec
mov edx, offset blank
invoke WriteString

mov edx, offset agilityTitle ;//prints character agility
invoke WriteString
mov eax, c1.agility
call WriteDec
mov edx, offset blank
invoke WriteString

mov edx, offset mindTitle ;//prints character mind
invoke WriteString
mov eax, c1.mind
call WriteDec
mov edx, offset blank
invoke WriteString

mov edx, offset fortuneTitle ;//prints character fortune
invoke WriteString
mov eax, c1.fortune
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

mov edx, offset defenceTitle ;//prints character defence
invoke WriteString
mov eax, c1.defence
call WriteDec
mov edx, offset blank
invoke WriteString


mov edx, offset blank
invoke WriteString

popAD
endm

mGetCharacterName MACRO
pushAD

mov edx, offset command1 ;//Player inputs character name
invoke WriteString
mov edx, offset c1.characterName
mov ecx, SIZEOF c1.characterName
call ReadString

popAD
endm

mInitializeCharacter MACRO ;//prints character sheet
pushAD



inc c1.brawn   ;// sets primary attributes
inc c1.agility
inc c1.mind   
inc c1.fortune

mov eax, c1.brawn ;// maxHP & hp initiliaze = brawn*2
sal eax,1 ;// multiply by 2
mov c1.hpMax,eax
mov c1.hp,eax

mov eax,c1.brawn;// damageMin & Max initialize damageMin = brawn/2 damage max = damageMin + agility/4
sar eax,1;//divide by 2
mov c1.damageMin,eax
mov ebx,c1.agility
sar ebx,2;//divide by 4
add eax,ebx
mov c1.damageMax,eax


popAD
endm
