#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "Utility.h"
#include "Maze.h"
#include "Item.h"
using namespace std;

class Player;
class Enemy;

class Game : public Utility
{
	public:
		Game(); 	// default constructor
		virtual ~Game(); 	// default destructor

		void startGame();
		void runGame();

	protected:

	private:
		Maze* maze;
		Player* player;
		Enemy* monsters[10];
		Item* items[15];
		int difficulty;
		
		//void initializeGame();
		void initializeDifficulty();

};

#endif // GAME_H