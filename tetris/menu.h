
#ifndef __MENU_H
#define __MENU_H
#include "utills.h"
#include "gameConfig.h"
#include "computer.h"
#include "human.h"


class Menu
{
public:
	
	//inputs from user computer player's level
	static char selectComputerLevel();
	
	//allocates players according to human/computer selection
	static void setPlayers(Player** players, int key);
	
	// Prints game instructions for player controls.
	static void printInstructions();

	// Handles pause/start menu logic for selecting new game, instructions, or exit.
	static int handleMenu(Player** players, bool start_or_pause);

	static constexpr int NEW_GAME = 1;
	static constexpr int HUMAN_VS_HUMAN = 1;
	static constexpr int HUMAN_VS_COMPUTER = 2;
	static constexpr int COMPUTER_VS_COMPUTER = 3;
	static constexpr int RESUME_GAME = 4;
	static constexpr int INSTRUCTIONS = 8;
	static constexpr int EXIT = 9;
	static constexpr char BEST = 'a';
	static constexpr char GOOD = 'b';
	static constexpr char NOVICE = 'c';

};

#endif