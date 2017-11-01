#include "game.h"

#include <iostream>
#include <unistd.h>

#define WIDTH 80
#define HEIGHT 15
#define FLOOR 11

#define FPS 60
#define FRAMETIME 1000000 / FPS

game::game() :
window(WIDTH, HEIGHT),
theplayer(3, FLOOR - 1)
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

void game::drawTitle()
{
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
	//Press spacebar to start
	//Press
	window.setCharacterAt(27, 77, 'P');
	window.setCharacterAt(28, 77, 'r');
	window.setCharacterAt(29, 77, 'e');
	window.setCharacterAt(30, 77, 's');
	window.setCharacterAt(31, 77, 's');
	//spacebar
	window.setCharacterAt(33, 77, 's');
	window.setCharacterAt(34, 77, 'p');
	window.setCharacterAt(35, 77, 'a');
	window.setCharacterAt(36, 77, 'c');
	window.setCharacterAt(37, 77, 'e');
	window.setCharacterAt(38, 77, 'b');
	window.setCharacterAt(39, 77, 'a');
	window.setCharacterAt(40, 77, 'r');
	//to
	window.setCharacterAt(42, 77, 't');
	window.setCharacterAt(43, 77, 'o');
	//start
	window.setCharacterAt(45, 77, 's');
	window.setCharacterAt(46, 77, 't');
	window.setCharacterAt(47, 77, 'a');
	window.setCharacterAt(48, 77, 'r');
	window.setCharacterAt(49, 77, 't');
	//Press q to quit
	//Press
	window.setCharacterAt(31, 78, 'P');
	window.setCharacterAt(32, 78, 'r');
	window.setCharacterAt(33, 78, 'e');
	window.setCharacterAt(34, 78, 's');
	window.setCharacterAt(35, 78, 's');
	//q
	window.setCharacterAt(37, 78, 'Q');
	//to
	window.setCharacterAt(39, 78, 't');
	window.setCharacterAt(40, 78, 'o');
	//quit
	window.setCharacterAt(42, 78, 'q');
	window.setCharacterAt(43, 78, 'u');
	window.setCharacterAt(44, 78, 'i');
	window.setCharacterAt(45, 78, 't');
}

void game::drawFloor()
{
	for(int y = HEIGHT - 1; y >= FLOOR + 1; y--)
	{
		for(int x = 0; x < WIDTH; x++)
		{
			window.setCharacterAt(x, y, '8');
		}
	}
	for(int x = 0; x < WIDTH; x++)
	{
		window.setCharacterAt(x, FLOOR, 'T');
	}
}

void game::drawGame()
{
	window.clear(' ');
	drawFloor();
	theplayer.render(&window);
}

void game::update()
{
	handleInput();
}

void game::render()
{
	switch(state)
	{
		case MENU:
			drawTitle();
			break;
		case GAME:
			drawGame();
			break;
	}
	window.draw();
}

void game::handleInput()
{
	char character = window.getTypedCharacter();
	if(state == GAME)
	{
		if(character == ' ')
		{
			//TODO handle jumps
		}
	}

	if(state == MENU)
	{
		if(character == ' ')
			state = GAME;
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
