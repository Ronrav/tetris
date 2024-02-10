#include "computer.h"

Shape Computer::calculateBestMove()
{
	bool flag = true;
	int best_score = -1; // Initialize the best score to an invalid value.
	Shape best_move;     // Initialize the best move as an empty shape.

	// Create a copy of the board to simulate the move.
	Board board_saver = this->playing_board;
	playing_board.zeroShapePlace(this->block);

	const Shape shape_saver = this->block;//שומר את הצורה הראשונה 


	for (int rotation = 0; rotation < 4; rotation++)
	{
		this->block = shape_saver;
		for (int i = 0; i < rotation; i++)
			this->block.rotateClockWise();

		moveBlockToLeftmost();
		//Shape currentBlock = block; //ואז נחזור לפה ונסובב שומר את המיקום הראשון של הצורה באיקס המסוים
		while (flag) //while+bool
		{
			const Shape shape_saver2 = this->block;
			dropNoPrint();

			// Calculate the score for this move.
			int score = 0;
			score += 100 * (playing_board.handleFullRows()); // Reward for clearing a line. צריך שיחזיר את כמות השורות 

			score += countNoHoles();//5 על כל קוביה טובה

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

		//playing_board = board_saver;
		playing_board.applyBlock(shape_saver);
	}
	return best_move;
}

int Computer::countNoHoles()
{
	int counter = 0;

	for (const Point& p : block)
	{
		for (int i = p.getX() - 1; i < p.getX() + 2; i++)
		{
			for (int j = p.getY() - 1; j < p.getY() + 2; j++)
			{
				if (playing_board.checkIfFreeCoord(i, j))
					counter++;
			}
		}
	}

	return (counter * 5);
}

void Computer::getNextBlock()
{
	this->block.getShape();
	inputMovesVector();
}

void Computer::inputMovesVector()
{
	Shape best, copy;
	best = calculateBestMove();
	copy = this->block;
	fitRotation(best, copy);
	fitLocation(best, copy);
	this->moves_list.push_back(GameConfig::DROP);
}

void Computer::fitRotation(const Shape& best, Shape& copy)
{
	while (copy.getRotationState() != best.getRotationState())
	{
		copy.rotateClockWise();
		this->moves_list.push_back(GameConfig::ROTATE_CLOCKWISE);
	}
}

void Computer::fitLocation(const Shape& best, Shape& copy)
{
	int direction, copy_x, best_x;
	copy_x = copy.getPointByIndex(0).getX();
	best_x = best.getPointByIndex(0).getX();
	char step;

	if (copy_x < best_x)
	{
		step = GameConfig::RIGHT;
		direction = 1;
	}

	else if (copy_x > best_x)
	{
		step = GameConfig::LEFT;
		direction = -1;
	}

	while (copy_x != best_x)
	{
		copy_x += direction;
		this->moves_list.push_back(step);
	}

}


int Computer::playMove(char key, int colored)
{
	if (moves_list.empty())
		return 0;
	key = makeMove(this->moves_list.front(), colored);
	moves_list.pop_front();
	return key;
}

