#include "menu.h"


int Menu::handleStartMenu()
{
	int key = -1;
	bool printed = false;
	std::cout << "(1) Start a new game\n(8) Present instrcutions and keys\n(9) EXIT";
	while (true)
	{
		if (_kbhit())
			key = _getch() - '0';
		if (key == GameConfig::INSTRUCTIONS && !printed)
		{
			printInstructions();
			printed = true;
		}
		else if (key == GameConfig::NEW_GAME || key == GameConfig::EXIT)
			return key;
	}
}

int Menu::handlePauseMenu()
{
	int key = -1;
	bool printed = false;
	setTextColor(GameConfig::WHITE);
	clear_screen();
	std::cout << "(1) Start a new game\n(2) Continue a paused game\n(8) Present instrcutions and keys\n(9) EXIT";
	while (true)
	{
		if (_kbhit())
			key = _getch() - '0';
		if (key == GameConfig::INSTRUCTIONS && !printed)
		{
			printInstructions();
			printed = true;
		}
		else if (key == GameConfig::NEW_GAME || key == GameConfig::RESUME_GAME || key == GameConfig::EXIT)
		{
			clear_screen();
			break;
		}
			
	}
	return key;
}

void Menu::printInstructions()
{
	std::cout << "\n\nLeft Player keys:\n\tLeft - a or A\n\tRight - d or D \n\tRotate clokwise - s or S \n\tRotate counterclokwise - w or W\n\tDrop - x or X";
	std::cout << "\n\nRight Player keys:\n\tLeft - j or J\n\tRight - l or L \n\tRotate clokwise - k or K \n\tRotate counterclokwise - i or I\n\tDrop - m or M\n";
	std::cout << "\nPress ESC for pause\n";
}
 