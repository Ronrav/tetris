#ifndef __GAME_H
#define __GAME_H
#include "board.h"
#include "utills.h"
#include <windows.h>
#include "gameConfig.h"
#include "shape.h"
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
	void init();
	void play(int color);
	
};

#endif

