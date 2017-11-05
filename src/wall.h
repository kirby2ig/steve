#ifndef WALL_H
#define WALL_H

#include "entity.h"

#define MAX_WALL_HEIGHT 4

class wall : public entity
{
	public:
		wall(int x, int height);
		~wall();
		void render(screen *window);
		void update();
		bool stillExists();
		int getHeight();
	private:
		int ticks;
		void move();
		bool exists;
		int height;
};

#endif
