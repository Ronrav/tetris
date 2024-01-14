#pragma once
#include "board.h"
//include block/shape
class Game
{
	Board board1;
	Board board2;
	char handleStartMenu();
	char handlePauseMenu();
	void printInstructions();
	char handleStartMenu();
	char handlePauseMenu();
	void printInstructions();
public:
	void init();
	void play();
};


