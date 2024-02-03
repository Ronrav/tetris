#ifndef __BOARD_H
#define __BOARD_H
#include "gameConfig.h"
#include "utills.h"
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <iostream>
#include "shape.h"
using namespace std;


class Board
{
	int x; //The x coordinate of the upper-left corner of the board. 
	int y; //The y coordinate of the upper-left corner of the board.
	int colored; //according to the players choice
	int board[GameConfig::BOARD_HEIGHT][GameConfig::BOARD_WIDTH]; 
	Shape block; 
public:
	
	
	// Initializes the game board with empty cells.
	void init(int _x, int _y, int _colored);

	//Draws the border around the game board.
	void drawBoardBorder();


	//Prints the contents of the game board with colored dots.
	void printBoard();


	//Checks if a specific coordinate is on the board and if its free.
	bool checkIfFreeCoord(int _x, int _y);


	//Copies the current state of the board to another board.
	void copyBoardTo(int copy_board[GameConfig::BOARD_HEIGHT][GameConfig::BOARD_WIDTH]) const;


	// Copies a given board to the current board.
	void copyToBoard(int copy_board[GameConfig::BOARD_HEIGHT][GameConfig::BOARD_WIDTH]);


	// Copies a given board to the current board.
	//return true if the shape was successfully assigned.
	bool assignShapeToBoard(Shape copy) const;
	


	//Checks if a specific row is full.
	//Returns 'true' if the row is full.
	bool isFullRow(int row);


	// Handles clearing full rows on the board.
	//Returns 'true' if any row was deleted.
	bool handleFullRows();


	//Gets a row to delete.
	//Deletes a full row and moves the rows above it down.
	void deleteAndMoveRow(int row);


	//Retrieves the shape for the current block.
	void setBlock();


	//Gets the direction of movment.
	//Moves the block in the specified direction on the board.
	//return 'true' if the block was moved.
	bool moveBlockOnBoard(char direction);


	//Drops the block to the lowest possible position on the board.
	void dropBlock();


	//Sets the current block on the board, checking for collisions.
	//returns 'true' if the block has seccesfully set.
	bool set_block();
	
	Shape getBlock() const
	{
		return this->block;
	}

	void updateBoard(Shape new_shape);
};

#endif

