#include <iostream>
#include <conio.h>
#include "Player.h"
#include "Enemy.h"
#include "Entity.h"
using namespace std;

Player::Player()		// default constructor
{
	inventory = nullptr;
	hasKey = false;
}

Player::Player(Maze* _maze, int _x, int _y, string _name, float _health, float _strength, float _defense, char _sprite) : Entity(_maze, _x, _y, _name, _health, _strength, _defense, _sprite)	// custom construtor
{
	inventory = new List();
	hasKey = false;
}

Player::~Player() 	// default destructor
{
}

void Player::move()
{
	int userInput = _getch();
	int tempPosX = xCoord;
	int tempPosY = yCoord;

    if (userInput == 'w')
    {
        tempPosY--;
    }

    else if (userInput == 'a')
    {
        tempPosX--;
    }

    else if (userInput == 's')
    {
        tempPosY++;
    }

    else if (userInput == 'd')
    {
        tempPosX++;
    }

    else
    {
        return;
    }

    switch (maze->getDifficulty())  // moves the sprite if the tile at the temp coordinate is passable (different cases for difficulty)
    {
        case 1:
            if (maze->getTileEasy(tempPosX, tempPosY)->getIsPassable() == true)
            {
                Entity::moveSprite(tempPosX, tempPosY);
            }
            break;

        case 2:
            if (maze->getTileNormal(tempPosX, tempPosY)->getIsPassable() == true)
            {
                Entity::moveSprite(tempPosX, tempPosY);
            }
            break;

        case 3:
            /*
            if (maze->getTileHard(tempPosY, tempPosX)->getIsPassable() == true)
            {
                Entity::moveSprite(tempPosX, tempPosY);
            }
            */
            break;
    }

    return;
}

List* Player::getInventory()
{
    return inventory;
}

bool Player::getHasKey()
{
    return hasKey;
}

void Player::useItem(Item*)
{

    return;
}

void Player::addItem(Item*)
{

    return;
}

void Player::displayInventory()
{

    return;
}

Enemy* Player::attack()
{
    Enemy* enemy = new Enemy();
    return enemy;
}