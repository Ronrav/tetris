#ifndef __COMPUTER_H
#define __COMPUTER_H
#include "Player.h"

class Computer : public Player
{
	Shape final_block;
	char level;
	
	//returns a final shape for computers next move
	Shape findBestMove();

	//finds optimal move, returns a shape that is located in the optimal place
	Shape calculateBestMove();

	//generates random valid move
	Shape getRandomMove();

	//generates best move for bomb move
	Shape calculateBombBestMove();
	
	void dropNoPrint() {
		while (moveBlockOnBoard(GameConfig::DOWN)) {}
	}
	
	void moveBlockToLeftmost()
	{
		while (moveBlockOnBoard(GameConfig::LEFT)) {}
	}
	
	//function for calculating the best move
	int countNoHoles();
	
	//function for calculating the best move
	int calculateScore();
	
	//function for calculating the best move
	bool decideIfBestMove();
	
	//function for calculating the best move
	int lowestColumn();
	
	//returns a char representing the computers next move according to the final shape member and the current block
	char getNextMove();
	
	//inputs final block data member
	void inputFinalBlock();

	static constexpr char BEST = 'a';
	static constexpr char GOOD = 'b';
	static constexpr char NOVICE = 'c';


public:
	
	Computer(char level = BEST) :level(level) {};
	
	virtual ~Computer() {};
	
	//generates next block for computer, and also the final shape member according to this block
	virtual void getNextBlock() override;
	
	//plays a computer move
	virtual int playMove(char key, int colored) override;



	
};

#endif