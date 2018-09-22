 #include<stdio.h>
 #include<conio.h>
 #include<graphics.h>
 void main()
 {
    int gd=DETECT,gm;
    int x,y,x1,y1,x2,y2;
    initgraph(&gd,&gm,"C:/TC/BGI");
    printf("Enter The Coordinates of First Point:");
    scanf("%d%d",&x1,&y1);
    printf("Enter The Coordinates of Second Point:");
    scanf("%d%d",&x2,&y2);
    x=x1;
    y=y1;
    int dy=y2-y1;
    int dx=x2-x1;
    int De=2*dy;
    int Dne=2*(dy-dx);
    int Ds=2*dy-dx;
    while(x2>x)
    {
	putpixel(x,y,7);
	if(Ds<=0)
	    {
		Ds=Ds+De;
	    }
	else
	    {
		Ds=Ds+Dne;
		y=y+1;
	    }
	x=x+1;
    }

    getch();
    closegraph();
 }