#ifndef GAME_H
#define GAME_H

#include "screen.h"
#include "player.h"

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
		void drawTitle();
		void drawFloor();
		void drawGame();
		int score;
		int x; 
		int y;
		player theplayer;
		gameState state;
}
;

#endif
