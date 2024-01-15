#include "board.h"
#include "gameConfig.h"


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
	for (i = 0; i < this->height; i++)
	{
		for (j = 0; j < this->width; j++)
		{
			gotoxy(i, j);
			printDot(this->x + j, this->y + i, this->board[i][j]);
		}
	}
}

bool Board::checkIfFreeCoord(int _x, int _y)
{
	if ((_x > this->x && x < this->x + width) &&
		(y > this->y && y < this->y + height) &&
		(this->board[x][y] == ' '))
		return true;
	return false;

}

void Board::copyBoard(char** copy_board)
{
	for (int i = 0; i < this->width; i++)
	{
		for (int j = 0; j < this->height; j++)
			copy_board[i][j] = board[i][j];
	}
}