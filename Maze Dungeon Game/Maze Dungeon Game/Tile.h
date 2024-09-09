#ifndef TILE_H
#define TILE_H
#include <iostream>
#include "Utility.h"
#include "Item.h"
using namespace std;

class Item;		// forward declaring class item

class Tile : public Utility
{
	public:
		Tile(); 	// default constructor
		Tile(char, char, bool, Item*);	// custom constructor
		virtual ~Tile(); 	// default destructor

		char getType();
		virtual bool getIsPassable();
		virtual void setIsPassable(bool);
		bool getIsCrumb();
		void setIsCrumb(bool);
		Item* getItem();
		void setItem(Item*);

		virtual void display();

	protected:
		char tileType;
		char sprite;
		bool isPassable();
		bool canMove;
		Item* item;

	private:
		bool isCrumb;
};

#endif // TILE_H