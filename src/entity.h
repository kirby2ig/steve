#ifndef ENTITY_H
#define ENTITY_H

#include "screen.h"

class entity
{
	public:
		entity(int x, int y);
		~entity(); 
		virtual void render(screen *window) = 0;
		int getX();
		int getY();
		void setX(int x);
		void setY(int y);
	protected:
		int x;
		int y;
};

#endif
