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
	Board boards[2];
	int handleStartMenu();
	int handlePauseMenu();
	void printInstructions();
	int handleKbhit();
	void printBoards();
	bool isGameEnded(bool scores[]);
	int init();
	void announceTheWinner(int winner);
	void printBorders();
public:
	void playGame();
	
};

#endif

