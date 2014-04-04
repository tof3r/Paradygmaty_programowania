
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int wczytaj_a()
{
int a;
printf("Wpisz zmienna a:\n");
scanf("%d", &a);
return a;
}


int wczytaj_b()
{
int b;
printf("Wpisz zmienna b:\n");
scanf("%d", &b);
return b;
}

int wczytaj_c()
{
int c;
printf("Wpisz zmienna c:\n");
scanf("%d", &c);
return c;
}

float oblicz_d(int a, int b, int c)
{
float d;
d=b*b-4*a*c;
return d;
}

int oblicz_pierwiastki(int a, int b, int c, float* x1r,float* x2r, float* x1u, float* x2u)
{
int x;
if((a==0) && (b!=0))
	{
	*x1r=-(float)c/(float)b;
	return 1;
	}

if((a==0) && (b==0) && (c!=0))
	{
	return 2;
	}

if((a==0) && (b==0) && (c==0))
	{
	return 3;
	}

if(a!=0)
	{
	float d=oblicz_d(a,b,c);
		if(d>0)
			{
			*x1r=((-b)-sqrt(d))/(2*(float)a);
			*x2r=((-b)+sqrt(d))/(2*(float)a);
			return x=4;
			}
		if(d==0)
			{
			*x1r=(float)(-b)/(float)(2*a);
			return x=5;
			}
		if(d<0)
			{
			*x1r=(float)(-b)/(2*a);
			*x2r=(float)(-b)/(2*a);
			*x1u=-sqrt(abs((float)d))/(2*(float)a);
			*x2u=sqrt(abs((float)d))/(2*(float)a);
			return x=6;
			}
	}

}

void dodaj(float* x1r,float* x2r, float* x1u,float* x2u,float* sr,float* su)
{
*sr=(*x1r)+(*x2r);
*su=(*x1u)+(*x2u);
}
void odejmij(float* x1r,float* x2r, float* x1u,float* x2u,float* rr,float* ru)
{
*rr=(*x1r)-(*x2r);
*ru=(*x1u)-(*x2u);
}
void iloczyn(float* x1r,float* x2r, float* x1u,float* x2u,float* ilr,float* ilu)
{
*ilr=(*x1r)*(*x2r);
*ilu=(*x1u)*(*x2u);
}

void wyswietl(float d, float* x1r,float* x2r,float* x1u,float* x2u, float* x1n,float* x2n,float* ilr,float* ilu,float* sr,float* su,float* rr,float* ru,int x)
{
	switch(x)
{
	case 1:
			printf("x1r = %0.4f\n", *x1r);
			break;
	case 2:
			printf("Rownanie sprzeczne\n");
			break;
	case 3:
			printf("Rownanie nieoznaczone\n");
			break;
	case 4:
			printf("Delta %0.4f\n", d);
			printf("x1r: %0.4f, x2r: %0.4f\n", *x1r,*x2r);
			printf("sr = %0.4f\n", *sr);
			printf("rr = %0.4f\n", *rr);
			printf("ilr = %0.4f\n", *ilr);
			break;
	case 5:
			printf("Delta = %0.4f\n", d);
			printf("x1r: %0.4f\n", *x1r);
			break;
	case 6:
			printf("Delta = %0.4f\n", d);
			printf("x1r = %0.4f x1u = %0.4fi, x2r= %0.4f x2u = %0.4fi\n\n\n", *x1r,*x1u, *x2r,*x2u);
			printf("sr= %0.4f, su = %0.4f\n", *sr,*su);
			printf("rr = %0.4f, ru = %0.4f\n", *rr,*ru);
			printf("ilr = %0.4f, ilu = %0.4f\n", *ilr,*ilu);
			break;


}
}



int main()
{	
int k=0;


int a,b,c;
int x;
float d;
float x1r,x2r,x1u,x2u,x1n,x2n;
float ilr,ilu,sr,su,rr,ru;
while(1)
{

a=wczytaj_a();
b=wczytaj_b();
c=wczytaj_c();
d=oblicz_d(a,b,c);

printf("Twoje rownanie to %dx^2 + %dx + %d\n", a,b,c);

printf("Wyniki rownania:\n");

x=oblicz_pierwiastki(a,b,c,&x1r,&x2r,&x1u,&x2u);

dodaj(&x1r,&x2r, &x1u,&x2u,&sr,&su);
odejmij(&x1r,&x2r, &x1u,&x2u,&rr,&ru);
iloczyn(&x1r,&x2r, &x1u,&x2u,&ilr,&ilu);

wyswietl(d,&x1r,&x2r,&x1u,&x2u, &x1n,&x2n,&ilr,&ilu,&sr,&su,&rr,&ru,x);




}
return 0;
}
