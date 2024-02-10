#include "gameConfig.h"

const int GameConfig::COLORS[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
const int GameConfig::NUM_OF_COLORS = sizeof(COLORS) / sizeof(int);
const int GameConfig::NUM_OF_SHAPES = 7;

const char GameConfig::VALID_LEFT_KEYS[] = { (char)LKeys::LEFT_LOWER, (char)LKeys::RIGHT_LOWER, (char)LKeys::ROTATE_CLOCKWISE_LOWER,
		(char)LKeys::ROTATE_COUNTERCLOCKWISE_LOWER, (char)LKeys::DROP_LOWER, (char)LKeys::LEFT_UPPER, (char)LKeys::RIGHT_UPPER,
		(char)LKeys::ROTATE_CLOCKWISE_UPPER, (char)LKeys::ROTATE_COUNTERCLOCKWISE_UPPER, (char)LKeys::DROP_UPPER, (char)LKeys::DO_NOTHING };

const char GameConfig::VALID_RIGHT_KEYS[] = { (char)RKeys::LEFT_LOWER, (char)RKeys::RIGHT_LOWER, (char)RKeys::ROTATE_CLOCKWISE_LOWER,
	(char)RKeys::ROTATE_COUNTERCLOCKWISE_LOWER, (char)RKeys::DROP_LOWER, (char)RKeys::LEFT_UPPER, (char)RKeys::RIGHT_UPPER,
	(char)RKeys::ROTATE_CLOCKWISE_UPPER, (char)RKeys::ROTATE_COUNTERCLOCKWISE_UPPER, (char)RKeys::DROP_UPPER, (char)RKeys::DO_NOTHING };

const int GameConfig::NUM_OF_KEYS = sizeof(VALID_RIGHT_KEYS) / sizeof(char);