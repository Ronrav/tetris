#pragma once
#include "point.h"
#include "utills.h"
class Shape
{
	Point points[4];
	int shape_type;
public:
	void assignShape(int x, int y);
	void rotateClockwise();
	void rotateCounterClockwise();
	
};

