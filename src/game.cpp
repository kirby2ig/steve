#include "game.h"

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

game::game() :
window(WIDTH, HEIGHT)
{
	thePlayer = new player(3, FLOOR - 1);
	running = true;
	state = MENU;
	walls = new wall*[MAX_WALLS];
	for(int i = 0; i < MAX_WALLS; i ++)
	{
		walls[i] = NULL;
	}
	ticks = 0;
	nextWall = 0;
	moveMultiple = 5;
	nextLevelScore = 20;
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
	delete thePlayer;
}

void game::reset()
{
	delete thePlayer;
	thePlayer = new player(3, FLOOR - 1);
	for(int i = 0; i < MAX_WALLS; i++)
	{
		if(walls[i] != NULL)
		{
			delete walls[i];
		}
	}
	delete[] walls;
	running = true;
	state = MENU;
	walls = new wall*[MAX_WALLS];
	for(int i = 0; i < MAX_WALLS; i ++)
	{
		walls[i] = NULL;
	}
	ticks = 0;
	nextWall = 0;
	moveMultiple = 5;
	nextLevelScore = 10;
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
	int score = thePlayer->getScore();
	int digits = 0;
	do
	{
		digits++;
		score /= 10;
	}
	while(score > 0);
	digits += 7;
	char* text = new char(digits);
	sprintf(text, "Score: %d", thePlayer->getScore());
	window.printText(text, -1, WIDTH - digits, 0);
	/*for(int i = 0; i < digits; i++)
	{
		char character = text[i];
		int x = WIDTH - digits + i;
		window.setCharacterAt(x, 0, character);
	}*/
	delete[] text;
}

void game::drawGameOver()
{
	//G
	window.setCharacterAt(11, 0, 'G');
	window.setCharacterAt(12, 0, 'G');
	window.setCharacterAt(13, 0, 'G');
	window.setCharacterAt(14, 0, 'G');
	window.setCharacterAt(15, 0, 'G');
	window.setCharacterAt(11, 1, 'G');
	window.setCharacterAt(11, 2, 'G');
	window.setCharacterAt(14, 2, 'G');
	window.setCharacterAt(15, 2, 'G');
	window.setCharacterAt(11, 3, 'G');
	window.setCharacterAt(15, 3, 'G');
 	window.setCharacterAt(11, 4, 'G');
	window.setCharacterAt(12, 4, 'G');
 	window.setCharacterAt(13, 4, 'G');
	window.setCharacterAt(14, 4, 'G');
	window.setCharacterAt(15, 4, 'G');
	//A
	window.setCharacterAt(19, 0, 'A');
	window.setCharacterAt(18, 1, 'A');
	window.setCharacterAt(20, 1, 'A');
	window.setCharacterAt(17, 2, 'A');
	window.setCharacterAt(18, 2, 'A');
	window.setCharacterAt(20, 2, 'A');
	window.setCharacterAt(21, 2, 'A');
	window.setCharacterAt(17, 3, 'A');
	window.setCharacterAt(21, 3, 'A');
	window.setCharacterAt(17, 4, 'A');
	window.setCharacterAt(21, 4, 'A');
	//M
	window.setCharacterAt(23, 0, 'M');
	window.setCharacterAt(27, 0, 'M');
	window.setCharacterAt(23, 1, 'M');
	window.setCharacterAt(24, 1, 'M');
	window.setCharacterAt(26, 1, 'M');
	window.setCharacterAt(27, 1, 'M');
	window.setCharacterAt(23, 2, 'M');
	window.setCharacterAt(25, 2, 'M');
	window.setCharacterAt(27, 2, 'M');
	window.setCharacterAt(23, 3, 'M');
	window.setCharacterAt(27, 3, 'M');
	window.setCharacterAt(23, 4, 'M');
	window.setCharacterAt(27, 4, 'M');
	//E
	window.setCharacterAt(29, 0, 'E');
	window.setCharacterAt(30, 0, 'E');
	window.setCharacterAt(31, 0, 'E');
	window.setCharacterAt(32, 0, 'E');
	window.setCharacterAt(33, 0, 'E');
	window.setCharacterAt(29, 1, 'E');
	window.setCharacterAt(29, 2, 'E');
	window.setCharacterAt(30, 2, 'E');
	window.setCharacterAt(31, 2, 'E');
	window.setCharacterAt(32, 2, 'E');
	window.setCharacterAt(33, 2, 'E');
	window.setCharacterAt(29, 3, 'E');
	window.setCharacterAt(29, 4, 'E');
	window.setCharacterAt(30, 4, 'E');
	window.setCharacterAt(31, 4, 'E');
	window.setCharacterAt(32, 4, 'E');
	window.setCharacterAt(33, 4, 'E');
	//O
	window.setCharacterAt(46, 0, 'O');
	window.setCharacterAt(47, 0, 'O');
	window.setCharacterAt(48, 0, 'O');
	window.setCharacterAt(49, 0, 'O');
	window.setCharacterAt(50, 0, 'O');
	window.setCharacterAt(46, 1, 'O');
	window.setCharacterAt(50, 1, 'O');
	window.setCharacterAt(46, 2, 'O');
	window.setCharacterAt(50, 2, 'O');
	window.setCharacterAt(46, 3, 'O');
	window.setCharacterAt(50, 3, 'O');
	window.setCharacterAt(46, 4, 'O');
	window.setCharacterAt(47, 4, 'O');
	window.setCharacterAt(48, 4, 'O');
	window.setCharacterAt(49, 4, 'O');
	window.setCharacterAt(50, 4, 'O');
	//V
	window.setCharacterAt(52, 0, 'V');
	window.setCharacterAt(56, 0, 'V');
	window.setCharacterAt(52, 1, 'V');
	window.setCharacterAt(56, 1, 'V');
	window.setCharacterAt(52, 2, 'V');
	window.setCharacterAt(56, 2, 'V');
	window.setCharacterAt(53, 3, 'V');
	window.setCharacterAt(55, 3, 'V');
	window.setCharacterAt(54, 4, 'V');
	//E
    window.setCharacterAt(58, 0, 'E');
	window.setCharacterAt(59, 0, 'E');
	window.setCharacterAt(60, 0, 'E');
	window.setCharacterAt(61, 0, 'E');
	window.setCharacterAt(62, 0, 'E');
	window.setCharacterAt(58, 1, 'E');
	window.setCharacterAt(58, 2, 'E');
	window.setCharacterAt(59, 2, 'E');
	window.setCharacterAt(60, 2, 'E');
	window.setCharacterAt(61, 2, 'E');
	window.setCharacterAt(62, 2, 'E');
	window.setCharacterAt(58, 3, 'E');
	window.setCharacterAt(58, 4, 'E');
	window.setCharacterAt(59, 4, 'E');
	window.setCharacterAt(60, 4, 'E');
	window.setCharacterAt(61, 4, 'E');
	window.setCharacterAt(62, 4, 'E');
	//R
	window.setCharacterAt(64, 0, 'R');
	window.setCharacterAt(65, 0, 'R');
	window.setCharacterAt(66, 0, 'R');
	window.setCharacterAt(67, 0, 'R');
	window.setCharacterAt(68, 0, 'R');
	window.setCharacterAt(64, 1, 'R');
	window.setCharacterAt(68, 1, 'R');
	window.setCharacterAt(64, 2, 'R');
	window.setCharacterAt(65, 2, 'R');
	window.setCharacterAt(66, 2, 'R');
	window.setCharacterAt(67, 2, 'R');
	window.setCharacterAt(68, 2, 'R');
	window.setCharacterAt(64, 3, 'R');
	window.setCharacterAt(66, 3, 'R');
	window.setCharacterAt(67, 3, 'R');
	window.setCharacterAt(64, 4, 'R');
	window.setCharacterAt(68, 4, 'R');
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
	window.printText((char*) "The jumping O", 13, 33, 6);  //this works! -Stephen
	/*//The
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
	window.setCharacterAt(45, 6, 'O');*/
	//Press spacebar to start
	window.printText((char*) "Press spacebar to start\n    Press Q to quit", /*23*/-1, 27, 77);  //this works! Uses newlines, too
	/*//Press
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
	window.setCharacterAt(49, 77, 't');*/
	//Press q to quit
	//window.printText((char*) "Press Q to quit", 15, 31, 78);
	/*//Press
	window.setCharacterAt(31, 78, 'P'); //old method
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
	window.setCharacterAt(45, 78, 't');*/
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
	thePlayer->render(&window);
	drawScore();
}

void game::updateEntities()
{
	thePlayer->update();	
	
	//Every moveMultiple ticks
	if(ticks % moveMultiple == 0)
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
	
	//Count the walls on screen
	int wallNum = 0;
	for(int i = 0; i < MAX_WALLS; i++)
	{
		if(walls[i] != NULL)
		{
			wallNum++;
		}
	}

	if(wallNum == 0 && thePlayer->getScore() >= nextLevelScore)
	{
		if(moveMultiple > 1)
		{
			moveMultiple--;
			nextLevelScore = thePlayer->getScore() * 2;
		}
	}

	//Add a new wall
	if(ticks >= nextWall)
	{
		nextWall = ticks + moveMultiple * (rand() % 25 + 26);
		if(moveMultiple == 1 || (moveMultiple > 1 && thePlayer->getScore() + wallNum < nextLevelScore))
		{
			for(int i = 0; i < MAX_WALLS; i++)
			{
				wall *w = walls[i];
				if(w == NULL)
				{
					walls[i] = new wall();
					break;
				}
			}
		}
	}
	

	//Check collisions
	for(int i = 0; i < MAX_WALLS; i++)
	{
		wall* w = walls[i];
		if(w != NULL)
		{
			thePlayer->checkCollision(w);
		}
	}
	//Check death
	if(!thePlayer->isAlive())
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
			drawGameOver();
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

			thePlayer->jump();
		}
	}

	if(state == MENU)
	{
		if(character == ' ')
			state = GAME;
	}
	
	if(state == DEATH)
	{
		if(character == ' ')
			reset();
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
