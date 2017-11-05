#include "wall.h"
#include "game.h"

wall::wall(int height):
entity(WALL_SPAWN, FLOOR - 1)
{
	this->height = height;
	exists = true;
	scored = false;
}

wall::~wall()
{
	
}

void wall::render(screen *window)
{
	if(exists)
	{
		for(int i = y; i >= FLOOR - height; i--)
		{
			window->setCharacterAt(x, i, '|');
		}	
	}
}

void wall::update()
{
	
}

bool wall::hasScored()
{
	return scored;
}

void wall::setScored(bool scored)
{
	this->scored = scored;
}

int wall::getHeight()
{
	return height;
}

void wall::move()
{
	x--;
	if(x < 0)
	{
		exists = false;
	}
}

bool wall::stillExists()
{
	return exists;
}
