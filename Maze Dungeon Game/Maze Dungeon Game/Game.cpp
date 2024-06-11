#include <iostream>
#include "Maze.h"
#include "Game.h"
#include "Utility.h"
using namespace std;

Game::Game()		// default constructor
{
	maze = nullptr;
	player = nullptr;

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

void Game::startGame()
{
	initializeDifficulty();
	maze = new Maze(difficulty);
	runGame();

	return;
}

void Game::runGame()
{
	cout << difficulty;
	maze->displayMaze();
	return;
}

void Game::initializeDifficulty()
{
	string menuArray[3] = { "Easy", "Medium", "Hard" };

	difficulty = menu("Choose a difficulty to play the game", menuArray, 3, "That is not a valid input. Try again.");

	return;
}