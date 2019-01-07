#include "Fluvirus.h"
#include<iostream>
#include"Virus.h"

enum color {
	RED = 1,
	BLUE = 2
};
Fluvirus::Fluvirus()
{
	this->DoBorn();
	this->Initresistance();

}


Fluvirus::~Fluvirus()
{
	this->m_color = 0;

}

Fluvirus::Fluvirus(const Fluvirus &flu)
{
	*this = flu;
}
void Fluvirus::DoBorn()
{
	fflush(stdin);
	this->LoadADNInformation();
	int r = rand() % 2 + 1;
	if (r == 1)
	{
		this->m_color = RED;
	}
	else
	{
		this->m_color = BLUE;
	}
}
vector <Virus *> Fluvirus::Doclone()
{
	vector<Virus *>list;
	Fluvirus *fluvirus = new Fluvirus(this);
	list.push_back(fluvirus);
	return list;
}

void Fluvirus::DoDie()
{
	this->~Fluvirus();
}
void Fluvirus::Initresistance()
{
	if (this->m_color == 1)
	{
		int i = rand() % 10 + 10;
		this->setmResistance(i);
	}
	if(this->m_color==2)
	{
		int i = rand() % 10 + 15;
		this->setmResistance(i);
	}
}
void Fluvirus::setmcolor(int color)
{
	this->m_color = color;
}

int Fluvirus::getmcolor()
{
	return this->m_color;
}
void Fluvirus::printdna()
{
	for (int i=1;i<48;i++)

	{
		cout << *(this->getmDna() + i);

	}
}