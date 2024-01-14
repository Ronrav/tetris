#include "tetrisGame.h"


void run()
{
	char key;
	key = handleStartMenu();
	if (key == 1)
	{
		// getColorChoice
		//printStartingGameScreen(color)
	}
	bool color;
	cout << "press 1 for color or 0 for no color\n";
	cin >> color;
	Board board1(GameConfig::MIN_X, GameConfig::MIN_Y, GameConfig::BOARD_WIDTH, GameConfig::BOARD_HEIGHT, color);
	Board board2(GameConfig::MIN_X + GameConfig::BOARD_WIDTH + GameConfig::BOARDS_GAP, GameConfig::MIN_Y, GameConfig::BOARD_WIDTH, GameConfig::BOARD_HEIGHT, color);
	board1.drawBoardBorder();
	board2.drawBoardBorder();
}

char handleStartMenu()
{
	char key;
	bool printed = false;
	cout << "(1) Start a new game\n(8) Present instrcutions and keys\n (9) EXIT";
	while (true)
	{
		key = getch();
		if (key == 8 && !printed)
		{
			printInstructions();
			printed = true;
		}
		else if (key == 1 || key == 9)
			return key;
	}
	
	
}

char handlePauseMenu()
{
}

void printInstructions()
{
}
