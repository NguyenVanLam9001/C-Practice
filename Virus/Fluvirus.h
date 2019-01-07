#pragma once
#include"Virus.h"
#include<vector>
using namespace std;
class Fluvirus:public Virus
{
private:
	int m_color;
public:
	Fluvirus();
	~Fluvirus();
	Fluvirus(const Fluvirus*);
	void DoBorn() override;
	std::vector<Virus *> Doclone() override;
	void DoDie() override;
	void setmcolor(int);
	void Initresistance() override;
	int getmcolor();
	void printdna();
};

