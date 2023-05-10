#pragma once
#include <iostream>
#include <vector>
#include "Stall.h"
#include "Pony.h"
#include "Ponyhof.h"
#include "Islandpferd.h"
#include "Shetlandpony.h"

class Ponyhof
{
public:
	Ponyhof();
	Ponyhof(std::string filename);
	~Ponyhof();
	void userDialog();
	int Ponyhufe(int anzHufe);
private:
	Stall stallung;
	std::vector<Pony*> beimReiten;
	std::vector<Pony*> beimWeidegang;
	int weide[40][60]; // Hier Datentyp überlegen
	void Ponyalegen();
	void PonyHolen();
	void HolenzumWeidegang();
	void vonWeidegangZumStall();
	void ZeigePonysWeidegang();
	void PonysKontrollieren();
	void IslandpferdAnlegen();
	void ShetlandponyAnlegen();
	void ZeigeInfoBeimReiten();
	void Feierabend();
};

