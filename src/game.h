#ifndef GAME_H
#define GAME_H

class game
{
	public:
		game();
		~game();
		void run();
	private:
		bool running;
		void update();
		void render();
		void handleInput();

}
;

#endif
