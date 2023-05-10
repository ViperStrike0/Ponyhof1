#include "Position.h"



Position::Position(int setx,int sety)
{
	x = setx;
	y = sety;
}

Position::Position()
{
	x = 0;
	y = 0;
}

Position::~Position()
{
}

int Position::getX()
{
	return x;
}

int Position::getY()
{
	return y;
}