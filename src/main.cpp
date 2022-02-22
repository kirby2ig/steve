#include <iostream>

#include "game.h"
#include "powerstats.h"

int main()
{
	powerstats_init();
	game *steve = new game();
	int init = steve->init();
	if(init <= 0)
	{
		std::cout << "Initialization failed" << std::endl;
		return init;
	}
	steve->run();
	delete steve;
	powerstats_finalize();
	return 0;
}
