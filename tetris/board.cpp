#include "board.h"
#include "gameConfig.h"


void Board::init(int _x, int _y, int _colored)
{
	this->x = _x;
	this->y = _y;
	this->colored = _colored;
	getBlock();
	for (int i = 0; i < GameConfig::BOARD_HEIGHT; i++)
	{
		for (int j = 0; j < GameConfig::BOARD_WIDTH; j++)
			this->board[i][j] = GameConfig::EMPTY;
	}
}

void Board::getBlock()
{
	this->block.getShape();
}

void Board::drawBoardBorder()
{
	for (int col = this->x - 1; col <= this->x + GameConfig::BOARD_WIDTH; col++)
	{
		gotoxy(col, this->y - 1);
		cout << "-";

		gotoxy(col, this->y + GameConfig::BOARD_HEIGHT);
		cout << "-";
	}

	for (int row = this->y - 1; row <= GameConfig::BOARD_HEIGHT + this->y; row++)
	{
		gotoxy(this->x - 1, row);
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
				printDot(this->x + j, this->y + i, this->board[i][j] * this->colored, true);
			else
				printDot(this->x + j, this->y + i, this->board[i][j] * this->colored, false);
		}
	}
}

bool Board::checkIfFreeCoord(int _x, int _y)
{
	if ((_x >= 0) && (_x < GameConfig::BOARD_WIDTH) && (_y < GameConfig::BOARD_HEIGHT) && (_y >= 0) && (this->board[y][x] == GameConfig::EMPTY))
		return true;
	return false;

}

void Board::copyBoardTo(int copy_board[GameConfig::BOARD_HEIGHT][GameConfig::BOARD_WIDTH])
{
	for (int i = 0; i < GameConfig::BOARD_HEIGHT; i++)
	{
		for (int j = 0; j < GameConfig::BOARD_WIDTH; j++)
			copy_board[i][j] = board[i][j];
	}
}

void Board::copyToBoard(int copy_board[GameConfig::BOARD_HEIGHT][GameConfig::BOARD_WIDTH])
{
	for (int i = 0; i < GameConfig::BOARD_HEIGHT; i++)
	{
		for (int j = 0; j < GameConfig::BOARD_WIDTH; j++)
			 this->board[i][j] = copy_board[i][j];
	}
}

bool Board::assignShapeToBoard(Shape copy)
{
	int backup_board[GameConfig::BOARD_HEIGHT][GameConfig::BOARD_WIDTH];
	this->copyBoardTo(backup_board);
	Point* copy_arr, *block_arr;
	copy_arr = copy.getPoints();
	block_arr = this->block.getPoints();


	for (int i = 0; i < 4; i++)
		this->board[block_arr[i].getY()][block_arr[i].getX()]= GameConfig::EMPTY;
	
	for (int i = 0; i < 4; i++)
	{
		if (this->checkIfFreeCoord(copy_arr[i].getX(), copy_arr[i].getY()))
			this->board[copy_arr[i].getY()][copy_arr[i].getX()] = this->block.getColor();
		else
		{
			this->copyToBoard(backup_board);
			return false;
		}	
	}
	return true;
}

bool Board::isFullRow(int row)
{
	for (int i = 0; i < GameConfig::BOARD_WIDTH; i++)
	{
		if (this->board[row][i] == GameConfig::EMPTY)
			return false;
	}
	return true;
}

bool Board::handleFullRows()
{
	bool is_deleted = false;
	for (int i = 0; i < GameConfig::BOARD_HEIGHT-1; i++)
	{
		if (isFullRow(i))
		{
			deleteAndMoveRow(i);
			is_deleted = true;
		}
	}
	return is_deleted;
}

void Board::deleteAndMoveRow(int row)
{
	for (int i = row-1; i >= 0; i--)
	{
		for (int j = 0; j < GameConfig::BOARD_WIDTH; j++)
			this->board[i + 1][j] = this->board[i][j];
	}
	for (int i = 0; i < GameConfig::BOARD_WIDTH; i++)
	{
		this->board[0][i] = GameConfig::EMPTY;
	}
}

bool Board::moveBlockOnBoard(char direction)
{
	bool moved;
	Shape tmp;
	this->block.copyShape(tmp);
	switch (direction)
	{
	case('L'):
		tmp.moveLeft();
		break;
	case('R'):
		tmp.moveRight();
		break;
	case('D'):
		tmp.moveDown();
		break;
	case('T'):
		tmp.rotateClockWise();
		break;
	case('G'):
		tmp.rotateCounterClockWise();
		break;
	default:
		break;
	}
	moved = assignShapeToBoard(tmp);
	if (moved)
		tmp.copyShape(this->block);
	return moved;
}

void Board::dropBlock()
{
	return;
}