#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int a,b,c;
float d, x1r, x2r, x1u, x2u;

void main()
{
	while(1)
	{
		printf("\nPodaj zmienna a: ");
		scanf("%d",&a);
		printf("\nPodaj zmienna b: ");
		scanf("%d",&b);
		printf("\nPodaj zmienna c: ");
		scanf("%d",&c);

		printf("\nRownanie ma postac: %dxx + %dx + %d = 0",a,b,c);

		if(a == 0 && b!=0)
		{
			x1r = -(float)(c/b);
			printf("\nx1r = %f",x1r);
		}
		else if(a == 0 && b == 0 && c != 0)
		{
			printf("\nRownianie sprzeczne.\n");
		}
		else if(a == 0 && b == 0 && c == 0)
		{
			printf("\nRownianie nieoznaczone.\n");
		}
		else if(a != 0)
		{
			d = (float)((b*b)-(4*a*c));
			printf("\nd = %f",d);

			if(d >0)
			{
				x1r = (float)((-b) - sqrt(d))/(float)(2*a);
				x2r = (float)((-b) + sqrt(d))/(float)(2*a);
				printf("\nx1r = %f",x1r);
				printf("\nx2r = %f",x2r);
			}
			if(d == 0)
			{
				x1r = (float)(-b)/(float)(2*a);
				printf("\nx1r = %f",x1r);
			}
			if(d < 0)
			{
				x1r = (float)(-b)/(float)(2*a);
				x2r = x1r;
				x1u = (float)((-sqrt(abs(d))))/(float)(2*a);
				x2u = - x1u;
				printf("\n%f+%fi\n", x1r,x1u);
				printf("%f+%fi\n", x2r,x2u);
			}
		}

		printf("\n\n");
	}
}