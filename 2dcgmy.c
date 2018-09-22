#include<stdio.h>
#include<math.h>
//#include<conio.h>
//#include<graphics.h>
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
void rotation(int x1,int y1,int x2,int y2,double th)
{
    int i;
    double xn,yn;
    double r11,r12,r21,r22,rad;
//    int gd=DETECT, gm;
//    initgraph(&gd,&gm,"C:\\TURBOC3\\bgi");
//    clrscr();
    printf("x1=%d  y1=%d  x2=%d  y2=%d  th=%f\n",x1,y1,x2,y2,th);
//    rectangle(x1,y1,x2,y2);

    /*r11=cos((th*3.1428)/180);
    r12=sin((th*3.1428)/180);
    r21=(-sin((th*3.1428)/180));
    r22=cos((th*3.1428)/180);
    //printf("%lf  %lf  %lf  %lf",r11,r12,r21,r22);
    xn=((x2*r11)-(y2*r12));
    yn=((x2*r12)+(y2*r11));*/
	rad=th*(3.14/180);
	xn=-((x2*cos(rad))-(y2*sin(rad)));
	yn=(x2*sin(rad))+(y2*cos(rad));



    printf("x1=%d  y1=%d  xn=%lf  yn=%lf\n",x1,y1,xn,yn);
//    rectangle(x1,y1,xn,yn);
 //   getch();
 //   closegraph();

}
void main()
{
	int x[10],y[10],ch,i;
	double th;
//	int gd=DETECT, gm;
//	initgraph(&gd,&gm,"C:\\TURBOC3\\bgi");
//	clrscr();
	printf("enter the co ordinates of  rectangle\n");
	for(i=0;i<4;i++)
	{
		scanf("%d %d",&x[i],&y[i]);
	}
	for(i=0;i<4;i++)
		printf("%d %d\n",x[i],y[i]);
	while(ch!=6)
	{
		printf("\n1. Rotation\t2. Translation\t3. Reflection\n4. Shearing\t5. Scaling\t6. Exit");
		printf("\nenter your choice:-");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("enter the angle of rotation:-");
		    scanf("%lf",&th);
		    rotation(x[0],y[0],x[2],y[2],th);
		    case 6:break;
		}
	}
	//getch();
    //closegraph();

}
