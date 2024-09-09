#include <iostream>
#include "Autosolver.h"
#include "Windows.h"
#include "conio.h"
#include "List.h"
using namespace std;

Autosolver::Autosolver()		// default constructor
{
	moveList = nullptr;
	mazePrevMoves = nullptr;
	keyBackTrack = nullptr;
}

Autosolver::Autosolver(Maze* _maze, int _x, int _y, char _sprite)		// custom constructor
{
	moveList = new Stack();
	mazePrevMoves = new Stack();
	keyBackTrack = new Stack();
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
		set_cursor(0, maze->getMazeLength() + 5);
		clearLines(1);
		moveList->display();
		char getch = _getch();

		bool isBackTracking = false;
		bool didMove = false;
		while (isBackTracking == false && didMove == false)
		{
			char direction = moveList->pop();
			int tempX = xPos;
			int tempY = yPos;
			
			switch (direction)
			{
				case 'u':
					tempY--;
					break;

				case 'd':
					tempY++;
					break;

				case 'r':
					tempX++;
					break;

				case 'l':
					tempX--;
					break;
			}

			if (maze->getTileNormal(tempX, tempY)->getIsPassable())
			{
				mazePrevMoves->push(opposite(moveList->peek()));
				moveSprite(tempX, tempY);
				maze->getTileNormal(tempX, tempY)->setIsCrumb(true);
				didMove = true;
			}

			else if (direction == mazePrevMoves->peek())
			{
				isBackTracking = true;
			}

			if (maze->getTileNormal(tempX, tempY)->getItem() != nullptr)
			{
				inventory->insertAfterItem(nullptr, maze->getTileNormal(tempX, tempY)->getItem());
				maze->getTileNormal(tempX, tempY)->getItem()->setIsTaken(true);
			}
		}

		if (isBackTracking)
		{
			backTrackFunc();
		}


	} while (xPos != maze->getEndPosX() or yPos != maze->getEndPosY());

	return;
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
	cout << '.';

	xPos = _tempX;
	yPos = _tempY;

	display();

	return;
}

void Autosolver::loadStack()
{
	switch (mazePrevMoves->peek())
	{
		case 'd':
			moveList->push('d');
			moveList->push('u');
			moveList->push('l');
			moveList->push('r');
			break;

		case 'u':
			moveList->push('u');
			moveList->push('d');
			moveList->push('l');
			moveList->push('r');
			break;

		case 'l':
			moveList->push('l');
			moveList->push('r');
			moveList->push('d');
			moveList->push('u');
			break;

		case 'r':
			moveList->push('r');
			moveList->push('l');
			moveList->push('d');
			moveList->push('u');
			break;

		case 'e':
			moveList->push('l');
			moveList->push('r');
			moveList->push('d');
			moveList->push('u');
			break;
	}

	return;
}

void Autosolver::backTrackFunc()
{
	bool didMove = false;
	while (didMove == false)
	{
		char direction = moveList->peek();
		char checkBack = mazePrevMoves->peek();
		int tempX = xPos;
		int tempY = yPos;

		switch (direction)
		{
		case 'u':
			tempY--;
			break;

		case 'd':
			tempY++;
			break;

		case 'r':
			tempX++;
			break;

		case 'l':
			tempX--;
			break;
		}

		if (direction == checkBack)
		{
			mazePrevMoves->pop();
			moveSprite(tempX, tempY);
		}

		else if (maze->getTileNormal(tempX, tempY)->getIsPassable())
		{
			moveList->pop();
			mazePrevMoves->push(direction);
			moveSprite(tempX, tempY);
			maze->getTileNormal(tempX, tempY)->setIsCrumb(true);
			didMove = true;
		}
	}

	return;
}

char Autosolver::opposite(char _original)
{
	switch (_original)
	{
	case 'u':
		return 'd';
		break;

	case 'd':
		return 'u';
		break;

	case 'r':
		return 'l';
		break;

	case 'l':
		return 'r';
		break;
	}
}