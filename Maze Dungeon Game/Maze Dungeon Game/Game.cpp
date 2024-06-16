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
			system("CLS");
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
	switch (difficulty)
	{
		case 1:
			player = new Player(maze, maze->getStartPosX(), maze->getStartPosY(), "Player", 150, 15, 15, 153, "\033[36m");
			items[0] = new Item("Key1", "\033[33m", 232, 13, 4, 'k');
			break;

		case 2:
			player = new Player(maze, maze->getStartPosX(), maze->getStartPosY(), "Player", 100, 10, 10, 153, "\033[32m");
			items[0] = new Item("Key1", "\033[33m", 232, 1, 5, 'k');
			items[1] = new Item("Key2", "\033[33m", 232, 17, 18, 'k');
			break;

		case 3:

			break;
	}

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
	displayGame();
	do
	{
		player->displayInventory();
		player->move();
		Item* checkItem = checkItemCoord();
		if (checkItem != nullptr)
		{
			player->addItem(checkItem);
		}
		
	} while ((player->getXCoord() != maze->getEndPosX() or player->getYCoord() != maze->getEndPosY()) or player->getIsAlive() == false);

	displayText(0, maze->getMazeLength() + 1, "You beat the game! Congratulations!");

	return;
}

void Game::displayGame()
{
	maze->displayMaze();
	player->display(maze->getStartPosX(), maze->getStartPosY());
	for (int i = 0; i < 15; i++)
	{
		if (items[i] != nullptr)
		{
			if (items[i]->getIsTaken() == false)	// if they aren't taken, they will get displayed
			{ 
				items[i]->display(false);
			}
		}
	}

	return;
}

Item* Game::checkItemCoord()  // checks if the player's coordinates match any of items on the map
{
	for (int i = 0; i < 15; i++)
	{
		if (items[i] != nullptr)
		{
			if (items[i]->getXPos() == player->getXCoord() and items[i]->getYPos() == player->getYCoord() and items[i]->getIsTaken() == false)
			{
				return items[i];
			}
		}
	}

	return nullptr;
}