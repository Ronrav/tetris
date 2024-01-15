#include "player.h"

void Player::init(char which_player, int x, int y, int colored)
{
	if (which_player == 'r')
	{
		this->left_key = (char)GameConfig::RKeys::LEFT;
		this->right_key = (char)GameConfig::RKeys::RIGHT;
		this->drop_key = (char)GameConfig::RKeys::DROP;
		this->rotate_key = (char)GameConfig::RKeys::ROTATE;
		this->rotate_counter_key = (char)GameConfig::RKeys::ROTATE_COUNTER;
	}
	else
	{
		this->left_key = (char)GameConfig::LKeys::LEFT;
		this->right_key = (char)GameConfig::LKeys::RIGHT;
		this->drop_key = (char)GameConfig::LKeys::DROP;
		this->rotate_key = (char)GameConfig::LKeys::ROTATE;
		this->rotate_counter_key = (char)GameConfig::LKeys::ROTATE_COUNTER;
	}
	this->board.init(x, y, colored);
	this->start_x = x + GameConfig::BOARD_WIDTH / 2;
	this->start_y = y;
	this->block.getShape(this->start_x, this->start_y);
}