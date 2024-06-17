#include <iostream>
#include "Door.h"
#include "Tile.h"
#include "Item.h"
using namespace std;

Door::Door()		// default constructor
{
	colour = RESET;
	isOpen = false;
}

Door::Door(string _colour, char _type, char _sprite, bool _canMove, Item* _item) : Tile(_type, _sprite, _canMove, _item)		// custom construtor with parent's constructor
{
	colour = _colour;
	isOpen = false;
}

Door::~Door() 	// default destructor
{
}

bool Door::getIsPassable()
{
	if (isOpen)
	{
		return true;
	}

	return false;
}

void Door::setIsPassable(bool _setBool)
{
	isOpen = _setBool;

	return;
}

void Door::display()
{
	if (isOpen)
	{
		cout << ' ';
	}

	else
	{
		cout << colour;
		cout << sprite;
		cout << RESET;
	}

	return;
}