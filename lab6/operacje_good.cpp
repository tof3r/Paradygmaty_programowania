#include "operacje_good.h"

operacje_good::operacje_good(void):d(0),x1r(0),x2r(0),sr(0),rr(0),ilr(0),irr(0),x1u(0),x2u(0),su(0),ru(0),ilu(0),iru(0)
{
	int a,b,c;
	int i = 0;
	vector<int>::iterator wektor_good;

	cout<<"Wprowadz a:"<<endl;
	cin>>a;
	cout<<"Wprowadz b:"<<endl;
	cin>>b;
	cout<<"Wprowadz c:"<<endl;
	cin>>c;

	tab.push_back(a);
	tab.push_back(b);
	tab.push_back(c);

	cout<<endl<<"Wartosci wprowadzone do wektora:"<<endl;
	for(wektor_good = tab.begin(); wektor_good != tab.end(); wektor_good++)
	{	
		cout<<"tab["<<i<<"] = "<<(*wektor_good);
		cout<<endl;
		i++;
	}
}

operacje_good::operacje_good(int a, int b, int c):d(0),x1r(0),x2r(0),sr(0),rr(0),ilr(0),irr(0),x1u(0),x2u(0),su(0),ru(0),ilu(0),iru(0)
{
	tab.push_back(a);
	tab.push_back(b);
	tab.push_back(c);
}

operacje_good::~operacje_good(void)
{
	cout<<"Destruktor good"<<endl;
}

void operacje_good::oblicz_d()
{
d=tab[1]*tab[1]-4*tab[0]*tab[2];
}

int operacje_good::oblicz_pierwiastki()
{
	if((tab[0]==0) && (tab[1]!=0))
	{
	x1r=-(float)tab[2]/(float)tab[1];
	return 1;
	}

	if((tab[0]==0) && (tab[1]==0) && (tab[2]!=0))
	{
	return 2;
	}

	if((tab[0]==0) && (tab[1]==0) && (tab[2]==0))
	{
	return 3;
	}

if(tab[0]!=0)
	{
	oblicz_d();
		if(d >0)
			{
			x1r=((-tab[1])-sqrt(d))/(2*(float)tab[0]);
			x2r=((-tab[1])+sqrt(d))/(2*(float)tab[0]);
			irr=(x1r/x2r);
			return 4;
			}
		if(d == 0)
			{
			x1r=(float)(-tab[1])/(float)(2*tab[0]);
			return 5;
			}
		if(d < 0)
			{
			x1r=(float)(-tab[1])/(2*tab[0]);
			x2r=(float)(-tab[1])/(2*tab[0]);
			x1u=-sqrt(abs((float)d))/(2*(float)tab[0]);
			x2u=sqrt(abs((float)d))/(2*(float)tab[0]);
			irr = (x1r * x2r + x1u * x2u)/((x2r * x2r) + (x2u * x2u));
			iru = (x2r * x1u - x1r * x2u)/((x2r * x2r) + (x2u * x2u));

			return 6;
			}
	}

}

void operacje_good::dodaj()
{
	if (d > 0)
	{
		sr=(x1r)+(x2r);
	}
	if (d < 0)
	{
		sr=(x1r)+(x2r);
		su=(x1u)+(x2u);
	}
}
void operacje_good::odejmij()
{
	if (d > 0)
	{
		rr=(x1r)-(x2r);
	}
	if (d < 0)
	{
		rr=(x1r)-(x2r);
		ru=(x1u)-(x2u);
	}
}
void operacje_good::iloczyn()
{
	if (d>0)
	{
		ilr=(x1r)*(x2r);
	}
	if (d < 0)
	{
		ilr=(x1r)*(x2r);
		ilu=(x1u)*(x2u);
	}
}

void operacje_good::podziel()
{
	if(d > 0)
	{
		irr = x1r/x2r;
	}
	if(d < 0)
	{
		irr = (x1r * x2r + x1u * x2u)/((x2r * x2r) + (x2u * x2u));
		iru = (x2r * x1u - x1r * x2u)/((x2r * x2r) + (x2u * x2u));
	}
}

void operacje_good::wyswietl()
{
	int y = operacje_good::oblicz_pierwiastki();
	switch(y)
	{
	case 1:
			cout<<"x1r = "<<x1r<<endl;
			break;
	case 2:
			cout<<"Rownanie sprzeczne"<<endl<<endl;
			break;
	case 3:
			cout<<"Rownanie nieoznaczone"<<endl<<endl;
			break;
	case 4:
			cout<<"Delta ="<<d<<endl;
			cout<<"x1r: "<<x1r<<" x2r: "<<x2r<<endl;
			cout<<"sr = "<<sr<<endl;
			cout<<"rr = "<<rr<<endl;
			cout<<"ilr = "<<ilr<<endl;
			cout<<"irr = "<<irr<<endl;
			break;
	case 5:
			cout<<"Delta = "<<d<<endl;
			cout<<"x1r: "<< x1r<<endl;
			break;
	case 6:
			cout<<"Delta = "<< d<<endl;
			cout<<"x1r = "<<x1r<<" x1u = "<<x1u<<"i\n"<<"x2r= "<<x2r<<"\nx2u = "<<x2u<<"i"<<endl<<endl;
			cout<<"sr= "<<sr<<", su = "<<su<<endl;
			cout<<"rr = "<<rr<<", ru = "<<ru<<endl;
			cout<<"ilr = "<<ilr<<", ilu = "<<ilu<<endl;
			cout<<"irr = "<<irr<<", iru = "<<iru<<endl<<endl;
			break;
	}
}