#ifndef GAME_H
#define GAME_H

#include "screen.h"

class game
{
	public:
		game();
		~game();
		int init();
		void run();
	private:
		screen window;
		bool running;
		void update();
		void render();
		void handleInput();
		int score;
		int x; 
		int y;

}
;

#endif
