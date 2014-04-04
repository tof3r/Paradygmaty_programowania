#include "operacje_bad.h"

operacje_bad::operacje_bad(void):d(0),x1r(0),x2r(0),sr(0),rr(0),ilr(0),irr(0),x1u(0),x2u(0),su(0),ru(0),ilu(0),iru(0)
{
	int a,b,c;
	tab = new int[3];
	
		cout<<"Wprowadz a:"<<endl;
		cin>>a;
		cout<<"Wprowadz b:"<<endl;
		cin>>b;
		cout<<"Wprowadz c:"<<endl;
		cin>>c;

	tab[0] = a;
	tab[1] = b;
	tab[2] = c;
}

operacje_bad::operacje_bad(int a, int b, int c):d(0),x1r(0),x2r(0),sr(0),rr(0),ilr(0),irr(0),x1u(0),x2u(0),su(0),ru(0),ilu(0),iru(0)
{
tab = new int[3];
tab[0] = a;
tab[1] = b;
tab[2] = c;
}

operacje_bad::~operacje_bad(void)
{
	cout<<"Destruktor bad"<<endl;
	delete [] tab;
}

void operacje_bad::oblicz_d()
{
d=tab[1]*tab[1]-4*tab[0]*tab[2];
}

void operacje_bad::dodaj()
{
	if (d > 0)
	{
		sr=(x1r)+(x2r);
	}
	if (d < 0)
	{
		sr=(x1r)+(x1u);
		su=(x2r)+(x2u);
	}
}
void operacje_bad::odejmij()
{
	if (d > 0)
	{
		rr=(x1r)-(x2r);
	}
	if (d < 0)
	{
		rr=(x1r)-(x1u);
		ru=(x2r)-(x2u);
	}
}
void operacje_bad::iloczyn()
{
	if (d>0)
	{
		ilr=(x1r)*(x2r);
	}
	if (d < 0)
	{
		ilr=(x1r)*(x1u);
		ilu=(x2r)*(x2u);
	}
}

void operacje_bad::podziel()
{
	if(d > 0)
	{
		irr = x1r/x2r;
	}
	if(d < 0)
	{
		irr=(x1r)/(x1u);
		iru=(x2r)/(x2u);
	}
}

void operacje_bad::wyswietl()
{
			cout<<"Delta = "<< d<<endl;
			cout<<"sr= "<<sr<<", su = "<<su<<endl;
			cout<<"rr = "<<rr<<", ru = "<<ru<<endl;
			cout<<"ilr = "<<ilr<<", ilu = "<<ilu<<endl;
			cout<<"irr = "<<irr<<", iru = "<<iru<<endl<<endl;
}