#ifndef __MENU_H
#define __MENU_H
#include "utills.h"
#include "gameConfig.h"

class Menu
{

public:

	// Handles the start menu logic for selecting new game, instructions, or exit.
	static int handleStartMenu();


	// Handles the pause menu logic for selecting new game, resuming, instructions, or exit during gameplay.
	// Returs key, representing the selected option.
	static int handlePauseMenu();


	// Prints game instructions for player controls.
	static void printInstructions();

};

#endif // !__MENU_H

