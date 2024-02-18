#ifndef __COMPUTER_H
#define __COMPUTER_H
#include "Player.h"

class Computer : public Player
{
	Shape final_block;
	char level;

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
	
	char getNextMove();
	
	void inputFinalBlock();

	static constexpr char BEST = 'a';
	static constexpr char GOOD = 'b';
	static constexpr char NOVICE = 'c';


public:
	
	Computer(char level = BEST) :level(level) {};
	
	virtual ~Computer() {};
	
	virtual void getNextBlock() override;
	
	virtual int playMove(char key, int colored) override;



	
};

#endif