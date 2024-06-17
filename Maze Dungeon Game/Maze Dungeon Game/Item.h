#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include "Utility.h"
#include "Tile.h"
using namespace std;

class Item : public Utility
{
	public:
		Item(); 	// default constructor
		Item(string, string, char, int, int, char);
		virtual ~Item(); 	// default destructor

		string getName();
		char getType();
		int getXPos();
		int getYPos();
		bool getIsTaken();
		void setIsTaken(bool);
		
		virtual void display(bool);

	protected:
		string name;
		string colour;
		char sprite;
		int posX;
		int posY;
		char type;
		bool isTaken;

	private:

};

#endif // ITEM_H