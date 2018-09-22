#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>

int x[4],y[4],nx[4],ny[4];

void draw_rect(int a[],int b[])
{
	int i;
	for(i=0;i<4;i++)
		{
		if(i==3)
			line(a[i],b[i],a[0],b[0]);
		else
			line(a[i],b[i],a[i+1],b[i+1]);
		}
}

void rotation(double th)
{
	int i,gd=DETECT,gm;
	double t;
	initgraph(&gd,&gm,"C://TURBOC3//BGI");
	draw_rect(x,y);
	t=(3.14*th)/180;
	for(i=0;i<4;i++)
	{
		nx[i]=abs((x[i]*cos(t))-(y[i]*sin(t)));
		ny[i]=abs((x[i]*sin(t))+(y[i]*cos(t)));
	}
	draw_rect(nx,ny);
	getch();
	clrscr();
	closegraph();
}

void translation(int tx,int ty)
{
	int i,gd=DETECT,gm;
	initgraph(&gd,&gm,"C://TURBOC3//BGI");
	for (i=0;i<4;i++)
	{
		nx[i]=x[i]+tx;
		ny[i]=y[i]+ty;
	}
	draw_rect(x,y);
	draw_rect(nx,ny);
	getch();
	closegraph();
}

void reflextion()
{
	int i,gd=DETECT,gm;
	initgraph(&gd,&gm,"C://TURBOC3//BGI");
	draw_rect(x,y);
	line(320,0,320,480);
	line(0,240,640,240);
	for (i=0;i<4;i++)
	{
		nx[i]=640-x[i];
		ny[i]=480-y[i];
	}
	draw_rect(x,ny);
	draw_rect(nx,ny);
	getch();
	closegraph();
}

void scaling(int sx,int sy)
{
	int i,gd=DETECT,gm;
	initgraph(&gd,&gm,"C://TURBOC3//BGI");
	for (i=0;i<4;i++)
	{
		nx[i]=x[i]*sx;
		ny[i]=y[i]*sy;
	}
	draw_rect(x,y);
	draw_rect(nx,ny);
	getch();
	closegraph();
}

void shear()
{
	int i,ch;
	float fx,fy;
	int gd=DETECT,gm;
	printf("enter shearing factors:");
	scanf("%f %f",&fx,&fy);
	printf("shear along 1.x 2.y\n");
	printf("enter the choice:-");
	scanf("%d",&ch);
	initgraph(&gd,&gm,"C://TURBOC3//BGI");
	draw_rect(x,y);
	for(i=0;i<4;i++)
	{
		if (ch==1)
		{
			if(i==2 || i==3)
				nx[i]=x[i]+(fx*y[i]);
			else
				nx[i]=x[i];
			ny[i]=y[i];
		}
		if(ch==2)
		{
			if(i==1 || i==2)
				ny[i]=y[i]+(fy*x[i]);
			else
				ny[i]=y[i];
			nx[i]=x[i];
		}
	}
	draw_rect(nx,ny);
	getch();
	closegraph();
}

int main()
{
	int i,ch,fx,fy;
	double t,th;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C://TURBOC3//BGI");
	
	printf("enter the co ordinates of rectangle:-");
	for(i=0;i<4;i++)
		scanf("%d %d",&x[i],&y[i]);
	
	for(i=0;i<4;i++)
		printf("%d %d\n",x[i],y[i]);
	while(ch!=6)
	{
		printf("\n1. Rotation\t2.
		Translation\t3. Reflection\n4. Shearing\t5.
		Scaling\t6. Exit");
		printf("\nenter your choice:-");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1: printf("enter the angle of rotation:-");
				scanf("%lf",&th);
				rotation(th);
				break;
		case 2: printf("enter translation factors:-");
				scanf("%d %d",&fx,&fy);
				translation(fx,fy);
				break;
		case 3: reflextion();
				break;
				case 4: shear();
				break;
		case 5: printf("enter scaling factors:-");
				scanf("%d %d",&fx,&fy);
				scaling(fx,fy);
				break;
		case 6:	break;
		}
		clrscr();
	}
	getch();
	closegraph();
	return 0;
}

