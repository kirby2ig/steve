#ifndef PLAYER_H
#define PLAYER_H

#include "screen.h"

class player: public entity
{

	public:
		int getHealth();
		int getScore();
		void setScore(int amount);
		void damage(int amount);
		bool isAlive();
	private:
		int health;
		int score;
};

#endif
