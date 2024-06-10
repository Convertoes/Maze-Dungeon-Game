#include <iostream>
#include <windows.h>
#include "Utility.h"
using namespace std;

Utility::Utility()		// default constructor
{
    difficulty = 0;

    return;
}

Utility::~Utility() 	// default destructor
{
}

void Utility::pauseAndClear()   // clears the screen and waits for user to input something before continuing the program
{
    cout << endl;
    system("pause");
    system("CLS");

    return;
}

void Utility::set_cursor(int x = 0, int y = 0)
{
    HANDLE handle;
    COORD coordinates;
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(handle, coordinates);
    return;
}

int Utility::randomNumb(int range, int offset) // generates a random number within a range with an offset
{
    int randNumb = 0;

    // generating random number
    srand((unsigned)time(NULL)); // generates a new seed 
    randNumb = (rand() % range) + offset;

    return randNumb;
}