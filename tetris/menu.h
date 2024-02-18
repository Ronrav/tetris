
#ifndef __MENU_H
#define __MENU_H
#include "utills.h"
#include "gameConfig.h"
#include "computer.h"
#include "human.h"

class Player;

class Menu
{
public:
	// Handles the start menu logic for selecting new game, instructions, or exit.
	static int handleStartMenu(Player** players);
	// Handles the pause menu logic for selecting new game, resuming, instructions, or exit during gameplay.
	// Returs key, representing the selected option.
	static char selectComputerLevel();
	static int handlePauseMenu(Player** players);
	static void setPlayers(Player** players, int key);
	
	// Prints game instructions for player controls.
	static void printInstructions();
	static constexpr int NEW_GAME = 1;
	static constexpr int HUMAN_VS_HUMAN = 1;
	static constexpr int HUMAN_VS_COMPUTER = 2;
	static constexpr int COMPUTER_VS_COMPUTER = 3;
	static constexpr int RESUME_GAME = 4;
	static constexpr int INSTRUCTIONS = 8;
	static constexpr int EXIT = 9;

};

#endif