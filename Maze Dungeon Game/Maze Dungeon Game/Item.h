#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include "Utility.h"
using namespace std;

class Item : public Utility
{
	public:
		Item(); 	// default constructor
		Item(string, string, char, bool, int, int, char);
		virtual ~Item(); 	// default destructor

		string getName();
		
		virtual void display(bool);

	protected:
		string name;
		string colour;
		char sprite;
		bool isKey;
		int posX;
		int posY;
		char type;
		bool isTaken;

	private:

};

#endif // ITEM_H