#ifndef GAME_H
#define GAME_H

#include "screen.h"
#include "player.h"
#include "wall.h"

//Window
#define WIDTH 80
#define HEIGHT 15
#define FLOOR 11

//Gravity
#define LITTLE_G -.075

//FPS
#define FPS 60
#define FRAMETIME 1000000 / FPS

//Walls
#define MAX_WALLS 5
#define WALL_SPAWN 79

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
		void drawGameOver();
		void drawScore();
		void updateEntities();
		void reset();
		int nextWall;
		int moveMultiple;
		int nextLevelScore;
		int x; 
		int y;
		long ticks;
		player* thePlayer;
		gameState state;
		wall** walls;
}
;

#endif
