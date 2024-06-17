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

	protected:

	private:
		Stack* moveList;
		Stack* solutionMoves;
		Maze* maze;
		int xPos;
		int yPos;
		char sprite;

		void moveSprite(int, int);
};

#endif // AUTOSOLVER_H