#include <iostream>
#include "Item.h"
#include "Utility.h"
using namespace std;

Item::Item()		// default constructor
{
	name = "";
	sprite = ' ';
	isKey = false;
	posX = 0;
	posY = 0;
	type = ' ';
	isTaken = false;
}

Item::Item(string _name, char _sprite, bool _isKey, int _x, int _y, char _type)	// custom constructor
{
	name = _name;
	sprite = _sprite;
	isKey = _isKey;
	posX = _x;
	posY = _y;
	type = _type;
	isTaken = false;
}

Item::~Item() 	// default destructor
{
}

void Item::display(bool _nameBool) // displays either the sprite or the name of the item
{
	if (_nameBool)	// displays the name of the item
	{
		cout << name;
	}

	else	//  displays the sprite of the item
	{
		cout << sprite;
	}

	return;
}