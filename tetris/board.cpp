#include "board.h"


void Board::drawBoardBorder()
{
	for (int col = this->x; col <= this->x + this->width; col++)
	{
		gotoxy(col, this->y - 1);
		cout << "-";

		gotoxy(col, this->y + this->height + 1);
		cout << "-";
	}

	for (int row = this->y - 1; row <= this->height + this->y; row++)
	{
		gotoxy(this->x, row);
		cout << "|";

		gotoxy(this->x + this->width, row);
		cout << "|";
	}
	cout << endl;
}


void Board::printBoard()
{
	int i, j;
	for (i = 0; i < GameConfig::BOARD_HEIGHT; i++)
	{
		for (j = 0; j < GameConfig::BOARD_WIDTH; j++)
		{
			printDot(this->x + j, this->y + i, this->board[i][j]);
		}
	}
}
