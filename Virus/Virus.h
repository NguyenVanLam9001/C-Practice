#ifdef virus_h
#endif // virus_h
#define virus_h

#pragma once
#include<vector>
using namespace std;
class Virus
{
private:
	char *m_dna;
	int m_resistance;

public:
	Virus();
	~Virus();
	Virus(const Virus*);
	void LoadADNInformation();
	void ReduceResistance(int);
	virtual void DoBorn() = 0;
	virtual std::vector<Virus*> Doclone()=0;
	virtual void DoDie() = 0;
	virtual void Initresistance()=0;
	void setmDna(char*);
	char* getmDna();
	void setmResistance(int);
	int getmResistance();
};

