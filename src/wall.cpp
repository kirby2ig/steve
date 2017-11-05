#include "wall.h"
#include "game.h"

wall::wall(int x, int height):
entity(x, FLOOR - 1)
{
	this->height = height;
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
	ticks++;
	if(ticks % 2 == 0)
		move();
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
