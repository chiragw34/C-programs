#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
void main()
{
	int gd=DETECT,gm;
	int x[4],y[4],px,py,i,n;
	double t;
	initgraph(&gd,&gm,"C:/TURBOC3/BGI");
	printf("Enter the no of control points:");
	scanf("%d",&n);
	printf("Enter the control points of bezier curve: ");
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		putpixel(x[i],y[i],GREEN);
	}
	for(t=0.0;t<=1.0;t+=0.001)
	{
		px=(1-t)*(1-t)*(1-t)*x[0]+3*t*(1-t)*(1-t)*x[1]+3*t*t*(1-t)*x[2]+t*t*t*x[3];
		py=(1-t)*(1-t)*(1-t)*y[0]+3*t*(1-t)*(1-t)*y[1]+3*t*t*(1-t)*y[2]+t*t*t*y[3];
		putpixel(px,py,WHITE);
		delay(2);
	}
	getch();
	closegraph();

}
