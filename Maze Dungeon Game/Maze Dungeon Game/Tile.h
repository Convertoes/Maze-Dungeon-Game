#ifndef TILE_H
#define TILE_H
#include <iostream>
#include "Utility.h"
using namespace std;

class Tile : public Utility
{
	public:
		Tile(); 	// default constructor
		Tile(char, char, bool);	// custom constructor
		virtual ~Tile(); 	// default destructor

		char getType();
		bool getIsPassable();
		bool getIsCrumb();
		void setIsCrumb(bool);

		void display();

	protected:
		char tileType;
		char sprite;
		bool isPassable;

	private:
		bool isCrumb;
};

#endif // TILE_H