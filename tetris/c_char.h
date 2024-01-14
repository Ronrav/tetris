#pragma once
#include "gameConfig.h"
#include "utills.h"
#include <iostream>
using namespace std;
//Colored char class
class Cchar
{
	char ch;
	int color;
public:
	Cchar(char _ch = ' ', int _color = GameConfig::COLORS[0]) : ch(_ch), color(_color) {}
	//init to blank black char
	void printCchar(bool color_flag);
};

