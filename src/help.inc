helpPara1 byte "To execute a command simply type the number next to it and hit enter."  , 13, 10, 0
helpPara2 byte "Character Sheet displays your characters stats."  , 13, 10, 0
helpPara3 byte "Level up will make your character stronger if you have enough exp."  , 13, 10, 0
helpPara4 byte "Inventory displays and lets you move equip the items your character has"  , 13, 10, 0
helpPara5 byte "Unequip takes the item your character is holding and puts it in your inventory."  , 13, 10, 0
helpPara6 byte "Travel will allow the player to explore the world and all its dangers"  , 13, 10, 0
helpPara7 byte "Rest will restore the player to full health."  , 13, 10, 0

mHelp MACRO
mov edx,offset helpPara1
invoke WriteString
mov edx,offset helpPara2
invoke WriteString
mov edx,offset helpPara3
invoke WriteString
mov edx,offset helpPara4
invoke WriteString
mov edx,offset helpPara5
invoke WriteString
mov edx,offset helpPara6
invoke WriteString
mov edx,offset helpPara7
invoke WriteString
mov edx, offset continueCommand
invoke WriteString
_get_input
endm