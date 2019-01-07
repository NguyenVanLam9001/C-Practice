#include "DengueVirus.h"
#include<iostream>
#include<vector>
#include<string>




DengueVirus::DengueVirus()
{
	this->DoBorn();
	this->Initresistance();

}


DengueVirus::~DengueVirus()
{
}

DengueVirus::DengueVirus(const DengueVirus * dVirus)
{
	*this = *dVirus;
}
void DengueVirus::DoBorn()
{
	this->LoadADNInformation();
	int r = rand() % 3 + 1;
	if (r == 1)
	{
		this->m_protein = "NS3";
	}
	if (r == 2)
	{
		this->m_protein = "NS5";
	}
	else
	{
		this->m_protein = "E";
	}
}
std::vector<Virus*> DengueVirus::Doclone()
{
	vector<Virus*> list;
	DengueVirus *dvirus1 = new DengueVirus(this);
	list.push_back(dvirus1);
	DengueVirus *dvirus2 = new DengueVirus(this);
	list.push_back(dvirus2);
	return	list;
}
void DengueVirus::DoDie()
{
	this->m_protein = "";
 }

void DengueVirus::Initresistance()
{
	if (this->m_protein == "NS3")
	{
		int i = rand() % 10 + 1;
		this->setmResistance(i);
	}
	if(this->m_protein== "NS5")
	{
		int i = rand() % 10 + 11;
		this->setmResistance(i);
	}
	else
	{
		int i = rand() % 10 + 21;
		this->setmResistance(i);

	}
}
void DengueVirus::setmprotein(string mprotein)
{
	this->m_protein = mprotein;
}
string DengueVirus::getmprotein()
{
	return this->m_protein;
}