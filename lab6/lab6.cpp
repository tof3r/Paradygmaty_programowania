#include <iostream>
#include "operacje_bad.h"
#include "operacje_good.h"
#include <conio.h>
#include <list>
using namespace std;

int main()
{

	char wybor;

	list<operacje_good> dane_good;
	list<operacje_good>::iterator dane_good_iter;

	list<operacje_bad> dane_bad;
	list<operacje_bad>::iterator dane_bad_iter;

	do
	{

	cout<<endl<<"Wprowadzanie danych"<<endl;

	cout<<"\nBezarametrowy good"<<endl<<endl;
	operacje_good bezparametrowy_good;
	cout<<"\nParametrowy good"<<endl;
	operacje_good parametrowy_good(4,4,1);
	cout<<"utworzono"<<endl;
	cout<<"\nBezparametrowy bad"<<endl<<endl;
	operacje_bad bezparametrowy_bad;
	cout<<"\nParametrowy bad"<<endl;
	operacje_bad parametrowy_bad(3,3,3);
	cout<<"utworzono"<<endl;

	//obiekty laduja na liscie
	dane_good.push_back(bezparametrowy_good);
	dane_good.push_back(parametrowy_good);

	dane_bad.push_back(bezparametrowy_bad);
	dane_bad.push_back(parametrowy_bad);

	
	cout<<endl<<"Lista obiektow klasy operacje_good"<<endl;
	
	for(dane_good_iter = dane_good.begin(); dane_good_iter != dane_good.end(); dane_good_iter++)
	{
		dane_good_iter->oblicz_d();
		dane_good_iter->oblicz_pierwiastki();
		dane_good_iter->dodaj();
		dane_good_iter->odejmij();
		dane_good_iter->iloczyn();
		dane_good_iter->podziel();
		cout<<endl;
		dane_good_iter->wyswietl();
	}

	cout<<endl<<"Lista obiektow klasy operacje_bad"<<endl;
	
	for(dane_bad_iter = dane_bad.begin(); dane_bad_iter != dane_bad.end(); dane_bad_iter++)
	{
		dane_bad_iter->oblicz_d();
		dane_bad_iter->dodaj();
		dane_bad_iter->odejmij();
		dane_bad_iter->iloczyn();
		dane_bad_iter->podziel();
		cout<<endl;
		dane_bad_iter->wyswietl();
	}

	//czyszczenie list
	cout<<"Czyszczenie list"<<endl;
	dane_good.clear();
	dane_bad.clear();

	cout<<endl<<"Czy liczyc dalej? Wcisnij dowolny klawisz. (k konczy obliczenia)";
	wybor = getch();
	cout<<endl<<"Twoj wybor: "<<wybor<<endl;
	cout<<endl;
	}while(wybor != 'k');

	cout<<endl;
	system("pause");
	return 0;
}