
C1 character {0,0,"Name",0}

characterSheetTitle byte "--CharacterSheet--", 13, 10, 0
xPosTitle           byte "xPos: "            , 0 , 10, 0
yPosTitle           byte "yPos: "            , 0 , 10, 0
nameTitle           byte "Name: "            , 0 , 10, 0
levelTitle          byte "Level:"            , 0 , 10, 0

mPrintCharacterSheet MACRO ;//prints character sheet 
mov edx, offset characterSheetTitle
invoke WriteString

mov edx, offset xPosTitle
invoke WriteString
mov eax, c1.xPos
call WriteDec
mov edx, offset blank
invoke WriteString

mov edx, offset yPosTitle
invoke WriteString
mov eax, c1.yPos
call WriteDec
mov edx, offset blank
invoke WriteString

mov edx, offset nameTitle
invoke WriteString
mov edx, offset c1.CharacterName
Call WriteString
mov edx, offset blank
invoke WriteString

mov edx, offset levelTitle
invoke WriteString
mov eax, c1.level
call WriteDec
mov edx, offset blank
invoke WriteString

endm