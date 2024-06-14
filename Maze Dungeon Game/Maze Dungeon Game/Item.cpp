#include <iostream>
#include "Item.h"
#include "Utility.h"
using namespace std;

Item::Item()		// default constructor
{
	name = "";
	colour = "";
	sprite = ' ';
	isKey = false;
	posX = 0;
	posY = 0;
	type = ' ';
	isTaken = false;
}

Item::Item(string _name, string _colour, char _sprite, bool _isKey, int _x, int _y, char _type)	// custom constructor
{
	name = _name;
	colour = _colour;
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