#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "Entity.h"
using namespace std;

class Player : public Entity
{
public:
	Player(); 	// default constructor
	//Player();	// custom constructor
	//Player();	// custom constructor with parent's constructor
	virtual ~Player(); 	// default destructor


protected:

private:

};

#endif // PLAYER_H