#include "screen.h"

#include <iostream>
#include <curses.h>
#include <stdio.h>

screen::screen(int width, int height)
{
	this->width = width;
	this->height = height;
	this->grid = new char*[width];
	for(int i = 0; i < width; i++)
	{
		this->grid[i] = new char[height];
	}
	clear(' ');
	debug = NULL;
	debuglength = 0;
}

screen::~screen()
{
	for(int i = 0; i < width; i++)
	{
		delete[] grid[i];
	}
	delete[] grid;
	delete[] debug;
	endwin();
}

int screen::init()
{
	initscr();
	int echoErr = noecho();
	int cbreakErr = cbreak();
	int nodelayErr = nodelay(stdscr, 1);
	if(echoErr == ERR)
	{
		std::cout << "fatal: Could not set noecho" << std::endl;
		return echoErr;
	}
	if(cbreakErr == ERR)
	{
		std::cout << "fatal: Could not set cbreak" << std::endl;
		return cbreakErr;
	}
	if(nodelayErr == ERR)
	{
		std::cout << "fatal: Could not set nodelay" << std::endl;
		return nodelayErr;
	}
	return 1;
}

int screen::getTypedCharacter()
{
	return getch();
}

void screen::setCharacterAt(int x, int y, char character)
{
	*(*(grid + x) + y) = character;
}

char screen::getCharacterAt(int x, int y)
{
	return *(*(grid + x) + y);
}

void screen::draw()
{
	for(int y = 0; y < height; y++)
	{
		for(int x = 0; x < width; x++)
		{
			char character = getCharacterAt(x, y);
			move(y, x);
			curs_set(0);
			printw("%c", character);
		}
	}
	for(int x = 0; x < debuglength; x++)
	{
		int y = height - 1;
		char character = *(debug + x);
		move(y, x);
		curs_set(0);
		printw("%c", character);
	}
	refresh();
}

void screen::clear(char space)
{
	for(int y = 0; y < height; y++)
	{
		for(int x = 0; x < width; x++)
		{
			setCharacterAt(x, y, space);
		}
	}
}

void screen::print(char* string, int length)
{
	delete[] debug;
	debug = string;
	debuglength = length;
}
