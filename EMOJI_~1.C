#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
void main()
{
	int x[100],y[100],nx[100],ny[100];
	int i,j=0,k,frame=0;
	int gd=DETECT,gm;


	while(j!=20)
	   {

		for (i=0;i<2;i++)
			{   initgraph(&gd,&gm,"C://TURBOC3//BGI");
				printf("this is frame %d",frame++);
				//FACE
				circle(120,120,70);
				setfillstyle(1,14);
				floodfill(120,120,WHITE);

				//DETAILS
				setcolor(BLACK);
				circle(90+8*i,85,10); //LEFT EYE
				circle(150+8*i,85,10); //RIGHT EYE
				line(80,140,160,140); //SMILE
				circle(90+8*i,90,3); //LEFT EYE PUPIL
				circle(150+8*i,90,3); //RIGHT EYE PUPIL

				//FILLING EYE PUPIL
				setfillstyle(1,0);
				floodfill(90+8*i,90,BLACK);
				floodfill(150+8*i,90,BLACK);



				delay(100);
			       //	closegraph();
			}


			for (i=0;i<2;i++)
			{
				initgraph(&gd,&gm,"C://TURBOC3//BGI");
				printf("this is frame %d",frame++);
				//FACE
				circle(120,120,70);
				setfillstyle(1,14);
				floodfill(120,120,WHITE);

				//DETAILS
				setcolor(BLACK);
				circle(95-8*i,85,10); //LEFT EYE
				circle(155-8*i,85,10);//RIGHT EYE
				line(80,140,160,140);//SMILE
				circle(95-8*i,90,3);//LEFT EYE PUPIL
				circle(155-8*i,90,3);//RIGHT EYE PUPIL

				//FILLING EYE PUPIL
				setfillstyle(1,0);
				floodfill(95-8*i,90,BLACK);
				floodfill(155-8*i,90,BLACK);


				delay(100);
		       //		closegraph();
			}

		j++;
	       //	for(i=0;i<4;i++)
		 //	closegraph();
	   }
	getch();

}