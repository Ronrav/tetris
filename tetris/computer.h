#ifndef __COMPUTER_H
#define __COMPUTER_H
#include <list>
#include "Player.h"

class Computer : public Player
{
	std::list<char> moves_list;

	void getMovesArray(const Shape& best_move);

	Shape calculateBestMove();

	void dropNoPrint() {
		while (moveBlockOnBoard('D')) {}
	}

	void moveBlockToLeftmost()
	{
		while (moveBlockOnBoard('L')) {}
	}
	int countNoHoles();

public:
	Computer() {};
	void getMovesArray();
	void getNextBlock();
	void inputMovesVector();
	void fitRotation(const Shape& best, Shape& copy);
	void fitLocation(const Shape& best, Shape& copy);
	int playMove(char key, int colored);
};

#endif