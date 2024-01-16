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
	Board boards[2];
	int handleStartMenu();
	int handlePauseMenu();
	void printInstructions();
	int handleKbhit();
public:
	int init();
	void play(int color);
	void playGame();
	
};

#endif

