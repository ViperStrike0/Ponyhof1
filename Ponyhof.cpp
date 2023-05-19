// Ponyhof.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.//

#include <iostream>
#include "Pony.h"
#include "Ponyhof.h"
#include <fstream>
#include <sstream>
#define WRITE_BIN

int main()
{
	Ponyhof ponyhof = Ponyhof("ponys.txt");
	ponyhof.userDialog();
}

Ponyhof::Ponyhof(std::string filename)
{
	for (int y = 0; y < 40; y++)
		for (int x = 0; x < 60; x++)
			weide[y][x] = 0;

	bool error;
	char ch;
	do
	{
		error = false;

#ifdef WRITE_BIN
		std::ifstream myFile;
		myFile.open(filename);
#else
		myFile.open(filename, std::ios::binary);
#endif
		
		int zeile_cntr = 0;
		if (myFile)
		{
			try
			{
				std::string zeile;
				while (std::getline(myFile, zeile))
				{
					zeile_cntr++;
					std::istringstream s(zeile);
					std::string wert;
					std::vector<std::string> pferd;

					while (std::getline(s, wert, ';'))
					{
						pferd.push_back(wert);
					}

					if (pferd.at(0) == "Islandpferd")
					{
						bool ekzemer;
						if (pferd.at(3) == "n")
							ekzemer = false;
						else
							ekzemer = true;

						int alter = std::stoi(pferd.at(2));

						Pony* Islandpony = new Islandpferd(pferd.at(1), alter, ekzemer);
						stallung.einstellen(Islandpony);
					}
					else if (pferd.at(0) == "Shetlandpony")
					{
						bool kinderlieb;
						if (pferd.at(3) == "n")
							kinderlieb = false;
						else
							kinderlieb = true;

						int alter = std::stoi(pferd.at(2));

						Pony* shetlandpony = new Shetlandpony(pferd.at(1), alter, kinderlieb);
						stallung.einstellen(shetlandpony);
					}
			// Pferd Name != Shetland../Island.. dann throw diese Nachricht
					else
					{
						throw "Falsches Format in Zeile";
						error = true;
					}
				}
			}
			// Die Fehlermeldung wird hier gezeigt und der User kann entscheiden,
			// entweder das Programm zu stoppen oder wieder einzulesen
			catch (const char* errorMsg)
			{
				std::cout << errorMsg << " Zeile " << zeile_cntr << "!" << std::endl;
				std::cout << "Neu einlesen [e] oder abbrechen [a] ? ";
				std::cin >> ch;
				if (ch == 'e')
				{
					error = true;
					continue;
				}
				else
				{
					exit(0);
				}
			}
			myFile.close();

		}
			// "While" Schlife wird benutzt
	} while (error == true);
}

Ponyhof::~Ponyhof()
{
	stallung.Save();
}

int Ponyhof::Ponyhufe(int numPonys)
{
	if (numPonys > 0)
	{
		return 4 + Ponyhufe(numPonys - 1);
	}
	else
	{
		return 0;
	}
}

void Ponyhof::HolenzumWeidegang()
{
	stallung.weidegang(weide);
	for (int i = 0; i < SIZE; i++)
	{
		Pony * p = stallung.getPonyAtIndex(i);
		beimWeidegang.push_back(p);
	}
}

void Ponyhof::vonWeidegangZumStall()
{
	for (int i = 0; i < beimWeidegang.size(); i++)
		stallung.einstellen(beimWeidegang.at(i));
}

void Ponyhof::userDialog()
{
	int eingabe = 0;

	// Menu
	do {
		do {
			std::cout << "1 Pony einstellen" << std::endl;
			std::cout << "2 Pony zum Reiten holen" << std::endl;
			std::cout << "3 Ponys kontrollieren" << std::endl;
			std::cout << "4 Ponys auf Weide schicken" << std::endl;
			std::cout << "5 Ponys beim Weidegang" << std::endl;
			std::cout << "9 Ponyhufen zaehlen" << std::endl;
			std::cout << "0 Programm beenden" << std::endl;
			std::cin >> eingabe;

			if (eingabe < 0 || eingabe > 9)
			{
				std::cout << "FEHLER: Eingabe muss zwischen 0 und 3 liegen" << std::endl;
			}

		} while (eingabe < 0 || eingabe > 9);

		switch (eingabe)
		{
		case 0:
			Feierabend();
			break;
		case 1:
			Ponyalegen();
			break;
		case 2:
			PonyHolen();
			break;
		case 3:
			PonysKontrollieren();
			break;
		case 4:
			HolenzumWeidegang();
			break;
		case 5:
			ZeigePonysWeidegang();
			break;
		case 9:
			int anz = 0;

			do {
				std::cout << "Anzahl der Ponys eingeben" << std::endl;
				std::cin >> anz;

				if (anz <= 0)
				{
					std::cout << "FEHLER: Bitte Zahl groeßer als 0 eingeben!" << std::endl;
				}
			} while (anz <= 0);

			int res = Ponyhufe(anz);

			std::cout << anz << " Ponys haben " << res << " Hufen" << std::endl;
			break;
		}
	} while (eingabe != 0);

	std::cout << "Programm wird beendet!" << std::endl;
}

void Ponyhof::Ponyalegen()
{
	int rasse = 0;

	do {
		std::cout << "Welche Ponyrasse wollen Sie alegen?" << std::endl;
		std::cout << "1 - Islandpferd" << std::endl;
		std::cout << "2 - Shetlandpony" << std::endl;
		std::cin >> rasse;
	} while (rasse != 1 && rasse != 2);

	switch (rasse)
	{
		case 1:
			IslandpferdAnlegen();
		break;

		case 2:
			ShetlandponyAnlegen();
		break;

		default:
			std::cout << "FEHLER: Keine gueltige Pferderasse gewaehlt!" << std::endl;
		break;
	}
}

void Ponyhof::IslandpferdAnlegen()
{
	int geburtsjahr = 0;
	std::string name = "";
	char ekz;
	bool ekzemer,erfolg;

	std::cout << std::endl;
	std::cout << "Islandpferd anlegen" << std::endl;

	std::cout << "Name des Pferdes angeben:" << std::endl;
	std::cin >> name;

	std::cout << "Geburtsjahr des Pferdes angeben" << std::endl;
	std::cin >> geburtsjahr;

	std::cout << "Ekzemer [y/n]:" << std::endl;
	std::cin >> ekz;

	if (ekz == 'y' || ekz == 'Y')
		ekzemer = true;
	else
		ekzemer = false;

	Pony * islandpferd = new Islandpferd(name, geburtsjahr, ekzemer);
	erfolg = stallung.einstellen(islandpferd);

	if (erfolg)
	{
		std::cout << "Islandpferd <" << name << "> erfolgreich  eingesellt" << std::endl;
	}
	else
	{
		std::cout << "FEHLER: Alle Pferdeboxen sind belegt!" << std::endl;
	}
}

void Ponyhof::ShetlandponyAnlegen()
{
	int geburtsjahr = 0;
	std::string name = "";
	char kl;
	bool kinderlieb,erfolg;

	std::cout << std::endl;
	std::cout << "Shetlandpony anlegen" << std::endl;

	std::cout << "Name des Pferdes angeben:" << std::endl;
	std::cin >> name;

	std::cout << "Geburtsjahr des Pferdes angeben" << std::endl;
	std::cin >> geburtsjahr;

	std::cout << "Ist Kinderlieb [y/n]" << std::endl;
	std::cin >> kl;
	
	if (kl == 'y' || kl == 'Y')
		kinderlieb = true;
	else
		kinderlieb = false;

	Pony * shetlandpony = new Shetlandpony(name, geburtsjahr, kinderlieb);
	erfolg = stallung.einstellen(shetlandpony);

	if(erfolg)
	{
		std::cout << "Shetlandpony <"<< name << "> erfolgreich  eingesellt" << std::endl;
	}
	else
	{
		std::cout << "FEHLER: Alle Pferdeboxen sind belegt!" << std::endl;
	}
}

void Ponyhof::PonyHolen()
{
	std::string name;

	std::cout << "Pony holen" << std::endl;
	std::cout << "Name des Ponys eingeben: " << std::endl;
	std::cin >> name;

	Pony * pony = stallung.herausholen(name);

	int alter = 0;

	std::cout << "Bitte Ihr alter angeben" << std::endl;
	std::cin >> alter;

	bool reitbar = pony->istReitbar(alter);

	if (reitbar)
	{
		if (pony != NULL)
		{
			if (std::count(beimReiten.begin(), beimReiten.end(), pony) == 0)
			{
				std::string name;
				int gebutsjahr;

				name = pony->gibName();
				gebutsjahr = pony->gibGeburtsjahr();

				beimReiten.push_back(pony);

				std::cout << "Pony <" << name << "> mit dem Geburtsjahr <" << gebutsjahr << "> wird geritten" << std::endl;
			}
			else
			{
				std::cout << "Pony nicht reitbar, da es momentan geritten wird!" << std::endl;
			}
		}
		else
		{
			std::cout << "FEHLER: Pony konnte nicht gefunden werden!" << std::endl;
		}
	}
	else
	{
		std::cout << "Pony wird wieder in Stallung gestellt!" << std::endl;
		stallung.einstellen(pony);
	}
}

void Ponyhof::PonysKontrollieren()
{
	stallung.zeigeInfo();
	ZeigeInfoBeimReiten();
}

void Ponyhof::ZeigePonysWeidegang()
{

	std::cout << "Ponys beim Weidegang:" << std::endl;
	for (int i = 0; i < beimWeidegang.size(); i++)
	{
		if (beimWeidegang.at(i) != NULL)
		{
			std::cout << "Name: " << beimWeidegang.at(i)->gibName();
			std::cout << "Geburtsjahr:" << beimWeidegang.at(i)->gibGeburtsjahr();
		}
	}
}


void Ponyhof::ZeigeInfoBeimReiten()
{
	int anzBeimReiten = beimReiten.size();

	std::cout << "Aktell werden " << anzBeimReiten << " Ponys geritten" << std::endl;
}

void Ponyhof::Feierabend()
{
	std::cout << "Feierabend, schicke alle Ponys wieder zurueck in den Stall" << std::endl;
	int anz = 0;
	for (int i = 0; i < beimReiten.size(); i++)
	{
		stallung.einstellen(beimReiten.at(i));
		anz++;
	}

	std::cout << "Es wurden " << anz << " Ponys in den Stall zurueckgestellt" << std::endl;
}