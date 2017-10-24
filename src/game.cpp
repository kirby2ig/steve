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
	state = MENU;
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
	switch(state)
	{
		case GAME:
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
			break;
		case MENU:
			window.clear(' ');
			//S
			window.setCharacterAt(24, 0, 'S');
			window.setCharacterAt(25, 0, 'S');
			window.setCharacterAt(26, 0, 'S');
			window.setCharacterAt(27, 0, 'S');
			window.setCharacterAt(28, 0, 'S');
			window.setCharacterAt(24, 1, 'S');
			window.setCharacterAt(24, 2, 'S');
			window.setCharacterAt(25, 2, 'S');
			window.setCharacterAt(26, 2, 'S');
			window.setCharacterAt(27, 2, 'S');
			window.setCharacterAt(28, 2, 'S');
			window.setCharacterAt(28, 3, 'S');
			window.setCharacterAt(24, 4, 'S');
			window.setCharacterAt(25, 4, 'S');
			window.setCharacterAt(26, 4, 'S');
			window.setCharacterAt(27, 4, 'S');
			window.setCharacterAt(28, 4, 'S');
			//T
			window.setCharacterAt(31, 0, 'T');
			window.setCharacterAt(32, 0, 'T');
			window.setCharacterAt(33, 0, 'T');
			window.setCharacterAt(34, 0, 'T');
			window.setCharacterAt(35, 0, 'T');
			window.setCharacterAt(33, 1, 'T');
			window.setCharacterAt(33, 2, 'T');
			window.setCharacterAt(33, 3, 'T');
			window.setCharacterAt(33, 4, 'T');
			//E
			window.setCharacterAt(38, 0, 'E');
			window.setCharacterAt(39, 0, 'E');
			window.setCharacterAt(40, 0, 'E');
			window.setCharacterAt(41, 0, 'E');
			window.setCharacterAt(42, 0, 'E');
			window.setCharacterAt(38, 1, 'E');
			window.setCharacterAt(38, 2, 'E');
			window.setCharacterAt(39, 2, 'E');
			window.setCharacterAt(40, 2, 'E');
			window.setCharacterAt(41, 2, 'E');
			window.setCharacterAt(42, 2, 'E');
			window.setCharacterAt(38, 3, 'E');
			window.setCharacterAt(38, 4, 'E');
			window.setCharacterAt(39, 4, 'E');
			window.setCharacterAt(40, 4, 'E');
			window.setCharacterAt(41, 4, 'E');
			window.setCharacterAt(42, 4, 'E');
			//V
			window.setCharacterAt(45, 0, 'V');
			window.setCharacterAt(49, 0, 'V');
			window.setCharacterAt(45, 1, 'V');
			window.setCharacterAt(49, 1, 'V');
			window.setCharacterAt(45, 2, 'V');
			window.setCharacterAt(49, 2, 'V');
			window.setCharacterAt(46, 3, 'V');
			window.setCharacterAt(48, 3, 'V');
			window.setCharacterAt(47, 4, 'V');
			//E
			window.setCharacterAt(52, 0, 'E');
			window.setCharacterAt(53, 0, 'E');
			window.setCharacterAt(54, 0, 'E');
			window.setCharacterAt(55, 0, 'E');
			window.setCharacterAt(56, 0, 'E');
			window.setCharacterAt(52, 1, 'E');
			window.setCharacterAt(52, 2, 'E');
			window.setCharacterAt(53, 2, 'E');
			window.setCharacterAt(54, 2, 'E');
			window.setCharacterAt(55, 2, 'E');
			window.setCharacterAt(56, 2, 'E');
			window.setCharacterAt(52, 3, 'E');
			window.setCharacterAt(52, 4, 'E');
			window.setCharacterAt(53, 4, 'E');
			window.setCharacterAt(54, 4, 'E');
			window.setCharacterAt(55, 4, 'E');
			window.setCharacterAt(56, 4, 'E');
			break;
		case DEATH:
			
			break;
	}
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
	if(character == (char) 27 || character == 'q')
	{
		running = false;
	}
}

gameState game::getGameState()
{
	return state;	
}

void game::setGameState(gameState nextState)
{
	state = nextState;
}
