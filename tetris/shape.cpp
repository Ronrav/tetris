#include "shape.h"

void Shape::assignShape(int x, int y)
{
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
		this->rotateIshape(clockwise);
		break;
		//S shape
	case(3):
		this->rotateSshape(clockwise);
		break;
		//Z shape
	case(4):
		this->rotateZshape(clockwise);
		break;
		//T shape
	case(5):
		this->rotateTshape(clockwise);
		break;
		//L shape
	case(6):
		this->rotateLshape(clockwise);
		break;
		//J shape
	case(7):
		this->rotateJshape(clockwise);
		break;
	}
}

void Shape::rotateIshape(bool clockwise)
{
	int x, y, color;
	x = this->points[0].getX();
	y = this->points[0].getY();
	color = x = this->points[0].get_color();
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
void Shape::rotateSshape(bool clockwise)
{
	int x, y, color;
	x = this->points[0].getX();
	y = this->points[0].getY();
	color = x = this->points[0].get_color();
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
		this->points[1].set(x, y + 1, color);
		this->points[2].set(x - 1, y, color);
		this->points[3].set(x - 1, y - 1, color);
		break;
		//180 shape
	case(3):
		this->points[1].set(x + 1, y, color);
		this->points[2].set(x, y + 1, color);
		this->points[3].set(x - 1, y + 1, color);
		break;
		//270 shape
	case(4):
		this->points[1].set(x + 1, y, color);
		this->points[2].set(x + 2, y, color);
		this->points[3].set(x + 3, y, color);
		break;
	}
}
void Shape::rotateZshape(bool clockwise)
{
	int x, y, color;
	x = this->points[0].getX();
	y = this->points[0].getY();
	color = x = this->points[0].get_color();
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
		this->points[2].set(x - 1, y, color);
		this->points[3].set(x - 1, y - 1, color);
		break;
		//180 shape
	case(3):
		this->points[1].set(x + 1, y, color);
		this->points[2].set(x, y + 1, color);
		this->points[3].set(x - 1, y + 1, color);
		break;
		//270 shape
	case(4):
		this->points[1].set(x + 1, y, color);
		this->points[2].set(x + 2, y, color);
		this->points[3].set(x + 3, y, color);
		break;
	}
}
void Shape::rotateTshape(bool clockwise)
{
	int x, y, color;
	x = this->points[0].getX();
	y = this->points[0].getY();
	color = x = this->points[0].get_color();
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
		this->points[2].set(x - 1, y, color);
		this->points[3].set(x - 1, y - 1, color);
		break;
		//180 shape
	case(3):
		this->points[1].set(x + 1, y, color);
		this->points[2].set(x, y + 1, color);
		this->points[3].set(x - 1, y + 1, color);
		break;
		//270 shape
	case(4):
		this->points[1].set(x + 1, y, color);
		this->points[2].set(x + 2, y, color);
		this->points[3].set(x + 3, y, color);
		break;
	}
}
void Shape::rotateLshape(bool clockwise)
{
	int x, y, color;
	x = this->points[0].getX();
	y = this->points[0].getY();
	color = x = this->points[0].get_color();
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
		this->points[1].set(x, y + 1, color);
		this->points[2].set(x - 1, y, color);
		this->points[3].set(x - 1, y - 1, color);
		break;
		//180 shape
	case(3):
		this->points[1].set(x + 1, y, color);
		this->points[2].set(x, y + 1, color);
		this->points[3].set(x - 1, y + 1, color);
		break;
		//270 shape
	case(4):
		this->points[1].set(x + 1, y, color);
		this->points[2].set(x + 2, y, color);
		this->points[3].set(x + 3, y, color);
		break;
	}
}
void Shape::rotateJshape(bool clockwise)
{
	int x, y, color;
	x = this->points[0].getX();
	y = this->points[0].getY();
	color = x = this->points[0].get_color();
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
		this->points[1].set(x, y + 1, color);
		this->points[2].set(x - 1, y, color);
		this->points[3].set(x - 1, y - 1, color);
		break;
		//180 shape
	case(3):
		this->points[1].set(x + 1, y, color);
		this->points[2].set(x, y + 1, color);
		this->points[3].set(x - 1, y + 1, color);
		break;
		//270 shape
	case(4):
		this->points[1].set(x + 1, y, color);
		this->points[2].set(x + 2, y, color);
		this->points[3].set(x + 3, y, color);
		break;
	}
}
