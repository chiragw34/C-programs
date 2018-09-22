#include<stdio.h>
//#include<conio.h>
//#include<graphics.h>
#include<math.h>
#include<stdlib.h>
void main()
{
	int x[100],y[100],nx[100],ny[100];
	int i,j=0,k;
//	int gd=DETECT,gm;


	while(j!=5)
	       {

			for (i=0;i<10;i++)
				{
					printf("%d. x=%d   y=%d  r=%d\n",i+1,80+i,120,10);
				}

                printf("\n");
				for (i=0;i<10;i++)
				{
				    printf("%d. x=%d   y=%d  r=%d\n",i+1,90-i,120,10);
				}

			j++;
			printf("j=%d\n",j);
	       }
	getch();

}
