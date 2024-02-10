#ifndef __PLAYER_H
#define __PLAYER_H
#include "board.h"
#include <vector>
class Player
{
protected:
	Board playing_board;
	Shape block;
	std::vector<char> moves_vector;

public:

	Player() : moves_vector(GameConfig::MAX_MOVES_PER_TURN, GameConfig::DO_NOTHING) { block.getShape(); }
	void printBoard(int colored) const;
	void printBorders() const;
	void playTurn(const std::vector<char>& moves_vector);
	void getNextBlock();


	//Gets the direction of movment.
	//Moves the block in the specified direction on the board.
	//return 'true' if the block was moved.
	bool moveBlockOnBoard(char direction);


	//Drops the block to the lowest possible position on the board.
	void dropBlock(int colored);

	// Handles clearing full rows on the board.
	//Returns 'true' if any row was deleted.
	bool handleFullRows();


	//Sets the current block on the board, checking for collisions.
	//returns 'true' if the block has seccesfully set.
	bool set_block();

	void handle_bomb();

	void makeMove();

	void dropNoPrint();

	void moveBlockToLeftmost();

	void ZeroPlayingBoard();

	void moveBlockToLeftmost(Shape& shape) const;
	Shape getCopyBlock();

};

#endif // !__PLAYER_H

