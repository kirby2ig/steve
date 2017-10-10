#include "screen.h"

#include<iostream>

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
}

screen::~screen()
{
	delete[] grid;
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
	std::cout << "\033[2J\033[1;1H";
	for(int y = 0; y < height; y++)
	{
		for(int x = 0; x < width; x++)
		{
			char character = getCharacterAt(x, y);
			std::cout << character;
		}
		std::cout << std::endl;
	}
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
