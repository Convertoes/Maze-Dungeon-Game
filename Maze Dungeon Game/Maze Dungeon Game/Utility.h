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

	protected:

		void set_cursor(int, int);
		int randomNumb(int, int);
		static const char VW = 219;
		static const char HW = 220;
		static const char VD = 186;
		static const char HD = 205;
		static const char FN = 176;
		static const char SP = ' ';


	private:
};

#endif // UTILITY_H