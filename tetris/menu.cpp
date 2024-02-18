#include "menu.h"
#include "computer.h"
#include "human.h"

int Menu::handleStartMenu(Player** players)
{
	int key = -1;
	bool printed = false;
	std::cout << "(1) Start a new game - Human vs Human\n(2) Start a new game - Human vs Computer\n(3) Start a new game - Computer vs Computer\n(8) Present instrcutions and keys\n(9) EXIT";
	while (true)
	{
		if (_kbhit())
		{
			key = _getch() - '0';
			switch (key)
			{
			case(INSTRUCTIONS):
				if (!printed)
				{
					printInstructions();
					printed = true;
				}
			case(HUMAN_VS_HUMAN):

				players[0] = new Human();
				players[1] = new Human();
				key = NEW_GAME;
				return key;

			case(HUMAN_VS_COMPUTER):

				players[0] = new Human();
				std::cout << "\nPlease choose computer's level:\n";
				players[1] = new Computer(Menu::selectComputerLevel());
				key = NEW_GAME;
				return key;

			case(COMPUTER_VS_COMPUTER):
				std::cout << "\nPlease choose 1st computer's level:\n";
				players[0] = new Computer(Menu::selectComputerLevel());
				std::cout << "\nPlease choose 2nd computer's level:\n";
				players[1] = new Computer(Menu::selectComputerLevel());
				key = NEW_GAME;
				return key;
			};

		}
	}
}
void Menu::setPlayers(Player** players, int key)
{
	switch (key)
	{

	case(HUMAN_VS_HUMAN):

		players[0] = new Human();
		players[1] = new Human();
		
	case(HUMAN_VS_COMPUTER):

		players[0] = new Human();
		std::cout << "\nPlease choose computer's level:\n";
		players[1] = new Computer(Menu::selectComputerLevel());
		

	case(COMPUTER_VS_COMPUTER):
		std::cout << "\nPlease choose 1st computer's level:\n";
		players[0] = new Computer(Menu::selectComputerLevel());
		std::cout << "\nPlease choose 2nd computer's level:\n";
		players[1] = new Computer(Menu::selectComputerLevel());
		
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
			if (computer_level == 'a' || computer_level == 'b' || computer_level == 'c')
				return computer_level;
		}
	}
	clear_screen();

}
int Menu::handlePauseMenu(Player** players)
{
	int key = -1;
	bool printed = false;
	setTextColor(GameConfig::WHITE);
	clear_screen();
	std::cout << "(1) Start a new game - Human vs Human\n(2) Start a new game - Human vs Computer\n(3) Start a new game - Computer vs Computer\n(8) Present instrcutions and keys\n(9) EXIT";
	while (true)
	{
		if (_kbhit())
			key = _getch() - '0';
		if (key ==INSTRUCTIONS && !printed)
		{
			printInstructions();
			printed = true;
		}
		else if (key == RESUME_GAME || key == EXIT)
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
 