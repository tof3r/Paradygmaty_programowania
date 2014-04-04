#pragma once
#include "operacje.h"
#include <vector>

class operacje_bad :virtual public operacje
{
protected:
	//int *tab;
	vector <int> tab;
	float d,x1r,x2r,sr,rr,ilr,irr,x1u,x2u,su,ru,ilu,iru;

public:
	operacje_bad(void);
	operacje_bad(int,int,int);
	~operacje_bad(void);

	void dodaj();
	void odejmij();
	void iloczyn();
	void podziel();

	void wyswietl();
	void oblicz_d();
};
