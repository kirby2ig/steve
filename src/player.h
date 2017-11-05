#ifndef PLAYER_H
#define PLAYER_H

#include "screen.h"
#include "entity.h"
#include "vec2f.h"
#include "wall.h"

class player: public entity
{

	public:
		player(int x, int y);
		~player();
		int getScore();
		void setScore(int amount);
		bool isAlive();
		void render(screen *window);
		void jump();
		void update();
		void checkCollision(wall* w);
	private:
		bool alive;
		int score;
		bool jumping;
		vec2f velocity;
};

#endif
