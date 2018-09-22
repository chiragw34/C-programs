#include<stdio.h>
#include<conio.h>
#include<graphics.h>
/*void scaling(x1,x2,y1,y2)
{
	line(x1,y1,x2,y2);
	printf("Enter scaling co-ordinates ");
	printf("x,y");
	scanf("%d%d",&x,&y);
	x1=(x1*x);
	y1=(y1*y);
	x2=(x2*x);
	y2=(y2*y);
	printf("Line after scaling");
	line(x1,y1,x2,y2);
	getch();
	closegraph();
}*/
void rotation(int x[],int y[],double th)
{
    int i,left=x[0],right=x[1],top=y[2],bottom=y[0];
    int xn,yn,x1,x2,x3,x4,y1,y2,y3,y4;
    double r11,r12,r21,r22,t;
    int gd=DETECT, gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\bgi");
    //clrscr();

    //rectangle(x1,y1,x2,y2);

    /*r11=cos((th*3.1428)/180);
    r12=sin((th*3.1428)/180);
    r21=(-sin((th*3.1428)/180));
    r22=cos((th*3.1428)/180);
    //printf("%lf  %lf  %lf  %lf",r11,r12,r21,r22);
    xn=((x2*r11)-(y2*r12));
    yn=((x2*r12)+(y2*r11));*/
	t=th*(3.14/180);
	setcolor(RED);
	//xn=-((x2*cos(rad)-y2*sin(rad)));
	//yn=(x2*sin(rad)+y2*cos(rad));
	
 
   x1=abs(x1*cos(t)-y1*sin(t));
   y1=abs(x1*sin(t)+y1*cos(t));
   x2=abs(x2*cos(t)-y2*sin(t));
   y2=abs(x2*sin(t)+y2*cos(t));
   x3=abs(x3*cos(t)-y3*sin(t));
   y3=abs(x3*sin(t)+y3*cos(t));
   x4=abs(x4*cos(t)-y4*sin(t));
   y4=abs(x4*sin(t)+y4*cos(t));
 
   line(fabs(x1),fabs(y1),fabs(x2),fabs(y2));
   line(fabs(x1),fabs(y1),fabs(x3),fabs(y3));
   line(fabs(x3),fabs(y3),fabs(x4),fabs(y4));
   line(fabs(x2),fabs(y2),fabs(x4),fabs(y4));



    //rectangle(x1,y1,xn,yn);
    getch();
    closegraph();

}
void main()
{
	int x[10],y[10],ch,i;
	double th;
	int gd=DETECT, gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\bgi");
	//clrscr();
      //	setbkcolor(WHITE);
	printf("enter the co ordinates of rectangle:-");
	for(i=0;i<4;i++)
	{
		scanf("%d %d",&x[i],&y[i]);
	}
	for(i=0;i<4;i++)
		printf("%d %d\n",x[i],y[i]);
	left=x[0];
	right=x[1];
	top=y[2];
	bottom=y[0];
	line(left,bottom,right,bottom);
	line(left,bottom,left,top);
	line(right,bottom,right,top);
	line(left,top,right,top);
	while(ch!=6)
	{
		printf("\n1. Rotation\t2. Translation\t3. Reflection\n4. Shearing\t5. Scaling\t6. Exit");
		printf("\nenter your choice:-");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("enter the angle of rotation:-");
		    scanf("%lf",&th);
		    rotation(x,y,th);
		    case 6:break;
		}
	}
//	getch();
  //  closegraph();

}
