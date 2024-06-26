#include "computer.h"

Shape Computer::findBestMove()
{
	if (block.getShapeType() == GameConfig::BOMB)
		return calculateBombBestMove();
	else
		return calculateBestMove();
}

Shape Computer::calculateBestMove()
{
	bool flag = true;
	int best_score = -1;
	Shape best_move;     

	// Create a copy of the board to simulate the move.
	Board board_saver = this->playing_board;
	const Shape shape_saver = this->block;
	
	for (int rotation = 0; rotation < GameConfig::ROTATION_STATES; rotation++)
	{
		this->block = shape_saver;

		moveBlockOnBoard(GameConfig::DOWN);
		moveBlockOnBoard(GameConfig::DOWN);
		moveBlockOnBoard(GameConfig::DOWN);


		for (int i = 0; i < rotation; i++)
			moveBlockOnBoard(GameConfig::ROTATE_CLOCKWISE);

		moveBlockToLeftmost(); 
		flag = true;
		while (flag) 
		{
			const Shape shape_saver2 = this->block;
			dropNoPrint();

			// Calculate the score for this move.
			int score = calculateScore();

			// Update the best move if this move has a higher score.
			if (score > best_score)
			{
				best_score = score;
				best_move = block;
			}

			this->playing_board = board_saver;
			this->block = shape_saver2;
			flag = moveBlockOnBoard(GameConfig::RIGHT);
		}
		playing_board = board_saver;
		block = shape_saver;
	}
	return best_move;
}

Shape Computer::calculateBombBestMove()
{
	const Shape saver = block;
	Shape best_move;
	Board board_saver = playing_board;
	int highest_column = playing_board.getHighestColumn();
	int diff_x = block.getBombSource().getX() - highest_column;
	char direction = GameConfig::LEFT;
	bool flag = true;
	if (diff_x < 0)
	{
		diff_x *= -1;
		direction = GameConfig::RIGHT;
	}
	while (diff_x > 0 && flag)
	{
		flag = moveBlockOnBoard(direction);
		diff_x--;
	}
	dropNoPrint();
	best_move = block;
	block = saver;
	playing_board = board_saver;
	return best_move;
}

int Computer::calculateScore() 
{
	int score = 0; 
	score += 100 * (playing_board.handleFullRows()); 
	score += countNoHoles();
	score += lowestColumn();
	return score;
}

int Computer::lowestColumn() const
{
	int min_hight = 0;// 0 is the highest y coord on board
	int curr_y = GameConfig::BOARD_WIDTH;;
	for (const Point& p : block)
	{
		curr_y = p.getY();
		if (curr_y > min_hight)
			min_hight = curr_y;
	}
	return (COLUMN_GRADE * curr_y);
}

int Computer::countNoHoles() const
{
	int counter = 0;

	for (const Point& p : block)
	{
		for (int i = p.getX() - 1; i < p.getX() + 2; i++)
		{
			for (int j = p.getY() - 1; j < p.getY() + 2; j++)
			{
				if (!playing_board.checkIfFreeCoord(i, j))
					counter++;
			}
		}
	}

	return (counter * HOLES_GRADE);
}

void Computer::getNextBlock()
{
	this->block.getShape();
	inputFinalBlock();
	
}

bool Computer::decideIfBestMove() const
{
	int random;
	switch (level)
	{
	case (GOOD):
		random = getRandom(1, B_ERROR);
		if (random == 1)
			return false;
		return true;

	case (NOVICE):
		random = getRandom(1, C_ERROR);
		if (random == 1)
			return false;
		return true;
	default:
		return true;
	}
}

void Computer::inputFinalBlock()
{
	bool is_best = decideIfBestMove();
	if (is_best)
		this->final_block = findBestMove();
	else
		this->final_block = getRandomMove();

}

//no bomb 
Shape Computer::getRandomMove()
{
	int rotation_state = getRandom(1, 4);
	int x = getRandom(0, GameConfig::BOARD_WIDTH);
	int counter = 0;
	bool flag = true;
	Shape move = block;
	const Shape shape_saver = block;
	const Board board_saver = playing_board;
	moveBlockOnBoard(GameConfig::DOWN);
	moveBlockOnBoard(GameConfig::DOWN);
	moveBlockOnBoard(GameConfig::DOWN);
	if (block.getShapeType() != GameConfig::BOMB)
	{
		for (int i = 0; i < rotation_state; i++)
			moveBlockOnBoard(GameConfig::ROTATE_CLOCKWISE);
	}
	moveBlockToLeftmost();
	while (flag && counter <= x)
		flag = moveBlockOnBoard(GameConfig::RIGHT);
	block = shape_saver;
	playing_board = board_saver;
	return move;
}

char Computer::getNextMove()
{
	int curr_x = block.getPointByIndex(0).getX();
	int best_x = final_block.getPointByIndex(0).getX();

	if (final_block.getRotationState() != block.getRotationState())
		return (char)GameConfig::RKeys::ROTATE_CLOCKWISE_LOWER;
	if (curr_x < best_x)
		return (char)GameConfig::RKeys::RIGHT_LOWER;
	if (curr_x > best_x)
		return (char)GameConfig::RKeys::LEFT_LOWER;
	return (char)GameConfig::RKeys::DROP_LOWER;

}

int Computer::playMove(char key, int colored)
{
	return makeMove(getNextMove(), colored);
}



