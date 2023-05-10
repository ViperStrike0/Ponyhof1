#pragma once
#include <iostream>
#include "Position.h"

class Pony
{
public:
	Pony(Position pos);
	Pony();
	~Pony();
	std::string gibName();
	int gibGeburtsjahr();
	void setzePos(const Position& position);
	virtual bool istReitbar(int alter);
	virtual void zeigeInfo();
	virtual bool retSpec();
	virtual std::string retRasse();
	Position GetPos();


protected:
	int geburtsJahr;
	std::string name;
	Position ort;
};

