#pragma once
#include "gameConfig.h"
#include "utills.h"
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <iostream>
#include "shape.h"
using namespace std;

class Point;
class Board
{
	int x;
	int y;
	int width;
	int height;
	bool colored;
	int board[GameConfig::BOARD_HEIGHT][GameConfig::BOARD_WIDTH];
public:
	Board(int _x, int _y, int _width, int _height, bool _colored) : x(_x), y(_y),
		width(_width), height(_height), colored(_colored), board() {}
	Board() {};
	void drawBoardBorder();
	void printBoard();
	bool checkIfFreeCoord(int _x, int _y);
	void copyBoardTo(int copy_board[GameConfig::BOARD_HEIGHT][GameConfig::BOARD_WIDTH]);
	void copyToBoard(int copy_board[GameConfig::BOARD_HEIGHT][GameConfig::BOARD_WIDTH]);
	bool assignShapeToBoard(Shape block);
};

