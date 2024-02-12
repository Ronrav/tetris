#ifndef __GAME_H
#define __GAME_H
#include "board.h"
#include "utills.h"
#include <windows.h>
#include "gameConfig.h"
#include "menu.h"
#include "human.h"
#include "computer.h"

class Game
{
	static constexpr int NUM_OF_PLAYERS = 2;
	Computer players[NUM_OF_PLAYERS];
	static int colored;

	static void set_colored(int key);

	//Prints the game boards for both players.
	void printBoards() const;


	// Checks if the game has ended based on the players' scores. 
	//It gets the scores array. and returns "true" if the game has ended. 
	//if true - prints the winner by "announceTheWinner" func. 
	bool isGameEnded(bool scores[]) const;


	//  Initializes the game, handles start menu, and initializes the game board.
	// Returs key, representing the selected option.
	int init();


	//Gets the player number who won or TIE for a tie, 
	//and prints the winner or a tie message and waits for a key press to return to the main menu.
	void announceTheWinner(int winner) const;


	//Prints the borders of the game boards for both players.
	void printBorders() const;


	//Handles clearing full rows in the game boards.
	void handleFullRows();


	//  Initializes the game board and color settings based on player input.
	void initColor();

	void handleBomb();

	void zeroPlayingBoards();

	char inputKbhit();

	void initNewGame();

	void cleanExit();
	int playPlayersTurn();
	bool isKeyBrakeGame(char key);
	void handleTurnEnd(bool move[]);

	static constexpr int PLAYER1 = 0;
	static constexpr int PLAYER2 = 1;
	static constexpr int TIE = 3;
	static constexpr int NO_COLOR = 0;
	static constexpr int WITH_COLOR = 1;
	static constexpr int MAX_KEYS_IN_BUFFER = 10;

	

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
public:
	// Initiates the gameplay loop, handles player input, updates the game state, and checks for game over conditions.
	void playGame();


	
	
};

#endif

