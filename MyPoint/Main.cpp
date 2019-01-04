#include"MyPoint.h"
#include<iostream>

using namespace std;

int main()
{
	MyPoint mp;
	MyPoint *x = new MyPoint(1,2);	
	x->Display();
	MyPoint *y = new MyPoint(2,1);	
	y->Display();
	cout << "distance:";
	cout << x->Distance(y) << endl;
	system("pause");
}