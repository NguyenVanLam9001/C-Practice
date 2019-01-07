#pragma once
#include<vector>
#include<string>
#include"Virus.h"
using namespace std;
class DengueVirus:public Virus
{
private:
	string m_protein;
public:
	DengueVirus();
	~DengueVirus();
	DengueVirus(const DengueVirus*);
	void DoBorn() override;
	std::vector<Virus*>Doclone() override;
	void DoDie() override;
	void Initresistance() override;
	void setmprotein(string);
	string getmprotein();
};

