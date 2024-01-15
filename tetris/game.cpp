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

void Game::init()
{
	int key = this->handleStartMenu();
	if (key != 9)
	{
		cout << "\npress 1 for color or 0 for no color\n";
		key = _getch();
		while (key - '0' != 1 && key - '0' != 0)
			key = _getch();
		clear_screen();
		cout << "Starting Game in 1..";
		Sleep(500);
		cout << "2..";
		Sleep(500);
		cout << "3";
		Sleep(500);
		clear_screen();
		this->board1.init(GameConfig::MIN_X, GameConfig::MIN_Y, key-'0');
		this->board2.init(GameConfig::MIN_X + GameConfig::BOARD_WIDTH + GameConfig::BOARDS_GAP, GameConfig::MIN_Y,key-'0');
		this->board1.drawBoardBorder();
		this->board2.drawBoardBorder();
	}
	
	
}

void Game::play(int color)
{
	bool end_game = false;
	Shape s1, s2, cpy_s1, cpy_s2;
	int x1, y1, x2, y2;

	this->board1.findStartPoint(&x1, &y1);
	s1.getShape(x1, y1);
	s1.copyShape(cpy_s1);

	//this->board2.findStartPoint(&x2, &y2);
	//findStartPoint(&x2, &y2);
	//s2.getShape(x2, y2);
	//copy

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
			



		/*int start_x, start_y;
		Board cpy_board;
		bool end_turn = false;

		findStartPoint(player, &start_x, &start_y);
		s.assignShape(start_x, start_y))
		thisPlayerIsTheLooser(player);


		while (!end_turn)
		{
			findStartPoint(player, &start_x, &start_y);
			if (!s.assignShape(start_x, start_y))
				thisPlayerIsTheLooser(player);

		//s1.assign_shape(initial postion);
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



//get the looser player, prints results and ends the game
void thisPlayerIsTheWinner(int player)
{
	clear_screen();
	cout << "THE WINNER IS: PLAYER NUMBER " << player << endl;
	return;
}




/*#include "game.h"


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
		key = _getch();
		while (key - '0' != 1 && key - '0' != 0)
			key = _getch();
		clear_screen();
		cout << "Starting Game in 1..";
		Sleep(500);
		cout << "2..";
		Sleep(500);
		cout << "3";
		Sleep(500);
		clear_screen();
		this->board1.init(GameConfig::MIN_X, GameConfig::MIN_Y, key-'0');
		this->board2.init(GameConfig::MIN_X + GameConfig::BOARD_WIDTH + GameConfig::BOARDS_GAP, GameConfig::MIN_Y,key-'0');
		this->board1.drawBoardBorder();
		this->board2.drawBoardBorder();
	}
	return key;
	
}

void Game::play(int color)
{
	bool end_game = false;
	Shape s1, s2, cpy_s1, cpy_s2;
	int x1, y1, x2, y2;

	this->board1.findStartPoint(&x1, &y1);
	s1.getShape(x1, y1);
	s1.copyShape(cpy_s1);

	//this->board2.findStartPoint(&x2, &y2);
	//findStartPoint(&x2, &y2);
	//s2.getShape(x2, y2);
	//copy

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
			



		/*int start_x, start_y;
		Board cpy_board;
		bool end_turn = false;

		findStartPoint(player, &start_x, &start_y);
		s.assignShape(start_x, start_y))
		thisPlayerIsTheLooser(player);


		while (!end_turn)
		{
			findStartPoint(player, &start_x, &start_y);
			if (!s.assignShape(start_x, start_y))
				thisPlayerIsTheLooser(player);

		//s1.assign_shape(initial postion);
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



//get the looser player, prints results and ends the game
void thisPlayerIsTheLooser(int player)
{
	return;
}*/