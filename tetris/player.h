#ifndef __PLAYER_H
#define __PLAYER_H
#include "board.h"
#include <vector>
#include "menu.h"

class Player
{
protected:
	Board playing_board;
	Shape block;

public:
	
	Player() { block.getShape(); }
	virtual ~Player() {};
	void printBoard(int colored) const;
	void printBorders() const;
	virtual void getNextBlock() = 0;
	virtual void makeEmptyList() = 0;



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

	void handle_bomb();

	void ZeroPlayingBoard();
	
	virtual int makeMove(char key, int colored);


	bool inputNewBlockToBoard();
	virtual int playMove(char key, int colored) = 0;

};

#endif // !__PLAYER_H

