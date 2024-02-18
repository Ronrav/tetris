#ifndef __HUMAN_H
#define __HUMAN_H
#include "player.h"


class Human : public Player {
	bool side;
	static bool side_flag;
	//verifies key is in player's key using the side data member
	bool isKeyInPlayerKeys(char key);

public:
	Human() : side(side_flag) { side_flag = !side_flag; }
	virtual ~Human() { side_flag = true; };
	
	//plays a move only if key pressed is in player's key
	virtual int playMove(char key, int colored) override;
	
	//generates player's next block
	virtual void getNextBlock() override;


};

#endif // !__HUMAN_H