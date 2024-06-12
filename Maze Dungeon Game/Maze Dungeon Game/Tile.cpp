#include <iostream>
#include <windows.h>
#include "Tile.h"
#include "Utility.h"
using namespace std;

Tile::Tile()		// default constructor
{
	tileType = 's';
	sprite = ' ';
	isPassable = true;
	isCrumb = false;

	return;
}

Tile::Tile(char _tileType, char _sprite, bool _isPassable)		// custom construtor
{
	tileType = _tileType;
	sprite = _sprite;
	isPassable = _isPassable;
	isCrumb = false;

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
	return isPassable;
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