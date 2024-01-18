#ifndef __SHAPE_H
#define __SHAPE_H
#include "point.h"

class Shape
{
	Point points[4];
	int shape_type;
	int rotation_state;
	int color;

	//all following functions rotate the shape, according to the wanted direction and to the shapes' type.
	void rotateIshape();
	void rotateSshape();
	void rotateZshape();
	void rotateTshape();
	void rotateLshape();
	void rotateJshape();
	//returns true if the rotate direction is clockeise, false if to the other side.
	void rotate (bool clockwise);
	static constexpr int ROTATION_STATES = 4;
	static constexpr int O_SHAPE = 1;
	static constexpr int I_SHAPE = 2;
	static constexpr int S_SHAPE = 3;
	static constexpr int Z_SHAPE = 4;
	static constexpr int T_SHAPE = 5;
	static constexpr int L_SHAPE = 6;
	static constexpr int J_SHAPE = 7;
	static constexpr int NUM_OF_SHAPES = 7;
	static constexpr int SIZE_OF_SHAPE = 4;



public:
	// Initializes a new shape with a random type, color, and initial position.
	void getShape();
	//Copies the shape to the 'dest' shape object.
	void copyShape(Shape& dest);
	//Rotates the shape clockwise.
	void rotateClockWise();
	//Rotates the shape counterclockwise.
	void rotateCounterClockWise();
	//Moves the shape down by incrementing the y-coordinates of its points.
	void moveDown();
	//Moves the shape to the left by decrementing the x-coordinates of its points.
	void moveLeft();
	//Moves the shape to the right by incrementing the x-coordinates of its points.
	void moveRight();
	//Returns the array of points representing the shape.
	Point* getPoints();
	//Returns the color of the shape.
	int getColor();
};

#endif
