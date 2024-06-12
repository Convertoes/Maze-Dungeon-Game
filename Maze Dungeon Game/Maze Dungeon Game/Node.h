#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "Item.h"

class Node
{
public:
	Node(); 	// default constructor
	Node(Item*);	// custom constructor
	virtual ~Node(); 	// default destructor

	Item* getItem();
	void setItem(Item*);
	Node* getNext();
	void setNext(Node*);
	Node* getPrev();
	void setPrev(Node*);

	void display();

protected:

private:
	Node* previous;
	Node* next;
	Item *item;
};

#endif // NODE_H