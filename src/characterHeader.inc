;// structure of character object
character struct 

characterName  db    16 dup (?)
level          DWORD 0
exp            DWORD 0
expToNext      DWORD 0
gold           DWORD 0

brawn          DWORD 1 ;//Primary Attributes
agility        DWORD 1
mind           DWORD 1
fortune        DWORD 1

hpMax          DWORD 0
hp             DWORD 0
damageMin      DWORD 0
damageMax      DWORD 0

weaponCode      DWORD 0
weaponBuyValue  DWORD 0
weaponSellValue DWORD 0
weaponDamage    DWORD 0
weaponElementalType DWORD 0


defence        DWORD 0

char_pad byte 37 dup (0) ;// pad character struct to 128 bytes

character ends