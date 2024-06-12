#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include "Utility.h"
using namespace std;

class Item : public Utility
{
	public:
		Item(); 	// default constructor
		Item(string, char, bool, int, int, char);
		virtual ~Item(); 	// default destructor

		virtual void display(bool);

	protected:
		string name;
		char sprite;
		bool isKey;
		int posX;
		int posY;
		char type;
		bool isTaken;

	private:

};

#endif // ITEM_H