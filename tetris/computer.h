#pragma once
#include "board.h"
#include "shape.h"
class Computer
{
	Board board;
	Shape final_shape_state;

public:

	Computer(const Board& b) : board(b), final_shape_state(board.getBlock()) {};//maybe we dont need the ;
	void calculateBestMove();//update the final_shape_state to the wanted one
	void playTurn();
	
	
};





