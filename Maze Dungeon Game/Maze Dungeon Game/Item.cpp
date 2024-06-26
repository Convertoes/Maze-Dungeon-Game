#include <iostream>
#include "Item.h"
#include "Utility.h"
using namespace std;

Item::Item()		// default constructor
{
	name = "";
	colour = "";
	sprite = ' ';
	posX = 0;
	posY = 0;
	type = ' ';
	isTaken = false;
}

Item::Item(string _name, string _colour, char _sprite, int _x, int _y, char _type)	// custom constructor
{
	name = _name;
	colour = _colour;
	sprite = _sprite;
	posX = _x;
	posY = _y;
	type = _type;
	isTaken = false;
}

Item::~Item() 	// default destructor
{
}

string Item::getName()
{
	return name;
}

void Item::display(bool _nameBool) // displays either the sprite or the name of the item
{
	if (_nameBool)	// displays the name of the item
	{
		cout << name;
	}

	else	//  displays the sprite of the item
	{
		set_cursor(posX, posY);
		cout << colour;
		cout << sprite;
		cout << RESET;
	}

	return;
}

char Item::getType()
{
	return type;
}

int Item::getXPos()
{
	return posX;
}
int Item::getYPos()
{
	return posY;
}

bool Item::getIsTaken()
{
	return isTaken;
}

void Item::setIsTaken(bool _isTaken)
{
	isTaken = _isTaken;
	return;
}