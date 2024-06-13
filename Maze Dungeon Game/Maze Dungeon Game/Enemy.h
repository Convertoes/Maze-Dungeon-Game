#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include "Entity.h"
#include "Player.h"
#include "Maze.h"
using namespace std;

class Enemy : public Entity
{
	public:
		Enemy(); 	// default constructor
		Enemy(Player*, Maze*, int, int, string, float, float, float, char);	// custom constructor with parent's constructor
		virtual ~Enemy(); 	// default destructor

		Player* getPlayer();

	protected:

	private:
		Player* player;

		void move();
};

#endif // ENEMY_H