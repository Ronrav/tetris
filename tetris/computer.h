#pragma once
#include "board.h"
#include "shape.h"
class Computer
{
	Board board;
	Shape final_block_state;

public:

	Computer(const Board& b) : board(b), final_block_state(board.getBlock()) {};//maybe we dont need the ;
	void calculateBestMove();//update the final_shape_state to the wanted one
	void playTurn();
	void getMovesArray();
};