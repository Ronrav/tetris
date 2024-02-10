#ifndef __GAME_CONFIG_H
#define __GAME_CONFIG_H

class GameConfig
{
public:

	enum class Color
	{
		BLACK = 0, BLUE = 1, GREEN = 2, CYAN = 3, RED = 4, MAGENTA = 5, BROWN = 6, LIGHTGREY = 7, DARKGREY = 8,
		LIGHTBLUE = 9, LIGHTGREEN = 10, LIGHTCYAN = 11, LIGHTRED = 12, LIGHTMAGENTA = 13, YELLOW = 14, WHITE = 15
	};
	static constexpr int BOARD_WIDTH = 12;
	static constexpr int BOARD_HEIGHT = 18;
	static constexpr int BOARDS_GAP = 40;
	static constexpr char BLOCK_SYMBOL = '#';
	static constexpr char BOMB_SYMBOL = '@';
	static constexpr int MIN_X = 10;
	static constexpr int MIN_Y = 2;
	static constexpr int START_X_COORD_BOARD_1 = 10 + (12 / 2);
	static constexpr int START_Y_COORD_BOARD_1 = MIN_Y + (BOARD_HEIGHT / 2);
	static constexpr int START_X_COORD_BOARD_2 = MIN_X + BOARDS_GAP + (BOARD_WIDTH / 2);
	static constexpr int START_Y_COORD_BOARD_2 = MIN_Y + BOARDS_GAP + (BOARD_HEIGHT / 2);
	static constexpr int EMPTY = -1;
	static constexpr int BOMB_RADIUS = 4;
	static constexpr int BOMB = -2;
	static constexpr int WHITE = 15;
	static constexpr int NEW_GAME = 1;
	static constexpr int RESUME_GAME = 2;
	static constexpr int INSTRUCTIONS = 8;
	static constexpr int EXIT = 9;
	static constexpr int NO_COLOR = 0;
	static constexpr int MAX_MOVES_PER_TURN = 10;
	static constexpr char DO_NOTHING = 'N';
	static const int COLORS[];
	static const int NUM_OF_COLORS;
	static const int NUM_OF_SHAPES;
	static const int NUM_OF_KEYS;
	static constexpr char ROTATE_CLOCKWISE = 'T';
	static constexpr char ROTATE_COUNTERCLOCKWISE = 'G';
	static constexpr char LEFT = 'L';
	static constexpr char RIGHT = 'R';
	static constexpr char DROP = 'x';

	enum class LKeys {
		LEFT_LOWER = 'a', RIGHT_LOWER = 'd', ROTATE_CLOCKWISE_LOWER = 's', ROTATE_COUNTERCLOCKWISE_LOWER = 'w', DROP_LOWER = 'x',
		LEFT_UPPER = 'A', RIGHT_UPPER = 'D', ROTATE_CLOCKWISE_UPPER = 'S', ROTATE_COUNTERCLOCKWISE_UPPER = 'W', DROP_UPPER = 'X',
		DO_NOTHING = 'N'
	};

	enum class RKeys {
		LEFT = 'j', RIGHT = 'l', ROTATE = 'k', ROTATE_COUNTER = 'i', DROP = 'm',
		LEFT_LOWER = 'j', RIGHT_LOWER = 'l', ROTATE_CLOCKWISE_LOWER = 'k', ROTATE_COUNTERCLOCKWISE_LOWER = 'i', DROP_LOWER = 'm',
		LEFT_UPPER = 'J', RIGHT_UPPER = 'L', ROTATE_CLOCKWISE_UPPER = 'K', ROTATE_COUNTERCLOCKWISE_UPPER = 'I', DROP_UPPER = 'M',
		DO_NOTHING = 'N'
	};
	static const char VALID_LEFT_KEYS[];
	static const char VALID_RIGHT_KEYS[];
};
#endif