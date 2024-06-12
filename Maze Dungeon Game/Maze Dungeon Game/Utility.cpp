#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Utility.h"
using namespace std;

Utility::Utility()		// default constructor
{
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

int Utility::menu(string title, string menuArray[], int menuSize, string errorMessage) // generic menu function
{
	int userInput = 0;

	do
	{
		cout << title << endl;
		cout << endl;

		for (int i = 0; i < menuSize; i++)
		{
			cout << i + 1 << ") " << menuArray[i] << endl;
		}

		cout << endl;
		cout << endl << "Input: ";
		cin >> userInput;
		pauseAndClear();


		if (userInput < 1 or userInput > menuSize)
		{
			cout << errorMessage << endl;

			pauseAndClear();
		}


	} while (userInput < 1 or userInput > menuSize);

	return userInput;
}