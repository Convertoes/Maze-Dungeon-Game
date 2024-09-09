#include <iostream>
#include <conio.h>
#include "Player.h"
#include "Enemy.h"
#include "Tile.h"
#include "List.h"
#include "Entity.h"
using namespace std;

Player::Player()		// default constructor
{
	inventory = nullptr;
	hasKey = false;
}

Player::Player(Maze* _maze, int _x, int _y, string _name, float _health, float _strength, float _defense, char _sprite, string _colour) : Entity(_maze, _x, _y, _name, _health, _strength, _defense, _sprite, _colour)	// custom construtor
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
            if (maze->getTileEasy(tempPosX, tempPosY)->getIsPassable())
            {
                Entity::moveSprite(tempPosX, tempPosY);
            }

            else if (maze->getTileEasy(tempPosX, tempPosY)->getType() == 'd')
            {
                tryOpenDoor(tempPosX, tempPosY);
            }

            if (maze->getTileEasy(tempPosX, tempPosY)->getItem() != nullptr)
            {
                addItem(maze->getTileEasy(tempPosX, tempPosY)->getItem());
            }

            break;

        case 2:
            if (maze->getTileNormal(tempPosX, tempPosY)->getIsPassable() == true)
            {
                Entity::moveSprite(tempPosX, tempPosY);
            }

            else if (maze->getTileNormal(tempPosX, tempPosY)->getType() == 'd')
            {
                tryOpenDoor(tempPosX, tempPosY);
            }

            if (maze->getTileNormal(tempPosX, tempPosY)->getItem() != nullptr)
            {
                addItem(maze->getTileNormal(tempPosX, tempPosY)->getItem());
            }


            break;

        case 3:
            if (maze->getTileHard(tempPosX, tempPosY)->getIsPassable() == true)
            {
                Entity::moveSprite(tempPosX, tempPosY);
            }

            if (maze->getTileHard(tempPosX, tempPosY)->getItem() != nullptr)
            {
                addItem(maze->getTileHard(tempPosX, tempPosY)->getItem());
            }

            else if (maze->getTileHard(tempPosX, tempPosY)->getType() == 'd')
            {
                tryOpenDoor(tempPosX, tempPosY);
            }

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

void Player::useItem(Item* _toUse)
{
    if (_toUse != nullptr)
    {
        switch (_toUse->getType())
        {
            case 'k':
                inventory->removeItem(_toUse);  // deletes the key as it has been used
                delete _toUse;
                break;

            case 'p':

                break;
        }
    }
    return;
}

void Player::addItem(Item* _toAdd)
{
    _toAdd->setIsTaken(true);
    displayNameText(0, maze->getMazeLength() +3, "You picked up ", _toAdd->getName());
    inventory->insertAfter(inventory->getBack(), new Node(_toAdd));
    return;
}

void Player::displayInventory()
{
    set_cursor(0, maze->getMazeLength() + 1);
    clearLines(2);
    set_cursor(0, maze->getMazeLength() + 1);
    inventory->display();
    return;
}

void Player::tryOpenDoor(int _tempX, int _tempY)
{
    if (inventory->searchList('k'))
    {
        int position = inventory->findIndex(new Item("", "", ' ', 0, 0, 'k'));   // getting the position within the inventory where the key is located
        switch (maze->getDifficulty())  // setting the door as passable/open
        {
        case 1:
            maze->getTileEasy(_tempX, _tempY)->setIsPassable(true); 
            break;

        case 2:
            maze->getTileNormal(_tempX, _tempY)->setIsPassable(true);
            break;

        case 3:
            maze->getTileHard(_tempX, _tempY)->setIsPassable(true);
            break;
        }
        
        set_cursor(_tempX, _tempY);
        cout << " ";
        displayText(0, maze->getMazeLength() + 4, "You unlocked the door!");
        displayNameText(0, maze->getMazeLength() + 1, "You used ", inventory->index(position)->getName());
        useItem(inventory->index(position));    // uses key
    }

    else
    {
        displayText(0, maze->getMazeLength() + 4, "This door is locked! You need to find a key to advance.");
    }
}


Enemy* Player::attack()
{
    Enemy* enemy = new Enemy();
    return enemy;
}