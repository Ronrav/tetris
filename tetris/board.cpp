#include "board.h"

int Board::dist_x = 0;

Board::Board() : x(GameConfig::MIN_X + dist_x), y(GameConfig::MIN_Y)
{
	zeroBoard();
	dist_x += GameConfig::BOARD_WIDTH + GameConfig::BOARDS_GAP;
}

void Board::zeroBoard()
{
	for (int i = 0; i < GameConfig::BOARD_HEIGHT; i++)
	{
		for (int j = 0; j < GameConfig::BOARD_WIDTH; j++)
			this->board[i][j] = GameConfig::EMPTY;
	}
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

void Board::printBoard(int colored) const
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

bool Board::assignShapeToBoard(const Shape& orig_block, const Shape& new_block)
{
	int backup_board[GameConfig::BOARD_HEIGHT][GameConfig::BOARD_WIDTH];
	this->copyBoardTo(backup_board);

	for (const Point& p: orig_block)
	{
		this->pos(p) = GameConfig::EMPTY;
	}

	for (const Point& p : new_block)
	{
		if (checkIfFreeCoord(p.getX(), p.getY()))
			this->pos(p) = new_block.getColor();
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

bool Board::isPointFreeOnBoard(const Point& p)
{
	return (pos(p) < 0);
}

bool Board::set_block(const Shape& block)
{
	for (const Point& p : block)
	{
		if (isPointFreeOnBoard(p))
			this->pos(p) = block.getColor();
		else
			return false;
	}
	return true;
}


void Board::getBombPerimeters(int& _x, int& _y, int source_x, int source_y) const
{
	_x = source_x - GameConfig::BOMB_RADIUS;
	_y = source_y - GameConfig::BOMB_RADIUS;
	if (_x < 0)
		_x = 0;
	if (_y < 0)
		_y = 0;
}

void Board::handle_bomb(const Shape& block)
{
	if (block.getShapeType() != GameConfig::BOMB)
		return;
	int x_perimeter, y_perimeter, i, j, x_center, y_center;
	Point bomb_center;
	bomb_center = block.getBombSource();
	x_center = bomb_center.getX();
	y_center = bomb_center.getY();
	getBombPerimeters(x_perimeter, y_perimeter, bomb_center.getX(), bomb_center.getY());
	for (i = y_perimeter; i < y_center + GameConfig::BOMB_RADIUS && i < GameConfig::BOARD_HEIGHT; i++)
		for (j = x_perimeter; j < x_center + GameConfig::BOMB_RADIUS && j < GameConfig::BOARD_WIDTH; j++)
			this->board[i][j] = GameConfig::EMPTY;
}