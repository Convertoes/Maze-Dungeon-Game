#include <iostream>
#include "List.h"
#include "Node.h"
#include "Item.h"
using namespace std;

List::List()		// default constructor
{
	front = nullptr;
	back = nullptr;
	listSize = 0;
	return;
}

List::List(Node* _front, Node* _back) 		// custom construtor
{
	front = _front;
	back = _back;

	if (back == nullptr and front == nullptr) // if both nodes are null, it is an empty list
	{
		listSize = 0;
	}

	else if (back == nullptr) // if the back is null, it is set to the same to front
	{
		back = front;
		listSize = 1;
	}

	else if (front == nullptr) // if front is null, it is set to the same as back
	{
		front = back;
		listSize = 1;
	}

	else
	{
		front->setNext(back);
		front->setPrev(nullptr);
		back->setPrev(front);
		back->setNext(nullptr);
		listSize = 2;
	}

	return;
}

List::~List() 	// default destructor
{
}

Node* List::getFront()
{
	return front;
}

Node* List::getBack()
{
	return back;
}


bool List::searchList(string _fugitive) // searches the list for a specified name, returns true if the item is contained within the items of the list
{
	Node* iterator = front;
	while (iterator != nullptr) // using an iterator to loop through the list until it runs into a nullptr
	{
		if (iterator->getItem()->getName() == _fugitive) // if the item in the current position of the iterator points to the same as the searched node, true is returned
		{
			return true;
		}

		iterator = iterator->getNext();
	}

	return false;
}

Item* List::index(int _position) // returns the nth value in the list
{
	Node* iterator = front;

	for (int i = 0; i < _position; i++)
	{
		if (iterator != nullptr)
		{
			iterator = iterator->getNext();
		}
	}

	if (iterator != nullptr) 	// only returns if iterator exists
	{
		return iterator->getItem();
	}

	else 	// returns nullptr if iterator does not exist at specified position
	{
		return nullptr;
	}
}

Node* List::nodeIndex(int _position) 	//returns the nth Node in the list.
{
	Node* iterator = front;

	for (int i = 0; i < _position; i++)
	{
		if (iterator != nullptr)
		{
			iterator = iterator->getNext();
		}
	}

	if (iterator != nullptr) 	// only returns if iterator exists
	{
		return iterator;
	}

	else 	// returns nullptr if iterator does not exist at specified position
	{
		return nullptr;
	}
}

void List::tryFindIndex(Item* _item, int &_position)	// tries findIndex method
{
	try		
	{
		_position = findIndex(_item);
	}

	catch (exception& e)	// catches and displays error message
	{
		cout << "Error: " << e.what() << endl;
	}

	return;
}

int List::findIndex(Item* _item) // returns the position where the first occurrence of a specified item is stored
{
	Node* iterator = front;
	int counter = 0;

	while (iterator != nullptr) // uses an iterator to pass through the list
	{
		if (iterator->getItem() == _item) 	// if the item of iterator at it's position is the same as the value
		{
			return counter;						// position is returned
		}

		iterator = iterator->getNext();
		counter++;
	}
	// returns nullptr if the value is not called during the while loop
	throw invalid_argument("The value is not contained within the list");
}

Node* List::findNodeIndex(Item* _item) // returns the Node where the first occurrence of a specified value is stored
{
	Node* iterator = front;
	Item* counter = 0;

	while (iterator != nullptr)
	{
		if (iterator->getItem() == _item)
		{
			return iterator;
		}

		iterator = iterator->getNext();
		counter++;
	}

	return nullptr;	// if item is not contained within the list, returns nullptr
}

void List::insertAfter(Node* _insertAfter, Node* _toInsert) // inserts a node into the list after another specified node
{
	if (_toInsert != nullptr) // checks if the node you are trying to insert is nullptr
	{
		Node* tempNode;
		int counter = -1; 	// default counter value is -1, only stays -1 if insertAfter is nullptr

		if (_insertAfter != nullptr)
		{
			counter = -2; 	// counter set to -2 so that if tryFindIndex returns an error, we know that when counter == -2, the index is not in the list.
			tryFindIndex(_insertAfter->getItem(), counter);	// uses the find index function to determine the position of the node 
		} 	

		if (counter != -2)
		{
			if (listSize == 0) // inserting into an empty list
			{
				front = _toInsert;
				front->setNext(nullptr);
				back = front;
			}

			else if (_insertAfter == nullptr) // inserting to the front of a non-empty list
			{
				tempNode = front;
				_toInsert->setNext(tempNode);
				tempNode->setPrev(_toInsert);
				front = _toInsert;
			}

			else if (_insertAfter->getItem() == front->getItem() and listSize == 1) // inserting into the back of a list with exactly one node
			{
				front->setNext(_toInsert);
				_toInsert->setPrev(front);
				_toInsert->setNext(nullptr);
				back = _toInsert;
			}

			else if (_insertAfter->getItem() == back->getItem()) // inserting to the back of a list
			{
				tempNode = back;
				tempNode->setNext(_toInsert);
				_toInsert->setPrev(tempNode);
				back = _toInsert;
			}

			else	//inserting into the interior of a non-empty list larger than 1
			{
				tempNode = front;
				for (int i = 0; i < counter; i++) 		// looping to get to the position in the array where the value is stored
				{
					tempNode = tempNode->getNext();		// < because when i is 1 less than counter, tempNode will be set to tempNode->Next, so i == counter should never be run
				}

				_toInsert->setNext(tempNode->getNext());
				_toInsert->setPrev(tempNode);
				tempNode->getNext()->setPrev(_toInsert); // no need to check for nullptr, if tempNode->next was nullptr, then _toInsert would be the back
				tempNode->setNext(_toInsert);
			}

			listSize++; 	// increases list size by 1
		}
	}

	else if (_insertAfter == nullptr)
	{
		cout << "Error: The node that you are trying to insert is not contained within the list!" << endl;
	}

	return;
}

void List::insertAfterValue(Item* _insertAfterValue, Item* _value) // inserts a value into this list after the first occurrence of another specified value in the list
{
	int position = -1; 	// position is -1, if the index does not exist then position will stay at -1
	Node* insertNode = new Node(_value);
	Node* iterator = front;
	Node* tempNode;
	tryFindIndex(_insertAfterValue, position);

	if (front != nullptr) // only runs if the list is not empty
	{
		if (position != -1) // only runs if the index exists within the list
		{
			for (int i = 0; i < position; i++)
			{
				iterator = iterator->getNext(); // loops through the list to get to the node where the value is contained
			}

			if (iterator->getItem() == back->getItem()) // inserts to the back of the list
			{
				tempNode = back;
				tempNode->setNext(insertNode);
				insertNode->setPrev(tempNode);
				back = insertNode;
			}

			else if (listSize == 1 and _insertAfterValue == front->getItem()) // inserts into the back of a list with a size of 1
			{
				front->setNext(insertNode);
				insertNode->setPrev(front);
				back = insertNode;
			}

			else
			{
				insertNode->setNext(iterator->getNext());
				insertNode->setPrev(iterator);
				iterator->getNext()->setPrev(insertNode); // no need to check for nullptr, if tempNode->next was nullptr, then _toInsert would be the back
				iterator->setNext(insertNode);
			}

			listSize++;
		}
	}

	else // error message for empty list
	{
		cout << "Error: The list you are inserting to is empty." << endl;
	}

	return;
}

void List::removeNode(Node* _toRemove) // removes a specified node from the list
{
	Node* tempNode = front;
	int counter = -1;

	if (listSize == 0)
	{
		cout << "Error: The list you are trying to remove from is empty!" << endl;
	}

	else if (_toRemove == nullptr)
	{
		cout << "Error: The node you are trying to remove is a null point!" << endl;
	}

	else
	{
		tryFindIndex(_toRemove->getItem(), counter); // determines the position of the node that is to be removed, counter remains -1 if node is not in list

		if (counter != -1) // runs only if node exists within the list
		{
			if (_toRemove->getItem() == front->getItem() and listSize == 1) // removes the front/back of a list containing 1 node
			{
				front = nullptr;
				back = nullptr;
				delete tempNode;
			}

			else if (_toRemove->getItem() == front->getItem()) // removes the front of the list containing more than 1 node
			{
				front = front->getNext();
				front->setPrev(nullptr);
				tempNode->setNext(nullptr);
				delete tempNode;
			}

			else if (_toRemove->getItem() == back->getItem()) // removes the back of the list containing more than 1 node
			{
				tempNode = back;
				back = back->getPrev();
				back->setNext(nullptr);
				tempNode->setPrev(nullptr);
				delete tempNode;
			}

			else
			{
				for (int i = 0; i < counter; i++) // loops through the list using a iterator to get access to the remove node
				{
					tempNode = tempNode->getNext();
				}

				tempNode->getPrev()->setNext(tempNode->getNext());
				tempNode->getNext()->setPrev(tempNode->getPrev());
				tempNode->setNext(nullptr);
				tempNode->setPrev(nullptr);
				delete tempNode;
			}

			listSize--; 	// lowers the listSize by 1
		}
	}

	return;
}

void List::removePosition(int _position) // removes the nth Node from the list
{
	Node* tempNode = front;
	Item* isContained = nullptr;

	if (listSize == 0) // does not run if the list is empty
	{
		cout << "Error: The list you are trying to remove from is empty!" << endl;
	}

	else
	{
		isContained = index(_position); 	// using tryIndex to determine if the position is within the limits of the list

		if (isContained != nullptr) 	// runs only if the position is in the list (counter will be > 0  if the pos is within the list)
		{
			if (_position == 0 and listSize == 1) // removes the front of a list containing one node
			{
				front = nullptr;
				back = nullptr;
				delete tempNode;
			}

			else if (_position == 0) // removes the front of a list containing more than one node
			{
				front = front->getNext();
				front->setPrev(nullptr);
				tempNode->setNext(nullptr);
				delete tempNode;
			}

			else if (isContained == back->getItem()) // removes the back of a list
			{
				tempNode = back;
				back = back->getPrev();
				back->setNext(nullptr);
				tempNode->setPrev(nullptr);
				delete tempNode;
			}

			else
			{
				tempNode = front;
				for (int i = 0; i < _position; i++)
				{
					tempNode = tempNode->getNext();
				}

				tempNode->getPrev()->setNext(tempNode->getNext());
				tempNode->getNext()->setPrev(tempNode->getPrev());
				tempNode->setNext(nullptr);
				tempNode->setPrev(nullptr);
				delete tempNode;
			}

			listSize--;
		}
	}

	return;
}

void List::removeItem(Item* _removeValue)	// removes the first occurrence of a specified value from the list
{
	Node* tempNode = front;
	int counter = -1;

	if (listSize == 0) // does not run if list is empty
	{
		cout << "Error: The list does not contain the node you are trying to remove!" << endl;
	}

	else
	{
		tryFindIndex(_removeValue, counter); // determines the position of the node that is to be removed, counter remains -1 if node is not in list

		if (counter != -1) // if the value is not in the list, nothing will be removed
		{
			if (_removeValue == front->getItem() and listSize == 1) // removes the front/back of a list containing 1 node
			{
				front = nullptr;
				back = nullptr;
				delete tempNode; 
			}

			else if (_removeValue == front->getItem()) // removes the front of the list containing more than 1 node
			{
				front = front->getNext();
				front->setPrev(nullptr);
				tempNode->setNext(nullptr);
				delete tempNode;
			}

			else if (_removeValue == back->getItem()) // removes the back of the list containing more than 1 node
			{
				tempNode = back;
				back = back->getPrev();
				back->setNext(nullptr);
				tempNode->setPrev(nullptr);
				delete tempNode;
			}

			else
			{
				for (int i = 0; i < counter; i++) // loops through the list using a iterator to get access to the remove node
				{
					tempNode = tempNode->getNext();
				}

				tempNode->getPrev()->setNext(tempNode->getNext());
				tempNode->getNext()->setPrev(tempNode->getPrev());
				tempNode->setNext(nullptr);
				tempNode->setPrev(nullptr);
				delete tempNode;
			}

			listSize--;
		}
	}

	return;
}

void List::display() 	// A display function that uses an iterator to display the items in the list
{
	Node* iterator = front;

	if (listSize == 0)
	{
		cout << "This is an empty list. Please insert an item before displaying again." << endl;
	}

	else
	{
		if (listSize == 1)
		{
			cout << "There is " << listSize << " item in the list. The item is: ";
			iterator->display();
		}

		else
		{
			cout << "There are " << listSize << " values in the list. The values are: ";
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
	}
	return;
}