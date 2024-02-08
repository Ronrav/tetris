#include "board.h"

int Board::colored = 0;

void Board::init(int _x, int _y)
{
	this->x = _x;
	this->y = _y;
	for (int i = 0; i < GameConfig::BOARD_HEIGHT; i++)
	{
		for (int j = 0; j < GameConfig::BOARD_WIDTH; j++)
			this->board[i][j] = GameConfig::EMPTY;
	}
	getBlock();
}

void Board::getBlock()
{
	this->block.getShape();
}

void Board::drawBoardBorder() const
{
	for (int col = this->x - 1; col <= this->x + GameConfig::BOARD_WIDTH; col++)
	{
		gotoxy(col, this->y - 1);
		std::cout << "-";

		gotoxy(col, this->y + GameConfig::BOARD_HEIGHT);
		std::cout << "-";
	}

	for (int row = this->y - 1; row <= GameConfig::BOARD_HEIGHT + this->y; row++)
	{
		gotoxy(this->x - 1, row);
		std::cout << "|";

		gotoxy(this->x + GameConfig::BOARD_WIDTH, row);
		std::cout << "|";
	}
	std::cout << std::endl;
}

void Board::printBoard() const
{
	int i, j;
	for (i = 0; i < GameConfig::BOARD_HEIGHT; i++)
	{
		for (j = 0; j < GameConfig::BOARD_WIDTH; j++)
			printDot(this->x + j, this->y + i, this->board[i][j] * colored, (this->board[i][j] != GameConfig::EMPTY));

	}
}

bool Board::checkIfFreeCoord(int _x, int _y) const
{
	if ((_x >= 0) && (_x < GameConfig::BOARD_WIDTH) && (_y < GameConfig::BOARD_HEIGHT) && (_y >= 0) && (this->board[_y][_x] < 0))
		return true;
	return false;

} 

void Board::copyBoardTo(int copy_board[GameConfig::BOARD_HEIGHT][GameConfig::BOARD_WIDTH]) const
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

bool Board::isFullRow(int row) const
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
	for (int i = 0; i < GameConfig::BOARD_HEIGHT; i++)
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
	//use copy ctor
	tmp = this->block;
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
		this->block = tmp;
	return moved;
}

void Board::dropBlock()
{
	while (moveBlockOnBoard('D'))
	{
		printBoard();
		Sleep(20);
	}
}

bool Board::set_block()
{
	Point* arr;
	arr = this->block.getPoints();
	for (int i = 0; i < 4; i++)
	{
		if (this->board[arr[i].getY()][arr[i].getX()] < 0) //check if empty and except bomb handling
			this->board[arr[i].getY()][arr[i].getX()] = this->block.getColor();
		else
			return false;
	}
	return true;
}

void Board::set_colored(int key)
{
	colored = key;
}

void Board::getBombPerimeters(int& _x, int& _y, int source_x, int source_y)
{
	_x = source_x - GameConfig::BOMB_RADIUS;
	_y = source_y - GameConfig::BOMB_RADIUS;
	if (_x < 0)
		_x = 0;
	if (_y < 0)
		_y = 0;
}

Point& Board::getBombSource()
{
	Point* arr;
	arr = this->block.getPoints();
	return arr[0];
}
void Board::handle_bomb()
{
	if (this->block.getShapeType() != GameConfig::BOMB)
		return;
	int x_perimeter, y_perimeter, i, j, x_center, y_center;
	Point bomb_center;
	bomb_center = getBombSource();
	x_center = bomb_center.getX();
	y_center = bomb_center.getY();
	getBombPerimeters(x_perimeter, y_perimeter, bomb_center.getX(), bomb_center.getY());
	for (i = y_perimeter; i < y_center + GameConfig::BOMB_RADIUS && i < GameConfig::BOARD_HEIGHT; i++)
		for (j = x_perimeter; j < x_center + GameConfig::BOMB_RADIUS && j < GameConfig::BOARD_WIDTH; j++)
			this->board[i][j] = GameConfig::EMPTY;
	

}