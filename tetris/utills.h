#ifndef __UTILLLS_H
#define __UTILLS_H
#include "gameConfig.h"
#include <windows.h> // for gotoxy
#include <process.h> // for system
#include <iostream>
using namespace std;

void gotoxy(int x, int y);
void setTextColor(int color);
void setBackColor(int color);
void hideCursor();
void clear_screen();
int getRandom(int min, int max);
void printDot(int x, int y, int color);

#endif // __UTILLS_H