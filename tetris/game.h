#pragma once
#include "board.h"
#include "utills.h"
#include <windows.h>
//include block/shape
class Game
{
	Board board1;
	Board board2;
	int handleStartMenu();
	int handlePauseMenu();
	void printInstructions();
public:
	Game() {};
	int init();
	void play(int color);
};


