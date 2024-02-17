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
	void fitRotation(const Shape& best, Shape& copy);
	void fitLocation(const Shape& best, Shape& copy);
	bool inputNewBlockToBoard();
	void inputMovesVector();

public:
	Computer(char level = 'a') :level(level) {};
	virtual ~Computer() {};
	void  getNextBlock() override;
	int playMove(char key, int colored) override;
	void makeEmptyList() override;

	static constexpr char BEST = 'a';
	static constexpr char GOOD = 'b';
	static constexpr char NOVICE = 'c';
	
};

#endif