#include "game.h"



//get the looser player, prints results and ends the game, put this function in class
void thisPlayerIsTheWinner(int player)
{
	clear_screen();
	cout << "THE WINNER IS: PLAYER NUMBER " << player << endl;
	return;
}

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
	int key = this->handleStartMenu();
	if (key != 9)
	{
		cout << "\npress 1 for color or 0 for no color\n";
		key = _getch() - '0';
		while (key != 1 && key != 0)
			key = _getch();
		clear_screen();
		cout << "Starting Game in 1..";
		Sleep(500);
		cout << "2..";
		Sleep(500);
		cout << "3";
		Sleep(500);
		clear_screen();
		this->board1.init(GameConfig::MIN_X, GameConfig::MIN_Y, key);
		this->board2.init(GameConfig::MIN_X + GameConfig::BOARD_WIDTH + GameConfig::BOARDS_GAP, GameConfig::MIN_Y,key);
		this->board1.drawBoardBorder();
		this->board2.drawBoardBorder();
	}
	return key;
	
}

//for now this is to test
void Game::play(int color)
{
	bool end_game = false;
	Shape s1, cpy_s1;
	int x1, y1;

	this->board1.findStartPoint(&x1, &y1);
	s1.getShape(x1, y1);
	s1.copyShape(cpy_s1);

	while (!end_game)
	{
		if (!this->board1.assignShapeToBoard(s1, cpy_s1))
			end_game = true;
		this->board1.printBoard();
		Sleep(500);

		while (true)
		{
			s1.moveDown();
			if (!this->board1.assignShapeToBoard(s1, cpy_s1))
				break;
			s1.copyShape(cpy_s1);
			this->board1.printBoard();
			Sleep(500);
		}
	}

}

//a template to play the game without extra player class
void Game::playGame()
{
	int key;
	bool end_game1, end_game2, move1, move2;
	Shape s1, s2, cpy_s1, cpy_s2;
	int x1, y1, x2, y2;
	this->board1.findStartPoint(&x1, &y1);
	this->board2.findStartPoint(&x2, &y2);
	while (true)
	{
		key = this->init();
		if (key == 9)
		{
			return;
		}
		end_game1 = false;
		end_game2 = false;
		while (!end_game1 && !end_game2)
		{
			//generate a piece to each board
			s1.getShape(x1, y1);
			s1.copyShape(cpy_s1);
			s2.getShape(x2, y2);
			s2.copyShape(cpy_s1);
			if (!this->board1.assignShapeToBoard(s1, cpy_s1))
				end_game1 = true;
			if (!this->board2.assignShapeToBoard(s2, cpy_s2))
				end_game2 = true;
			//if (checkAndPrintWinner(end_game1, end_game2)
				//break;
			this->board1.printBoard();
			this->board2.printBoard();
			Sleep(500);
			move1 = true;
			move2 = true;
			while (move1 || move2)
			{
				if (move1)
				{
					//key = handleKbhit()
					//if (key == 9)
					//return
					//if (key == 1)
					//end_game1 = true;
					//break;
					s1.moveDown();
					if (this->board1.assignShapeToBoard(s1, cpy_s1))
					{
						s1.copyShape(cpy_s1);
						this->board1.printBoard();
					}
					else
						move1 = false;
				}
				if (move2)
				{
					//key = handleKbhit()
					//if (key == 9)
					//return
					//else if (key == 1)
					//end_game1 = true;
					//break;
					s2.moveDown();
					if (this->board1.assignShapeToBoard(s1, cpy_s1))
					{
						s1.copyShape(cpy_s1);
						this->board1.printBoard();
					}
					else
						move1 = false;
				}
				Sleep(500);
				if(this->board1.handleFullRows())
					this->board1.printBoard();
				if (this->board2.handleFullRows())
					this->board2.printBoard();

			}

		}
	}
}

int Game::handleKbhit(char player)
{
	if (!_kbhit)
		return GameConfig::EMPTY;
	int key = _getch();
	//esc
	if (key == 27)
		return handlePauseMenu();
	return;

}
