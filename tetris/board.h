#pragma once
#include "gameConfig.h"
#include "utills.h"
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;


class Board
{
	int board[GameConfig::BOARD_HEIGHT][GameConfig::BOARD_WIDTH];
public:
	void drawBoard(int x, int y, int height, int width);
	void drawBoards();
};

