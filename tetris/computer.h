#pragma once

#include "Player.h"

class Computer : public Player
{
	Shape final_block_state;
	void getMovesVector();

public:
	Computer() {};
	Computer(const Board& b) : board(b), final_block_state(board.getBlock()) {};//maybe we dont need the ;
	void calculateBestMove();//update the final_shape_state to the wanted one
	void playTurn();
	void getMovesArray();
};