#include "game.h"



//get the looser player, prints results and ends the game, put this function in class
void thisPlayerIsTheWinner(int player)
{
	clear_screen();
	cout << "\n\n\nTHE WINNER IS: PLAYER NUMBER " << player << endl;
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
	setTextColor(15);
	clear_screen();
	cout << "(1) Start a new game\n(2) Continue a paused game\n(8) Present instrcutions and keys\n(9) EXIT";
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
	clear_screen();
	hideCursor();
	//set text color white
	setTextColor(15);
	int key = this->handleStartMenu();
	if (key != 9)
	{
		cout << "\npress 1 for color or 0 for no color\n";
		key = _getch() - '0';
		while (key != 1 && key != 0)
			key = _getch();
		clear_screen();
		cout << "Starting Game in 1..";
		Sleep(100);
		cout << "2..";
		Sleep(100);
		cout << "3";
		Sleep(300);
		clear_screen();
		this->boards[0].init(GameConfig::MIN_X, GameConfig::MIN_Y, key);
		this->boards[1].init(GameConfig::MIN_X + GameConfig::BOARD_WIDTH + GameConfig::BOARDS_GAP, GameConfig::MIN_Y, key);
		this->boards[0].drawBoardBorder();
		this->boards[1].drawBoardBorder();
	}
	return key;
	
}

//a template to play the game without extra player class
void Game::playGame()
{
	srand(time(NULL));
	int key, i;
	bool end_game[2];
	bool move[2] = { false, false };
	while (true)
	{
		key = init();
		if (key == 9)
		{
			return;
		}
		end_game[0] = false;
		end_game[1] = false;
		while (!end_game[0] && !end_game[1])
		{
			
			for (i = 0; i < 2; i++)
			{
				if (!move[i])
				{
					//generate a piece to each board
					this->boards[i].getBlock();
					//add block to board and check if possible
					if (!this->boards[i].set_block())
						end_game[i] = true;
				}
				
			}
			printBoards();
			if (isGameEnded(end_game))
				break;
			for (i = 0; i < 10; i++)
			{
				key = handleKbhit();
				if (key == 9)
				{
					clear_screen();
					return;
				}
				
				else if (key == 2)
				{
					clear_screen();
					printBorders();
				}
					
				//Sleep(50);
				printBoards();
			}
			for (i = 0; i < 2; i++)
			{
				move[i] = this->boards[i].moveBlockOnBoard('D');
			}
			//Sleep(100);
			printBoards();
			emptyKBuffer();
		}
	}
	clear_screen();
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
		this->boards[0].moveBlockOnBoard('L');
		break;
	case('d'):
	case('D'):
		//move right
		this->boards[0].moveBlockOnBoard('R');
		break;
	case('s'):
	case('S'):
		//Rotate clockwise
		this->boards[0].moveBlockOnBoard('T');
		break;
	case('w'):
	case('W'):
		//rotate counterclockwise
		this->boards[0].moveBlockOnBoard('G');
		break;
	case('x'):
	case('X'):
		//drop block
		this->boards[0].dropBlock();
		break;
	case('j'):
	case('J'):
		//move left
		this->boards[1].moveBlockOnBoard('L');
		break;
	case('l'):
	case('L'):
		//move right
		this->boards[1].moveBlockOnBoard('R');
		break;
	case('k'):
	case('K'):
		//Rotate clockwise
		this->boards[1].moveBlockOnBoard('T');
		break;
	case('i'):
	case('I'):
		//rotate counterclockwise
		this->boards[1].moveBlockOnBoard('G');
		break;
	case('m'):
	case('M'):
		//drop block
		this->boards[1].dropBlock();
		break;
	}
	
	return 0;

}

void Game::printBoards()
{
	this->boards[0].printBoard();
	this->boards[1].printBoard();
}

bool Game::isGameEnded(bool scores[])
{
	bool is_end = false;
	int winner;
	//player 2 is the winner
	if (scores[0] != scores[1])
	{
		is_end = true;

		if (scores[1] == true)//player 1 is the winner
			winner = GameConfig::PLAYER1;

		else //player 2 is the winner
			winner = GameConfig::PLAYER2;

		announceTheWinner(winner);
	}

	else //both players with the same score
	{
		if (scores[0] == true)//both players lost, its a tie
		{
			is_end = true;
			winner = GameConfig::TIE;
			announceTheWinner(winner);
		}
	}
	return is_end;
}

//get the looser player, prints results and ends the game, put this function in class
void Game::announceTheWinner(int winner)
{
	setTextColor(15);
	if (winner != GameConfig::TIE)
		cout << "\n\nTHE WINNER IS: PLAYER NUMBER " << winner << "!!!" << endl;
	else
		cout << "\n\nGAME ENDED, IT'S A TIE!!!" << endl;
	cout << "\n\nPress any key to go back to main menu\n";
	emptyKBuffer();
	while (true)
	{
		if (_kbhit())
		{
			clear_screen();
			break;
		}
			
	}
	return;
}

void Game::printBorders()
{
	this->boards[0].drawBoardBorder();
	this->boards[1].drawBoardBorder();
}
