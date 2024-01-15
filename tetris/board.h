#ifndef __BOARD_H
#define __BOARD_H
#include "gameConfig.h"
#include "utills.h"
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <iostream>
#include "shape.h"
using namespace std;

class Shape;
class Point;
class Board
{
	int x;
	int y;
	int colored;
	int board[GameConfig::BOARD_HEIGHT][GameConfig::BOARD_WIDTH];
public:
	//Board() {};
	void init(int _x, int _y, int _colored);
	void drawBoardBorder();
	void printBoard();
	bool checkIfFreeCoord(int _x, int _y);
	void copyBoardTo(int copy_board[GameConfig::BOARD_HEIGHT][GameConfig::BOARD_WIDTH]);
	void copyToBoard(int copy_board[GameConfig::BOARD_HEIGHT][GameConfig::BOARD_WIDTH]);
	bool assignShapeToBoard(Shape block, Shape copy);
	void findStartPoint(int* _x, int* _y);
	bool isFullRow(int row);
	bool handleFullRows();
	void deleteAndMoveRow(int row);
	

};

#endif

