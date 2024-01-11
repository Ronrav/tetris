#include "board.h"


void Board::drawBoard(int x, int y, int height, int width)
{
	for (int col = x; col <= x + width; col++)
	{
		gotoxy(col, y - 1);
		cout << "-";

		gotoxy(col, y + height + 1);
		cout << "-";
	}

	for (int row = y - 1; row <= height + y; row++)
	{
		gotoxy(x, row);
		cout << "|";

		gotoxy(x + width, row);
		cout << "|";
	}
}

void Board::drawBoards()
{
	//board 1
	drawBoard(GameConfig::MIN_X, GameConfig::MIN_Y, GameConfig::BOARD_HEIGHT, GameConfig::BOARD_WIDTH);
	//board 2
	drawBoard(GameConfig::MIN_X + GameConfig::BOARD_WIDTH + GameConfig::BOARDS_GAP, GameConfig::MIN_Y, GameConfig::BOARD_HEIGHT, GameConfig::BOARD_WIDTH);
}
