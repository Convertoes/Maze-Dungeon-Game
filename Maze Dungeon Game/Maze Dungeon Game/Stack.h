#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "Container.h"

class Stack
{
	public:
		Stack(); 	// default constructor
		Stack(char);
		virtual ~Stack(); 	// default destructor

		void push(char);
		char pop();
		char peek();

		void display();
	protected:

	private:
		Container* top;
};

#endif // STACK_H