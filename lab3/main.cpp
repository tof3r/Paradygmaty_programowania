#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct urojona
{
	float x1u,x2u,su,ru,ilu,iru;
};

struct liczba
{
	int *tab;
	float d,x1r,x2r,sr,rr,ilr,irr;
	struct urojona u;
};



void wczytaj_a(struct liczba* x)
{
printf("Wpisz zmienna a:\n");
scanf("%d", &x->tab[0]);
}


void wczytaj_b(struct liczba* x)
{
printf("Wpisz zmienna b:\n");
scanf("%d", &x->tab[1]);
}

void wczytaj_c(struct liczba* x)
{
printf("Wpisz zmienna c:\n");
scanf("%d", &x->tab[2]);
}

void oblicz_d(struct liczba* x)
{
x->d=x->tab[1]*x->tab[1]-4*x->tab[0]*x->tab[2];
}

int oblicz_pierwiastki(struct liczba* x)
{
	if((x->tab[0]==0) && (x->tab[1]!=0))
	{
	x->x1r=-(float)x->tab[2]/(float)x->tab[1];
	return 1;
	}

	if((x->tab[0]==0) && (x->tab[1]==0) && (x->tab[2]!=0))
	{
	return 2;
	}

	if((x->tab[0]==0) && (x->tab[1]==0) && (x->tab[2]==0))
	{
	return 3;
	}

if(x->tab[0]!=0)
	{
	oblicz_d(x);
		if(x->d >0)
			{
			x->x1r=((-x->tab[1])-sqrt(x->d))/(2*(float)x->tab[0]);
			x->x2r=((-x->tab[1])+sqrt(x->d))/(2*(float)x->tab[0]);
			x->irr=(x->x1r/x->x2r);
			return 4;
			}
		if(x->d == 0)
			{
			x->x1r=(float)(-x->tab[1])/(float)(2*x->tab[0]);
			return 5;
			}
		if(x->d < 0)
			{
			x->x1r=(float)(-x->tab[1])/(2*x->tab[0]);
			x->x2r=(float)(-x->tab[1])/(2*x->tab[0]);
			x->u.x1u=-sqrt(abs((float)x->d))/(2*(float)x->tab[0]);
			x->u.x2u=sqrt(abs((float)x->d))/(2*(float)x->tab[0]);
			/*x->irr = (x->x1r * x->x2r + x->u.x1u * x->u.x2u)/((x->x2r * x->x2r) + (x->u.x2u * x->u.x2u));
			x->u.iru = (x->x2r * x->u.x1u - x->x1r * x->u.x2u)/((x->x2r * x->x2r) + (x->u.x2u * x->u.x2u));*/

			return 6;
			}
	}

}

void dodaj(struct liczba* x)
{
	if (x->d > 0)
	{
		x->sr=(x->x1r)+(x->x2r);
	}
	if (x->d < 0)
	{
		x->sr=(x->x1r)+(x->x2r);
		x->u.su=(x->u.x1u)+(x->u.x2u);
	}
}
void odejmij(struct liczba* x)
{
	if (x->d > 0)
	{
		x->rr=(x->x1r)-(x->x2r);
	}
	if (x->d < 0)
	{
		x->rr=(x->x1r)-(x->x2r);
		x->u.ru=(x->u.x1u)-(x->u.x2u);
	}
}
void iloczyn(struct liczba* x)
{
	if (x->d>0)
	{
		x->ilr=(x->x1r)*(x->x2r);
	}
	if (x->d < 0)
	{
		x->ilr=(x->x1r)*(x->x2r);
		x->u.ilu=(x->u.x1u)*(x->u.x2u);
	}
}

void podziel(struct liczba* x)
{
	if(x->d > 0)
	{
		x->irr = x->x1r/x->x2r;
	}
	if(x->d < 0)
	{
		x->irr = (x->x1r * x->x2r + x->u.x1u * x->u.x2u)/((x->x2r * x->x2r) + (x->u.x2u * x->u.x2u));
		x->u.iru = (x->x2r * x->u.x1u - x->x1r * x->u.x2u)/((x->x2r * x->x2r) + (x->u.x2u * x->u.x2u));
	}
}

void wyswietl(struct liczba* x)
{
	int y = oblicz_pierwiastki(x);
	switch(y)
{
	case 1:
			printf("x1r = %0.4f\n", x->x1r);
			break;
	case 2:
			printf("Rownanie sprzeczne\n");
			break;
	case 3:
			printf("Rownanie nieoznaczone\n");
			break;
	case 4:
			printf("Delta %0.4f\n", x->d);
			printf("x1r: %0.4f, x2r: %0.4f\n", x->x1r,x->x2r);
			printf("sr = %0.4f\n", x->sr);
			printf("rr = %0.4f\n", x->rr);
			printf("ilr = %0.4f\n", x->ilr);
			printf("irr = %0.4f\n", x->irr);
			break;
	case 5:
			printf("Delta = %0.4f\n", x->d);
			printf("x1r: %0.4f\n", x->x1r);
			break;
	case 6:
			printf("Delta = %0.4f\n", x->d);
			printf("x1r = %0.4f\nx1u = %0.4fi\nx2r= %0.4f \nx2u = %0.4fi\n\n\n", x->x1r,x->u.x1u, x->x2r,x->u.x2u);
			printf("sr= %0.4f, su = %0.4f\n", x->sr,x->u.su);
			printf("rr = %0.4f, ru = %0.4f\n", x->rr,x->u.ru);
			printf("ilr = %0.4f, ilu = %0.4f\n", x->ilr,x->u.ilu);
			printf("irr = %0.4f, iru = %0.4f\n", x->irr,x->u.iru);
			break;


}
}



int main()
{	
struct liczba x;
int a,b,c;
float d;
float x1r,x2r,x1u,x2u,x1n,x2n;
float ilr,ilu,sr,su,rr,ru;

x.tab = (int*)malloc(3*sizeof(int));

while(1)
{

wczytaj_a(&x);
wczytaj_b(&x);
wczytaj_c(&x);
oblicz_d(&x);

printf("Twoje rownanie to %dx^2 + %dx + %d\n", x.tab[0],x.tab[1],x.tab[2]);

printf("Wyniki rownania:\n\n");

oblicz_pierwiastki(&x);

dodaj(&x);
odejmij(&x);
iloczyn(&x);
podziel(&x);

wyswietl(&x);
}

free(x.tab);
return 0;
}
