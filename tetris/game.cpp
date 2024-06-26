#include "game.h"

int Game::colored = 0;

void Game::set_colored(int key)
{
	colored = key;
}

int Game::init(Player** players)
{
	//set text color white

	hideCursor();
	int key = Menu::handleMenu(players, true);
	if (key != Menu::EXIT)
	{
		initColor();
	}
	return key;
	
}


void Game::initColor()
{
	//set text color white
	setTextColor((int)GameConfig::Color::WHITE);
	int key = -1;
	clear_screen();
	std::cout << "\npress 1 for color or 0 for no color\n";
	
	do 
		key = _getch() - '0';
	while (key != WITH_COLOR && key != NO_COLOR);
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
	players[PLAYER1]->printBoard(colored);
	players[PLAYER2]->printBoard(colored);
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
		std::cout << "\n\n\n\nTHE WINNER IS: PLAYER NUMBER " << winner + 1 << "!!!" << std::endl;
	else
		std::cout << "\n\n\n\nGAME ENDED, IT'S A TIE!!!" << std::endl;
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
	players[PLAYER1]->printBorders();
	players[PLAYER2]->printBorders();
}

void Game::handleFullRows()
{
	players[PLAYER1]->handleFullRows();
	players[PLAYER2]->handleFullRows();
}

void Game::playGame()
{
	srand(time(NULL));
	int key = 20, i;
	bool new_game; //true if the game is over 
	bool end_game[NUM_OF_PLAYERS]; // true if this player lost 
	bool move[NUM_OF_PLAYERS] = { false, false }; //true if a move was made
	while (true)
	{
		key = init(players);

		if (key == Menu::EXIT)
			return;

		end_game[PLAYER1] = end_game[PLAYER2] = false;
		printBorders();
		while (!end_game[PLAYER1] && !end_game[PLAYER2]) // game didn't end
		{
			new_game = false;

			//input new block to each board, if it is not possible, meaning end of game
			for (i = 0; i < NUM_OF_PLAYERS; i++)
				if (!move[i])
					if(!players[i]->inputNewBlockToBoard())
						end_game[i] = true;

			printBoards();
			if (isGameEnded(end_game))
				break;

			for (int i = 0; i < GameConfig::MAX_MOVES_PER_TURN; i++)
			{
				key = playPlayersTurn(players);
				printBoards();
				switch (key)
				{
				case(Menu::EXIT):
					cleanExit();
					return;
					break;
				case(Menu::RESUME_GAME):
					printBorders();
					break;
				case(Menu::NEW_GAME):
					new_game = true;
					move[PLAYER1] = move[PLAYER2] = false;
					i = GameConfig::MAX_MOVES_PER_TURN;
					initNewGame();
					break;
				}
				printBoards();
			}
			if (!new_game)
				handleTurnEnd(move);
			emptyKBuffer();
		}
		std::cout << "finished one game";
	}
	clear_screen();
}
			
char Game::inputKbhit() const
{
	if (!_kbhit())
		return GameConfig::DO_NOTHING;
	else
		return _getch();
}

void Game::cleanExit() const
{
	setTextColor((int)GameConfig::Color::WHITE);
	clear_screen();
}

void Game::initNewGame()
{
	initColor();
	printBorders();
}

int Game::playPlayersTurn(Player** players)
{
	char kb = inputKbhit();
	if (kb == GameConfig::ESC)
		return Menu::handleMenu(players, false);
	players[PLAYER1]->playMove(kb, colored);
	players[PLAYER2]->playMove(kb, colored);
	return GameConfig::DO_NOTHING;
}

void Game::handleTurnEnd(bool move[])
{
	//check if block was dropped all the way down
	for (int i = 0; i < NUM_OF_PLAYERS; i++)
	{
		move[i] = players[i]->gravitate_block();
		Sleep(50);
		if (!move[i])
			players[i]->handle_bomb();
	}
	handleFullRows();
	printBoards();
}


