#ifndef __SHAPE_H
#define __SHAPE_H
#include "point.h"
//#include "utills.h"

//class Point;

class Shape
{
	Point points[4];
	int shape_type;
	int rotation_state;

	void rotateIshape();
	void rotateSshape();
	void rotateZshape();
	void rotateTshape();
	void rotateLshape();
	void rotateJshape();
	void rotate(bool clockwise);
	static constexpr int ROTATION_STATES = 4;
public:
	//Shape(Point p1 = (0,0), Point p2 = (0,0), Point p3 = (0,0), Point p4 = (0,0)) {
		//points[0] = p1;
		//points[1] = p2;
		//points[2] = p3;
		//points[3] = p4;

//	};
	void getShape(int x, int y);
	void rotateClockWise();
	void rotateCounterClockWise();
	void moveDown();
	void moveLeft();
	void moveRight();
	Point* getPoints();
	void copyShape(Shape& dest);
	
};

#endif
