#include "board.h"
#include "gameConfig.h"


void Board::init(int _x, int _y, int _colored)
{
	this->x = _x;
	this->y = y;
	this->colored = _colored;
	for (int i = 0; i < GameConfig::BOARD_WIDTH; i++)
	{
		for (int j = 0; j < GameConfig::BOARD_HEIGHT; j++)
			this->board[i][j] = GameConfig::EMPTY;
	}
}

void Board::drawBoardBorder()
{
	for (int col = this->x; col <= this->x + GameConfig::BOARD_WIDTH; col++)
	{
		gotoxy(col, this->y - 1);
		cout << "-";

		gotoxy(col, this->y + GameConfig::BOARD_HEIGHT + 1);
		cout << "-";
	}

	for (int row = this->y - 1; row <= GameConfig::BOARD_HEIGHT + this->y; row++)
	{
		gotoxy(this->x, row);
		cout << "|";

		gotoxy(this->x + GameConfig::BOARD_WIDTH, row);
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
			if (this->board[i][j] != GameConfig::EMPTY)
			{
				gotoxy(i, j);
				printDot(this->x + j, this->y + i, this->board[i][j] * this->colored);

			}
		}
	}
}

bool Board::checkIfFreeCoord(int _x, int _y)
{
	if ((_x > this->x && x < this->x + GameConfig::BOARD_WIDTH) &&
		(y > this->y && y < this->y + GameConfig::BOARD_HEIGHT) &&
		(this->board[x][y] == GameConfig::EMPTY))
		return true;
	return false;

}

void Board::copyBoardTo(int copy_board[GameConfig::BOARD_HEIGHT][GameConfig::BOARD_WIDTH])
{
	for (int i = 0; i < GameConfig::BOARD_WIDTH; i++)
	{
		for (int j = 0; j < GameConfig::BOARD_HEIGHT; j++)
			copy_board[i][j] = board[i][j];
	}
}

void Board::copyToBoard(int copy_board[GameConfig::BOARD_HEIGHT][GameConfig::BOARD_WIDTH])
{
	for (int i = 0; i < GameConfig::BOARD_WIDTH; i++)
	{
		for (int j = 0; j < GameConfig::BOARD_HEIGHT; j++)
			 this->board[i][j] = copy_board[i][j];
	}
}

bool Board::assignShapeToBoard(Shape block)
{
	int backup_board[GameConfig::BOARD_HEIGHT][GameConfig::BOARD_WIDTH];
	this->copyBoardTo(backup_board);
	Point* shape_arr;
	shape_arr = block.getPoints();
	for (int i = 0; i < 4; i++)
	{
		if (this->checkIfFreeCoord(shape_arr[i].getX(), shape_arr[i].getY()))
			this->board[shape_arr[i].getX()][shape_arr[i].getY()] = shape_arr[i].getColor();
		else
		{
			this->copyToBoard(backup_board);
			return false;
		}
			
	}
	return true;
}

