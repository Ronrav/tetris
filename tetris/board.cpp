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
	for (i = 0; i < GameConfig::BOARD_HEIGHT; i++)
	{
		for (j = 0; j < GameConfig::BOARD_WIDTH; j++)
		{
			gotoxy(i, j);
			//this->board[i][j].printCchar(this->colored);
		}
	}
}

bool Board::checkIfFreeCoord(int _x, int _y)
{
	if ((_x > this->x && x < this->x + width) &&
		(y > this->y && y < this->y + height) &&
		(this->board[x][y] == GameConfig::EMPTY))

}

void Board::copyBoard(char** copy_board)
{
	for (int i = 0; i < GameConfig::BOARD_WIDTH)
	{
		for (j = 0; j < GameConfig::BOARD_HEIGHT)
			copy_board[i][j] = board[i][j];
	}
}