#include <iostream>
#include "operacje_bad.h"
#include "operacje_good.h"
#include <conio.h>
using namespace std;

void main()
{
	char wybor;
	
	do
	{	
	cout<<"\nPolimorfizm"<<endl<<endl;

	cout<<"Bezparametrowy good"<<endl<<endl;
	operacje_good bezparametrowy_good;
	operacje_good* opGood= &bezparametrowy_good;
	opGood->oblicz_d();
	opGood->oblicz_pierwiastki();
	opGood->dodaj();
	opGood->odejmij();
	opGood->iloczyn();
	opGood->podziel();
	cout<<endl;
	opGood->wyswietl();

	cout<<"\nParametrowy good"<<endl<<endl;
	operacje_good parametrowy_good(1,1,0);
	opGood = &parametrowy_good;
	opGood->oblicz_d();
	opGood->oblicz_pierwiastki();
	opGood->dodaj();
	opGood->odejmij();
	opGood->iloczyn();
	opGood->podziel();
	cout<<endl;
	opGood->wyswietl();

	cout<<"\nBezparametrowy bad"<<endl<<endl;
	operacje_bad bezparametrowy_bad;
	operacje_bad* opBad = &bezparametrowy_bad;
	opBad->oblicz_d();
	opBad->dodaj();
	opBad->odejmij();
	opBad->iloczyn();
	opBad->podziel();
	cout<<endl;
	opBad->wyswietl();

	cout<<"\nParametrowy bad"<<endl<<endl;
	operacje_bad parametrowy_bad(0,0,0);
	opBad = &parametrowy_bad;
	opBad->oblicz_d();
	opBad->dodaj();
	opBad->odejmij();
	opBad->iloczyn();
	opBad->podziel();
	cout<<endl;
	opBad->wyswietl();

	cout<<"Czy liczyc dalej? Wcisnij dowolny klawisz. (k konczy obliczenia)";
	wybor = getch();
	cout<<endl<<"Twoj wybor: "<<wybor<<endl;
	cout<<endl;
	}while(wybor != 'k');

	cout<<endl;
	system("pause");
}