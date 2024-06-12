#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include "Entity.h"
using namespace std;

class Enemy : public Entity
{
public:
	Enemy(); 	// default constructor
	//Enemy();	// custom constructor
	//Enemy();	// custom constructor with parent's constructor
	virtual ~Enemy(); 	// default destructor


protected:

private:

};

#endif // ENEMY_H