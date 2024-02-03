#ifndef __POINT_H
#define __POINT_H

class Point
{
	int x = 0;
	int y = 0;


public:
	Point(int _x, int _y) : x(_x), y(_y) {};
	Point() {};
	void set(int _x, int _y);
	int getX() const;
	int getY() const;
	void setX(int _x);
	void setY(int _y);
};

#endif
