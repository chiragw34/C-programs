#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
#include<dos.h>
#include<process.h>
void main()
{
	int x[100],y[100],nx[100],ny[100];
	int i,k,d=500;
	//int j=0,frame=0;
	int gd=DETECT,gm;
	char ch;
	initgraph(&gd,&gm,"C://TURBOC3//BGI");

	while(1)
	{
		for (i=0;i<2;i++)
		{
				//TOP LEFT FACE
				setcolor(WHITE);
				circle(120,120,70);
				setfillstyle(1,14);
				floodfill(120,120,WHITE);
				//DETAILS
				setcolor(BLACK);
				circle(90+8*i,85,10); //LEFT EYE
				circle(150+8*i,85,10); //RIGHT EYE
				arc(120,100,200+20*i,340-20*i,60);
				circle(90+8*i,90,3); //LEFT EYE PUPIL
				circle(150+8*i,90,3); //RIGHT EYE PUPIL
				//FILLING EYE PUPIL
				setfillstyle(1,0);
				floodfill(90+8*i,90,BLACK);
				floodfill(150+8*i,90,BLACK);



				//BOTTOM LEFT FACE
				setcolor(WHITE);
				circle(120,370,60);
				setfillstyle(1,14);
				floodfill(120,370,WHITE);
				//head ring0
				ellipse(120,280+4*(i+1),0,360,70,15);
				ellipse(120,277+4*(i+1),0,360,50,5);
				setfillstyle(1,1);
				floodfill(81,290,WHITE);
				//DETAILS
				setcolor(BLACK);
				circle(90,340,10); //LEFT EYE
				circle(150,340,10); //RIGHT EYE
				arc(120,340,240,300,60);
				circle(90,340,3); //LEFT EYE PUPIL
				circle(150,340,3); //RIGHT EYE PUPIL
				//FILLING EYE PUPIL
				setfillstyle(1,0);
				floodfill(90,340,BLACK);
				floodfill(150,340,BLACK);



				//TOP RIGHT FACE
				setcolor(WHITE);
				circle(460,60,20);
				setfillstyle(1,14);
				floodfill(460,60,WHITE);
				//DETAILS
				setcolor(BLACK);
				circle(450,53,2);//left eye
				circle(470,53,2);//right eye
				setfillstyle(1,0);
				floodfill(450,53,BLACK);
				floodfill(470,53,BLACK);
				arc(460,60,230,310,10);
				setcolor(RED);
				line(460,80,460,150);//body
				if(i==0)
				{
					line(460,90,480,100);//right arm
					line(480,100,490,130);
					line(460,90,440,100);//left arm
					line(440,100,430,130);
				}
				else
				{
					line(460,90,480,80);//right arm
					line(480,80,430,55);
					line(460,90,440,80);//left arm
					line(440,80,370,55);
				}
				setcolor(BLUE);
				line(460,150,445,200);//left leg
				line(460,150,475,200);//right leg
				setcolor(DARKGRAY);
				line(445,200,425,200);//left shoe
				line(475,200,495,200);//right shoe





				//BOTTOM RIGHT FACE
				setcolor(WHITE);
				circle(460,300,70);
				setfillstyle(1,14);
				floodfill(460,300,WHITE);
				//DETAILS
				setcolor(BLACK);
				circle(430,280,10); //LEFT EYE
				arc(430,280,30,150,15);//LEFT EYEBROW
				circle(490,280,10); //RIGHT EYE
				arc(490,280,30,150,15);//RIGHT EYEBROW
				line(430,320,490,320); //SMILE
				circle(430,280,3); //LEFT EYE PUPIL
				circle(490,280,3); //RIGHT EYE PUPIL
				//FILLING EYE PUPIL
				setfillstyle(1,0);
				floodfill(430,280,BLACK);
				floodfill(490,280,BLACK);

				delay(d);
				cleardevice();
	}

    for (i=0;i<2;i++)
    {
		//TOP LEFT FACE
				setcolor(WHITE);
				circle(120,120,70);
				setfillstyle(1,14);
				floodfill(120,120,WHITE);
				//DETAILS
				setcolor(BLACK);
				circle(95-8*i,85,10); //LEFT EYE
				circle(155-8*i,85,10);//RIGHT EYE
				arc(120,100,200+20*i,340-20*i,60);
				//line(80,140,160,140);//SMILE
				circle(95-8*i,90,3);//LEFT EYE PUPIL
				circle(155-8*i,90,3);//RIGHT EYE PUPIL
				//FILLING EYE PUPIL
				setfillstyle(1,0);
				floodfill(95-8*i,90,BLACK);
				floodfill(155-8*i,90,BLACK);



				//BOTTOM lEFT FACE
				setcolor(WHITE);
				circle(120,370,60);
				setfillstyle(1,14);
				floodfill(120,370,WHITE);
				//head ring
				ellipse(120,288-4*(i+1),0,360,70,15);
				ellipse(120,285-4*(i+1),0,360,50,5);
				setfillstyle(1,1);
				floodfill(81,290,WHITE);
				//DETAILS
				setcolor(BLACK);
				arc(95,360,30,150,15);
				arc(145,360,30,150,15);
				//circle(90,340,10); //LEFT EYE
				//circle(150,340,10); //RIGHT EYE
				//arc(120,340,200+20*i,340-20*i,60);
				//line(80,270,160,270);//SMILE
				arc(120,340,230,310,60);
				//circle(90,340,3); //LEFT EYE PUPIL
				//circle(150,340,3); //RIGHT EYE PUPIL
				//FILLING EYE PUPIL
				//setfillstyle(1,0);
				//floodfill(90,340,BLACK);
				//floodfill(150,340,BLACK);


				//TOP RIGHT FACE
				setcolor(WHITE);
				circle(460,60,20);
				setfillstyle(1,14);
				floodfill(460,60,WHITE);
				setcolor(BLACK);
				circle(450,53,2);//left eye
				circle(470,53,2);//right eye
				setfillstyle(1,0);
				floodfill(450,53,BLACK);
				floodfill(470,53,BLACK);
				arc(460,60,230,310,10);
				setcolor(RED);
				line(460,80,460,150);//body
				if(i==0)
				{
					line(460,90,480,90);//right arm
					line(480,90,460,80);
					line(460,90,440,90);//left arm
					line(440,90,400,80);
				}
				else
				{
					line(460,90,480,100);//right arm
					line(480,100,490,130);
					line(460,90,440,100);//left arm
					line(440,100,430,130);
				}
				setcolor(BLUE);
				line(460,150,445,200);//left leg
				line(460,150,475,200);//right leg
				setcolor(DARKGRAY);
				line(445,200,425,200);//left shoe
				line(475,200,495,200);//right shoe



				//BOTTOM RIGHT FACE
				setcolor(WHITE);
				circle(460,300,70);
				setfillstyle(1,14);
				floodfill(460,300,WHITE);
				//DETAILS
				setcolor(BLACK);
				//circle(430,270,10); //LEFT EYE
				arc(430,285,20,125,9);//LEFT WYNK
				arc(430,280,50,150,16);//LEFT EYEBROW
				circle(490,280,7); //RIGHT EYE
				arc(490,270,20,120,15);//RIGHT EYEBROW
				arc(460,270,220,320,60);//SMILE
				//line(330,320,410,320); //SMILE
				//circle(430,275,3); //LEFT EYE PUPIL
				circle(490,278,3); //RIGHT EYE PUPIL
				//FILLING EYE PUPIL
				setfillstyle(1,0);
				//floodfill(430,275,BLACK);
				floodfill(490,278,BLACK);

				delay(d);
				cleardevice();
	  //	       closegraph();
	}
    if(kbhit())
    {
	ch = getch();
	if(ch==27)
	    exit(0);
    }

		//j++;
		//for(i=0;i<4;i++)
			//closegraph();
	    }
	//get ch0();
      //	00closegraph();

 }
