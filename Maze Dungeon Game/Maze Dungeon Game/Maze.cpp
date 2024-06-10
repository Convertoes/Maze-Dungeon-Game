#include <iostream>
#include "Maze.h"
#include "Utility.h"
using namespace std;

Maze::Maze()		// default constructor
{

	return;
}

Maze::Maze() 		// custom construtor
{
    Tile* VWL = new Tile ('w', 219, false); // vertical wall
    Tile* HWL = new Tile('w', 220, false);  // horizontal wall
    Tile* SPC = new Tile('w', ' ', true); // empty block
    
    if (difficulty == 1)
    {

    }

    else if (difficulty == 2)
    {
        
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