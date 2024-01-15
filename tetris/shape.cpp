#include "shape.h"
#include "point.h"

void Shape::getShape(int x, int y)
{
	this->rotation_state = 0;
	this->shape_type = getRandom(1, 7);
	int color = GameConfig::COLORS[getRandom(1, 16)];
		//space filler
		switch (this->shape_type)
		{
			//O shape
		case(1):
			this->points[0].set(x, y, color);
			this->points[1].set(x + 1, y, color);
			this->points[2].set(x, y + 1, color);
			this->points[3].set(x + 1, y + 1, color);
			break;
			//I shape
		case(2):
			this->points[0].set(x, y, color);
			this->points[1].set(x, y + 1, color);
			this->points[2].set(x, y + 2, color);
			this->points[3].set(x, y + 3, color);
			break;
			//S shape
		case(3):
			this->points[0].set(x, y, color);
			this->points[1].set(x + 1, y, color);
			this->points[2].set(x, y + 1, color);
			this->points[3].set(x - 1, y + 1, color);
			break;
			//Z shape
		case(4):
			this->points[0].set(x, y, color);
			this->points[1].set(x - 1, y, color);
			this->points[2].set(x, y + 1, color);
			this->points[3].set(x + 1, y + 1, color);
			break;
			//T shape
		case(5):
			this->points[0].set(x, y, color);
			this->points[1].set(x - 1, y, color);
			this->points[2].set(x + 1, y, color);
			this->points[3].set(x, y + 1, color);
			break;
			//L shape
		case(6):
			this->points[0].set(x, y, color);
			this->points[1].set(x, y + 1, color);
			this->points[2].set(x, y + 2, color);
			this->points[3].set(x + 1, y + 2, color);
			break;
			//J shape
		case(7):
			this->points[0].set(x, y, color);
			this->points[1].set(x, y + 1, color);
			this->points[2].set(x, y + 2, color);
			this->points[3].set(x - 1, y + 2, color);
			break;
		}
}


void Shape::rotateClockWise()
{
	this->rotate(true);
}


void Shape::rotateCounterClockWise()
{
	this->rotate(false);
}


void Shape::moveDown()
{
	for (int i = 0; i < 4; i++)
		this->points[i].setY(this->points[i].getY() + 1);
}


void Shape::moveLeft()
{
	for (int i = 0; i < 4; i++)
		this->points[i].setX(this->points[i].getX() - 1);
}


void Shape::moveRight()
{
	for (int i = 0; i < 4; i++)
		this->points[i].setX(this->points[i].getX() + 1);
}


Point* Shape::getPoints()
{
	return this->points;
}


void Shape::rotate(bool clockwise)
{
	if (clockwise)
		this->rotation_state = (this->rotation_state + 1) % ROTATION_STATES;
	else
		this->rotation_state = (this->rotation_state - 1) % ROTATION_STATES;
	switch (this->shape_type)
	{
		//O shape
	case(1):
		break;
		//I shape
	case(2):
		this->rotateIshape();
		break;
		//S shape
	case(3):
		this->rotateSshape();
		break;
		//Z shape
	case(4):
		this->rotateZshape();
		break;
		//T shape
	case(5):
		this->rotateTshape();
		break;
		//L shape
	case(6):
		this->rotateLshape();
		break;
		//J shape
	case(7):
		this->rotateJshape();
		break;
	}
}


void Shape::rotateIshape()
{
	int x, y, color;
	x = this->points[0].getX();
	y = this->points[0].getY();
	color = x = this->points[0].getColor();
	switch (this->rotation_state)
	{
		//0 celsius
	case(1):
		this->points[1].set(x, y + 1, color);
		this->points[2].set(x, y + 2, color);
		this->points[3].set(x, y + 3, color);
		break;
		//90 shape
	case(2):
		this->points[1].set(x - 1, y, color);
		this->points[2].set(x - 2, y, color);
		this->points[3].set(x - 3, y, color);
		break;
		//180 shape
	case(3):
		this->points[1].set(x, y - 1, color);
		this->points[2].set(x, y - 2, color);
		this->points[3].set(x, y - 3, color);
		break;
		//270 shape
	case(4):
		this->points[1].set(x + 1, y, color);
		this->points[2].set(x + 2, y, color);
		this->points[3].set(x + 3, y, color);
		break;
	}
}


void Shape::rotateSshape()
{
	int x, y, color;
	x = this->points[0].getX();
	y = this->points[0].getY();
	color = x = this->points[0].getColor();
	switch (this->shape_type)
	{
		//0 celsius
	case(1):
		this->points[1].set(x + 1, y, color);
		this->points[2].set(x, y + 1, color);
		this->points[3].set(x - 1, y + 1, color);
		break;
		//90 shape
	case(2):
		this->points[1].set(x, y - 1, color);
		this->points[2].set(x + 1, y, color);
		this->points[3].set(x + 1, y + 1, color);
		break;
		//180 shape
	case(3):
		this->points[1].set(x - 1, y, color);
		this->points[2].set(x, y - 1, color);
		this->points[3].set(x + 1, y, color);
		break;
		//270 shape
	case(4):
		this->points[1].set(x, y + 1, color);
		this->points[2].set(x - 1, y, color);
		this->points[3].set(x - 1, y - 1, color);
		break;
	}
}


void Shape::rotateZshape()
{
	int x, y, color;
	x = this->points[0].getX();
	y = this->points[0].getY();
	color = x = this->points[0].getColor();
	switch (this->shape_type)
	{
		//0 celsius
	case(1):
		this->points[1].set(x - 1, y, color);
		this->points[2].set(x, y + 1, color);
		this->points[3].set(x + 1, y + 1, color);
		break;
		//90 shape
	case(2):
		this->points[1].set(x, y + 1, color);
		this->points[2].set(x + 1, y, color);
		this->points[3].set(x + 1, y - 1, color);
		break;
		//180 shape
	case(3):
		this->points[1].set(x + 1, y, color);
		this->points[2].set(x, y - 1, color);
		this->points[3].set(x - 1, y - 1, color);
		break;
		//270 shape
	case(4):
		this->points[1].set(x, y - 1, color);
		this->points[2].set(x - 1, y, color);
		this->points[3].set(x - 1, y + 1, color);
		break;
	}
}


void Shape::rotateTshape()
{
	int x, y, color;
	x = this->points[0].getX();
	y = this->points[0].getY();
	color = x = this->points[0].getColor();
	switch (this->shape_type)
	{
		//0 celsius
	case(1):
		this->points[1].set(x - 1, y, color);
		this->points[2].set(x + 1, y, color);
		this->points[3].set(x, y + 1, color);
		break;
		//90 shape
	case(2):
		this->points[1].set(x, y + 1, color);
		this->points[2].set(x, y - 1, color);
		this->points[3].set(x + 1, y, color);
		break;
		//180 shape
	case(3):
		this->points[1].set(x + 1, y, color);
		this->points[2].set(x - 1, y, color);
		this->points[3].set(x, y - 1, color);
		break;
		//270 shape
	case(4):
		this->points[1].set(x, y - 1, color);
		this->points[2].set(x, y + 1, color);
		this->points[3].set(x - 1, y, color);
		break;
	}
}


void Shape::rotateLshape()
{
	int x, y, color;
	x = this->points[0].getX();
	y = this->points[0].getY();
	color = x = this->points[0].getColor();
	switch (this->shape_type)
	{
		//0 celsius
	case(1):
		this->points[1].set(x, y + 1, color);
		this->points[2].set(x, y + 2, color);
		this->points[3].set(x + 1, y + 2, color);
		break;
		//90 shape
	case(2):
		this->points[1].set(x + 1, y, color);
		this->points[2].set(x + 2, y, color);
		this->points[3].set(x + 2, y - 1, color);
		break;
		//180 shape
	case(3):
		this->points[1].set(x, y - 1, color);
		this->points[2].set(x, y - 2, color);
		this->points[3].set(x - 1, y - 2, color);
		break;
		//270 shape
	case(4):
		this->points[1].set(x - 1, y, color);
		this->points[2].set(x - 2, y, color);
		this->points[3].set(x - 2, y + 1, color);
		break;
	}
}


void Shape::rotateJshape()
{
	int x, y, color;
	x = this->points[0].getX();
	y = this->points[0].getY();
	color = x = this->points[0].getColor();
	switch (this->shape_type)
	{
		//0 celsius
	case(1):
		this->points[1].set(x, y + 1, color);
		this->points[2].set(x, y + 2, color);
		this->points[3].set(x - 1, y + 2, color);
		break;
		//90 shape
	case(2):
		this->points[1].set(x + 1, y, color);
		this->points[2].set(x + 2, y, color);
		this->points[3].set(x + 2, y + 1, color);
		break;
		//180 shape
	case(3):
		this->points[1].set(x, y - 1, color);
		this->points[2].set(x, y - 2, color);
		this->points[3].set(x + 1, y - 2, color);
		break;
		//270 shape
	case(4):
		this->points[1].set(x - 1, y, color);
		this->points[2].set(x - 2, y, color);
		this->points[3].set(x - 2, y - 1, color);
		break;
	}
}

void Shape::copyShape(Shape& dest)
{
	for (int i = 0; i < 4; i++)
		dest.points[i] = this->points[i];

	dest.rotation_state = this->rotation_state;

}
