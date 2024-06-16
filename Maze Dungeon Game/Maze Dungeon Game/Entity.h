#ifndef ENTITY_H
#define ENTITY_H
#include <iostream>
#include "Utility.h"
#include "Maze.h"
using namespace std;

class Entity : public Utility
{
	public:
		Entity(); 	// default constructor
		Entity(Maze*, int, int, string, float, float, float, char, string);	// custom constructor with parent's constructor
		virtual ~Entity(); 	// default destructor

		bool getIsAlive();
		int getXCoord();
		int getYCoord();
		string getName();
		float getHealth();
		float getStrength();
		float getDefense();
		void display(bool);

	protected:
		Maze* maze;
		int xCoord;
		int yCoord;
		string name;
		float health;
		float strength;
		float defense;
		char sprite;
		string colour;

		void moveSprite(int, int);
		bool checkIsAlive();

	private:
		
};

#endif // ENTITY_H