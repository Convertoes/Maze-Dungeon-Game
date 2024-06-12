#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "Node.h"
#include "Item.h"

class List
{
public:
	List(); 	// default constructor
	List(Node*, Node*);	// custom constructor
	virtual ~List(); 	// default destructor

	Node* getFront();
	Node* getBack();

	bool searchList(Item*);
	Item* index(int);
	Node* nodeIndex(int);
	void tryFindIndex(Item*, int&);
	int findIndex(Item*);
	Node* findNodeIndex(Item*);
	void insertAfter(Node*, Node*);
	void insertAfterValue(Item*, Item*);
	void removeNode(Node*);
	void removePosition(int);
	void removeItem(Item*);

	void display(); // uses an iterator to display items

protected:

private:
	Node* front;
	Node* back;
	int listSize;
};

#endif // LIST_H