
#include"Virus.h"
#include"FluVirut.h"
#include"DengueVirus.h"
#include<iostream>
#include<fstream>
int main()
{
	DengueVirus *d = new DengueVirus();
	d->LoadADNInformation();
	system("pause");
	return 0;
}