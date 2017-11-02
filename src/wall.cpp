#include "wall.h"
#include "game.h"

wall::wall(int x, int y, int height):
entity(x, y)
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
		//Render wall
	}
}

void wall::update()
{
	ticks++;
	if(ticks % 3 == 0)
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