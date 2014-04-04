#pragma once
#include "operacje.h"
#include <cmath>
#include <vector>


class operacje_good : virtual public operacje
{
protected:
	//int *tab;
	vector <int> tab;
	float d,x1r,x2r,sr,rr,ilr,irr,x1u,x2u,su,ru,ilu,iru;

public:
	operacje_good(void);
	operacje_good(int,int,int);
	~operacje_good(void);

	void dodaj();
	void odejmij();
	void iloczyn();
	void podziel();
	
	void wyswietl();
	void oblicz_d();
	int oblicz_pierwiastki();
};
