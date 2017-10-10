#include <iostream>
#include <unistd.h>

#include "game.h"

#define WIDTH 50
#define HEIGHT 10

#define FRAMERATE 30
#define FRAMETIME 1000000 / FRAMERATE

int main()
{
	game steve;
	steve.run();
}
