#include <iostream>
#include "Autosolver.h"
using namespace std;

Autosolver::Autosolver()		// default constructor
{
	moveList = nullptr;
	solutionMoves = nullptr;
}

Autosolver::Autosolver(Maze* _maze, int _x, int _y, char _sprite)		// custom constructor
{
	moveList = nullptr;
	solutionMoves = nullptr;
}

Autosolver::~Autosolver() 	// default destructor
{
}

void Autosolver::solveMaze()
{
	switch (maze->getDifficulty())
	{
		case 1:


			break;

		case 2:


			break;

		case 3:


			break;
	}
}

void Autosolver::display()
{
	set_cursor(xPos, yPos);
	cout << sprite;
	set_cursor(0, maze->getMazeLength());	// returns cursor to the default console location

	return;
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