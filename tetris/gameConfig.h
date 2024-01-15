#pragma once
class GameConfig
{
public:
	enum class eKeys {
		P1_LEFT = 'a', P1_RIGHT = 'd', P1_ROTATE = 's', P1_ROTATE_COUNTER = 'w', P1_DROP = 'x',
		P2_LEFT = 'j', P2_RIGHT = 'l', P2_ROTATE = 'k', P2_ROTATE_COUNTER = 'i', P2_DROP = 'm', ESC = 27};

	enum Color
	{
		BLACK = 0, BLUE = 1, GREEN = 2, CYAN = 3, RED = 4, MAGENTA = 5, BROWN = 6, LIGHTGREY = 7, DARKGREY = 8,
		LIGHTBLUE = 9, LIGHTGREEN = 10, LIGHTCYAN = 11, LIGHTRED = 12, LIGHTMAGENTA = 13,YELLOW = 14, WHITE = 15
	};
	static constexpr int BOARD_WIDTH = 12;
	static constexpr int BOARD_HEIGHT = 18;
	static constexpr int BOARDS_GAP  = 40;
	static constexpr char SYMBOL = '#';
	static constexpr int MIN_X = 10;
	static constexpr int MIN_Y = 2;
	static constexpr int START_X_COORD_BOARD_1 = 10 + (12 / 2);
	static constexpr int START_Y_COORD_BOARD_1 = MIN_Y + (BOARD_HEIGHT / 2);
	static constexpr int START_X_COORD_BOARD_2 = MIN_X + BOARDS_GAP + (BOARD_WIDTH / 2);
	static constexpr int START_Y_COORD_BOARD_2 = MIN_Y + BOARDS_GAP + (BOARD_HEIGHT / 2);






	static const int COLORS[];
	static const int NUM_OF_COLORS;
};

