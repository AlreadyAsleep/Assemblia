;// structure of character object
character struct 

xPos           DWORD 0
yPos           DWORD 0
characterName  db    8 dup (?)
level          DWORD 0
exp            DWORD 0
expToNext      DWORD 0

brawn          DWORD 1 ;//Primary Attributes
agility        DWORD 1
mind           DWORD 1
fortune        DWORD 1

hpMax          DWORD 0
hp             DWORD 0
damageMin      DWORD 0
damageMax      DWORD 0
defence        DWORD 0




character ends