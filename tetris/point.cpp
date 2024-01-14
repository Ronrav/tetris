#include "point.h"
#include "gameConfig.h"
#include "utills.h"
#include "board.h"
#include <iostream>
#include <Windows.h>
using namespace std;

void Point::set(int _x, int _y, int _color = )
{
	x = _x;
	y = _y;
	color = _color;
}
void Point::draw(char ch, int backcolor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), backcolor);
	gotoxy(x + GameConfig::MIN_X - 1, y + GameConfig::MIN_Y - 1);
	cout << ch;
}
//checks if left or right move is possible and how much down steps is possible 
/*
bool Point::isPossiblemoveByKey(GameConfig::eKeys key, int* steps_down)
{
	int new_x, new_y;
	bool is_possible_move = false;

	if (key == GameConfig::eKeys::P1_RIGHT || key == GameConfig::eKeys::P2_RIGHT)
		is_possible_move = this->board.checkIfFreeCoord(x + 1, y);

	else if (key == GameConfig::eKeys::P1_LEFT || key == GameConfig::eKeys::P2_LEFT)
		is_possible_move = this->board.checkIfFreeCoord(x - 1, y);

	else if (key == GameConfig::eKeys::P1_DROP || key == GameConfig::eKeys::P2_DROP)
	{
		while (this->board.checkIfFreeCoord(x, y - 1))
		{
			*steps_down -= 1;
			bool is_possible_move = true;
		}
	}
	return is_possible_move;
}
*/
void Point::move(int new_x, int new_y)
{
	x = new_x;
	y = new_y;
}

int Point::getX()
{
	return x;
}
int Point::getY()
{
	return y;
}




