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

void Utility::clearLines(int _numbOfLines)	// manually clears a number of lines
{
	if (_numbOfLines > 0)
	{
		for (int i = 0; i < _numbOfLines; i++)
		{
			cout << "                                                                                                   " << endl;
		}
	}

	return;
}

void Utility::displayText(int _x, int _y, string _message)
{
	set_cursor(_x, _y);
	clearLines(2);
	set_cursor(_x, _y);
	cout << _message << endl;
	system("pause");
	set_cursor(_x, _y);
	clearLines(2);
	return;
}

void Utility::displayNameText(int _x, int _y, string _message, string _name)
{
	set_cursor(_x, _y);
	clearLines(2);
	set_cursor(_x, _y);
	cout << _message << _name << endl;
	system("pause");
	set_cursor(_x, _y);
	clearLines(2);
	return;
}

const string Utility::RESET = "\033[0m";