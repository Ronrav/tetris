#ifndef __COMPUTER_H
#define __COMPUTER_H
#include <list>
#include "Player.h"

class Computer : public Player
{
	std::list<char> moves_list;
	char level;

	//void getMovesArray(const Shape& best_move);
	Shape findBestMove();
	Shape calculateBestMove();
	Shape getRandomMove();
	Shape calculateBombBestMove();
	void dropNoPrint() {
		while (moveBlockOnBoard(GameConfig::DOWN)) {}
	}
	void moveBlockToLeftmost()
	{
		while (moveBlockOnBoard(GameConfig::LEFT)) {}
	}
	int countNoHoles();
	int calculateScore();
	bool decideIfBestMove();
	int lowestColumn();
	
public:
	Computer(char level):level('a') {};
	~Computer() {delete this;}
	void getMovesArray();
	void getNextBlock();
	void inputMovesVector();
	void fitRotation(const Shape& best, Shape& copy);
	void fitLocation(const Shape& best, Shape& copy);
	int playMove(char key, int colored);
	bool inputNewBlockToBoard();
	static constexpr char BEST = 'a';
	static constexpr char GOOD = 'b';
	static constexpr char NOVICE = 'c';
	void makeEmptyList();
	

};

#endif