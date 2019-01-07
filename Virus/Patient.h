#pragma once
#include"Virus.h"
#include<vector>
using namespace std;
class Patient
{
private:
	int m_Resistance;
	vector<Virus*>m_Viruslist;
	int m_State;
public:
	Patient();
	~Patient();
	void DoStart();
	void TakeMedicine();
	int GetState();
	void DoDie();	
	void InitResistance();
	vector<Virus*> GetVirusList();
};

