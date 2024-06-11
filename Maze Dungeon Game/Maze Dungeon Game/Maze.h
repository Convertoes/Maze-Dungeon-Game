#ifndef MAZE_H
#define MAZE_H
#include <iostream>
#include "Utility.h"
#include "Tile.h"
using namespace std;

class Maze : public Utility
{
	public:
		Maze(); 	// default constructor
		Maze();	// custom constructor
		virtual ~Maze(); 	// default destructor
/*
		Tile* mazeEasy[15][15];
		Tile* mazeNormal[20][20];
		Tile* mazeHard[30][30];
*/
		void displayMaze();
		int getLength();

	protected:

	private:
		int mazeLength;
		int fogDistance;
		int endPosX;
		int endPosY;

};

#endif // MAZE_H