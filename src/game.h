#ifndef GAME_H
#define GAME_H

#include "screen.h"
#include "player.h"

#define WIDTH 80
#define HEIGHT 15
#define FLOOR 11

#define LITTLE_G -0.05

#define FPS 60
#define FRAMETIME 1000000 / FPS

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
