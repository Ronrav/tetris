#include "computer.h"



void Computer::calculateBestMove()
{
	bool flag = true, is_first = true, is_right
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
			this->block.rotate(true);

		moveBlockToLeftmost(); 
		//Shape currentBlock = block; //ואז נחזור לפה ונסובב שומר את המיקום הראשון של הצורה באיקס המסוים
		while(flag) //while+bool
		{
			const Shape shape_saver2 = this->block;
			dropNoPrint();
			// Calculate the score for this move.
			int score = 0;
			score += 100 * playing_board.handleFullRows(); // Reward for clearing a line. צריך שיחזיר את כמות השורות 
				
			score += NoHoles();//5 על כל קוביה טובה

			// Update the best move if this move has a higher score.
			if (score > bestScore)
			{
				best_score = score;
				best_move = currentBlock;
			}

			this->playing_board.copyToBoard(board_saver);
			this->block = saver2;
			//moveBlockOnBoard('R');
			// Restore the board to its previous state for the next iteration.
			flag = moveBlockOnBoard('R');

		}

		//playingBoard	= להחזיר את הצורה
	}
	

	// After iterating through all possible moves, apply the best move (position with highest score).
	//  board.assignShapeToBoard(bestMove); - we dont want to change the board
	final_block_state = bestMove;
}


/*void Computer::getMovesArray()
{
	Shape curr_bock = board.getBlock();
	int diff_x = curr_block.get



}

void Computer::playTurn()
{
	Shape curr_block = board.getBlock();
	char move = curr_block.moveToWanted(final_block_state);

	switch (move)
	{
	case((int)Shape::LEFT):
		this->board.moveBlockOnBoard(RIGHT);
		break;
	case((int)LKeys::ROTATE_CLOCKWISE_LOWER):
	case((int)LKeys::ROTATE_CLOCKWISE_UPPER):
		//Rotate clockwise
		this->boards[PLAYER1].moveBlockOnBoard(ROTATE_CLOCKWISE);
		break;
	case((int)LKeys::ROTATE_COUNTERCLOCKWISE_LOWER):
	case((int)LKeys::ROTATE_COUNTERCLOCKWISE_UPPER):
		//rotate counterclockwise
		this->boards[PLAYER1].moveBlockOnBoard(ROTATE_COUNTERCLOCKWISE);
		break;
	case((int)LKeys::DROP_LOWER):
	case((int)LKeys::DROP_UPPER):
		//drop block
		this->boards[PLAYER1].dropBlock();
		break;
	case((int)RKeys::LEFT_LOWER):
	case((int)RKeys::LEFT_UPPER):
		//move left
		this->boards[PLAYER2].moveBlockOnBoard(LEFT);
		break;
	case((int)RKeys::RIGHT_LOWER):
	case((int)RKeys::RIGHT_UPPER):
		//move right
		this->boards[PLAYER2].moveBlockOnBoard(RIGHT);
		break;
	case((int)RKeys::ROTATE_CLOCKWISE_LOWER):
	case((int)RKeys::ROTATE_CLOCKWISE_UPPER):
		//Rotate clockwise
		this->boards[PLAYER2].moveBlockOnBoard(ROTATE_CLOCKWISE);
		break;
	case((int)RKeys::ROTATE_COUNTERCLOCKWISE_LOWER):
	case((int)RKeys::ROTATE_COUNTERCLOCKWISE_UPPER):
		//rotate counterclockwise
		this->boards[PLAYER2].moveBlockOnBoard(ROTATE_COUNTERCLOCKWISE);
		break;
	case((int)RKeys::DROP_LOWER):
	case((int)RKeys::DROP_UPPER):
		//drop block
		this->boards[PLAYER2].dropBlock();
		break;
	}
}
*/
void Computer::getNextBlock()
{
	this->block.getShape();
	inputMovesVector();
}

void Computer::inputMovesVector()
{
	Shape best, copy;
	//best = getBestMove()
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