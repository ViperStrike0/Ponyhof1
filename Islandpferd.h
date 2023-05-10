#pragma once
#include "Pony.h"
#include <iostream>

class Islandpferd : public Pony
{
public:
	Islandpferd(std::string name, int alter, bool ekzemer);
	Islandpferd();
	~Islandpferd();
	bool hatEkzem();
	bool istReitbar(int atler) override;
	void zeigeInfo() override;
	bool retSpec() override;
	std::string retRasse() override;

private:
	bool ekzemer;
};

