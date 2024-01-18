#ifndef __UTILLLS_H
#define __UTILLS_H
#include "gameConfig.h"
#include <windows.h> // for gotoxy
#include <process.h> // for system
#include <iostream>
#include <conio.h>
#include<cstdlib>
#include<ctime>
using namespace std;

// Positions the cursor at the specified console coordinates.
void gotoxy(int x, int y);
//Sets the text color of the console.
void setTextColor(int color);
//Hides the console cursor.
void hideCursor();
//Clears the console screen.
void clear_screen();
//Generates a random integer within the specified range, between min to max.
int getRandom(int min, int max);
//Prints a colored dot at the specified coordinates with an option for fill.
void printDot(int x, int y, int color, bool fill);
//mpties the keyboard input buffe.
void emptyKBuffer();

#endif // __UTILLS_H