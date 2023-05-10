#pragma once
class Position
{
public:
	Position(int setx, int sety);
	Position();
	~Position();
	int getX();
	int getY();

private:
	float x = 0;
	float y = 0;

};

