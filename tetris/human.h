#ifndef __HUMAN_H
#define __HUMAN_H
#include "player.h"


class Human : public Player {
	bool side;
	static bool side_flag;

	bool isKeyInPlayerKeys(char key);

public:
	Human() : side(side_flag) { side_flag = !side_flag; }
	virtual ~Human() { side_flag = true; };
	virtual int playMove(char key, int colored) override;
	virtual void getNextBlock() override;


};

#endif // !__HUMAN_H