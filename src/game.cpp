#include "game.h"

#include <iostream>
#include <curses.h>

#define WIDTH 50
#define HEIGHT 10


game::game() : window(WIDTH, HEIGHT)
{
	running = true;
}

game::~game()
{

}

int game::init()
{
	return window.init();
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
	char character = window.getTypedCharacter();
	if(character == ' ')
	{
		std::cout << "Jump" << std::endl;
	}
}
