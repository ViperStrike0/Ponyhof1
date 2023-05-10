#pragma once
#include "Pony.h"

class Shetlandpony : public Pony
{
public:
	Shetlandpony(std::string name, int alter,bool kinderlieb);
	Shetlandpony();
	~Shetlandpony();
	bool istKinderlieb();
	bool istReitbar(int alter) override;
	void zeigeInfo() override;
	bool retSpec() override;
	std::string retRasse() override;

private:
	bool kinderlieb;
};

