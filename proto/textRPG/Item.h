#pragma once
#include <string>
#include <iostream>
class Item
{
private:
	std::string name;
	int level;
	int buyValue;
	int sellValue;
	int rarity;

public:
	Item(std::string name = "NONE", int level = 0,
		int buyValue = 0,
		int sellValue = 0,
		int rarity = 0);

	virtual ~Item();

	inline std::string debugPrint() const
	{
		return this->name;
	}//debugPrint


};

