#include "game.h"


int Game::handleStartMenu() const
{
	int key = -1;
	bool printed = false;
	std::cout << "(1) Start a new game\n(8) Present instrcutions and keys\n(9) EXIT";
	while (true)
	{
		if (_kbhit())
			key = _getch() - '0';
		if (key == INSTRUCTIONS && !printed)
		{
			printInstructions();
			printed = true;
		}
		else if (key == NEW_GAME|| key == EXIT)
			return key;
	}
}

int Game::handlePauseMenu() const
{
	int key = -1;
	bool printed = false;
	setTextColor(WHITE);
	clear_screen();
	std::cout << "(1) Start a new game\n(2) Continue a paused game\n(8) Present instrcutions and keys\n(9) EXIT";
	while (true)
	{
		if(_kbhit())
			key = _getch() - '0';
		if (key == INSTRUCTIONS && !printed)
		{
			printInstructions();
			printed = true;
		}
		else if ( key == NEW_GAME || key == RESUME_GAME || key == EXIT)
		{
			clear_screen();
			if (key == RESUME_GAME)
				printBorders();
			return key;
		}
	}
	return key;
}

void Game::printInstructions() const
{
	std::cout << "\n\nLeft Player keys:\n\tLeft - a or A\n\tRight - d or D \n\tRotate clokwise - s or S \n\tRotate counterclokwise - w or W\n\tDrop - x or X";
	std::cout << "\n\nRight Player keys:\n\tLeft - j or J\n\tRight - l or L \n\tRotate clokwise - k or K \n\tRotate counterclokwise - i or I\n\tDrop - m or M\n";
	std::cout << "\nPress ESC for pause\n";
}

int Game::init()
{

	clear_screen();
	hideCursor();
	//set text color white
	setTextColor((int)GameConfig::Color::WHITE);
	int key = this->handleStartMenu();
	if (key != EXIT)
	{
		initBoardAndColor();
	}
	return key;
	
}

void Game::initBoardAndColor()
{
	int key;
	clear_screen();
	std::cout << "\npress 1 for color or 0 for no color\n";
	key = _getch() - '0';
	while (key != WITH_COLOR && key != NO_COLOR)
		key = _getch();
	Board::set_colored(key);
	clear_screen();
	Sleep(300);
	std::cout << "Starting Game in 1..";
	Sleep(300);
	std::cout << "2..";
	Sleep(300);
	std::cout << "3";
	Sleep(300);
	clear_screen();
	this->boards[0].init(GameConfig::MIN_X, GameConfig::MIN_Y);
	this->boards[1].init(GameConfig::MIN_X + GameConfig::BOARD_WIDTH + GameConfig::BOARDS_GAP, GameConfig::MIN_Y);
	this->boards[0].drawBoardBorder();
	this->boards[1].drawBoardBorder();
}

void Game::playGame()
{
	srand(time(NULL));
	int key, i;
	bool new_game; //true if the game is over 
	bool end_game[NUM_OF_PLAYERS]; // true if this player lost 
	bool move[NUM_OF_PLAYERS] = {false, false}; //true if a move was made
	while (true)
	{
		key = init();
			
		if (key == EXIT)
		{
			return;
		}
		end_game[PLAYER1] = false;
		end_game[PLAYER2] = false;
		while (!end_game[PLAYER1] && !end_game[PLAYER2]) // game didn't end
		{
			new_game = false;
			for (i = 0; i < NUM_OF_PLAYERS; i++)
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
			for (i = 0; i < MAX_KEYS_IN_BUFFER; i++)
			{
				key = handleKbhit();
				if (key == EXIT)
					return;
				else if (key == NEW_GAME)
				{
					new_game = true;
					initBoardAndColor();
					break;
				}
				Sleep(10);
				printBoards();
			}
			if(!new_game)
				for (i = 0; i < NUM_OF_PLAYERS; i++)
				{
					move[i] = this->boards[i].moveBlockOnBoard('D');
				}
			emptyKBuffer();
			Sleep(100);
			handleFullRows();
			
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
	case(ESC):
		return handlePauseMenu();
		break;
	case((int)LKeys::LEFT_LOWER):
	case((int)LKeys::LEFT_UPPER):
		//move left
		this->boards[PLAYER1].moveBlockOnBoard(LEFT);
		break;
	case((int)LKeys::RIGHT_LOWER):
	case((int)LKeys::RIGHT_UPPER):
		//move right
		this->boards[PLAYER1].moveBlockOnBoard(RIGHT);
		break;
	case((int)LKeys::ROTATE_CLOCKWISE_LOWER):
	case((int)LKeys::ROTATE_CLOCKWISE_UPPER):
		//Rotate clockwise
		this->boards[PLAYER1].moveBlockOnBoard(ROTATE_CLOCKWISE);
		break;
	case((int)LKeys::ROTATE_COUNTERCLOCKWISE_LOWER):
	case((int)LKeys::ROTATE_COUNTERCLOCKWISE_UPPER):
		//rotate counterclockwise
		this->boards[PLAYER1].moveBlockOnBoard(ROTATE_COUNTERCLOCKWISE);
		break;
	case((int)LKeys::DROP_LOWER):
	case((int)LKeys::DROP_UPPER):
		//drop block
		this->boards[PLAYER1].dropBlock();
		break;
	case((int)RKeys::LEFT_LOWER):
	case((int)RKeys::LEFT_UPPER):
		//move left
		this->boards[PLAYER2].moveBlockOnBoard(LEFT);
		break;
	case((int)RKeys::RIGHT_LOWER):
	case((int)RKeys::RIGHT_UPPER):
		//move right
		this->boards[PLAYER2].moveBlockOnBoard(RIGHT);
		break;
	case((int)RKeys::ROTATE_CLOCKWISE_LOWER):
	case((int)RKeys::ROTATE_CLOCKWISE_UPPER):
		//Rotate clockwise
		this->boards[PLAYER2].moveBlockOnBoard(ROTATE_CLOCKWISE);
		break;
	case((int)RKeys::ROTATE_COUNTERCLOCKWISE_LOWER):
	case((int)RKeys::ROTATE_COUNTERCLOCKWISE_UPPER):
		//rotate counterclockwise
		this->boards[PLAYER2].moveBlockOnBoard(ROTATE_COUNTERCLOCKWISE);
		break;
	case((int)RKeys::DROP_LOWER):
	case((int)RKeys::DROP_UPPER):
		//drop block
		this->boards[PLAYER2].dropBlock();
		break;
	}
	
	return 0;

}

void Game::printBoards() const
{
	this->boards[PLAYER1].printBoard();
	this->boards[PLAYER2].printBoard();
}

bool Game::isGameEnded(bool scores[]) const
{
	bool is_end = false;
	int winner;
	//player 2 is the winner
	if (scores[PLAYER1] != scores[PLAYER2])
	{
		is_end = true;

		if (scores[PLAYER2] == true) //player 1 is the winner
			winner = PLAYER1;

		else //player 2 is the winner
			winner = PLAYER2;

		announceTheWinner(winner);
	}

	else //both players with the same score
	{
		if (scores[PLAYER1] == true)//both players lost, its a tie
		{
			is_end = true;
			winner =TIE;
			announceTheWinner(winner);
		}
	}
	return is_end;
}

void Game::announceTheWinner(int winner) const
{
	setTextColor(WHITE);
	if (winner != TIE)
		std::cout << "\n\nTHE WINNER IS: PLAYER NUMBER " << winner + 1 << "!!!" << endl;
	else
		std::cout << "\n\nGAME ENDED, IT'S A TIE!!!" << endl;
	std::cout << "\n\nPress any key to go back to main menu\n";
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

void Game::printBorders() const
{
	this->boards[PLAYER1].drawBoardBorder();
	this->boards[PLAYER2].drawBoardBorder();
}

void Game::handleFullRows()
{
	this->boards[PLAYER1].handleFullRows();
	this->boards[PLAYER2].handleFullRows();
}