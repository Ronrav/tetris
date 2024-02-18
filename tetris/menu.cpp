#include "menu.h"


int Menu::handleMenu(Player** players, bool start_or_pause)
{
	setTextColor((int)GameConfig::Color::WHITE);
	clear_screen();
	int key = -1;
	bool printed = false;
	if(start_or_pause)
		std::cout << "(1) Start a new game - Human vs Human\n(2) Start a new game - Human vs Computer\n(3) Start a new game - Computer vs Computer\n(8) Present instrcutions and keys\n(9) EXIT";
	else
		std::cout << "(1) Start a new game - Human vs Human\n(2) Start a new game - Human vs Computer\n(3) Start a new game - Computer vs Computer\n(4) Continue a paused game\n(8) Present instrcutions and keys\n(9) EXIT";
	while (true)
	{
		if (_kbhit())
			key = _getch() - '0';
		switch (key)
		{
		case(INSTRUCTIONS):
			if (!printed)
			{
				printInstructions();
				printed = true;
			}
			break;
		case(RESUME_GAME):
		case(EXIT):
			clear_screen();
			return key;
			break;
		case(HUMAN_VS_HUMAN):
		case(HUMAN_VS_COMPUTER):
		case(COMPUTER_VS_COMPUTER):
			setPlayers(players, key);
			key = NEW_GAME;
			return key;
		}
	}
}

void Menu::setPlayers(Player** players, int key)
{
	if (players[0] != nullptr)
	{
		delete players[0];
		delete players[1];
	}

	switch (key)
	{
	case(HUMAN_VS_HUMAN):
		players[0] = new Human();
		players[1] = new Human();
		break;
		
	case(HUMAN_VS_COMPUTER):
		players[0] = new Human();
		std::cout << "\nPlease choose computer's level (Right Board):\n";
		players[1] = new Computer(Menu::selectComputerLevel());
		break;
		

	case(COMPUTER_VS_COMPUTER):
		std::cout << "\nPlease choose 1st computer's level (Left Board):\n";
		players[0] = new Computer(Menu::selectComputerLevel());
		std::cout << "\nPlease choose 2nd computer's level (Right Board):\n";
		players[1] = new Computer(Menu::selectComputerLevel());
		break;
	};
}

char Menu::selectComputerLevel()
{
	char computer_level;
	std::cout << "\n(a) BEST\n(b) GOOD\n(C) NOVICE\n";
	while (true)
	{
		if (_kbhit())
		{
			computer_level = _getch();
			if (computer_level == BEST || computer_level == GOOD || computer_level == NOVICE)
				return computer_level;
		}
	}
	clear_screen();
}

void Menu::printInstructions()
{
	std::cout << "\n\nLeft Player keys:\n\tLeft - a or A\n\tRight - d or D \n\tRotate clokwise - s or S \n\tRotate counterclokwise - w or W\n\tDrop - x or X";
	std::cout << "\n\nRight Player keys:\n\tLeft - j or J\n\tRight - l or L \n\tRotate clokwise - k or K \n\tRotate counterclokwise - i or I\n\tDrop - m or M\n";
	std::cout << "\nPress ESC for pause\n";
}
 