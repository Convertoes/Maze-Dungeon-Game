#include <iostream>
#include "Node.h"
#include "Item.h"
using namespace std;

Node::Node()		// default constructor
{
    previous = nullptr;
    next = nullptr;
    item = nullptr;
    return;
}

Node::Node(Item* _item) 	// custom construtor, only initializes the item since
{                           // next and previous cannot be initialized properly without
    previous = nullptr; 	// using a list and its methods
    next = nullptr;			
    item = _item;
    return;
}

Node::~Node() 	// default destructor
{
}

Item* Node::getItem()
{
    return item;
}

void Node::setItem(Item* _item)
{
    item = _item;
    return;
}

Node* Node::getNext()
{
    return next;
}

void Node::setNext(Node* _next)
{
    next = _next;
    return;
}

Node* Node::getPrev()
{
    return previous;
}

void Node::setPrev(Node* _prev)
{
    previous = _prev;
    return;
}

void Node::display()
{
    if (item != nullptr)
    {
        item->display(true);
    }
}