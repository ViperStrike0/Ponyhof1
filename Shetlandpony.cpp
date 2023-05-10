#include "Shetlandpony.h"
#include "Pony.h"

Shetlandpony::Shetlandpony()
{

}

Shetlandpony::Shetlandpony(std::string n, int a, bool kl)
{
	name = n;
	geburtsJahr = a;
	kinderlieb = kl;

}

Shetlandpony::~Shetlandpony()
{
}

bool Shetlandpony::istReitbar(int alter)
{
	if (alter >= 5 && alter <= 12)
	{
		if (alter <= 8)
		{
			if (istKinderlieb())
			{
				return true;
			}
			else
			{
				std::cout << "Pony nicht reitbar, da bei Kinder unter 8 das Pony kinderlieb sein muss!" << std::endl;
				return false;
			}
		}
		else
		{
			return true;
		}
	}
	else
	{
		std::cout << "Pony nicht reitbar, da alter zwischen 5 und 12 liegen muss!" << std::endl;
		return false;
	}
}

void Shetlandpony::zeigeInfo()
{
	std::cout << std::endl;
	std::cout << "Zeige Infos zu Pony <" << name << ">" << std::endl;
	std::cout << "Alter: " << geburtsJahr << std::endl;
	if (istKinderlieb())
	{
		std::cout << "Kinderlieb: y" << std::endl;
	}
	else
	{
		std::cout << "Kinderlieb: n" << std::endl;
	}
	std::cout << "Rasse: Shetlandpony" << std::endl;

	//Position p = this->GetPos();

	std::cout << "Das Pony befindet sich auf Pos <" << ort.getX() << "|" << ort.getY() << std::endl;
}

bool Shetlandpony::istKinderlieb()
{
	return kinderlieb;
}

bool Shetlandpony::retSpec()
{
	return kinderlieb;
}

std::string Shetlandpony::retRasse()
{
	return "Shetlandpony";
}
