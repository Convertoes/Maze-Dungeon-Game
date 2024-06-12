// Author: Alex Larochette
// Project: Maze Game Final Project
// Description: A dungeon maze game with moving enemies, items, keys, locked doors, an autosolver and traps
// Created: 03/06/2024
// Modified: 12/06/2024

// ============================= libraries ====================================================================================================================

#include <iostream>
#include <windows.h>
#include "Game.h"
using namespace std;

// ============================= main =========================================================================================================================

int main()
{
	Game dungeonGame;

	dungeonGame.playGame();

	return 0;
}