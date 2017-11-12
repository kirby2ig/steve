#include "wall.h"
#include "game.h"

#include <stdlib.h>

wall::wall():
entity(WALL_SPAWN, FLOOR - 1)
{
	exists = true;
	scored = false;
	height = rand() % MAX_WALL_HEIGHT + 1;
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
