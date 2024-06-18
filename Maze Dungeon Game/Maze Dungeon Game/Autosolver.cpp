#include <iostream>
#include "Autosolver.h"
using namespace std;

Autosolver::Autosolver()		// default constructor
{
	moveList = nullptr;
	lastMoves = nullptr;
}

Autosolver::Autosolver(Maze* _maze, int _x, int _y, char _sprite)		// custom constructor
{
	moveList = new Stack();
	lastMoves = new Stack();
	maze = _maze;
	xPos = _x;
	yPos = _y;
	sprite = _sprite;
}

Autosolver::~Autosolver() 	// default destructor
{
}

void Autosolver::solveMaze()
{
	do
	{
		loadStack();

		bool isBackTracking = false;
		bool didMove = false;
		while (isBackTracking == false or didMove == false)
		{
			switch (moveList->peek())
			{
				case 'u':
					if (maze->getTileNormal(xPos, yPos - 1)->getIsPassable())
					{
						lastMoves->push(moveList->pop());
						didMove = true;
					}
					break;

				case 'd':
					if (maze->getTileNormal(xPos, yPos + 1)->getIsPassable())
					{
						lastMoves->push(moveList->pop());
						didMove = true;
					}
					break;

				case 'r':
					if (maze->getTileNormal(xPos + 1, yPos)->getIsPassable())
					{
						lastMoves->push(moveList->pop());
						didMove = true;
					}
					break;

				case 'l':
					if (maze->getTileNormal(xPos - 1, yPos)->getIsPassable())
					{
						lastMoves->push(moveList->pop());
						didMove = true;
					}
					break;

				case 'b':
					lastMoves->push(moveList->pop());
					isBackTracking = true;
					break;
			}

			if (isBackTracking)
			{
				
			}
		}

	} while (xPos != maze->getEndPosX() or yPos != maze->getEndPosY());

}

void Autosolver::display()
{
	set_cursor(xPos, yPos);
	cout << sprite;
	set_cursor(0, maze->getMazeLength());	// returns cursor to the default console location

	return;
}

int Autosolver::getXPos()
{
	return xPos;
}

int Autosolver::getYPos()
{
	return yPos;
}

void Autosolver::moveSprite(int _tempX, int _tempY)	// moves the character by one space, called from subclasses
{
	set_cursor(xPos, yPos);
	cout << ' ';

	xPos = _tempX;
	yPos = _tempY;

	display();

	return;
}

void Autosolver::loadStack()
{
	switch (lastMoves->peek())
	{
		case 'u':
			moveList->push('b');
			moveList->push('d');
			moveList->push('u');
			moveList->push('l');
			moveList->push('r');
			break;

		case 'd':
			moveList->push('b');
			moveList->push('u');
			moveList->push('d');
			moveList->push('l');
			moveList->push('r');
			break;

		case 'r':
			moveList->push('b');
			moveList->push('l');
			moveList->push('r');
			moveList->push('d');
			moveList->push('u');
			break;

		case 'l':
			moveList->push('b');
			moveList->push('r');
			moveList->push('l');
			moveList->push('d');
			moveList->push('u');
			break;

		default:
			moveList->push('b');
			moveList->push('l');
			moveList->push('r');
			moveList->push('d');
			moveList->push('u');
			break;
	}

	return;
}