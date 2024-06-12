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

	private:
};

#endif // UTILITY_H