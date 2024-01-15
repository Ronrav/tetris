#pragma once
#include "point.h"
#include "utills.h"
class Shape
{
	Point points[4];
	int shape_type;
	int rotation_state = 0;
	void rotateIshape();
	void rotateSshape();
	void rotateZshape();
	void rotateTshape();
	void rotateLshape();
	void rotateJshape();
	void rotate(bool clockwise);
	static constexpr int ROTATION_STATES = 4;
public:
	Shape() {};
	void assignShape(int x, int y);
	void rotateClockWise();
	void rotateCounterClockWise();
	void moveDown();
	void moveLeft();
	void moveRight();
	Point* getPoints();
	
	
};

