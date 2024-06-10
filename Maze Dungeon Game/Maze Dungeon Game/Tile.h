#ifndef TILE_H
#define TILE_H
#include <iostream>
#include "Utility.h"
using namespace std;

class Tile : public Utility
{
	public:
		Tile(); 	// default constructor
		Tile(int, int, char, string, bool);	// custom constructor
		virtual ~Tile(); 	// default destructor

		int getPosX();
		int getPosY();
		char getType();
		bool getIsPassable();
		bool getIsCrumb();
		void setIsCrumb(bool);

		void display();

	protected:
		int posX;
		int posY;
		char tileType;
		string sprite;
		bool isPassable;

	private:
		bool isCrumb;
};

#endif // TILE_H