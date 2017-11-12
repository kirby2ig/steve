#include "entity.h"

entity::entity(int x, int y)
{
	this->x = x;
	this->y = y;
}

entity::~entity()
{

}

int entity::getX()
{
	return x;
}

int entity::getY()
{
	return y;
}

void entity::setX(int x)
{
	this->x = x;
}

void entity::setY(int y)
{
	this->y = y;
}