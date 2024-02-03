#ifndef __GAME_H
#define __GAME_H
#include "board.h"
#include "utills.h"
#include <windows.h>
#include "gameConfig.h"

class Game
{
	static constexpr int NUM_OF_PLAYERS = 2;
	Board boards[NUM_OF_PLAYERS];

	// Handles the start menu logic for selecting new game, instructions, or exit.
	int handleStartMenu() const;


	// Handles the pause menu logic for selecting new game, resuming, instructions, or exit during gameplay.
	// Returs key, representing the selected option.
	int handlePauseMenu() const;


	// Prints game instructions for player controls.
	void printInstructions() const;


	//  Handles keyboard input during gameplay, allowing players to move, rotate, drop blocks, and pause the game.
	// return key, that represents the wanted action.
	int handleKbhit();


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
	void initBoardAndColor();

	static constexpr int PLAYER1 = 0;
	static constexpr int PLAYER2 = 1;
	static constexpr int TIE = 3;
	static constexpr int NEW_GAME = 1;
	static constexpr int RESUME_GAME = 2;
	static constexpr int INSTRUCTIONS = 8;
	static constexpr int EXIT = 9;
	static constexpr int WHITE = 15;
	static constexpr int NO_COLOR = 0;
	static constexpr int WITH_COLOR = 1;
	static constexpr int MAX_KEYS_IN_BUFFER = 10;
	static constexpr int ESC = 27;
	static constexpr char LEFT = 'L';
	static constexpr char RIGHT = 'R';
	static constexpr char ROTATE_CLOCKWISE = 'T';
	static constexpr char ROTATE_COUNTERCLOCKWISE = 'G';


	enum class LKeys {
		LEFT_LOWER = 'a', RIGHT_LOWER = 'd', ROTATE_CLOCKWISE_LOWER = 's', ROTATE_COUNTERCLOCKWISE_LOWER = 'w', DROP_LOWER = 'x',
		LEFT_UPPER = 'A', RIGHT_UPPER = 'D', ROTATE_CLOCKWISE_UPPER = 'S', ROTATE_COUNTERCLOCKWISE_UPPER = 'W', DROP_UPPER = 'X',
	};

	enum class RKeys {
		LEFT = 'j', RIGHT = 'l', ROTATE = 'k', ROTATE_COUNTER = 'i', DROP = 'm',
		LEFT_LOWER = 'j', RIGHT_LOWER = 'l', ROTATE_CLOCKWISE_LOWER = 'k', ROTATE_COUNTERCLOCKWISE_LOWER = 'i', DROP_LOWER = 'm',
		LEFT_UPPER = 'J', RIGHT_UPPER = 'L', ROTATE_CLOCKWISE_UPPER = 'K', ROTATE_COUNTERCLOCKWISE_UPPER = 'I', DROP_UPPER = 'M',
	};
public:
	// Initiates the gameplay loop, handles player input, updates the game state, and checks for game over conditions.
	void playGame();
	
	
};

#endif

