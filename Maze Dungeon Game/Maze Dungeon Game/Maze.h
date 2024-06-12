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

		void displayMaze();
		int getStartPosX();
		int getStartPosY();
		int getEndPosX();
		int getEndPosY();
		int getDifficulty();
		Tile* getTileEasy(int, int);
		Tile* getTileNormal(int, int);
		Tile* getTileHard(int, int);

	protected:

	private:
		int mazeLength;
		int fogDistance;
		int startPosX;
		int startPosY;
		int endPosX;
		int endPosY;
		int difficulty;

		Tile* mazeNormal[20][20];
		Tile* mazeEasy[15][15];
		Tile* mazeHard[31][31];
};

#endif // MAZE_H