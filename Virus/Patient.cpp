#include "Patient.h"
#include"Fluvirus.h"
#include"DengueVirus.h"
#include"Virus.h"
#include<iostream>
#include<vector>


Patient::Patient()
{
	this->InitResistance();
	this->DoStart();
}


Patient::~Patient()
{

}

void Patient::DoStart()
{
	this->m_State = 1;
	int rvirus = rand() % 11 + 10;
	for (int i = 0; i <= rvirus; i++)
	{
		int rd = rand() % 2 + 1;
		if (rd == 1)
		{
			Fluvirus *viruss = new Fluvirus();
			this->m_Viruslist.push_back(viruss);
		}
		if (rd == 2)
		{
			DengueVirus *dengueVirus = new DengueVirus();
			this->m_Viruslist.push_back(dengueVirus);
		}
	}
}
void Patient::TakeMedicine()
{

}
void Patient::DoDie()
{
	this->m_State = 0;
	cout << "patien die" << endl;
}
void Patient::InitResistance()
{
	int r = rand() % 8001 + 1000;
	this->m_Resistance = r;
}