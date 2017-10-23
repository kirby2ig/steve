#ifndef GAME_H
#define GAME_H

#include "screen.h"

typedef enum gameState
{
	MENU, GAME, DEATH
} gameState;

class game
{
	public:
		game();
		~game();
		int init();
		void run();
		gameState getGameState();
		void setGameState(gameState nextState);
	private:
		screen window;
		bool running;
		void update();
		void render();
		void handleInput();
		int score;
		int x; 
		int y;
		gameState state;
}
;

#endif
