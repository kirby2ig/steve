#ifndef PLAYER_H
#define PLAYER_H

#include "screen.h"
#include "entity.h"

class player: public entity
{

	public:
		player(int x, int y);
		~player();
		int getHealth();
		int getScore();
		void setScore(int amount);
		void damage(int amount);
		bool isAlive();
		void render(screen *window);
	private:
		int health;
		int score;
};

#endif
