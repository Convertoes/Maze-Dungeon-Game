#include <iostream>
#include "Maze.h"
#include "Utility.h"
#include "Tile.h"
using namespace std;

Maze::Maze()		// default constructor
{

	return;
}

Maze::Maze() 		// custom construtor
{
    Tile* VW = new Tile ('w', 219, false); // vertical wall
    Tile* HW = new Tile('w', 220, false);  // horizontal wall
    Tile* VD = new Tile('d', 186, false);  // vertical door
    Tile* HD = new Tile('d', 205, false);  // horizontal door
    Tile* FN = new Tile('f', 176, true);    // finish tile
    Tile* SP = new Tile('w', ' ', true); // empty block
    
    if (difficulty == 1)
    {

    }

    else if (difficulty == 2)
    {
        Tile* mazeNormal[20][20] = {
            {HW, HW, HW, HW, HW, HW, HW, HW, HW, HW, HW, HW, HW, HW, HW, HW, HW, HW, HW, HW},
            {VW, SP, SP, SP, SP, SP, SP, SP, SP, VW, SP, SP, SP, SP, SP, VW, SP, SP, SP, VW},
            {VW, SP, VW, SP, VW, SP, HW, HW, HW, VW, SP, HW, HW, HW, SP, VW, HW, HW, SP, VW},
            {VW, SP, VW, SP, VW, SP, SP, SP, SP, SP, SP, VW, SP, SP, SP, SP, SP, VW, SP, VW},
            {VW, SP, VW, SP, VW, HW, HW, SP, HW, HW, HW, VW, HW, HW, HW, HW, SP, SP, SP, VW},
            {VW, SP, SP, SP, VW, SP, SP, SP, SP, VW, SP, SP, SP, SP, SP, VW, SP, VW, SP, VW},
            {VW, HW, HW, HW, VW, SP, HW, HW, HW, VW, HW, HW, SP, VW, SP, VW, SP, VW, SP, VW},
            {VW, SP, SP, SP, VW, SP, VW, SP, SP, SP, SP, VW, SP, VW, SP, VW, SP, VW, SP, VW},
            {VW, SP, VW, SP, VW, SP, VW, SP, HW, HW, HW, VW, SP, VW, SP, VW, SP, VW, SP, VW},
            {VW, SP, SP, SP, VW, SP, VW, SP, VW, FN, FN, SP, SP, VW, SP, VW, SP, VW, SP, VW},
            {VW, SP, HW, HW, VW, SP, VW, SP, VW, FN, FN, HW, HW, VW, SP, VW, SP, VW, SP, VW},
            {VW, SP, VW, SP, SP, SP, VW, SP, VW, HW, HW, VW, SP, VW, SP, SP, SP, VW, SP, VW},
            {VW, SP, VW, SP, VW, SP, VW, SP, SP, SP, SP, SP, SP, VW, SP, VW, SP, VW, SP, VW},
            {VW, SP, SP, SP, VW, HW, VW, SP, HW, HW, HW, HW, HW, VW, SP, VW, HW, VW, SP, VW},
            {VW, SP, VW, SP, VW, SP, SP, SP, SP, SP, VW, SP, SP, SP, SP, VW, SP, SP, SP, VW},
            {VW, SP, VW, SP, SP, SP, HW, HW, HW, SP, VW, HW, HW, HW, HW, VW, SP, VW, SP, VW},
            {VW, HW, VW, SP, VW, SP, SP, SP, SP, SP, VW, SP, SP, SP, SP, VW, SP, VW, SP, VW},
            {VW, SP, SP, SP, VW, HW, HW, HW, SP, HW, VW, SP, HW, HW, SP, VW, SP, VW, SP, VW},
            {VW, SP, SP, SP, VW, SP, SP, SP, SP, SP, SP, SP, SP, SP, SP, VW, SP, SP, SP, VW},
            {VW, HW, HW, HW, VW, HW, HW, HW, HW, HW, HW, HW, HW, HW, HW, VW, HW, HW, HW, VW}
        };


    }

    else if (difficulty == 3)
    {

    }

	return;
}

Maze::~Maze() 	// default destructor
{
}

int Maze::getLength() 
{
	return mazeLength;
}


void Maze::displayMaze()
{
    for (int rows = 0; rows < mazeLength; rows++)
    {
       
        if (difficulty == 1)
        {
            for (int columns = 0; columns < mazeLength; columns++)
            {  
                mazeEasy[rows][columns]->display();
            }
        }
        
        else if (difficulty == 2)
        {
            for (int columns = 0; columns < mazeLength; columns++)
            {
                mazeNormal[rows][columns]->display();
            }
        }

        else if (difficulty == 3)
        {
            for (int columns = 0; columns < mazeLength; columns++)
            {
                mazeHard[rows][columns]->display();
            }
        }

        cout << endl;
    }
}