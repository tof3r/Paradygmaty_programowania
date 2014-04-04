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
	return x=1;
	}

    if((a==0) && (b==0) && (c!=0))
	{
	return x=2;
	}

    if((a==0) && (b==0) && (c==0))
	{
	return x=3;
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

void wyswietl(float d, float* x1r,float* x2r,float* x1u,float* x2u,float* sr,float* su,float* rr,float* ru,float* ilr,float* ilu,int x)
{
	switch(x)
{
	case 1:
			printf("x1r = %0.4f\n", *x1r);
			break;
	case 2:
			printf("Rownanie sprzeczne.\n");
			break;
	case 3:
			printf("Rownanie nieoznaczone.\n");
			break;
	case 4:
			printf("d =  %0.4f\n\n", d);
			printf("x1r: %0.4f\n",*x1r);
            printf("x2r: %0.4f\n\n",*x2r);
			printf("sr = %0.4f\n\n", *sr);
			printf("rr = %0.4f\n\n", *rr);
			printf("ilr = %0.4f\n\n", *ilr);
			break;
	case 5:
			printf("d = %0.4f\n", d);
			printf("x1r: %0.4f\n", *x1r);
			break;
	case 6:
			printf("d = %0.4f\n\n", d);
			printf("x1r = %0.4f\n", *x1r);
            printf("x2r= %0.4f\n\n",*x2r);
            printf("x1u = %0.4fi\n", *x1u);
            printf("x2u = %0.4fi\n\n",*x2u);
			printf("sr= %0.4f\n",*sr);
            printf("su = %0.4f\n\n",*su);
			printf("rr = %0.4f\n",*rr);
            printf("ru = %0.4f\n\n",*ru);
			printf("ilr = %0.4f\n",*ilr); 
            printf("ilu = %0.4f\n",*ilu);
			break;


}
}



int main()
{	

int x;
float d;
int a,b,c;
float x1r,x2r,x1u,x2u;
float ilr,ilu,sr,su,rr,ru;

while(1)
{
printf("\n\n");
a=wczytaj_a();
b=wczytaj_b();
c=wczytaj_c();
d=oblicz_d(a,b,c);

printf("\nTwoje rownanie to %dxx + %dx + %d\n", a,b,c);

printf("\nWyniki:\n\n");

x=oblicz_pierwiastki(a,b,c,&x1r,&x2r,&x1u,&x2u);

dodaj(&x1r,&x2r, &x1u,&x2u,&sr,&su);
odejmij(&x1r,&x2r, &x1u,&x2u,&rr,&ru);
iloczyn(&x1r,&x2r, &x1u,&x2u,&ilr,&ilu);

wyswietl(d,&x1r,&x2r,&x1u,&x2u,&sr,&su,&rr,&ru,&ilr,&ilu,x);




}
return 0;
}
