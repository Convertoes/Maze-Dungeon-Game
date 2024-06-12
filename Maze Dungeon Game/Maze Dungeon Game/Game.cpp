#include <iostream>
#include <windows.h>
#include "Maze.h"
#include "Game.h"
#include "Item.h"
#include "Player.h"
#include "Enemy.h"
#include "Utility.h"
using namespace std;

Game::Game()		// default constructor
{
	maze = nullptr;
	player = nullptr;
	difficulty = 0;

	for (int i = 0; i < 10; i++)
	{
		monsters[i] = nullptr;
	}

	for (int i = 0; i < 15; i++)
	{
		items[i] = nullptr;
	}
}

Game::~Game() 	// default destructor
{
}

void Game::playGame()
{
	string menuArray[4] = { "Play Game", "Autosolver", "Instructions", "Exit Program" };
	int userInput = 0;
	system("CLS");
	
	do
	{
		userInput = menu("Welcome to the Cryptic Corridors. Will you survive and escape?", menuArray, 4, "Please enter a valid input.");

		switch (userInput)
		{
		case 1:
			initializeGame();
			runGame();
			pauseAndClear();
			break;

		case 2:
			pauseAndClear();
			break;

		case 3:
			pauseAndClear();
			break;

		case 4:
			cout << "Thank you for playing the game. Goodbye." << endl;
			break;
		}

	} while (userInput != 4);

	return;
}

void Game::initializeGame()
{
	initializeDifficulty();
	maze = new Maze(difficulty);

	return;
}

void Game::initializeDifficulty()
{
	string menuArray[3] = {"Easy (15x15)", "Medium (20x20)", "Hard (30x30)"};
	difficulty = menu("Choose a difficulty to play the game", menuArray, 3, "That is not a valid input. Try again.");

	return;
}

void Game::runGame()
{
	maze->displayMaze();
	while ((player->getXCoord() != maze->getEndPosX() or player->getYCoord() != maze->getEndPosY()) or player->getIsAlive())
	{
		player->move();
	}

	cout << "congrats" << endl;

	return;
}