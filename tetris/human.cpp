#include "human.h"

bool Human::side_flag = true;


bool Human::isKeyInPlayerKeys(char key)
{
	const char* keys_arr;
	if (this->side)
		keys_arr = GameConfig::VALID_LEFT_KEYS;
	else
		keys_arr = GameConfig::VALID_RIGHT_KEYS;
	for (int i = 0; i < GameConfig::NUM_OF_KEYS; i++)
		if (keys_arr[i] == key)
			return true;
	return false;
}

int Human::playMove(char key, int colored)
{
	if (isKeyInPlayerKeys(key))
		return makeMove(key, colored);
	return 0;
}
