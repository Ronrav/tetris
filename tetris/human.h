#ifndef __HUMAN_H
#define __HUMAN_H
#include "player.h"


class Human : public Player {
	bool side;
	static bool side_flag;


public:
	Human() : side(side_flag) { side_flag = !side_flag; }
	virtual ~Human() {};
	bool isKeyInPlayerKeys(char key);
	virtual int playMove(char key, int colored) override;
	virtual void getNextBlock() override;


};

#endif // !__HUMAN_H