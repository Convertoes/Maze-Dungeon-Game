#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "Utility.h"
#include "Maze.h"
#include "Player.h"
#include "Enemy.h"
#include "Item.h"
using namespace std;

class Game : public Utility
{
	public:
		Game(); 	// default constructor
		Game();	// custom constructor
		virtual ~Game(); 	// default destructor

		void startGame();
		void runGame();

	protected:

	private:
		Maze* mazes[3];
		
		void initializeGame();
		void initializeDifficulty();

};

#endif // GAME_H