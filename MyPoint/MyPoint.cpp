#include "MyPoint.h"
#include<iostream>
#include<math.h>

MyPoint::MyPoint() 
{
	this->mPosX;
	this->mPosY;
}

MyPoint:: MyPoint(int X,int Y)
{
	this->mPosX = X;
	this->mPosY = Y;
}


MyPoint::~MyPoint()
{
}
void MyPoint::Display() 
{

	cout << "X: " << mPosX<<endl;
	cout << "Y:" << mPosY<<endl;
}
void MyPoint::SetX(int X)
{
	this->mPosX = X;
}
int MyPoint::GetX() { return mPosX; }
void MyPoint::SetY(int Y)
{
	this->mPosY = Y;
}
int MyPoint::GetY() { return mPosY; }

float MyPoint::Distance(MyPoint *p)
{
	return sqrt(pow(this->mPosX - p->mPosX, 2) + pow(this->mPosY - p->mPosY, 2));
}
