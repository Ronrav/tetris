#include "utills.h"

using namespace std;

void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	cout.flush();
	dwCursorPosition.X = x;
	dwCursorPosition.Y = y;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition);
}

void setTextColor(int colorToSet) 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorToSet);
}


void hideCursor()
{
	HANDLE myconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CURSOR;
	CURSOR.dwSize = 1;
	CURSOR.bVisible = FALSE;
	SetConsoleCursorInfo(myconsole, &CURSOR);//second argument need pointer
}

void clear_screen()
{
	system("cls");
}

int getRandom(int min, int max) 
{
	srand(time(NULL));
	return rand() % (max - min + 1) + min;
}

void printDot(int x, int y, int color, bool fill)
{
	if(color != GameConfig::BLACK)
		setTextColor(color);
	gotoxy(x, y);
	if (fill)
		cout << (char)GameConfig::SYMBOL;
	else
		cout << ' ';
}

void emptyKBuffer()
{
	while (_kbhit())
		_getch();
}
