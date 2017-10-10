#include "game.h"

#include <iostream>
#include <curses.h>


game::game()
{
	nodelay(stdscr,1);
	this->running = true;
}

game::~game()
{

}

void game::run()
{
	while(running)
	{
		update();
		render();
	}
}

void game::update()
{
	handleInput();
}

void game::render()
{

}

void game::handleInput()
{
	int x = getch();
	if(x != ERR)
	{
		std::cout << x << std::endl;
	}
}
