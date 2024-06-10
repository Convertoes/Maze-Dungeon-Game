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
        for (int columns = 0; columns < mazeLength; columns++)
        {
            if (difficulty == 1)
            {
                cout << mazeEasy[rows][columns];
            }

            else if (difficulty == 2)
            {
                cout << mazeNormal[rows][columns];
            }

            else if (difficulty == 3)
            {
                cout << mazeHard[rows][columns];
            }
        }

        cout << endl;
    }
}