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
	hideCursor();
	//set text color white
	setTextColor(15);
	int key = this->handleStartMenu();
	if (key == 9)
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
		this->boards[0].init(GameConfig::MIN_X, GameConfig::MIN_Y, key);
		this->boards[1].init(GameConfig::MIN_X + GameConfig::BOARD_WIDTH + GameConfig::BOARDS_GAP, GameConfig::MIN_Y, key);
		this->boards[0].drawBoardBorder();
		this->boards[1].drawBoardBorder();
	}
	return key;
	
}

//for now this is to test
void Game::play(int color)
{
	bool end_game = false;
	this->board1.moveBlockOnBoard(0);
	this->board1.printBoard();
	Sleep(300);
	while (!end_game)
	{
		if (!this->board1.moveBlockOnBoard('D'))
			end_game = true;
		this->board1.printBoard();
		Sleep(300);

	}
	return;
}

//a template to play the game without extra player class
void Game::playGame()
{
	int key, i;
	bool end_game[2];
	bool move[2];
	while (true)
	{
		key = this->init();
		if (key == 9)
		{
			return;
		}
		end_game[0] = false;
		end_game[1] = false;
		while (!end_game[0] && end_game[1])
		{
			
			for (i = 0; i < 2; i++)
			{
				//generate a piece to each board
				this->boards[i].getBlock();
				//add block to board and check if possible
				if (!this->boards[i].moveBlockOnBoard(NULL))
					end_game[i] = true;
				this->boards[i].printBoard();
			}

			
			//if (checkAndPrintWinner(end)
				//break;
			
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
	return;
}

int Game::handleKbhit()
{
	if (!_kbhit())
		return GameConfig::EMPTY;
	int key = _getch();
	switch (key)
	{
		//esc
	case(27):
		return handlePauseMenu();
		break;
	case('a'):
	case('A'):
		//move left
		this->board1.moveBlockOnBoard('L');
		break;
	case('d'):
	case('D'):
		//move right
		this->board1.moveBlockOnBoard('R');
		break;
	case('s'):
	case('S'):
		//Rotate clockwise
		this->board1.moveBlockOnBoard('T');
		break;
	case('w'):
	case('W'):
		//rotate counterclockwise
		this->board1.moveBlockOnBoard('G');
		break;
	case('x'):
	case('X'):
		//drop block
		this->board1.dropBlock();
		break;
	case('j'):
	case('J'):
		//move left
		this->board2.moveBlockOnBoard('L');
		break;
	case('l'):
	case('L'):
		//move right
		this->board2.moveBlockOnBoard('R');
		break;
	case('k'):
	case('K'):
		//Rotate clockwise
		this->board2.moveBlockOnBoard('T');
		break;
	case('i'):
	case('I'):
		//rotate counterclockwise
		this->board2.moveBlockOnBoard('G');
		break;
	case('m'):
	case('M'):
		//drop block
		this->board2.dropBlock();
		break;
	}
	//esc
	if (key == 27)
		return handlePauseMenu();

	return 0;

}
