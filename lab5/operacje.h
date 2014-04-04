#pragma once
#include <iostream>
using namespace std;

class operacje
{
public:
	operacje(void);
	~operacje(void);

	virtual void dodaj() = 0;
	virtual void odejmij() = 0;
	virtual void iloczyn() = 0;
	virtual void podziel() = 0;
};
