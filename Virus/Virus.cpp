#include "Virus.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;
Virus::Virus()
{
	this->m_dna = new char;
}


Virus::~Virus()
{
}
Virus::Virus(const Virus* virus)
{
	delete this->m_dna;
	this->m_resistance = 0;
}

void Virus::LoadADNInformation()
{
	string line;
	
	ifstream file;
	file.open("ATXG.bin");
	
	if (file.fail())
	{
		cout << "fail !";
	}
	else
	{
		file >> line;
	}
	this->m_dna = const_cast<char*>(line.c_str());
	cout << this->m_dna << endl;
}
void Virus::ReduceResistance(int rs)
{
	this->m_resistance = this->m_resistance - rs;
	if (this->m_resistance <= 0)
	{
		this->DoDie();
	}
}
void Virus::setmDna(char *m_Dna)
{
	this->m_dna = m_Dna;
}
void Virus::setmResistance(int m_resistance)
{
	this->m_resistance = m_resistance;
}
char * Virus::getmDna()
{
	return this->m_dna;
}
int Virus::getmResistance()
{
	return this->m_resistance;
}