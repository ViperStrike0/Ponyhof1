#include "Islandpferd.h"



Islandpferd::Islandpferd()
{
}

Islandpferd::Islandpferd(std::string n, int a, bool ekz)
{
	ekzemer = ekz;
	name = n;
	geburtsJahr = a;
}

Islandpferd::~Islandpferd()
{
}

bool Islandpferd::istReitbar(int alter) 
{
	if (alter >= 10)
	{
		return true;
	}
	else
	{
		std::cout << "Pony nicht reitbar, da alter mindestens 10 Jahre betragen muss!" << std::endl;
		return false;
	}
}

bool Islandpferd::hatEkzem()
{
	return ekzemer;
}

void Islandpferd::zeigeInfo()
{
	std::cout << std::endl;
	std::cout << "Zeige Infos zu Pony <" << name << std::endl;
	std::cout << "Alter: " << geburtsJahr << std::endl;
	if (hatEkzem())
	{
		std::cout << "Ekzem: y" << std::endl;
	}
	else
	{
		std::cout << "Ekzem: n" << std::endl;
	}
	std::cout << "Rasse: Islandpferd" << std::endl;

	//Position p = this->GetPos();

	std::cout << "Das Pony befindet sich auf Pos <" << ort.getX() << "|" << ort.getY() << std::endl;
}

bool Islandpferd::retSpec()
{
	return ekzemer;
}

std::string Islandpferd::retRasse()
{
	return "Islandpferd";
}
