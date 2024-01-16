#include "Game.h"
#include<cstdlib>
#include<ctime>

void main()
{
	//srand(0);
	Game game;
	int color = game.init();
	if(color != 9)
		game.play(color);
	cout << "\n\n\n";
}