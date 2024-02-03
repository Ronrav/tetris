#include "shape.h"


void Shape::setShape()
{
	this->rotation_state = 0;
	this->shape_type = getRandom(1, NUM_OF_SHAPES);
	this->color = GameConfig::COLORS[getRandom(1, GameConfig::NUM_OF_COLORS)];
	
		//space filler
		switch (this->shape_type)
		{
		case(O_SHAPE):
			this->points[0].set(GameConfig::BOARD_WIDTH / 2, 0);
			this->points[1].set(GameConfig::BOARD_WIDTH / 2 + 1, 0);
			this->points[2].set(GameConfig::BOARD_WIDTH / 2, 1);
			this->points[3].set(GameConfig::BOARD_WIDTH / 2 + 1, 1);  
			break;
			
		case(I_SHAPE):
			this->points[0].set(GameConfig::BOARD_WIDTH / 2, 0);
			this->points[1].set(GameConfig::BOARD_WIDTH / 2, 1);
			this->points[2].set(GameConfig::BOARD_WIDTH / 2, 2);
			this->points[3].set(GameConfig::BOARD_WIDTH / 2, 3);
			break;
			
		case(S_SHAPE):
			this->points[0].set(GameConfig::BOARD_WIDTH / 2, 0);
			this->points[1].set(GameConfig::BOARD_WIDTH / 2 + 1, 0);
			this->points[2].set(GameConfig::BOARD_WIDTH / 2, 1);
			this->points[3].set(GameConfig::BOARD_WIDTH / 2 - 1, 1);
			break;
			
		case(Z_SHAPE):
			this->points[0].set(GameConfig::BOARD_WIDTH / 2, 0);
			this->points[1].set(GameConfig::BOARD_WIDTH / 2 - 1, 0);
			this->points[2].set(GameConfig::BOARD_WIDTH / 2, 1);
			this->points[3].set(GameConfig::BOARD_WIDTH / 2 + 1, 1);
			break;
			
		case(T_SHAPE):
			this->points[0].set(GameConfig::BOARD_WIDTH / 2, 0);
			this->points[1].set(GameConfig::BOARD_WIDTH / 2 - 1, 0);
			this->points[2].set(GameConfig::BOARD_WIDTH / 2 + 1, 0);
			this->points[3].set(GameConfig::BOARD_WIDTH / 2, 1);
			break;
		
		case(L_SHAPE):
			this->points[0].set(GameConfig::BOARD_WIDTH / 2, 0);
			this->points[1].set(GameConfig::BOARD_WIDTH / 2, 1);
			this->points[2].set(GameConfig::BOARD_WIDTH / 2, 2);
			this->points[3].set(GameConfig::BOARD_WIDTH / 2 + 1, 2);
			break;
			
		case(J_SHAPE):
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
	for (int i = 0; i < SIZE_OF_SHAPE ; i++)
		this->points[i].setY(this->points[i].getY() + 1);
}


void Shape::moveLeft()
{
	for (int i = 0; i < SIZE_OF_SHAPE; i++)
		this->points[i].setX(this->points[i].getX() - 1);
}


void Shape::moveRight()
{
	for (int i = 0; i < SIZE_OF_SHAPE; i++)
		this->points[i].setX(this->points[i].getX() + 1);
}


Point* Shape::getPoints() const
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
		
	case(O_SHAPE):
		break;
	
	case(I_SHAPE):
		this->rotateIshape();
		break;
		
	case(S_SHAPE):
		this->rotateSshape();
		break;
	
	case(Z_SHAPE):
		this->rotateZshape();
		break;
		
	case(T_SHAPE):
		this->rotateTshape();
		break;
		
	case(L_SHAPE):
		this->rotateLshape();
		break;
		
	case(J_SHAPE):
		this->rotateJshape();
		break;
	}
}

void Shape::rotateIshape()
{
	int x, y;
	this->rotation_state *= 90;//multiply by 90 in order to understand the rotation state in degrees.
	x = this->points[0].getX();
	y = this->points[0].getY();
	switch (this->rotation_state)
	{
		//0 degrees
	case(0):
		this->points[1].set(x, y + 1);
		this->points[2].set(x, y + 2);
		this->points[3].set(x, y + 3);
		break;
		//90 degrees
	case(90):
		this->points[1].set(x - 1, y);
		this->points[2].set(x - 2, y);
		this->points[3].set(x - 3, y);
		break;
		//180 degrees
	case(180):
		this->points[1].set(x, y - 1);
		this->points[2].set(x, y - 2);
		this->points[3].set(x, y - 3);
		break;
		//270 degrees
	case(270):
		this->points[1].set(x + 1, y);
		this->points[2].set(x + 2, y);
		this->points[3].set(x + 3, y);
		break;
	}
	this->rotation_state /= 90;
}

void Shape::rotateSshape()
{
	int x, y;
	this->rotation_state *= 90;//multiply by 90 in order to understand the rotation state in degrees.
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
	case(90):
		this->points[1].set(x, y - 1);
		this->points[2].set(x + 1, y);
		this->points[3].set(x + 1, y + 1);
		break;
		//180 degrees
	case(180):
		this->points[1].set(x - 1, y);
		this->points[2].set(x, y - 1);
		this->points[3].set(x + 1, y-1);
		break;
		//270 degrees
	case(270):
		this->points[1].set(x, y + 1);
		this->points[2].set(x - 1, y);
		this->points[3].set(x - 1, y - 1);
		break;
	}
	this->rotation_state /= 90;
}


void Shape::rotateZshape()
{
	int x, y;
	this->rotation_state *= 90;//multiply by 90 in order to understand the rotation state in degrees.
	x = this->points[0].getX();
	y = this->points[0].getY();
	switch (this->rotation_state)
	{
		//0 degrees
	case(0):
		this->points[1].set(x - 1, y);
		this->points[2].set(x, y + 1);
		this->points[3].set(x + 1, y + 1);
		break;
		//90 degrees
	case(90):
		this->points[1].set(x, y + 1);
		this->points[2].set(x + 1, y);
		this->points[3].set(x + 1, y - 1);
		break;
		//180 degrees
	case(180):
		this->points[1].set(x + 1, y);
		this->points[2].set(x, y - 1);
		this->points[3].set(x - 1, y - 1);
		break;
		//270 degrees
	case(270):
		this->points[1].set(x, y - 1);
		this->points[2].set(x - 1, y);
		this->points[3].set(x - 1, y + 1);
		break;
	}
	this->rotation_state /= 90;
}


void Shape::rotateTshape()
{
	int x, y;
	this->rotation_state *= 90;//multiply by 90 in order to understand the rotation state in degrees.
	x = this->points[0].getX();
	y = this->points[0].getY();
	switch (this->rotation_state)
	{
		//0 degrees
	case(0):
		this->points[1].set(x - 1, y);
		this->points[2].set(x + 1, y);
		this->points[3].set(x, y + 1);
		break;
		//90 degrees
	case(90):
		this->points[1].set(x, y + 1);
		this->points[2].set(x, y - 1);
		this->points[3].set(x + 1, y);
		break;
		//180 degrees
	case(180):
		this->points[1].set(x + 1, y);
		this->points[2].set(x - 1, y);
		this->points[3].set(x, y - 1);
		break;
		//270 degrees
	case(270):
		this->points[1].set(x, y - 1);
		this->points[2].set(x, y + 1);
		this->points[3].set(x - 1, y);
		break;
	}
	this->rotation_state /= 90;
}


void Shape::rotateLshape()
{
	int x, y;
	this->rotation_state *= 90;//multiply by 90 in order to understand the rotation state in degrees.
	x = this->points[0].getX();
	y = this->points[0].getY();
	switch (this->rotation_state)
	{
		//0 degrees
	case(0):
		this->points[1].set(x, y + 1);
		this->points[2].set(x, y + 2);
		this->points[3].set(x + 1, y + 2);
		break;
		//90 degrees
	case(90):
		this->points[1].set(x + 1, y);
		this->points[2].set(x + 2, y);
		this->points[3].set(x + 2, y - 1);
		break;
		//180 degrees
	case(180):
		this->points[1].set(x, y - 1);
		this->points[2].set(x, y - 2);
		this->points[3].set(x - 1, y - 2);
		break;
		//270 degrees
	case(270):
		this->points[1].set(x - 1, y);
		this->points[2].set(x - 2, y);
		this->points[3].set(x - 2, y + 1);
		break;
	}
	this->rotation_state /= 90;
}


void Shape::rotateJshape()
{
	int x, y;
	this->rotation_state *= 90;//multiply by 90 in order to understand the rotation state in degrees.
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
	case(90):
		this->points[1].set(x + 1, y);
		this->points[2].set(x + 2, y);
		this->points[3].set(x + 2, y + 1);
		break;
		//180 degrees
	case(180):
		this->points[1].set(x, y - 1);
		this->points[2].set(x, y - 2);
		this->points[3].set(x + 1, y - 2);
		break;
		//270 degrees
	case(270):
		this->points[1].set(x - 1, y);
		this->points[2].set(x - 2, y);
		this->points[3].set(x - 2, y - 1);
		break;
	}
	this->rotation_state /= 90;
}

void Shape::copyShape(Shape& dest)
{
	for (int i = 0; i < SIZE_OF_SHAPE; i++)
		dest.points[i] = this->points[i];

	dest.rotation_state = this->rotation_state;
	dest.shape_type = this->shape_type;
	dest.color = this->color;

}

int Shape::getColor()
{
	return this->color;
}

//the consts needs to be like the rKeys and Lkeys in Game class 
char Shape::moveToWanted(const Shape& wanted_shape)
{
	int cur_column = this->points[0].getX();
	int wanted_column = wanted_shape.points[0].getX();


	if (wanted_shape.rotation_state != this->rotation_state)
		return ROTATE_CLOCKWISE;

	else if (cur_column != wanted_column)
	{
		if (cur_column < wanted_column)
			return RIGHT;
		else
			return LEFT;
	}
	else
		return DROP;

}

