#include "stdafx.h"
#include "Inventory.h"


Inventory::Inventory()
{
	this->cap = 10;
	this->nrOfItems = 0;
	this->itemArr = new Item*[cap];
}


Inventory::~Inventory()
{
	for (size_t i = 0; i < this->nrOfItems; i++)
	{
		delete this->itemArr[i];
	} // for
		delete[] itemArr;
}

void Inventory::expand()
{
	this->cap *= 2;

	Item **tempArr = new Item*[this->cap];

	for (size_t i = 0; i < nrOfItems; i++)
	{
		tempArr[i] = new Item(*this->itemArr[i]);
	}//for

	for (size_t i = 0; i < nrOfItems; i++)
	{
		delete this->itemArr[i];
	}//for
	delete[] this->itemArr;

	this->itemArr = tempArr;

	this->initialize(this->nrOfItems);

}//expand
void Inventory::initialize(const int from)
{
	for (size_t i = from; i < cap; i++)
	{
		this->itemArr[i] = nullptr;
	} // for
}//intitialize
void Inventory::addItem(const Item &item)
{
	if (this->nrOfItems >= this->cap)
	{
		expand();
	}//if

	this->itemArr[this->nrOfItems++] = new Item(item);
}//addItem


