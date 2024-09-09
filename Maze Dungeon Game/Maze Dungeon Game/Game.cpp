#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Maze.h"
#include "Game.h"
#include "Autosolver.h"
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

	autosolver = nullptr;
}

Game::~Game() 	// default destructor
{
}

void Game::playGame()
{
	string menuArray[3] = { "Play Game", "Autosolver", "Exit Program" };
	int userInput = 0;
	system("CLS");
	
	do
	{
		userInput = menu("Welcome to the Cryptic Corridors. Will you survive and escape?", menuArray, 3, "Please enter a valid input.");

		switch (userInput)
		{
		case 1:
			initializeGame();
			runGame();
			system("CLS");
			break;

		case 2:
			initializeAutosolver();
			runAutosolver();
			pauseAndClear();
			break;

		case 3:
			cout << "Thank you for playing the game. Goodbye." << endl;
			break;
		}

	} while (userInput != 3);

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
			maze->getTileEasy(13, 4)->setItem(items[0]);
			monsters[0] = new Enemy(player, maze, 8, 1, "Ogre", 80, 10, 20, 225, "\033[31m");
			break;

		case 2:
			player = new Player(maze, maze->getStartPosX(), maze->getStartPosY(), "Player", 125, 20, 15, 153, "\033[32m");
			items[0] = new Item("Key1", "\033[33m", 232, 1, 5, 'k');
			maze->getTileNormal(1, 5)->setItem(items[0]);
			items[1] = new Item("Key2", "\033[33m", 232, 17, 18, 'k');
			maze->getTileNormal(17, 18)->setItem(items[1]);
			monsters[0] = new Enemy(player, maze, 1, 4, "Golem 1", 80, 10, 20, 225, "\033[31m");
			monsters[1] = new Enemy(player, maze, 2, 5, "Golem 2", 80, 10, 20, 225, "\033[31m");
			monsters[2] = new Enemy(player, maze, 12, 11, "Bat", 40, 5, 5, 238, "\033[31m");
			monsters[3] = new Enemy(player, maze, 18, 13, "Dungeon Guardian", 100, 20, 10, 157, "\033[31m");
			break;

		case 3:
			player = new Player(maze, maze->getStartPosX(), maze->getStartPosY(), "Player", 100, 10, 10, 153, "\033[90m");

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
		Enemy* enemy = checkEnemies();
		if (enemy != nullptr)
		{
			combat(enemy);

			if (player->getIsAlive())
			{
				displayGame();
			}
		}
		
	} while ((player->getXCoord() != maze->getEndPosX() or player->getYCoord() != maze->getEndPosY()) and player->getIsAlive());

	if (player->getIsAlive())
	{
		displayText(0, maze->getMazeLength() + 1, "You beat the game! Congratulations!");
	}

	else
	{
		displayText(0, 0, "You were killed by an enemy! PLease try again.");
	}

	return;
}

void Game::displayGame()
{
	maze->displayMaze();
	player->display(false);
	for (int i = 0; i < 10; i++)
	{
		if (monsters[i] != nullptr and monsters[i]->getIsAlive())
		{
			monsters[i]->display(false);
		}
	}

	for (int i = 0; i < 15; i++)
	{
		if (items[i] != nullptr and items[i]->getIsTaken() == false)
		{
			items[i]->display(false);
		}
	}

	return;
}

Enemy* Game::checkEnemies()
{
	for (int i = 0; i < 10; i++)
	{
		if (monsters[i] != nullptr)
		{
			if (monsters[i]->getIsAlive())
			{
				if (monsters[i]->getXCoord() == player->getXCoord() and monsters[i]->getYCoord() == player->getYCoord())
				{
					return monsters[i];
				}
			}
		}
	}

	return nullptr;
}

void Game::runAutosolver()
{
	maze->displayMaze();
	for (int i = 0; i < 15; i++)
	{
		if (items[i] != nullptr)
		{
			items[i]->display(false);
		}
	}
	autosolver->display();
	autosolver->solveMaze();

	return;
}

void Game::initializeAutosolver()
{
	maze = new Maze(2);	// creates a maze with normal difficulty
	autosolver = new Autosolver(maze, maze->getStartPosX(), maze->getStartPosY(), 233);
	items[0] = new Item("Key1", "\033[33m", 232, 1, 5, 'k');
	items[1] = new Item("Key2", "\033[33m", 232, 17, 18, 'k');

	return;
}

void Game::combat(Enemy* _enemy)
{
	do
	{
		system("CLS");
		
		cout << "Combat! \n" << endl;
		cout << player->getName() << ": " << endl;
		cout << "\033[32m" << "Health: " << player->getHealth() << RESET << endl;
		cout << "\033[31m" << "Strength " << player->getStrength() << RESET << endl;
		cout << "\033[90m" << "Defense " << player->getDefense() << RESET << endl;
		cout << endl;

		cout << _enemy->getName() << ": " << endl;
		cout << "\033[32m" << "Health: " << _enemy->getHealth() << RESET << endl;
		cout << "\033[31m" << "Strength " << _enemy->getStrength() << RESET << endl;
		cout << "\033[90m" << "Defense " << _enemy->getDefense() << RESET << endl;
		cout << endl;
		
		_enemy->setHealth(_enemy->getHealth() - (player->getStrength() - _enemy->getDefense() / 2));
		player->setHealth(player->getHealth() - (_enemy->getStrength() - player->getDefense() / 2));

		char getch = _getch();

	} while (player->getIsAlive() and _enemy->getIsAlive());

	system("CLS");
	
	if (player->getIsAlive())
	{
		cout << "You killed the " << _enemy->getName() << "!" << endl;
		player->setHealth(100);
	}

	else
	{
		cout << "You were killed by the " << _enemy->getName() << "!" << endl;
	}

	system("CLS");

	return;
}