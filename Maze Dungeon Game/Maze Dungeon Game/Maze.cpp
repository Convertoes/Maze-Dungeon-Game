#include <iostream>
#include "Maze.h"
#include "Utility.h"
#include "Tile.h"
using namespace std;

Maze::Maze()
{
    difficulty = 0;
    mazeLength = 20;
    fogDistance = 4;
    endPosX = 10;
    endPosY = 9;

    char mazeChar[20][20] = {
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
            if (mazeChar[rows][columns] == HW)
            {
                mazeNormal[rows][columns] = new Tile('w', 220, false);  // horizontal wall
            }

            else if (mazeChar[rows][columns] == VW)
            {
                mazeNormal[rows][columns] = new Tile('w', 219, false); // vertical wall
            }

            else if (mazeChar[rows][columns] == VD)
            {
                mazeNormal[rows][columns] = new Tile('d', 186, false);  // vertical door
            }

            else if (mazeChar[rows][columns] == HD)
            {
                mazeNormal[rows][columns] = new Tile('d', 205, false);  // horizontal door
            }

            else if (mazeChar[rows][columns] == FN)
            {
                mazeNormal[rows][columns] = new Tile('f', 176, true);    // finish tile
            }

            else if (mazeChar[rows][columns] == SP)
            {
                mazeNormal[rows][columns] = new Tile(); // empty space
            }

            else if (mazeChar[rows][columns] == BG)
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

    for (int rows = 0; rows < 31; rows++)
    {
        for (int columns = 0; columns < 31; columns++)
        {
            mazeHard[rows][columns] = nullptr;
        }
    }
}

Maze::Maze(int _difficulty)		// default constructor
{
    difficulty = _difficulty;
    
    if (difficulty == 1)
    {
        mazeLength = 15;
        fogDistance = 4;
        startPosX = 1;
        startPosY = 13;
        endPosX = 13;
        endPosY = 2;

        char mazeChar[15][15] = {
            {HW, HW, HW, HW, HW, HW, HW, HW, HW, HW, HW, HW, HW, HW, HW},
            {VW, SP, SP, SP, SP, SP, SP, SP, SP, SP ,SP ,SP, VW, FN, VW},
            {VW, SP, HW, HW, HW, HW, HW, HW, HW, HW, HW, SP, SP, SP, VW},
            {VW, SP, VW, SP, SP, SP, SP, SP, SP, SP, VW, HW, HW, HW, VW},
            {VW, SP, SP, SP, HW, HW, HW, HW, HW, SP, SP, SP, VW, SP, VW},
            {VW, SP, VW, SP, SP, SP, SP, SP, VW, SP, VW, SP, VW, SP, VW},
            {VW, SP, VW, HW, HW, SP, HW, HW, VW, HW, VW, SP, VW, SP, VW},
            {VW, HW, VW, SP, VW, SP, VW, SP, SP, SP, VW, SP, VW, SP, VW},
            {VW, SP, SP, SP, VW, SP, VW, HW, HW, SP, VW, SP, VW, SP, VW},
            {VW, SP, VW, SP, VW, SP, SP, SP, SP, SP, VW, SP, VW, SP, VW},
            {VW, SP, VW, SP, VW, SP, HW, HW, HW, SP, VW, SP, VW, SP, VW},
            {VW, SP, SP, SP, SP, SP, VW, SP, SP, SP, SP, SP, VW, SP, VW},
            {VW, HW, SP, HW, HW, HW, VW, HW, SP, HW, HW, SP, VW, SP, VW},
            {VW, BG, SP, SP, SP, SP, SP, SP, SP, VW ,SP ,SP, SP, SP, VW},
            {VW, HW, HW, HW, HW, HW, HW, HW, HW, VW, HW, HW, HW, HW, VW}
        };

        for (int rows = 0; rows < mazeLength; rows++)
        {
            for (int columns = 0; columns < mazeLength; columns++)
            {
                if (mazeChar[rows][columns] == HW)
                {
                    mazeEasy[rows][columns] = new Tile('w', 220, false);  // horizontal wall
                }

                else if (mazeChar[rows][columns] == VW)
                {
                    mazeEasy[rows][columns] = new Tile('w', 219, false); // vertical wall
                }

                else if (mazeChar[rows][columns] == VD)
                {
                    mazeEasy[rows][columns] = new Tile('d', 186, false);  // vertical door
                }

                else if (mazeChar[rows][columns] == HD)
                {
                    mazeEasy[rows][columns] = new Tile('d', 205, false);  // horizontal door
                }

                else if (mazeChar[rows][columns] == FN)
                {
                    mazeEasy[rows][columns] = new Tile('f', 176, true);    // finish tile
                }

                else if (mazeChar[rows][columns] == SP)
                {
                    mazeEasy[rows][columns] = new Tile('w', ' ', true); // empty block
                }

                else if (mazeChar[rows][columns] == BG)
                {
                    mazeEasy[rows][columns] = new Tile('b', ' ', true); // beginning
                }
            }
        }

        for (int rows = 0; rows < 20; rows++)
        {
            for (int columns = 0; columns < 20; columns++)
            {
                mazeNormal[rows][columns] = nullptr;
            }
        }

        for (int rows = 0; rows < 31; rows++)
        {
            for (int columns = 0; columns < 31; columns++)
            {
                mazeHard[rows][columns] = nullptr;
            }
        }
    }

    else if (difficulty == 2)
    {
        mazeLength = 20;
        fogDistance = 3;
        startPosX = 1;
        startPosY = 18;
        endPosX = 10;
        endPosY = 9;

        char mazeChar[20][20] = {
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
                if (mazeChar[rows][columns] == HW)
                {
                    mazeNormal[rows][columns] = new Tile('w', 220, false);  // horizontal wall
                }

                else if (mazeChar[rows][columns] == VW)
                {
                    mazeNormal[rows][columns] = new Tile('w', 219, false); // vertical wall
                }

                else if (mazeChar[rows][columns] == VD)
                {
                    mazeNormal[rows][columns] = new Tile('d', 186, false);  // vertical door
                }

                else if (mazeChar[rows][columns] == HD)
                {
                    mazeNormal[rows][columns] = new Tile('d', 205, false);  // horizontal door
                }

                else if (mazeChar[rows][columns] == FN)
                {
                    mazeNormal[rows][columns] = new Tile('f', 176, true);    // finish tile
                }

                else if (mazeChar[rows][columns] == SP)
                {
                    mazeNormal[rows][columns] = new Tile('w', ' ', true); // empty block
                }

                else if (mazeChar[rows][columns] == BG)
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

        for (int rows = 0; rows < 31; rows++)
        {
            for (int columns = 0; columns < 31; columns++)
            {
                mazeHard[rows][columns] = nullptr;
            }
        }
    }

    else if (difficulty == 3)
    {

    }
}

Maze::~Maze() 	// default destructor
{
}

int Maze::getStartPosX()
{
    return startPosX;
}

int Maze::getStartPosY()
{
    return startPosY;
}

int Maze::getEndPosX()
{
    return endPosX;
}

int Maze::getEndPosY()
{
    return endPosY;
}

int Maze::getDifficulty()
{
    return difficulty;
}

Tile* Maze::getTileEasy(int _x, int _y)
{
    return mazeEasy[_y][_x];
}

Tile* Maze::getTileNormal(int _x, int _y)
{
    return mazeNormal[_y][_x];
}

Tile* Maze::getTileHard(int _x, int _y)
{
    return mazeHard[_y][_x];
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