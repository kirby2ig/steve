#include "game.h"

#include <iostream>
#include <curses.h>
#include <unistd.h>

#define WIDTH 80
#define HEIGHT 15

#define FPS 60
#define FRAMETIME 1000000 / FPS

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
		usleep(FRAMETIME);
	}
}

void game::update()
{
	handleInput();
	if(x >= WIDTH)
	{
		y++;
		x = 0;
	}
	if(y >= HEIGHT)
	{
		y = 0;
		x = 0;
	}
	window.clear('-');
	window.setCharacterAt(x, y, '0');
	x++;
}

void game::render()
{
	window.draw();
}

void game::handleInput()
{
	char character = window.getTypedCharacter();
	if(character == ' ')
	{
		//TODO handle jumps
	}
}
