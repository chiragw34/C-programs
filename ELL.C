#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void disp();
float x,y;
int xc,yc;
void main()
{
    int gd=DETECT,gm,a,b;
    float d1,d2;
    initgraph(&gd,&gm,"c:\\turboc3\\bgi");
    printf("Enter The Co-ordinates Of The Center:");
    scanf("%d %d",&xc,&yc);
    printf("Enter The X_axis_length(a) and Y_axis_length(b):");
    scanf("%d %d",&a,&b);
    x=0;y=b;
    disp();
    d1=(b*b)-(a*a*b)+(a*a)/4;
    while((2.0*b*b*x)<=(2.0*a*a*y))
    {
        x++;
        if(d1<=0)
        d1=d1+(2.0*b*b*x)+(3*b*b);
        else
        {
            y--;
            d1=d1+(2.0*b*b*x)+(3*b*b)-(2.0*a*a*y)-(2*a*a);
        }
        disp();
        x=-x;
        disp();
        x=-x;
    }
    x=a;
    y=0;
    disp();
    d2=(a*a)+2.0*(b*b*a)+(b*b)/4;
    while((2.0*b*b*x)>(2.0*a*a*y))
    {
        y++;
        if(d2>0)
        d2=d2+(a*a)-(2.0*a*a*y);
        else
        {
            x--;
            d2=d2+(2.0*b*b*x)-(2.0*a*a*y)+(a*a);
        }
        disp();
        y=-y;
        disp();
        y=-y;
    }
    setfillstyle(HATCH_FILL,RED);
    fillellipse(xc, yc, a, b);
    getch();
    closegraph();
}
void disp()
{
    setcolor(WHITE);
    putpixel(xc+x,yc+y,7);
    putpixel(xc-x,yc+y,7);
    putpixel(xc+x,yc-y,7);
    putpixel(xc+x,yc-y,7);
}
