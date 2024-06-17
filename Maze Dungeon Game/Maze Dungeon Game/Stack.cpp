#include <iostream>
#include "Stack.h"
#include "Container.h"
using namespace std;

Stack::Stack()		// default constructor
{
	top = nullptr;
	return;
}

Stack::Stack(char _direction)
{
	top = new Container;
	top->setDirection(_direction);
	return;
}

Stack::~Stack() 	// default destructor
{
}

void Stack::push(char _newTop)
{
	Container* newCont = new Container(nullptr, _newTop);

	if (top == nullptr)
	{
		top = newCont;
		return;
	}

	else
	{
		newCont->setNext(top);
		top = newCont;
	}

	return;
}

char Stack::pop()
{
	if (top != nullptr)
	{
		Container* temp = top;
		char returnDirection = temp->getDirection();
		top = top->getNext();
		temp->setNext(nullptr);
		delete temp;

		return returnDirection;
	}

	return 'e';
}

char Stack::peek()
{
	if (top != nullptr)
	{
		return top->getDirection();
	}

	return 'e';
}

void Stack::display()
{
	Container* iterator = top;

	while (iterator != nullptr)
	{
		iterator->display();
		iterator = iterator->getNext();
	}

	return;
}