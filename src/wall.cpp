#include "wall.h"
#include "game.h"

wall::wall(int height):
entity(WALL_SPAWN, FLOOR - 1)
{
	this->height = height;
	exists = true;
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
