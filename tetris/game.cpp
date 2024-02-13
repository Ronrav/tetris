#include "game.h"

int Game::colored = 0;

void Game::set_colored(int key)
{
	colored = key;
}

int Game::init()
{

	clear_screen();
	hideCursor();
	int key = Menu::handleStartMenu();
	if (key != GameConfig::EXIT)
	{
		initColor();
	}
	return key;
	
}

void Game::initColor()
{
	//set text color white
	setTextColor((int)GameConfig::Color::WHITE);
	int key;
	clear_screen();
	std::cout << "\npress 1 for color or 0 for no color\n";
	key = _getch() - '0';
	while (key != WITH_COLOR && key != NO_COLOR)
		key = _getch();
	set_colored(key);
	clear_screen();
	Sleep(300);
	std::cout << "Starting Game in 1..";
	Sleep(300);
	std::cout << "2..";
	Sleep(300);
	std::cout << "3";
	Sleep(300);
	clear_screen();
}

void Game::printBoards() const
{
	this->players[PLAYER1].printBoard(colored);
	this->players[PLAYER2].printBoard(colored);
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
	setTextColor(GameConfig::WHITE);
	if (winner != TIE)
		std::cout << "\n\nTHE WINNER IS: PLAYER NUMBER " << winner + 1 << "!!!" << std::endl;
	else
		std::cout << "\n\nGAME ENDED, IT'S A TIE!!!" << std::endl;
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
	setTextColor((int)GameConfig::Color::WHITE);
	this->players[PLAYER1].printBorders();
	this->players[PLAYER2].printBorders();
}

void Game::handleFullRows()
{
	this->players[PLAYER1].handleFullRows();
	this->players[PLAYER2].handleFullRows();
}

void Game::handleBomb(bool move[])
{
	for (int i = 0; i < NUM_OF_PLAYERS; i++)
	{
		if(!move[i])
			this->players[i].handle_bomb();
	}
}

void Game::playGame()
{
	srand(time(NULL));
	char kb;
	int key = 20, i;
	bool new_game; //true if the game is over 
	bool end_game[NUM_OF_PLAYERS]; // true if this player lost 
	bool move[NUM_OF_PLAYERS] = { false, false }; //true if a move was made
	while (true)
	{
		key = init();

		if (key == GameConfig::EXIT)
			return;

		end_game[PLAYER1] = false;
		end_game[PLAYER2] = false;
		printBorders();
		while (!end_game[PLAYER1] && !end_game[PLAYER2]) // game didn't end
		{
			new_game = false;
			for (i = 0; i < NUM_OF_PLAYERS; i++)
			{
				if (!move[i])
				{
					this->players[i].makeEmptyList();
					//generate a piece to each board
					players[i].getNextBlock();
					//add block to board and check if possible
					if (!players[i].set_block())
						end_game[i] = true;
				}
			}
			printBoards();
			if (isGameEnded(end_game))
				break;
			
			for (int i = 0; i < GameConfig::MAX_MOVES_PER_TURN; i++)
			{
				key = 20;
				kb = inputKbhit();
				//key = players[PLAYER1].playMove(kb, colored);
				//if (!key)
				//	key = players[PLAYER2].playMove(kb, colored);
				players[PLAYER1].playMove(kb, colored);
				players[PLAYER2].playMove(kb, colored);
				printBoards();

				if (key == GameConfig::EXIT)
				{
					cleanExit();
					return;
				}
				else if (key == GameConfig::RESUME_GAME)
					printBorders();
				else if (key == GameConfig::NEW_GAME)
				{
					new_game = true;
					initNewGame();
					break;
				}
				Sleep(10);
				printBoards();
			}
			if (!new_game)
				for (i = 0; i < NUM_OF_PLAYERS; i++)
					move[i] = players[i].moveBlockOnBoard(GameConfig::DOWN);
			emptyKBuffer();
			Sleep(100);
			if (!move[PLAYER1] || !move[PLAYER2])
			{
				handleBomb(move);
				handleFullRows();
			}
			printBoards();

		}
	}
	clear_screen();
}
char Game::inputKbhit()
{
	if (!_kbhit())
		return GameConfig::DO_NOTHING;
	else
		return _getch();
}

void Game::cleanExit()
{
	setTextColor((int)GameConfig::Color::WHITE);
	clear_screen();
}

void Game::initNewGame()
{
	initColor();
	zeroPlayingBoards();
	printBorders();
	players[PLAYER1].getNextBlock();
	players[PLAYER2].getNextBlock();
}


void Game::zeroPlayingBoards()
{
	this->players[PLAYER1].ZeroPlayingBoard();
	this->players[PLAYER2].ZeroPlayingBoard();

}

