#ifndef __POINT_H
#define __POINT_H
#include "utills.h"
#include "gameConfig.h"
#include "board.h"
#include <iostream>
#include <Windows.h>
using namespace std;

class Point
{
	int x;
	int y;
	int color;


public:
	Point(int _x, int _y) : x(_x), y(_y), color(GameConfig::COLORS[0]) {};
	Point() {};
	void set(int _x, int _y, int _color = GameConfig::COLORS[0]);
	void draw(char ch, int backcolor);
	void move(int new_x, int new_y);
	int getY();
	int getX();
	void setX(int _x);
	void setY(int _y);
	int getColor();
};

#endif
