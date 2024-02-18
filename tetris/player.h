#ifndef __PLAYER_H
#define __PLAYER_H
#include "board.h"


class Player
{
protected:
	Board playing_board;
	Shape block;

public:
	
	Player() { block.getShape(); }
	virtual ~Player() {};
	
	//print player's board
	void printBoard(int colored) const;
	
	//print players's board's borders
	void printBorders() const;
	
	//enforce implementation of function to generate new block for a player
	virtual void getNextBlock() = 0;

	virtual int playMove(char key, int colored) = 0;

	//Gets the direction of movment.
	//Moves the block in the specified direction on the board.
	//return 'true' if the block was moved.
	bool moveBlockOnBoard(char direction);


	//Drops the block to the lowest possible position on the board.
	void dropBlock(int colored);

	// Handles clearing full rows on the board.
	//Returns 'true' if any row was deleted.
	int handleFullRows();


	//Sets the current block on the board, checking for collisions.
	//returns 'true' if the block has seccesfully set.
	bool set_block();

	//handles bomb explosion
	void handle_bomb();

	//zero board to empty
	void ZeroPlayingBoard();
	
	//receives a key and a performes a move accordingly
	int makeMove(char key, int colored);

	//generates a new block and tries to place it on the board. returns false if board does nto have room for a new block
	bool inputNewBlockToBoard();

	//moves player block one spot down
	bool gravitate_block();

};

#endif // !__PLAYER_H

