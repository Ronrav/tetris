#pragma once
#include "point.h"
#include "utills.h"
class Shape
{
	Point points[4];
	int shape_type;
	int rotation_state = 0;
	void rotateIshape(bool clockwise);
	void rotateSshape(bool clockwise);
	void rotateZshape(bool clockwise);
	void rotateTshape(bool clockwise);
	void rotateLshape(bool clockwise);
	void rotateJshape(bool clockwise);
	static constexpr int ROTATION_STATES = 4;
public:
	void assignShape(int x, int y);
	void rotate(bool clockwise);
	
	
};

