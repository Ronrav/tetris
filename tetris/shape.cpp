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
			this->points[0].init(x, y, color);
			this->points[0].init(x + 1, y, color);
			this->points[0].init(x, y + 1, color);
			this->points[0].init(x + 1, y + 1, color);
			break;
			//I shape
		case(2):
			this->points[0].init(x, y, color);
			this->points[0].init(x, y + 1, color);
			this->points[0].init(x, y + 2, color);
			this->points[0].init(x, y + 3, color);
			break;
			//S shape
		case(3):
			this->points[0].init(x, y, color);
			this->points[0].init(x + 1, y, color);
			this->points[0].init(x, y + 1, color);
			this->points[0].init(x - 1, y + 1, color);
			break;
			//Z shape
		case(4):
			this->points[0].init(x, y, color);
			this->points[0].init(x - 1, y, color);
			this->points[0].init(x, y + 1, color);
			this->points[0].init(x + 1, y + 1, color);
			break;
			//T shape
		case(5):
			this->points[0].init(x, y, color);
			this->points[0].init(x - 1, y, color);
			this->points[0].init(x + 1, y, color);
			this->points[0].init(x, y + 1, color);
			break;
			//L shape
		case(6):
			this->points[0].init(x, y, color);
			this->points[0].init(x, y + 1, color);
			this->points[0].init(x, y + 2, color);
			this->points[0].init(x + 1, y + 2, color);
			break;
			//J shape
		case(7):
			this->points[0].init(x, y, color);
			this->points[0].init(x, y + 1, color);
			this->points[0].init(x, y + 2, color);
			this->points[0].init(x - 1, y + 2, color);
			break;
		}
}

void Shape::rotateClockwise()
{
	//x = get x
	//y = get y
	int x, y;
	switch (this->shape_type)
	{
		//O shape
	case(1):
		break;
		//I shape
	case(2):
		this->points[0].init(x, y, color);
		this->points[0].init(x, y + 1, color);
		this->points[0].init(x, y + 2, color);
		this->points[0].init(x, y + 3, color);
		break;
		//S shape
	case(3):
		this->points[0].init(x, y, color);
		this->points[0].init(x + 1, y, color);
		this->points[0].init(x, y + 1, color);
		this->points[0].init(x - 1, y + 1, color);
		break;
		//Z shape
	case(4):
		this->points[0].init(x, y, color);
		this->points[0].init(x - 1, y, color);
		this->points[0].init(x, y + 1, color);
		this->points[0].init(x + 1, y + 1, color);
		break;
		//T shape
	case(5):
		this->points[0].init(x, y, color);
		this->points[0].init(x - 1, y, color);
		this->points[0].init(x + 1, y, color);
		this->points[0].init(x, y + 1, color);
		break;
		//L shape
	case(6):
		this->points[0].init(x, y, color);
		this->points[0].init(x, y + 1, color);
		this->points[0].init(x, y + 2, color);
		this->points[0].init(x + 1, y + 2, color);
		break;
		//J shape
	case(7):
		this->points[0].init(x, y, color);
		this->points[0].init(x, y + 1, color);
		this->points[0].init(x, y + 2, color);
		this->points[0].init(x - 1, y + 2, color);
		break;
	}
}

void Shape::rotateCounterClockwise()
{
}
