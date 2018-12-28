#include<iostream>
#include"GameTictac.h"
#include<string>
using namespace std;
void main()
{
	string p1;
	string p2;
	cout << "\n Welcome To Tic-tac-toe game! Play with your way!";	
	cout << "\n Insert player 1 (X)" << endl;
	cin >> p1;
	cout << "\n Insert player 2 (O)" << endl;
	cin >> p2;
	

	GameTicTac t;	
	while (!t.nguoithang) {
		t.dichuyen();
	}
	char nguoichoi = t.layngchoi();
	cout << endl;
	t.Hinh();
	cout << endl << endl << endl << "Nguoi choi ( " << nguoichoi << " ) chien thang" << endl;
	system("pause");
}