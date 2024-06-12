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
		Maze(int);	// custom constructor
		virtual ~Maze(); 	// default destructor

		void displayMaze(int);
		int getEndPosX();
		int getEndPosY();

	protected:

	private:
		int mazeLength;
		int fogDistance;
		int endPosX;
		int endPosY;

		Tile* mazeNormal[20][20];
		Tile* mazeEasy[15][15];
		Tile* mazeHard[31][31];
};

#endif // MAZE_H