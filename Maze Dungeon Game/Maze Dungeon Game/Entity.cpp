#include <iostream>
#include <cstdio>
#include "Maze.h"
#include "Entity.h"
using namespace std;

Entity::Entity()		// default constructor
{
	maze = nullptr;
	xCoord = 0;
	yCoord = 0;
	name = "";
	health = 0.00;
	strength = 0.00;
	defense = 0.00;
	sprite = ' ';
	colour = "\033[0m";
}

Entity::Entity(Maze* _maze, int _x, int _y, string _name, float _health, float _strength, float _defense, char _sprite, string _colour) 		// custom construtor
{
	maze = _maze;
	xCoord = _x;
	yCoord = _y;
	name = _name;
	health = _health;
	strength = _strength;
	defense = _defense;
	sprite = _sprite;
	colour = _colour;
}

Entity::~Entity() 	// default destructor
{
}

bool Entity::getIsAlive()	// gets the checkIfAlive method
{
	return checkIsAlive();
}

int Entity::getXCoord()
{
	return xCoord;
}

int Entity::getYCoord()
{
	return yCoord;
}

string Entity::getName()
{
	return name;
}

float Entity::getHealth()
{
	return health;
}

void Entity::setHealth(float _health)
{
	health = _health;
	return;
}

float Entity::getStrength()
{
	return strength;
}

float Entity::getDefense()
{
	return defense;
}

void Entity::display(bool _displayName)
{
	if (_displayName)
	{
		cout << name;
	}

	else
	{
		set_cursor(xCoord, yCoord);
		cout << colour;
		cout << sprite;
		cout << RESET;
		set_cursor(0, maze->getMazeLength());	// returns cursor to the default console location
	}

	return;
}

void Entity::moveSprite(int _tempX, int _tempY)	// moves the character by one space, called from subclasses
{
	set_cursor(xCoord, yCoord);
	cout << ' ';

	xCoord = _tempX;
	yCoord = _tempY;

	display(false);

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