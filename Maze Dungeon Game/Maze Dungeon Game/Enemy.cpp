#include <iostream>
#include "Utility.h"
#include "Enemy.h"
#include "Player.h"
#include "Entity.h"
using namespace std;

Enemy::Enemy()		// default constructor
{
	player = nullptr;
}

Enemy::Enemy(Player* _player, Maze* _maze, int _x, int _y, string _name, float _health, float _strength, float _defense, char _sprite) : Entity(_maze, _x, _y, _name, _health, _strength, _defense, _sprite)		// custom construtor with parent's constructor
{
	player = _player;
}

Enemy::~Enemy() 	// default destructor
{
}

Player* Enemy::getPlayer()
{
	return player;
}

void Enemy::move()
{
	int direction = 0;
	bool didMove = false;
	do
	{
		int tempPosX = xCoord;
		int tempPosY = yCoord;

		switch (direction)
		{
			case 0:	// moves up
				tempPosY--;
				break;

			case 1:	// moves left
				tempPosX--;
				break;

			case 2:	// moves down
				tempPosY++;
				break;

			case 3: // moves right
				tempPosX++;
				break;
		}

		switch (maze->getDifficulty())  // moves the sprite if the tile at the temp coordinate is passable (different cases for difficulty)
		{
		case 1:
			if (maze->getTileEasy(tempPosY, tempPosX)->getIsPassable() == true)
			{
				Entity::moveSprite(tempPosX, tempPosY);
				didMove = true;
			}
			break;

		case 2:
			if (maze->getTileNormal(tempPosY, tempPosX)->getIsPassable() == true)
			{
				Entity::moveSprite(tempPosX, tempPosY);
				didMove = true;
			}
			break;

		case 3:
			/*
			if (maze->getTileHard(tempPosY, tempPosX)->getIsPassable() == true)
			{
				Entity::moveSprite(tempPosX, tempPosY);
				didMove = true;
			}
			*/
			break;
		}

		direction++;
	} while (didMove = false);	// loops until the enemy moves

	return;
}