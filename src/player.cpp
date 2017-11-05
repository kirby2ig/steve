#include "player.h"
#include "game.h"
#include <math.h>

#define JUMP_VELOC 1

player::player(int x, int y): 
entity(x, y)
{
	jumping = false;
	velocity.x = 0;
	velocity.y = 0;
	score = 0;
	alive = true;
}

player::~player()
{

}

int player::getScore()
{
	return score;
}

bool player::isAlive()
{
	return alive;
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
		jumping = true;
		velocity.y = JUMP_VELOC;
	}
}

void player::checkCollision(wall* w)
{
	if(w->getX() == x)
	{
		if(w->getY() - w->getHeight() <= y)
		{
			alive = false;
		}
	}
	else if(w->getX() < x)
	{
		if(!w->hasScored())
		{
			score++;
			w->setScored(true);
		}	
	}
}

void player::update()
{
	velocity.y += LITTLE_G;
	y -= round(velocity.y);
	if(y < 0)
		y = 0;
	if(y > FLOOR - 1)
	{
		jumping = false;
	}
	if(!jumping)
	{
		y = FLOOR - 1;
		velocity.y = 0;
	}
}
