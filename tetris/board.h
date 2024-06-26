#ifndef __BOARD_H
#define __BOARD_H
#include "gameConfig.h"
#include "utills.h"
#include "shape.h"


class Board
{
	int x = GameConfig::MIN_X; //The x coordinate of the upper-left corner of the board. 
	int y = GameConfig::MIN_Y;; //The y coordinate of the upper-left corner of the board.
	int board[GameConfig::BOARD_HEIGHT][GameConfig::BOARD_WIDTH];
	static int dist_x;




	//Copies the current state of the board to another board.
	void copyBoardTo(int copy_board[GameConfig::BOARD_HEIGHT][GameConfig::BOARD_WIDTH]) const;


	// Copies a given board to the current board.
	void copyToBoard(int copy_board[GameConfig::BOARD_HEIGHT][GameConfig::BOARD_WIDTH]);

	//Checks if a specific row is full.
	//Returns 'true' if the row is full.
	bool isFullRow(int row) const;


	//Gets a row to delete.
	//Deletes a full row and moves the rows above it down.
	void deleteAndMoveRow(int row);


	int& pos(const Point& p)
	{
		return board[p.getY()][p.getX()];
	}

	//returns bomb explosion radius by reference
	void getBombPerimeters(int& x, int& y, int source_x, int source_y) const;


	bool isPointFreeOnBoard(const Point& p);

public:

	Board();
	~Board() { dist_x = 0; }

	//Checks if a specific coordinate is on the board and if its free.
	bool checkIfFreeCoord(int _x, int _y) const;

	void zeroBoard();

	//Draws the border around the game board.
	void drawBoardBorder() const;


	//Prints the contents of the game board with colored dots.
	void printBoard(int colored) const;



	// Copies a given board to the current board.
	//return true if the shape was successfully assigned.
	bool assignShapeToBoard(const Shape& orig_block, const Shape& new_block);


	// Handles clearing full rows on the board.
	//Returns 'true' if any row was deleted.
	int handleFullRows();

	//Sets the current block on the board, checking for collisions.
	//returns 'true' if the block has seccesfully set.
	bool set_block(const Shape& block);

	//deletes all sqaures in bomb radius on board
	void handle_bomb(const Shape& block);

	//set block's place in board to empty
	void zeroShapePlace(const Shape& shape);

	//set block's place on board to occupied
	void applyBlock(const Shape& shape);

	//returns the column number that has the highest number of block parts
	int getHighestColumn() const;
};

#endif

