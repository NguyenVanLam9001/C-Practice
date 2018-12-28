#pragma once

class GameTicTac
{
private:
	char nguoichoi;
	char luoi[3][3];
	int sodichuyen;

public:
	GameTicTac();
	~GameTicTac();
	void Hinh();
	void dichuyen();
	void capnhathinh( int a);
	char layngchoi();
	void doiluotchoi();
	char ktdichuuyen(int );
	bool ktwin();
	bool nguoithang;
	bool kthoa();
	bool hoanhau;
};

