#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "Entity.h"
#include "Item.h"
#include "List.h"
using namespace std;

class Enemy;	// forward declaring enemy

class Player : public Entity
{
	public:
		Player(); 	// default constructor
		Player(Maze*, int, int, string, float, float, float, char);	// custom constructor with parent's constructor
		virtual ~Player(); 	// default destructor

		void move();
		List* getInventory();
		bool getHasKey();
		void useItem(Item*);
		void addItem(Item*);
		void displayInventory();

		Enemy* attack();

	protected:

	private:
		List* inventory;
		bool hasKey;

};

#endif // PLAYER_H