#include "player.h"

int player::getHealth()
{
	return health;
}

int player::getScore()
{
	return score;
}

void player::damage(int amount)
{
	health -= amount;
	if(health < 0)
		health = 0;
}

bool player::isAlive()
{
	return health > 0;
}

void player::setScore(int amount)
{
	score = amount;
}
