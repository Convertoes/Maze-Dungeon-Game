#include <iostream>
#include "Stack.h"
#include "Container.h"
using namespace std;

Stack::Stack()		// default constructor
{
	top = nullptr;
}

Stack::Stack(char _direction)
{
	top = new Container(_direction);
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
		char returnDirection = top->getDirection();
		top = top->getNext();
		temp->setNext(nullptr);
		delete temp;

		return returnDirection;
	}

	cout << "Top is nullptr";

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
	if (top != nullptr)
	{
		Container* iterator = top;

		iterator->display();
		iterator = iterator->getNext();
		
		while (iterator != nullptr)
		{
			cout << ", ";
			iterator->display();
			iterator = iterator->getNext();
		}
	}

	cout << endl;
	cout << "The stack has " << countStack() << " elements." << endl;

	return;
}

int Stack::countStack()
{
	Stack* tempStack = new Stack();
	int count = 0;

	while (top != nullptr)
	{
		tempStack->push(pop());
		count++;
	}

	while (tempStack->top != nullptr)
	{
		push(tempStack->pop());
	}

	return count;
}