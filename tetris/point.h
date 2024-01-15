#pragma once

#include "gameConfig.h"
#include "board.h"

class Point
{
	int x;
	int y;
	int color;
	Board& board;//maybe we won't need it :(

public:
	Point(int _x, int _y, Board& _board) : x(_x), y(_y), board(_board), color(GameConfig::COLORS[0]) {};
	void set(int _x, int _y, int _color = GameConfig::COLORS[0]);
	void draw(char ch, int backcolor);
	void move(int new_x, int new_y);
	int getY();
	int getX();
	int get_color();
};

