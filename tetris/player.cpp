#include "player.h"


void Player::printBoard(int colored) const
{
	this->playing_board.printBoard(colored);
}

void Player::printBorders() const
{
	this->playing_board.drawBoardBorder();
}

void Player::playTurn(const std::vector<char>& moves_vector)
{

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
	case('L'):
		tmp.moveLeft();
		break;
	case('R'):
		tmp.moveRight();
		break;
	case('D'):
		tmp.moveDown();
		break;
	case('T'):
		tmp.rotateClockWise();
		break;
	case('G'):
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
		Sleep(20);
	}
}
void Player::dropNoPrint()//move to computer.cpp
{
	while (moveBlockOnBoard('D')) {}
}

bool Player::handleFullRows()
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

void Player:: moveBlockToLeftmost()//computer
{
	while (moveBlockOnBoard('L')){}
}

