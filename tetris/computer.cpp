#include "computer.h"

void Computer::calculateBestMove()
{
	int bestScore = -1; // Initialize the best score to an invalid value.
	Shape bestMove;     // Initialize the best move as an empty shape.

	// Create a copy of the board to simulate the move.
	int tempBoard[GameConfig::BOARD_HEIGHT][GameConfig::BOARD_WIDTH];
	board.copyBoardTo(tempBoard);

	// Create a copy of the current block.
	Shape currentBlock = final_block_state;

	// Iterate through all possible rotations of the current block.
	for (int rotation = 0; rotation < Shape::ROTATE_STATES; rotation++)
	{
		currentBlock.rotateClockWise(); // Rotate the block.
		// Iterate through all possible positions starting from the left-most.
		for (int x = 0; x <= GameConfig::BOARD_WIDTH; x++)
		{
			// Set the initial position of the block.
			currentBlock.moveRight();

			// Move the block down until it can't move further.
			while (board.assignShapeToBoard(currentBlock))
				currentBlock.moveDown();
			
			// Calculate the score for this move.
			int score = 0;
			while (board.handleFullRows())
				score += 100; // Reward for clearing a line.

			// Update the best move if this move has a higher score.
			if (score > bestScore)
			{
				bestScore = score;
				bestMove = currentBlock;
			}

			// Restore the board to its previous state for the next iteration.
			board.copyToBoard(tempBoard);
		}
	}

	// After iterating through all possible moves, apply the best move (position with highest score).
    //  board.assignShapeToBoard(bestMove); - we dont want to change the board
	final_block_state = bestMove;
}


void Computer::getMovesArray()
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