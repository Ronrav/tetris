#ifndef __PLAYER_H
#define __PLAYER_H
#include "board.h"
#include "shape.h"
#include "gameConfig.h"

class Player
{
	Board board;
	Shape block;
	char left_key;
	char right_key;
	char drop_key;
	char rotate_key;
	char rotate_counter_key;
	int start_x;
	int start_y;

public:
	void init(char which_player, int x, int y, int colored);
};




#endif // !__PLAYER_H

