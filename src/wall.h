#ifndef WALL_H
#define WALL_H

#include "entity.h"

#define MAX_WALL_HEIGHT 4

class wall :
public entity
{
	public:
		wall(int height);
		~wall();
		void render(screen *window);
		void update();
		void move();
		bool stillExists();
		int getHeight();
		bool hasScored();
		void setScored(bool scored);
	private:
		int ticks;
		bool exists;
		int height;
		bool scored;
};

#endif
