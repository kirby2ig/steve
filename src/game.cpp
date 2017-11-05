#include "game.h"

#include <iostream>
#include <unistd.h>
#include <math.h>
#include <stdio.h>

game::game() :
window(WIDTH, HEIGHT),
thePlayer(3, FLOOR - 1)
{
	running = true;
	state = MENU;
	walls = new wall*[MAX_WALLS];
	for(int i = 0; i < MAX_WALLS; i ++)
	{
		walls[i] = NULL;
	}
}

game::~game()
{
	for(int i = 0; i < MAX_WALLS; i++)
	{
		if(walls[i] != NULL)
		{
			delete walls[i];
		}
	}
	delete[] walls;
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

void game::drawScore()
{
	int score = thePlayer.getScore();
	int digits = 0;
	do
	{
		digits++;
		score /= 10;
	}
	while(score > 0);
	digits += 7;
	char* text = new char(digits);
	sprintf(text, "Score: %d", thePlayer.getScore());
	for(int i = 0; i < digits; i++)
	{
		char character = text[i];
		int x = WIDTH - digits + i;
		window.setCharacterAt(x, 0, character);
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
	//The jumping O
	//The
	window.setCharacterAt(33, 6, 'T');
	window.setCharacterAt(34, 6, 'h');
	window.setCharacterAt(35, 6, 'e');
	//jumping
	window.setCharacterAt(37, 6, 'j');
	window.setCharacterAt(38, 6, 'u');
	window.setCharacterAt(39, 6, 'm');
	window.setCharacterAt(40, 6, 'p');
	window.setCharacterAt(41, 6, 'i');
	window.setCharacterAt(42, 6, 'n');
	window.setCharacterAt(43, 6, 'g');
	//O
	window.setCharacterAt(45, 6, 'O');
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
	for(int i = 0; i < MAX_WALLS; i++)
	{
		wall* w = walls[i];
		if(w != NULL)
		{
			w->render(&window);
		}
	}
	thePlayer.render(&window);
	drawScore();
}

void game::updateEntities()
{
	thePlayer.update();
	//Move walls every 2 ticks
	if(ticks % 2 == 0)
	{
		//Move walls
		for(int i = 0; i < MAX_WALLS; i++)
		{
			wall* w = walls[i];
			if(w != NULL)
			{
				w->move();
			}
		}
		//Remove dead walls
		for(int i = 0; i < MAX_WALLS; i++)
		{
			wall* w = walls[i];
			if(w != NULL)
			{
				if(!w->stillExists())
				{
					delete w;
					walls[i] = NULL;
				}
			}
		}
	}
	//Add new walls
	if(ticks % 60 == 0)
	{
		for(int i = 0; i < MAX_WALLS; i++)
		{
			wall* w = walls[i];
			if(w == NULL)
			{
				int height = rand() % MAX_WALL_HEIGHT + 1;
			  	walls[i] = new wall(height);
				break;
			}
		}
	}
	//Check collisions
	for(int i = 0; i < MAX_WALLS; i++)
	{
		wall* w = walls[i];
		if(w != NULL)
		{
			thePlayer.checkCollision(w);
		}
	}
	//Check death
	if(!thePlayer.isAlive())
	{
		state = DEATH;
	}	
}

void game::update()
{
	handleInput();
	if(state == GAME)
	{
		updateEntities();
		ticks++;
	}
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
		case DEATH:
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

			thePlayer.jump();
		}
	}

	if(state == MENU)
	{
		if(character == ' ')
			state = GAME;
	}

	if(character == 'q')
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
