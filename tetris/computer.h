#ifndef __COMPUTER_H
#define __COMPUTER_H
#include <list>
#include "Player.h"

class Computer : public Player
{
	std::list<char> moves_list;
	void getMovesVector();

public:
	Computer();
	void calculateBestMove();//update the final_shape_state to the wanted one
	void playTurn();
	void getMovesArray();
	void getNextBlock();
	void inputMovesVector();
	void fitRotation(const Shape& best, Shape& copy);
	void fitLocation(const Shape& best, Shape& copy);
	int playMove(char key, int colored);
};

#endif