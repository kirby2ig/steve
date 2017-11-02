#include "player.h"
#include "game.h"

player::player(int x, int y): 
entity(x, y)
{
	jumping = false;
}

player::~player()
{

}

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

void player::render(screen *window)
{
	window->setCharacterAt(x, y, 'O');
}

void player::jump()
{
	if(!jumping)
	{
		y--;
		if(y < 0)
		{
			y = 0;
		}
	}
}
