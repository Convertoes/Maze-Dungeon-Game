#include "Container.h"
#include <iostream>
using namespace std;

Container::Container()		// default constructor
{
    next = nullptr;
    direction = ' ';
    return;
}

Container::Container(char _direction)
{
    next = nullptr;
    direction = _direction;
    return;
}

Container::Container(Container* _next, char _direction)
{
    next = _next;
    direction = _direction;
    return;
}

Container::~Container() 	// default destructor
{
}

Container* Container::getNext()
{
    return next;
}

void Container::setNext(Container* _next)
{
    next = _next;
    return;
}

char Container::getDirection()
{
    return direction;
}

void Container::setDirection(char _direction)
{
    direction = _direction;
    return;
}

void Container::display()
{
    cout << direction;
    return;
}