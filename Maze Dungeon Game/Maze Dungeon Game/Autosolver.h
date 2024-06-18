#ifndef AUTOSOLVER_H
#define AUTOSOLVER_H
#include <iostream>
#include "Utility.h"
#include "Maze.h"
#include "Stack.h"
#include "Container.h"
using namespace std;

class Autosolver : public Utility
{
	public:
		Autosolver(); 	// default constructor
		Autosolver(Maze*, int, int, char); 	// custom constructor
		virtual ~Autosolver(); 	// default destructor

		void solveMaze();
		void display();
		int getXPos();
		int getYPos();

	protected:

	private:
		Stack* moveList;
		Stack* lastMoves;
		Maze* maze;
		int xPos;
		int yPos;
		char sprite;

		void moveSprite(int, int);
		void loadStack();
};

#endif // AUTOSOLVER_H