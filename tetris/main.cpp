#include "Game.h"

void main()
{
	Game game;
	int color = game.init();
	if(color != 9)
		game.play(color);
}