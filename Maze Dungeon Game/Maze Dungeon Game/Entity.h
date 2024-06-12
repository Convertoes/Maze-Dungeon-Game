#ifndef ENTITY_H
#define ENTITY_H
#include <iostream>
#include "Utility.h"
using namespace std;

class Entity : public Utility
{
	public:
		Entity(); 	// default constructor
		Entity(int, int, string, float, float, float, char);	// custom constructor with parent's constructor
		virtual ~Entity(); 	// default destructor


	protected:
		int xCoord;
		int yCoord;
		string name;
		float health;
		float strength;
		float defense;
		char sprite;

		bool getIsAlive();

	private:
		virtual void move(int, int);
		bool checkIsAlive();
};

#endif // ENTITY_H