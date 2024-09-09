#ifndef AUTOSOLVER_H
#define AUTOSOLVER_H
#include <iostream>
#include "Utility.h"
#include "Maze.h"
#include "Stack.h"
#include "List.h"
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
		Stack* mazePrevMoves;
		Stack* keyBackTrack;
		Maze* maze;
		List* inventory;
		int xPos;
		int yPos;
		char sprite;

		void moveSprite(int, int);
		void loadStack();
		void backTrackFunc();
		char opposite(char);
};

#endif // AUTOSOLVER_H