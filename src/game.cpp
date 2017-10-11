#include "game.h"

#include <iostream>
#include <curses.h>


game::game()
{
	this->running = true;
	initscr();
	if(noecho() == ERR)
	{
		std::cout << "fatal: Couldn't set noecho mode." << std::endl;
		this->running = false;
	}
	if(cbreak() == ERR)
	{
		std::cout << "fatal: Couldn't set cbreak mode." << std::endl;
		this->running = false;
	}
	if(nodelay(stdscr, 1) == ERR)
	{
		std::cout << "fatal: Cooldn't set nodelay mode." << std::endl;
		this->running = false;
	}
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
	char x = getch();
	if(x == ' ')
	{
		printf("jump\n");
	}
}
