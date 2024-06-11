#include <iostream>
#include "Maze.h"
#include "Utility.h"
#include "Tile.h"
using namespace std;

static const char VW = 219;
static const char HW = 220;
static const char VD = 186;
static const char HD = 205;
static const char FN = 176;
static const char SP = ' ';
static const char BG = ' ';

Maze::Maze()
{
    mazeLength = 20;
    fogDistance = 4;
    endPosX = 10;
    endPosY = 9;

    char mazeNormalChar[20][20] = {
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
        {VW, BG, SP, SP, VW, SP, SP, SP, SP, SP, SP, SP, SP, SP, SP, VW, SP, SP, SP, VW},
        {VW, HW, HW, HW, VW, HW, HW, HW, HW, HW, HW, HW, HW, HW, HW, VW, HW, HW, HW, VW}
    };

    for (int rows = 0; rows < mazeLength; rows++)
    {
        for (int columns = 0; columns < mazeLength; columns++)
        {
            if (mazeNormalChar[rows][columns] == HW)
            {
                mazeNormal[rows][columns] = new Tile('w', 220, false);  // horizontal wall
            }

            else if (mazeNormalChar[rows][columns] == VW)
            {
                mazeNormal[rows][columns] = new Tile('w', 219, false); // vertical wall
            }

            else if (mazeNormalChar[rows][columns] == VD)
            {
                mazeNormal[rows][columns] = new Tile('d', 186, false);  // vertical door
            }

            else if (mazeNormalChar[rows][columns] == HD)
            {
                mazeNormal[rows][columns] = new Tile('d', 205, false);  // horizontal door
            }

            else if (mazeNormalChar[rows][columns] == FN)
            {
                mazeNormal[rows][columns] = new Tile('f', 176, true);    // finish tile
            }

            else if (mazeNormalChar[rows][columns] == SP)
            {
                mazeNormal[rows][columns] = new Tile('w', ' ', true); // empty block
            }

            else if (mazeNormalChar[rows][columns] == BG)
            {
                mazeNormal[rows][columns] = new Tile('b', ' ', true); // beginning
            }
        }

    }

    for (int rows = 0; rows < 15; rows++)
    {
        for (int columns = 0; columns < 15; columns++)
        {
            mazeEasy[rows][columns] = nullptr;
        }
    }

    for (int rows = 0; rows < 30; rows++)
    {
        for (int columns = 0; columns < 30; columns++)
        {
            mazeEasy[rows][columns] = nullptr;
        }
    }
}

Maze::Maze(int _difficulty)		// default constructor
{
 
    if (_difficulty == 1)
    {

    }

    else if (_difficulty == 2)
    {
        mazeLength = 20;
        fogDistance = 4;
        endPosX = 10;
        endPosY = 9;

        char mazeNormalChar[20][20] = {
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
            {VW, BG, SP, SP, VW, SP, SP, SP, SP, SP, SP, SP, SP, SP, SP, VW, SP, SP, SP, VW},
            {VW, HW, HW, HW, VW, HW, HW, HW, HW, HW, HW, HW, HW, HW, HW, VW, HW, HW, HW, VW}
        };

        for (int rows = 0; rows < mazeLength; rows++)
        {
            for (int columns = 0; columns < mazeLength; columns++)
            {
                if (mazeNormalChar[rows][columns] == HW)
                {
                    mazeNormal[rows][columns] = new Tile('w', 220, false);  // horizontal wall
                }

                else if (mazeNormalChar[rows][columns] == VW)
                {
                    mazeNormal[rows][columns] = new Tile('w', 219, false); // vertical wall
                }

                else if (mazeNormalChar[rows][columns] == VD)
                {
                    mazeNormal[rows][columns] = new Tile('d', 186, false);  // vertical door
                }

                else if (mazeNormalChar[rows][columns] == HD)
                {
                    mazeNormal[rows][columns] = new Tile('d', 205, false);  // horizontal door
                }

                else if (mazeNormalChar[rows][columns] == FN)
                {
                    mazeNormal[rows][columns] = new Tile('f', 176, true);    // finish tile
                }

                else if (mazeNormalChar[rows][columns] == SP)
                {
                    mazeNormal[rows][columns] = new Tile('w', ' ', true); // empty block
                }

                else if (mazeNormalChar[rows][columns] == BG)
                {
                    mazeNormal[rows][columns] = new Tile('b', ' ', true); // beginning
                }
            }

        }

        for (int rows = 0; rows < 15; rows++)
        {
            for (int columns = 0; columns < 15; columns++)
            {
                mazeEasy[rows][columns] = nullptr;
            }
        }

        for (int rows = 0; rows < 30; rows++)
        {
            for (int columns = 0; columns < 30; columns++)
            {
                mazeHard[rows][columns] = nullptr;
            }
        }
    }

    else if (_difficulty == 3)
    {

    }
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
    if (difficulty == 1)
    {
        for (int rows = 0; rows < mazeLength; rows++)
        {
            for (int columns = 0; columns < mazeLength; columns++)
            {
                mazeEasy[rows][columns]->display();
            }

            cout << endl;
        }
    }

    else if (difficulty == 2)
    {
        cout << "test" << endl;
        for (int rows = 0; rows < mazeLength; rows++)
        {

            for (int columns = 0; columns < mazeLength; columns++)
            {
                mazeNormal[rows][columns]->display();
            }

            cout << endl;
        }
    }

    else if (difficulty == 3)
    {
        for (int rows = 0; rows < mazeLength; rows++)
        {

            for (int columns = 0; columns < mazeLength; columns++)
            {
                mazeHard[rows][columns]->display();
            }

            cout << endl;
        }
    }
}