#pragma once
#include "Item.h"
class Inventory
{
public:
	Inventory();
	~Inventory();
	void addItem(const Item &item);
	void removeItem(int index);
	inline void debugPrint() const
	{
		for (size_t i = 0; i < this->nrOfItems; i++)
			std::cout << this->itemArr[i]->debugPrint() << std::endl;
	}//debugPrint
private:
	void expand();
	int nrOfItems;
	int cap;
	void initialize(const int from);
	Item **itemArr;
};

