#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "Utility.h"
#include "Maze.h"
#include "Autosolver.h"
#include "Item.h"
#include "Player.h"
#include "Enemy.h"
using namespace std;

class Game : public Utility
{
	public:
		Game(); 	// default constructor
		virtual ~Game(); 	// default destructor

		void playGame();

	protected:

	private:
		Maze* maze;
		Player* player;
		Enemy* monsters[10];
		Item* items[15];
		Autosolver* autosolver;
		int difficulty;
		
		void initializeGame();
		void initializeDifficulty();
		void runGame();
		void displayGame();
		void moveEnemies();

		Item* checkItemCoord();

};

#endif // GAME_H