#include <iostream>
#include <windows.h>
#include "Tile.h"
#include "Utility.h"
using namespace std;

Tile::Tile()		// default constructor
{
	tileType = 's';
	sprite = ' ';
	isCrumb = false;
	canMove = false;

	return;
}

Tile::Tile(char _tileType, char _sprite, bool _canMove)		// custom construtor
{
	tileType = _tileType;
	sprite = _sprite;
	isCrumb = false;
	canMove = _canMove;

	return;
}

Tile::~Tile() 	// default destructor
{
}

char Tile::getType()
{
	return tileType;
}

bool Tile::getIsPassable()
{
	return isPassable();
}

bool Tile::getIsCrumb()
{
	return isCrumb;
}

void Tile::setIsCrumb(bool _isCrumb)
{
	isCrumb = _isCrumb;
	return;
}

void Tile::display()
{
	cout << sprite;

	return;
}

bool Tile::isPassable()
{
	if (canMove)
	{
		return true;
	}

	return false;
}
void Tile::setIsPassable(bool _void)
{
	canMove = _void;
	return;
}