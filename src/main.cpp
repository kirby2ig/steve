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
	int init = steve.init();
	if(init <= 0)
	{
		std::cout << "Initialization failed" << std::endl;
		return init;
	}
	steve.run();
	return 0;
}
