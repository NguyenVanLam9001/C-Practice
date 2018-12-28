#include "GameTicTac.h"
#include<iostream>


using namespace std;


GameTicTac::GameTicTac()
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			luoi[i][j] = 'A';
		}
	}
	nguoichoi = 'O';
	nguoithang = false;
	hoanhau = false;

}


GameTicTac::~GameTicTac()
{

}
void GameTicTac::Hinh()
{
	char c;
	int b = 0;
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "\t";
		for (int j = 0; j < 3; j++)
		{
			b++;
			c = (luoi[i][j] == 'A') ? ('0' + b) : luoi[i][j];
			cout << c;
			if (j != 2) 
			{
				cout << " | ";
			}
		}
		if (i != 2) {
			cout << endl;
			cout << "\t" << "--|-- |--" << endl;
		}


	}
}
char GameTicTac::layngchoi()
{
	return nguoichoi;
}
void GameTicTac::dichuyen() {
	int dchuyen;
	Hinh();
	doiluotchoi();
	cout << endl;
	cout << "\n\n\n Nguoi choi hien tai: " << nguoichoi<< endl;
	cout << " Chon vi tri: ";
	cin >> dchuyen;
	char kt = ktdichuuyen(dchuyen);
	while (kt!='Y')
	{
		cout << "\nKhong ton tai vi tri da chon";
		cout << "Chon vi tri khac";
		cin >> dchuyen;
		kt = ktdichuuyen(dchuyen);
	}
	capnhathinh(dchuyen);
	nguoithang = ktwin();
	if (!nguoithang) 
	{
		if (kthoa()) {
			hoanhau = true;
			cout << "Hoa nhau" << endl;
			return;
		}
	}
	}
void GameTicTac::capnhathinh(int t) {
	luoi[(t - 1) / 3][(t - 1) % 3] = nguoichoi;
}
void GameTicTac::doiluotchoi()
{
	if (nguoichoi == 'O')
	{
		nguoichoi = 'X';
	}
	else
	{
		nguoichoi ='O';
	}
}
char GameTicTac::ktdichuuyen(int k) {
	char x = luoi[(k - 1) / 3][(k - 1) % 3];
	if (k>0 && k<10 && x=='A')
	{
		return 'Y';
	}
	else
	{
		return 'N';
	}
}
bool GameTicTac::ktwin()
{
	int r1;
	int r2;
	//kiem tra dong
	for (int i = 0; i < 3; i++)
	{
		r1 = 0;
		for (int j = 0; j < 3; j++) 
		{
			if (luoi[i][j] == nguoichoi)
				r1++;
		}
		if (r1 == 3) 
		{
			return true;
		}
	}
	//kiem tra cot 
	for (int i = 0; i < 3; i++) 
	{
		r1 = 0;
		for (int j = 0; j < 3; j++) 
		{
			if (luoi[i][j] == nguoichoi)
				r1++;
		}
		if(r1==3)
		{
			return true;
		}
	}

	//kiem tra duong cheo
	int y = 0;
	int c = 2;
	r1 = 0;
	r2 = 0;
	for (int i = 0; i < 3; i++, y++,c--) {
		if (luoi[i][y] == nguoichoi) r1++;
		if (luoi[i][c] == nguoichoi) r2++;
		if (r1 == 3 || r2 == 3) return true;
	}
	return false;
}

bool GameTicTac::kthoa() {
	int cout = 0;
	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j<3; j++)
		{
			if (luoi[i][j] == 'X' || luoi[i][j] == 'O')
				cout++;			
		}
	}

	return (cout == 9);

}