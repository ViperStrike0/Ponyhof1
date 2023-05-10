#include "Stall.h"
#include <ctime>
#include <vector>
#include <fstream>
#include <sstream>
Stall::Stall()
{

}


Stall::~Stall()
{
}



bool Stall::einstellen(Pony* p)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (pferdeboxen[i] == NULL)
		{
			pferdeboxen[i] = p;
			return true;
		}
	}
	return false;
}

Pony* Stall::herausholen(std::string name)
{
	Pony* pony = NULL;

	for (int i = 0; i < SIZE; i++)
	{
		if (pferdeboxen[i] != NULL)
		{
			if (pferdeboxen[i]->gibName() == name)
			{
				pony = pferdeboxen[i];
				pferdeboxen[i] = NULL;
				return pony;
			}
		}
	}
	return pony;
}

int Stall::belegteBoxen()
{
	int cntr = 0;

	for (int i = 0; i < SIZE; i++)
	{
		if (pferdeboxen[i] != NULL)
		{
			cntr++;
		}
	}

	return cntr;
}

void Stall::zeigeInfo()
{
	int untergestellePonys = 0;

	untergestellePonys = belegteBoxen();

	std::cout << "Aktuell sind insgesamt " << untergestellePonys << " Ponys im Stall untergestellt!" << std::endl;

	zeigeInfoPonysStall();

	float avgAlter = durchschnittsalter();

	std::cout << "Das Durchschnittsalter der Pferde beraegt: " << avgAlter << " Jahre" << std::endl;
}

void Stall::zeigeInfoPonysStall()
{
	for (int i = 0; i < SIZE; i++)
	{
		if (pferdeboxen[i] != NULL)
		{
			pferdeboxen[i]->zeigeInfo();
		}
	}
}

float Stall::durchschnittsalter()
{
	int sumalter = 0;
	int anz = 0;
	float durchschnitt = 0;

	//std::cout << "Aktuelles Jahr: " << berechneJahr() << std::endl;

	for (int i = 0; i < SIZE; i++)
	{
		if (pferdeboxen[i] != NULL)
		{
			anz++;
			sumalter += berechneJahr() - pferdeboxen[i]->gibGeburtsjahr();
		}
	}

	if (anz > 0)
	{
		durchschnitt = sumalter / anz;
	}
	return durchschnitt;
}

int Stall::berechneJahr()
{
	time_t seconds = time(NULL);

	float Jahr = seconds / 60 / 60 / 24 / 365.25;
	int j = (int)Jahr + 1970;
	return j;

}

Pony * Stall::GetPonys()
{
	return *pferdeboxen;
}

Pony* Stall::getPonyAtIndex(int i)
{
	if (pferdeboxen[i] != NULL)
		return pferdeboxen[i];
}

void Stall::weidegang(int weide[40][60])
{
	
	int zx = 0, zy = 0;
	
	//zx /= RAND_MAX;
	//zy /= RAND_MAX;

	srand(time(NULL));

	for (int i = 0; i < SIZE; i++)
	{	
		if (pferdeboxen[i] != NULL)
		{		
			zx = rand() %  30 + 0;
			zy = rand() %  40 + 0;
			std::cout << zx+30 << "\n";
			std::cout << zy << "\n";
			Position pos = Position(zx+30, zy);
			pferdeboxen[i]->setzePos(pos);
			std::cout << "POSX: " << pferdeboxen[i]->GetPos().getX();
			std::cout << "POSY: " << pferdeboxen[i]->GetPos().getY();
			std::cout << std::endl;
			weide[zy][zx+30] = 1;
			
			//herausholen(pferdeboxen[i]->gibName());
		}
	}
	for (int y = 0; y < 40; y++)
	{
		for (int x = 0; x < 60; x++)
			std::cout << weide[y][x];

		std::cout << std::endl;
	}
}

void Stall::Save()
{
	// save all data in a file

		std::ofstream myFile;

		myFile.open("ponys.txt", std::ios::out);

		if (myFile.is_open()) {

			for (int i = 0; i < SIZE; i++)

			{

				Pony* p = pferdeboxen[i];

				if (pferdeboxen[i] != nullptr)

				{

					// Write Pony's information to the file

					myFile << p->retRasse() << ";";

					myFile << p->gibName() << ";";

					myFile << p->gibGeburtsjahr() << ";";

					bool spec = p->retSpec();
					std::string sp;
					if (spec) sp = "y";
					else sp = "n";
					myFile << sp;
					myFile << std::endl;

				}

			}

			myFile.close();

			std::cout << "Data saved successfully!" << std::endl;

		}
		else {

			std::cout << "Failed to open file for writing." << std::endl;

		}

	}
