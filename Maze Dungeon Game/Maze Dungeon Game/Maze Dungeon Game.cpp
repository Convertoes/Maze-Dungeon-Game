// Author: Alex Larochette
// Project: Maze Game Final Project
// Description: A dungeon maze game with moving enemies, items, keys, locked doors, an autosolver and 
// Created:
// Modified:

// ============================= libraries ====================================================================================================================

#include <iostream>
#include <windows.h>
#include "Utility.h"
#include "Game.h"
using namespace std;

// ============================= main =========================================================================================================================

int main()
{
	Game dungeonGame;

	dungeonGame.startGame();

	return 0;
}