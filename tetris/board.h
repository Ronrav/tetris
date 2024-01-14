#pragma once
#include "gameConfig.h"
#include "utills.h"
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <iostream>
using namespace std;

class Point;
class Board
{
	int x;
	int y;
	int width;
	int height;
	bool colored;
	int board[GameConfig::BOARD_HEIGHT][GameConfig::BOARD_WIDTH] = {0};
public:
	Board(int _x, int _y, int _width, int _height, bool _colored) : x(_x), y(_y), 
		width(_width), height(_height), colored(_colored) {}
	Board() {}
	void drawBoardBorder();
	void printBoard();
};

