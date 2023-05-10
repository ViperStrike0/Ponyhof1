#pragma once
#include <iostream>
#include "Pony.h"
#define SIZE 20

class Stall
{
public:
	Stall();
	~Stall();
	int belegteBoxen();
	bool einstellen(Pony* neuesPony);
	Pony* herausholen(std::string name);
	void HolenzumWeidegang();
	float durchschnittsalter();
	void weidegang(int weide[40][60]);
	void zeigeInfo();
	void zeigeInfoPonysStall();
	int berechneJahr();
	Pony * getPonyAtIndex(int i);
	Pony * GetPonys();
	void Save();

private:
	Pony* pferdeboxen[SIZE];
};

