#include <iostream>

#include "game.h"

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
