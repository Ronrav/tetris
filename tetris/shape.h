#ifndef __SHAPE_H
#define __SHAPE_H
#include "point.h"

class Shape
{
	Point points[4];
	int shape_type;
	int rotation_state;
	int color;

	void rotateIshape();
	void rotateSshape();
	void rotateZshape();
	void rotateTshape();
	void rotateLshape();
	void rotateJshape();
	void rotate(bool clockwise);
	static constexpr int ROTATION_STATES = 4;
public:
	void getShape();
	void copyShape(Shape& dest);
	void rotateClockWise();
	void rotateCounterClockWise();
	void moveDown();
	void moveLeft();
	void moveRight();
	Point* getPoints();
	int getColor();
};

#endif
