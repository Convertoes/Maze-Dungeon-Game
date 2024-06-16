#ifndef UTILITY_H
#define UTILITY_H
#include <iostream>
using namespace std;

class Utility
{
	public:
		Utility(); 	// default constructor
		virtual ~Utility(); 	// default destructor

		void pauseAndClear();	
		int menu(string, string[], int, string);
		void clearLines(int);
		void displayText(int, int, string);
		void displayNameText(int, int, string, string);

	protected:

		void set_cursor(int, int);
		int randomNumb(int, int);
		static const char VW = 219;	// vertical wall
		static const char HW = 220;	// horizontal wall
		static const char VD = 186; // vertical door
		static const char HD = 205; // horizontal door
		static const char FN = 176;	// finish
		static const char SP = ' ';	// space

		static const string RESET;

	private:

};

#endif // UTILITY_H