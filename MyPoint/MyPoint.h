#ifndef My_Point
#define My_Point
#pragma once

using namespace std;
class MyPoint
{
private:
	int mPosX;
	int mPosY;
public:
	MyPoint();
	~MyPoint();
	MyPoint(int X , int Y);
	void Display();
	void SetX(int);
	int GetX();
	void SetY(int);
	int GetY();
	float Distance(MyPoint *p);

};
#endif 

