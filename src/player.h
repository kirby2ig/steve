#ifndef PLAYER_H
#define PLAYER_H

#include "screen.h"
#include "entity.h"
#include "vec2f.h"

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
		void jump();
		void update();
	private:
		int health;
		int score;
		bool jumping;
		vec2f velocity;
};

#endif
