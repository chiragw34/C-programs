#include<stdio.h>
#include<math.h>
#include<stdlib.h>
//#include<complex.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

int i,xs[5],ys[5];
int tempx,tempy;
float shearxfact,shearyfact;

void Draw()
{
	for (i=0;i<4;i++)
	line(xs[i],ys[i],xs[(i+1)%4],ys[(i+1)%4]);
}
void shearx()
{
	for (i=0;i<4;i++)
	xs[i]=xs[i]+shearxfact*ys[i];
}
void sheary()
{
	for (i=0;i<4;i++)
	ys[i]=ys[i]+shearyfact*ys[i];
}
void fliph()
{
       //	tempy=getmaxx()/2;
	for (i=0;i<4;i++)
	xs[i]=tempy+(tempy-xs[i]);    //vertical axis to flip about
//	for (i=0;i<getmaxxy();i++)
	putpixel(tempy,i,WHITE);
}
void flipv()
{
       //	tempx=getmaxy()/2;
	for (i=0;i<4;i++)
	ys[i]=tempx+(tempx-ys[i]);       //horizontal axis to flip about
 //	for (i=0;i<getmaxx();i++)
	putpixel(i,tempx,WHITE);
}

void main()
{
	int gd=DETECT,gm,n,opt,r;
	int tx,ty,x1,x2,x3,x4,y1,y2,y3,y4,nx1,nx2,nx3,nx4,ny1,ny2,ny3,ny4;
	float sx,sy;
	float t;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	printf("enter the co_ordinates of rectangle");
	scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x4,y4);
	line(x4,y4,x1,y1);

	printf("1.translation\n2.scaling\n3.rotation\n4.shear\n5.reflection\n6.exit");
	printf("\nenter your option");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:printf("enter the Translation factors");
		       scanf("%d%d",&tx,&ty);
		       nx1=x1+tx;
		       nx2=x2+tx;
		       nx3=x3+tx;
		       nx4=x4+tx;
		       ny1=y1+ty;
		       ny2=y2+ty;
		       ny3=y3+ty;
		       ny4=y4+ty;
		       setcolor(CYAN);
		       line(nx1,ny1,nx2,ny2);
		       line(nx2,ny2,nx3,ny3);
		       line(nx3,ny3,nx4,ny4);
		       line(nx4,ny4,nx1,ny1);
		       break;
		case 2:printf("enter the Scaling factors");
		       scanf("%f%f",&sx,&sy);
		       nx1=x1*sx;
		       nx2=x2*sx;
		       nx3=x3*sx;
		       nx4=x4*sx;
		       ny1=y1*sy;
		       ny2=y2*sy;
		       ny3=y3*sy;
		       ny4=y4*sy;
		       setcolor(CYAN);
		       line(nx1,ny1,nx2,ny2);
		       line(nx2,ny2,nx3,ny3);
		       line(nx3,ny3,nx4,ny4);
		       line(nx4,ny4,nx1,ny1);
		       break;
		case 3:printf("enter the angle of rotation");
		       scanf("%d",&r);
		       t=3.14*r/180;
		       nx1=abs(x1*cos(t)-y1*sin(t));
		       nx2=abs(x2*cos(t)-y2*sin(t));
		       nx3=abs(x3*cos(t)-y3*sin(t));
		       nx4=abs(x4*cos(t)-y4*sin(t));
		       ny1=abs(x1*sin(t)+y1*cos(t));
		       ny2=abs(x2*sin(t)+y2*cos(t));
		       ny3=abs(x3*sin(t)+y3*cos(t));
		       ny4=abs(x4*sin(t)+y4*cos(t));
		       setcolor(CYAN);
		       line(nx1,ny1,nx2,ny2);
		       line(nx2,ny2,nx3,ny3);
		       line(nx3,ny3,nx4,ny4);
		       line(nx4,ny4,nx1,ny1);
		       break;
		case 4:printf("Enter x shear factor");
		       scanf("%f",&shearxfact);
		       printf("Enter y shear factor");
		       scanf("%f",&shearyfact);
		       printf("after shearing");
		       xs[0]=x1;
		       xs[1]=x2;
		       xs[2]=x3;
		       xs[3]=x4;
		       ys[0]=y1;
		       ys[1]=y2;
		       ys[2]=y3;
		       ys[3]=y4;
		       shearx();
		       setcolor(CYAN);
		       Draw();
		       sheary();
		       setcolor(RED);
		       Draw();
		       break;
		case 5:xs[0]=x1;
		       xs[1]=x2;
		       xs[2]=x3;
		       xs[3]=x4;
		       ys[0]=y1;
		       ys[1]=y2;
		       ys[2]=y3;
		       ys[3]=y4;
			setcolor(CYAN);
			flipv();
			Draw();
			setcolor(RED);
			fliph();
			Draw();
			break;
		case 6:break;
		default:printf("Enter valid option ");
			  break;
	      }
	getch();
	closegraph();
 }
