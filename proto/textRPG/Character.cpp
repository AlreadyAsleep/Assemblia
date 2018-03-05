#include "stdafx.h"
#include "Character.h"


Character::Character()
{
	this->xPos = 0.0;
	this->yPos = 0.0;

	this->name = name;
	this->level = 0;
	this->exp = 0;
	this->expNext = 0;
	this->hp = 0;
	this->hpMax = 0;
	this->stamina = 0;
	this->damageMin = 0;
	this->damageMax = 0;
	this->defense = 0;

	this->strength = 5;
	this->vitality = 5;
	this->dexterity = 5;
	this->intelligence = 5;
	this->luck = 5;

	this->statPoints = 0;
	this->skillPoints = 0;
}

Character::Character(const std::string name)
{
	this->xPos = 0.0;
	this->yPos = 0.0;

	this->name = name;
	this->level = 0;
	this->exp = 0;
	this->expNext = 0;
	this->hp = 0;
	this->hpMax = 0;
	this->stamina = 0;
	this->damageMin = 0;
	this->damageMax = 0;
	this->defense = 0;

	this->strength = 5;
	this->vitality = 5;
	this->dexterity = 5;
	this->intelligence = 5;
	this->luck = 5;

	this->statPoints = 0;
	this->skillPoints = 0;
}

Character::~Character()
{
	
}//character

void Character::initialize(const std::string name)
{
	this->xPos = 0.0;
	this->yPos = 0.0;
	this->name = name;
	this->level = 1;
	this->exp = 0;
	this->expNext = level * 100;
	this->hp = 10;
	this->hpMax = 10;
	this->stamina = 10;
	this->staminaMax = 10;
	this->damageMin = 2;
	this->damageMax = 4;
	this->defense = 1;
	
}

//Functions
void Character::printStats() const
{
	std::cout << "= Character Sheet =" << std::endl;
	std::cout << "= Name: " << this->name << std::endl;
	std::cout << "= Level: " << this->level << std::endl;
	std::cout << "= Exp: " << this->exp << std::endl;
	std::cout << "= Exp to next level: " << this->expNext << std::endl;
	//std::cout << std::setw(10) << std::setfill('=') << std::endl;
	std::cout << "= Strength: " << this->strength << std::endl;
	std::cout << "= Vitality: " << this->vitality << std::endl;
	std::cout << "= Dexterity: " << this->dexterity << std::endl;
	std::cout << "= Intelligence: " << this->intelligence << std::endl;
	std::cout << "= Luck: " << this->luck << std::endl;

	std::cout << "= HP: " << this->hp << " / " << this-> hpMax << std::endl;
	std::cout << "= Stamina: " << this->stamina << " / " << this->staminaMax << std::endl;
	std::cout << "= Damage: " << this->damageMin << " - " << damageMax << std::endl;
	std::cout << "= Defense: " << this->defense << std::endl;
	
	std::cout << std::endl;

}//printStats

void Character::levelUp()
{
	while (exp >= expNext)
	{
		this->exp -= expNext;
		this->level++;
		this->exp = 0;
		this->expNext = this->level * 100;

		this->statPoints++;
		this->skillPoints++;
	}//while
}//levelUp

std::string Character::getAsString() const
{
	return std::to_string(xPos) + " "
		+ std::to_string(yPos) + " "
		+ name + " "
		+ std::to_string(level) + " "
		+ std::to_string(exp) + " "
		+ std::to_string(strength) + " "
		+ std::to_string(vitality) + " "
		+ std::to_string(dexterity) + " "
		+ std::to_string(intelligence) + " "
		+ std::to_string(hp) + " "
		+ std::to_string(stamina) + " "
		+ std::to_string(statPoints) + " "
		+ std::to_string(skillPoints);
}//getAsString
