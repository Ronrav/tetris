#include "player.h"


void Player::printBoard(int colored) const
{
	this->playing_board.printBoard(colored);
}

void Player::printBorders() const
{
	this->playing_board.drawBoardBorder();
}

void Player::getNextBlock()
{
	this->block.getShape();
}

bool Player::moveBlockOnBoard(char direction)
{
	bool moved;
	Shape tmp;
	//use copy ctor
	tmp = this->block;
	switch (direction)
	{
	case(GameConfig::LEFT):
		tmp.moveLeft();
		break;
	case(GameConfig::RIGHT):
		tmp.moveRight();
		break;
	case(GameConfig::DOWN):
		tmp.moveDown();
		break;
	case(GameConfig::ROTATE_CLOCKWISE):
		tmp.rotateClockWise();
		break;
	case(GameConfig::ROTATE_COUNTERCLOCKWISE):
		tmp.rotateCounterClockWise();
		break;
	default:
		break;
	}
	moved = this->playing_board.assignShapeToBoard(this->block, tmp);
	if (moved)
		this->block = tmp;
	return moved;
}

void Player::dropBlock(int colored)
{
	while (moveBlockOnBoard('D'))
	{
		this->playing_board.printBoard(colored);
		Sleep(10);
	}
}

int Player::handleFullRows()
{
	return this->playing_board.handleFullRows();
}

bool Player::set_block()
{
	return this->playing_board.set_block(this->block);
}

void Player::handle_bomb()
{
	this->playing_board.handle_bomb(this->block);
}

void Player::ZeroPlayingBoard()
{
	this->playing_board.zeroBoard();
}


int Player::makeMove(char key, int colored)
{
	switch (key)
	{
	
	case(GameConfig::DO_NOTHING):
		break;
		//esc
	case(GameConfig::ESC):
		return Menu::handlePauseMenu();
		break;

	case((char)GameConfig::LKeys::LEFT_LOWER):
	case((char)GameConfig::LKeys::LEFT_UPPER):
	case((char)GameConfig::RKeys::LEFT_LOWER):
	case((char)GameConfig::RKeys::LEFT_UPPER):
		//move left
		moveBlockOnBoard(GameConfig::LEFT);
		break;

	case((char)GameConfig::LKeys::RIGHT_LOWER):
	case((char)GameConfig::LKeys::RIGHT_UPPER):
	case((char)GameConfig::RKeys::RIGHT_LOWER):
	case((char)GameConfig::RKeys::RIGHT_UPPER):
		//move right
		moveBlockOnBoard(GameConfig::RIGHT);
		break;

	case((char)GameConfig::LKeys::ROTATE_CLOCKWISE_LOWER):
	case((char)GameConfig::LKeys::ROTATE_CLOCKWISE_UPPER):
	case((char)GameConfig::RKeys::ROTATE_CLOCKWISE_LOWER):
	case((char)GameConfig::RKeys::ROTATE_CLOCKWISE_UPPER):
		//Rotate clockwise
		moveBlockOnBoard(GameConfig::ROTATE_CLOCKWISE);
		break;

	case((char)GameConfig::LKeys::ROTATE_COUNTERCLOCKWISE_LOWER):
	case((char)GameConfig::LKeys::ROTATE_COUNTERCLOCKWISE_UPPER):
	case((char)GameConfig::RKeys::ROTATE_COUNTERCLOCKWISE_LOWER):
	case((char)GameConfig::RKeys::ROTATE_COUNTERCLOCKWISE_UPPER):

		//rotate counterclockwise
		moveBlockOnBoard(GameConfig::ROTATE_COUNTERCLOCKWISE);
		break;

	case((char)GameConfig::LKeys::DROP_LOWER):
	case((char)GameConfig::LKeys::DROP_UPPER):
	case((char)GameConfig::RKeys::DROP_LOWER):
	case((char)GameConfig::RKeys::DROP_UPPER):
		//drop block
		dropBlock(colored);
		break;
	
	}

	return GameConfig::MADE_MOVE;

}

bool Player::inputNewBlockToBoard()
{
	getNextBlock();
	return set_block();
}