#ifndef __BOARD_H
#define __BOARD_H
#include "gameConfig.h"
#include "utills.h"
#include "shape.h"


class Board
{
	int x; //The x coordinate of the upper-left corner of the board. 
	int y; //The y coordinate of the upper-left corner of the board.
	int board[GameConfig::BOARD_HEIGHT][GameConfig::BOARD_WIDTH]; 
	Shape block; 
	static int colored;
public:

	// Initializes the game board with empty cells.
	void init(int _x, int _y);

	//Draws the border around the game board.
	void drawBoardBorder() const;


	//Prints the contents of the game board with colored dots.
	void printBoard() const;


	//Checks if a specific coordinate is on the board and if its free.
	bool checkIfFreeCoord(int _x, int _y) const;


	//Copies the current state of the board to another board.
	void copyBoardTo(int copy_board[GameConfig::BOARD_HEIGHT][GameConfig::BOARD_WIDTH]) const;


	// Copies a given board to the current board.
	void copyToBoard(int copy_board[GameConfig::BOARD_HEIGHT][GameConfig::BOARD_WIDTH]);


	// Copies a given board to the current board.
	//return true if the shape was successfully assigned.
	bool assignShapeToBoard(Shape copy);


	//Checks if a specific row is full.
	//Returns 'true' if the row is full.
	bool isFullRow(int row) const;


	// Handles clearing full rows on the board.
	//Returns 'true' if any row was deleted.
	bool handleFullRows();


	//Gets a row to delete.
	//Deletes a full row and moves the rows above it down.
	void deleteAndMoveRow(int row);


	//Retrieves the shape for the current block.
	void getBlock();


	//Gets the direction of movment.
	//Moves the block in the specified direction on the board.
	//return 'true' if the block was moved.
	bool moveBlockOnBoard(char direction);


	//Drops the block to the lowest possible position on the board.
	void dropBlock();


	//Sets the current block on the board, checking for collisions.
	//returns 'true' if the block has seccesfully set.
	bool set_block();

	static void set_colored(int key);

	void handle_bomb();
	void getBombPerimeters(int& x, int& y, int source_x, int source_y);
	Point& getBombSource();

};

#endif

