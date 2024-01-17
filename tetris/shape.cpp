#include "shape.h"

void Shape::getShape()
{
	this->rotation_state = 0;
	this->shape_type = getRandom(1, GameConfig::NUM_OF_SHAPES);
	this->color = GameConfig::COLORS[getRandom(1, GameConfig::NUM_OF_COLORS)];
	
		//space filler
		switch (this->shape_type)
		{
			//O shape
		case(1):
			this->points[0].set(GameConfig::BOARD_WIDTH / 2, 0);
			this->points[1].set(GameConfig::BOARD_WIDTH / 2 + 1, 0);
			this->points[2].set(GameConfig::BOARD_WIDTH / 2, 1);
			this->points[3].set(GameConfig::BOARD_WIDTH / 2 + 1, 1);
			break;
			//I shape
		case(2):
			this->points[0].set(GameConfig::BOARD_WIDTH / 2, 0);
			this->points[1].set(GameConfig::BOARD_WIDTH / 2, 1);
			this->points[2].set(GameConfig::BOARD_WIDTH / 2, 2);
			this->points[3].set(GameConfig::BOARD_WIDTH / 2, 3);
			break;
			//S shape
		case(3):
			this->points[0].set(GameConfig::BOARD_WIDTH / 2, 0);
			this->points[1].set(GameConfig::BOARD_WIDTH / 2 + 1, 0);
			this->points[2].set(GameConfig::BOARD_WIDTH / 2, 1);
			this->points[3].set(GameConfig::BOARD_WIDTH / 2 - 1, 1);
			break;
			//Z shape
		case(4):
			this->points[0].set(GameConfig::BOARD_WIDTH / 2, 0);
			this->points[1].set(GameConfig::BOARD_WIDTH / 2 - 1, 0);
			this->points[2].set(GameConfig::BOARD_WIDTH / 2, 1);
			this->points[3].set(GameConfig::BOARD_WIDTH / 2 + 1, 1);
			break;
			//T shape
		case(5):
			this->points[0].set(GameConfig::BOARD_WIDTH / 2, 0);
			this->points[1].set(GameConfig::BOARD_WIDTH / 2 - 1, 0);
			this->points[2].set(GameConfig::BOARD_WIDTH / 2 + 1, 0);
			this->points[3].set(GameConfig::BOARD_WIDTH / 2, 1);
			break;
			//L shape
		case(6):
			this->points[0].set(GameConfig::BOARD_WIDTH / 2, 0);
			this->points[1].set(GameConfig::BOARD_WIDTH / 2, 1);
			this->points[2].set(GameConfig::BOARD_WIDTH / 2, 2);
			this->points[3].set(GameConfig::BOARD_WIDTH / 2 + 1, 2);
			break;
			//J shape
		case(7):
			this->points[0].set(GameConfig::BOARD_WIDTH / 2, 0);
			this->points[1].set(GameConfig::BOARD_WIDTH / 2, 1);
			this->points[2].set(GameConfig::BOARD_WIDTH / 2, 2);
			this->points[3].set(GameConfig::BOARD_WIDTH / 2 - 1, 2);
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
	if (!clockwise)
		this->rotation_state = (this->rotation_state + 1) % ROTATION_STATES;
	else
		this->rotation_state = (this->rotation_state + 3) % ROTATION_STATES;
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
	int x, y;
	x = this->points[0].getX();
	y = this->points[0].getY();
	switch (this->rotation_state)
	{
		//0 celsius
	case(0):
		this->points[1].set(x, y + 1);
		this->points[2].set(x, y + 2);
		this->points[3].set(x, y + 3);
		break;
		//90 shape
	case(1):
		this->points[1].set(x - 1, y);
		this->points[2].set(x - 2, y);
		this->points[3].set(x - 3, y);
		break;
		//180 shape
	case(2):
		this->points[1].set(x, y - 1);
		this->points[2].set(x, y - 2);
		this->points[3].set(x, y - 3);
		break;
		//270 shape
	case(3):
		this->points[1].set(x + 1, y);
		this->points[2].set(x + 2, y);
		this->points[3].set(x + 3, y);
		break;
	}
}

void Shape::rotateSshape()
{
	int x, y;
	x = this->points[0].getX();
	y = this->points[0].getY();
	switch (this->rotation_state)
	{
		//0 celsius
	case(0):
		this->points[1].set(x + 1, y);
		this->points[2].set(x, y + 1);
		this->points[3].set(x - 1, y + 1);
		break;
		//90 shape
	case(1):
		this->points[1].set(x, y - 1);
		this->points[2].set(x + 1, y);
		this->points[3].set(x + 1, y + 1);
		break;
		//180 shape
	case(2):
		this->points[1].set(x - 1, y);
		this->points[2].set(x, y - 1);
		this->points[3].set(x + 1, y-1);
		break;
		//270 shape
	case(3):
		this->points[1].set(x, y + 1);
		this->points[2].set(x - 1, y);
		this->points[3].set(x - 1, y - 1);
		break;
	}
}


void Shape::rotateZshape()
{
	int x, y;
	x = this->points[0].getX();
	y = this->points[0].getY();
	switch (this->rotation_state)
	{
		//0 celsius
	case(0):
		this->points[1].set(x - 1, y);
		this->points[2].set(x, y + 1);
		this->points[3].set(x + 1, y + 1);
		break;
		//90 shape
	case(1):
		this->points[1].set(x, y + 1);
		this->points[2].set(x + 1, y);
		this->points[3].set(x + 1, y - 1);
		break;
		//180 shape
	case(2):
		this->points[1].set(x + 1, y);
		this->points[2].set(x, y - 1);
		this->points[3].set(x - 1, y - 1);
		break;
		//270 shape
	case(3):
		this->points[1].set(x, y - 1);
		this->points[2].set(x - 1, y);
		this->points[3].set(x - 1, y + 1);
		break;
	}
}


void Shape::rotateTshape()
{
	int x, y;
	x = this->points[0].getX();
	y = this->points[0].getY();
	switch (this->rotation_state)
	{
		//0 celsius
	case(0):
		this->points[1].set(x - 1, y);
		this->points[2].set(x + 1, y);
		this->points[3].set(x, y + 1);
		break;
		//90 shape
	case(1):
		this->points[1].set(x, y + 1);
		this->points[2].set(x, y - 1);
		this->points[3].set(x + 1, y);
		break;
		//180 shape
	case(2):
		this->points[1].set(x + 1, y);
		this->points[2].set(x - 1, y);
		this->points[3].set(x, y - 1);
		break;
		//270 shape
	case(3):
		this->points[1].set(x, y - 1);
		this->points[2].set(x, y + 1);
		this->points[3].set(x - 1, y);
		break;
	}
}


void Shape::rotateLshape()
{
	int x, y;
	x = this->points[0].getX();
	y = this->points[0].getY();
	switch (this->rotation_state)
	{
		//0 celsius
	case(0):
		this->points[1].set(x, y + 1);
		this->points[2].set(x, y + 2);
		this->points[3].set(x + 1, y + 2);
		break;
		//90 shape
	case(1):
		this->points[1].set(x + 1, y);
		this->points[2].set(x + 2, y);
		this->points[3].set(x + 2, y - 1);
		break;
		//180 shape
	case(2):
		this->points[1].set(x, y - 1);
		this->points[2].set(x, y - 2);
		this->points[3].set(x - 1, y - 2);
		break;
		//270 shape
	case(3):
		this->points[1].set(x - 1, y);
		this->points[2].set(x - 2, y);
		this->points[3].set(x - 2, y + 1);
		break;
	}
}


void Shape::rotateJshape()
{
	int x, y;
	x = this->points[0].getX();
	y = this->points[0].getY();
	switch (this->rotation_state)
	{
		//0 degrees
	case(0):
		this->points[1].set(x, y + 1);
		this->points[2].set(x, y + 2);
		this->points[3].set(x - 1, y + 2);
		break;
		//90 degrees
	case(1):
		this->points[1].set(x + 1, y);
		this->points[2].set(x + 2, y);
		this->points[3].set(x + 2, y + 1);
		break;
		//180 degrees
	case(2):
		this->points[1].set(x, y - 1);
		this->points[2].set(x, y - 2);
		this->points[3].set(x + 1, y - 2);
		break;
		//270 degrees
	case(3):
		this->points[1].set(x - 1, y);
		this->points[2].set(x - 2, y);
		this->points[3].set(x - 2, y - 1);
		break;
	}
}

void Shape::copyShape(Shape& dest)
{
	for (int i = 0; i < 4; i++)
		dest.points[i] = this->points[i];

	dest.rotation_state = this->rotation_state;
	dest.shape_type = this->shape_type;
	dest.color = this->color;

}

int Shape::getColor()
{
	return this->color;
}