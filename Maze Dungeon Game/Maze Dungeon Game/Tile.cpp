#include <iostream>
#include "Tile.h"
#include "Utility.h"
using namespace std;

Tile::Tile()		// default constructor
{
	posX = 0;
	posY = 0;
	tileType = 'e';
	sprite = "  ";
	isPassable = false;
	isCrumb = false;

	return;
}

Tile::Tile(int _posX, int _posY, char _tileType, string _sprite, bool _isPassable)		// custom construtor
{
	posX = _posX;
	posY = _posY;
	tileType = _tileType;
	sprite = _sprite;
	isPassable = _isPassable;
	isCrumb = false;

	return;
}

Tile::~Tile() 	// default destructor
{
}

int Tile::getPosX()
{
	return posX;
}

int Tile::getPosY()
{
	return posY;
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
	cout << "sprite";

	return;
}