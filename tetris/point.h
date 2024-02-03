#ifndef __POINT_H
#define __POINT_H
#include "utills.h"
#include "gameConfig.h"
#include <iostream>
#include <Windows.h>
using namespace std;


class Point
{
	int x;
	int y;


public:
	Point(int _x = 0, int _y = 0) : x(_x), y(_y) {};
	void set(int _x, int _y);
	void draw(char ch, int backcolor) const;
	void move(int new_x, int new_y);
	int getY() const;
	int getX() const;
	void setX(int _x);
	void setY(int _y);
	
};

#endif
