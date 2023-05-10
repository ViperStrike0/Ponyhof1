#include "Pony.h"
#include "Position.h"
Pony::Pony(Position pos)
{
	ort = pos;
}

Pony::Pony()
{
}

Pony::~Pony()
{
}

int Pony::gibGeburtsjahr()
{
	return geburtsJahr;
}

std::string Pony::gibName()
{
	return name;
}

bool Pony::istReitbar(int alter)
{
	std::cout << "Falsche Funktion istReitbar()" << std::endl;
	return false;
}

void Pony::zeigeInfo()
{
	std::cout << "Falsche Funktion fuer ZeigeInfo()" << std::endl;
}

std::string Pony::retRasse()
{
	return "";
}

bool Pony::retSpec()
{
	return false;
}

Position Pony::GetPos()
{
	return ort;
}

void Pony::setzePos(const Position & p)
{
	ort = p;
}