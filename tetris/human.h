#ifndef __HUMAN_H
#define __HUMAN_H



#include "player.h"
class Human : public Player {
	bool side;
	static bool side_flag;


public:
	Human() : side(side_flag) { side_flag = !side_flag; }

	bool isKeyInPlayerKeys(char key);
	int playMove(char key, int colored);


};

#endif // !__HUMAN_H