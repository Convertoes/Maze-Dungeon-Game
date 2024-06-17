#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>
using namespace std;

class Container
{
	public:
		Container(); 	// default constructor
		Container(Container*, char);
		virtual ~Container(); 	// default destructor

		Container* getNext();
		void setNext(Container*);
		char getDirection();
		void setDirection(char);

		void display();

	protected:

	private:
		Container* next;
		char direction;
};

#endif // CONTAINER_H