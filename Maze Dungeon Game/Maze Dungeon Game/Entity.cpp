#include <iostream>
#include "Entity.h"
using namespace std;

Entity::Entity()		// default constructor
{
	xCoord = 0;
	yCoord = 0;
	name = "";
	health = 0.00;
	strength = 0.00;
	defense = 0.00;
	sprite = ' ';
}

Entity::Entity(int _x, int _y, string _name, float _health, float _strength, float _defense, char _sprite) 		// custom construtor
{
	xCoord = _x;
	yCoord = _y;
	name = _name;
	health = _health;
	strength = _strength;
	defense = _defense;
	sprite = _sprite;
}

Entity::~Entity() 	// default destructor
{
}

bool Entity::getIsAlive()	// gets the checkIfAlive method
{
	return checkIsAlive;
}

void Entity::move(int _tempX, int _tempY)	// moves the character by one space, called from subclasses
{
	set_cursor(xCoord, yCoord);
	cout << ' ';

	set_cursor(_tempX, _tempY);
	cout << sprite;

	xCoord = _tempX;
	yCoord = _tempY;

	return;
}

bool Entity::checkIsAlive()	// checks if the entity's health is above 0
{
	if (health > 0)	// if health is above 0, it is alive
	{
		return true;
	}

	return false;
}