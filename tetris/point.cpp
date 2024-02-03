#include "point.h"

void Point::set(int _x, int _y)
{
	x = _x;
	y = _y;
}

int Point::getX() const
{
	return this->x;
}

int Point::getY() const
{
	return this->y;
}

void Point::setX(int _x)
{
	this->x = _x;
}

void Point::setY(int _y)
{
	this->y = _y;
}



