#include "game.h"

int Game::handleStartMenu()
{
	int key = -1;
	bool printed = false;
	cout << "(1) Start a new game\n(8) Present instrcutions and keys\n(9) EXIT";
	while (true)
	{
		if (_kbhit())
			key = _getch() - '0';
		if (key == 8 && !printed)
		{
			printInstructions();
			printed = true;
		}
		else if (key == 1 || key == 9)
			return key;
	}
}

int Game::handlePauseMenu()
{
	int key = -1;
	bool printed = false;
	cout << "(1) Start a new game\n(2) Continue a paused game\n(8) Present instrcutions and keys\n (9) EXIT";
	while (true)
	{
		if(_kbhit())
			key = _getch() - '0';
		if (key == 8 && !printed)
		{
			printInstructions();
			printed = true;
		}
		else if (key == 1 || key == 9 || key == 2)
			return key;
	}
}

void Game::printInstructions()
{
	cout << "\n\nLeft Player keys:\n\tLeft - a or A\n\tRight - d or D \n\tRotate clokwise - s or S \n\tRotate counterclokwise - w or W\n\tDrop - x or X";
	cout << "\n\nRight Player keys:\n\tLeft - j or J\n\tRight - l or L \n\tRotate clokwise - k or K \n\tRotate counterclokwise - i or I\n\tDrop - m or M\n";
}

int Game::init()
{
	int color, key = this->handleStartMenu();
	if (key != 9)
	{
		cout << "\npress 1 for color or 0 for no color\n";
		cin >> color;

		clear_screen();
		cout << "Starting Game in 1..";
		Sleep(500);
		cout << "2..";
		Sleep(500);
		cout << "3";
		Sleep(500);
		clear_screen();
	}
	return key;
	
}

void Game::play(int color)
{
	Board tmp1(GameConfig::MIN_X, GameConfig::MIN_Y, GameConfig::BOARD_WIDTH, GameConfig::BOARD_HEIGHT, color);
	Board tmp2(GameConfig::MIN_X + GameConfig::BOARD_WIDTH + GameConfig::BOARDS_GAP, GameConfig::MIN_Y, GameConfig::BOARD_WIDTH, GameConfig::BOARD_HEIGHT, color);
	this->board1 = tmp1;
	this->board2 = tmp2;
	this->board1.drawBoardBorder();
	this->board2.drawBoardBorder();
	bool end_game = false;
	Shape s1, s2;
	while (!end_game)
	{
		s1.assignShape(GameConfig::MIN_X + GameConfig::BOARD_WIDTH / 2, GameConfig::MIN_Y + 1);

		//s1.assign_shape(this->board1);
		//s2.assign_shape(initial postion);
		/*
		* if(place_shape_in_board)
		* print_board
		* else
		* sleep(500)
		* while(!end_game && !dropped)
		* {
		* if(_kbhit)
		* key = _getch
		* switch, case (left, right, drop, pause)
		*/

	}

	
}

