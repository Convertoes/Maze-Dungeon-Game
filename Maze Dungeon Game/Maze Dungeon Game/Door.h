#ifndef DOOR_H
#define DOOR_H
#include <iostream>
#include "Tile.h"
#include "Item.h"
using namespace std;

class Door : public Tile
{
	public:
		Door(); 	// default constructor
		Door(string, char, char, bool, Item*);	// custom constructor with parent's constructor
		virtual ~Door(); 	// default destructor

		bool getIsPassable();
		void setIsPassable(bool);
		void display();

	protected:

	private:
		bool isOpen;
		string colour;
};

#endif // DOOR_H