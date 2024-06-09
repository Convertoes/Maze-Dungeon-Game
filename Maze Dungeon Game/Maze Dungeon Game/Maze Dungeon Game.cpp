// windows with menu
// Author: Alex Larochette
// Project:
// Description:
// Created:
// Modified:

// ============================= libraries ========================================================================================================

#include <iostream>
#include <windows.h>
using namespace std;

// ============================= function prototypes ==============================================================================================

int menu(string, string[], int, string);
void pauseAndClear();

// ============================= functions definitions ========================================================================================================

int menu(string title, string menuArray[], int menuSize, string errorMessage) // generic menu function
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

void pauseAndClear() // clears the screen and waits for user to input something before continuing the program
{
	cout << endl;
	system("pause");
	system("CLS");

	return;
}

// ============================= main =============================================================================================================

int main()
{
	int userInput = 0;
	string menuArray[6] = { "Start New Game", "Autosolve Maze", "Information", "", "Quit Program"};
	system("CLS");

	do
	{
		userInput = menu("", menuArray, 2, "Please enter a valid input.");

		switch (userInput)
		{
		case 1:
			pauseAndClear();
			break;

		case 2:
			cout << "Thank you for using this program. Goodbye." << endl;
			break;
		}

	} while (userInput != 2);

	return 0;
}