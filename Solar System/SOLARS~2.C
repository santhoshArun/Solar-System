#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>

union REGS in,out;

void main()
{

    int a=DETECT,b,i,j,cl=0,x,y;
    float w=0,mer=0,ven=0,mar=0,jup=0,sat=0,ura=0,nep=0,plu=0,sun=0;
    clrscr();
    initgraph(&a,&b,"c:/tc/bgi");
    setbkcolor(0);

    //sun
    setcolor(4);
    setfillstyle(1,4);
    circle(320,190,25);
    floodfill(320,190,4);
    setcolor(15);
    outtextxy(309,186,"sun");

    //orbit
    setcolor(15);
    ellipse(320,190,0,360,50,5);          //mercury
    ellipse(320,190,0,360,80,7);          //venus
    ellipse(320,190,0,360,110,10);        //earth
    ellipse(320,190,0,360,150,14);        //mars

    ellipse(320,190,0,360,240,33);        //jupiter
    ellipse(320,190,0,360,265,40);        //saturn
    ellipse(320,190,0,360,280,50);        //uranus
    ellipse(320,190,0,360,295,65);        //neptune
    ellipse(320,190,0,360,314,85);        //pluto

    //mercury
    setcolor(4);
    setfillstyle(1,4);
    circle(360,193,2);
    floodfill(360,193,4);
    setcolor(15);
    outtextxy(350,200,"mercury");

    //venus
    setcolor(6);
    setfillstyle(1,6);
    circle(242,190,3);
    floodfill(242,190,6);
    setcolor(15);
    outtextxy(230,194,"venus");

    //earth
    setcolor(9);
    setfillstyle(1,9);
    circle(395,183,5);
    floodfill(395,183,9);
    setcolor(15);
    outtextxy(407,175,"earth");

    //mars
    setcolor(14);
    setfillstyle(1,14);
    circle(200,181,4);
    floodfill(200,181,14);
    setcolor(15);
    outtextxy(183,167,"mars");

    //jupiter
    setcolor(6);
    setfillstyle(1,6);
    circle(140,210,15);
    floodfill(140,210,6);
    setcolor(15);
    outtextxy(160,205,"jupiter");

    //saturn
    setcolor(6);
    setfillstyle(1,6);
    circle(470,158,10);
    floodfill(470,158,6);
    setcolor(15);
    outtextxy(460,140,"saturn");

	//rings
	setcolor(6);
	ellipse(470,158,0,360,22,3);
	ellipse(470,158,0,360,23,3);
	ellipse(470,158,0,360,24,4);
	ellipse(470,158,0,360,25,4);
	ellipse(470,158,0,360,26,5);
	ellipse(470,158,0,360,27,5);

    //uranus
    setcolor(3);
    setfillstyle(1,3);
    circle(250,140,8);
    floodfill(250,140,3);
    setcolor(15);
    outtextxy(260,130,"uranus");

    //neptune
    setcolor(7);
    setfillstyle(1,7);
    circle(498,242,7);
    floodfill(498,242,7);
    setcolor(15);
    outtextxy(450,250,"neptune");

    //pluto
    setcolor(1);
    setfillstyle(1,1);
    circle(350,105,2);
    floodfill(350,105,1);
    setcolor(15);
    outtextxy(330,92,"pluto");

    setcolor(15);
    settextstyle(4,0,5);
    outtextxy(215,30,"solar system");

    //stars
    for(i=50;i<650;i+=50)
    {
	for(j=50;j<450;j+=50)
	{
	    putpixel(i,j,15);
	}
    }

    for(i=25;i<650;i+=50)
    {
	for(j=25;j<450;j+=50)
	{
	    putpixel(i,j,14);
	}
    }

    //show mouse
    in.x.ax=1;
    int86(51,&in,&out);

    //set mouse position
    in.x.ax=4;
    in.x.cx=200;
    in.x.dx=200;
    int86(51,&in,&out);

    do
    {
	in.x.ax=3;
	int86(51,&in,&out);
	cl=out.x.bx;
	x=out.x.cx;
	y=out.x.dx;
	gotoxy(1,1);
	printf("\n\tx: %d\t\ty: %d\t\tclick: %d",x,y,cl);

	setcolor(15);
	settextstyle(2,0,6);
	outtextxy(405,305,"weight conversion");
	rectangle(400,309,572,325);

	for(i=395;i<=500;i++)
	{
	    for(j=309;j<=332;j++)
	    {
		if(x==i&&y==j&&cl==1)
		{
		    gotoxy(45,23);
		    printf("enter your weight: ");
		    rectangle(500,350,550,369);
		    scanf("%f",&w);
		    mer=0.387*w;
		    ven=0.907*w;
		    mar=0.377*w;
		    jup=2.364*w;
		    sat=0.916*w;
		    ura=0.889*w;
		    nep=1.125*w;
		    plu=0.067*w;
		    sun=27.072*w;
		}
	    }
	}

	for(i=295;i<=343;i++)
	{
	    for(j=167;j<=213;j++)
	    {
		if(x==i&&y==j&&cl==1)
		{
		    gotoxy(1,19);
		    printf("object name       : sun            \n");
		    printf("diameter          : 13,90,000 km   \n");
		    printf("rotation period   : 24 days        \n");
		    printf("revolution period : 225 million years\n");
		    printf("distance from sun : 0 km           \n");
		    printf("mass              : 1.989x10^30 kg \n");
		    printf("number of moon    : 0              \n");
		    printf("your weight       : %f           ",sun);
		}
	    }
	}

	for(i=356;i<=364;i++)
	{
	    for(j=189;j<=197;j++)
	    {
		if(x==i&&y==j&&cl==1)
		{
		    gotoxy(1,19);
		    printf("planet name       : mercury        \n");
		    printf("diameter          : 4,880 km       \n");
		    printf("rotation period   : 59 days        \n");
		    printf("revolution period : 88 days        \n");
		    printf("distance from sun : 5.79 crore km  \n");
		    printf("mass              : 3.3x10^23 kg   \n");
		    printf("number of moon    : 0              \n");
		    printf("your weight       : %f           ",mer);
		}
	    }
	}

	for(i=236;i<=264;i++)
	{
	    for(j=184;j<=195;j++)
	    {
		if(x==i&&y==j&&cl==1)
		{
		    gotoxy(1,19);
		    printf("planet name       : venus          \n");
		    printf("diameter          : 12,104 km      \n");
		    printf("rotation period   : 243 days       \n");
		    printf("revolution period : 224.7 days     \n");
		    printf("distance from sun : 10.82 crore km \n");
		    printf("mass              : 4.869x10^24 kg \n");
		    printf("number of moon    : 0              \n");
		    printf("your weight       : %f           ",ven);
		}
	    }
	}


	for(i=388;i<=401;i++)
	{
	    for(j=176;j<=189;j++)
	    {
		if(x==i&&y==j&&cl==1)
		{
		    gotoxy(1,19);
		    printf("planet name       : earth          \n");
		    printf("diameter          : 12,756 km      \n");
		    printf("rotation period   : 24 hours       \n");
		    printf("revolution period : 365.25 days    \n");
		    printf("distance from sun : 14.96 crore km \n");
		    printf("mass              : 5.972x10^24 kg \n");
		    printf("number of moon    : 1              \n");
		    printf("your weight       : %f             ",w);
		}
	    }
	}


	for(i=193;i<=206;i++)
	{
	    for(j=175;j<=187;j++)
	    {
		if(x==i&&y==j&&cl==1)
		{
		    gotoxy(1,19);
		    printf("planet name       : mars           \n");
		    printf("diameter          : 6,794 km       \n");
		    printf("rotation period   : 1 day 40 mins  \n");
		    printf("revolution period : 687 days       \n");
		    printf("distance from sun : 22.79 crore km \n");
		    printf("mass              : 6.422x10^23 kg \n");
		    printf("number of moon    : 2              \n");
		    printf("your weight       : %f           ",mar);
		}
	    }
	}


	for(i=125;i<=155;i++)
	{
	    for(j=196;j<=225;j++)
	    {
		if(x==i&&y==j&&cl==1)
		{
		    gotoxy(1,19);
		    printf("planet name       : jupiter        \n");
		    printf("diameter          : 1,42,984 km    \n");
		    printf("rotation period   : 9 hrs 50 mins  \n");
		    printf("revolution period : 11.86 years    \n");
		    printf("distance from sun : 77.83 crore km \n");
		    printf("mass              : 1.9x10^27 kg   \n");
		    printf("number of moon    : 28             \n");
		    printf("your weight       : %f           ",jup);
		}
	    }
	}


	for(i=457;i<=485;i++)
	{
	    for(j=148;j<=169;j++)
	    {
		if(x==i&&y==j&&cl==1)
		{
		    gotoxy(1,19);
		    printf("planet name       : saturn         \n");
		    printf("diameter          : 1,20,536 km    \n");
		    printf("rotation period   : 10 hrs 48 mins \n");
		    printf("revolution period : 29.46 years    \n");
		    printf("distance from sun : 142.7 crore km \n");
		    printf("mass              : 5.68x10^26 kg  \n");
		    printf("number of moon    : 30             \n");
		    printf("your weight       : %f           ",sat);
		}
	    }
	}


	for(i=240;i<=258;i++)
	{
	    for(j=131;j<=148;j++)
	    {
		if(x==i&&y==j&&cl==1)
		{
		    gotoxy(1,19);
		    printf("planet name       : uranus         \n");
		    printf("diameter          : 51,118 km      \n");
		    printf("rotation period   : 17 hrs 14 mins \n");
		    printf("revolution period : 84.01 years    \n");
		    printf("distance from sun : 286.96 crore km\n");
		    printf("mass              : 8.683x10^25 kg \n");
		    printf("number of moon    : 21             \n");
		    printf("your weight       : %f           ",ura);
		}
	    }
	}


	for(i=490;i<=505;i++)
	{
	    for(j=234;j<=252;j++)
	    {
		if(x==i&&y==j&&cl==1)
		{
		    gotoxy(1,19);
		    printf("planet name       : neptune        \n");
		    printf("diameter          : 49,532 km      \n");
		    printf("rotation period   : 16 hrs 6 mins  \n");
		    printf("revolution period : 164.8 years    \n");
		    printf("distance from sun : 449 crore km   \n");
		    printf("mass              : 1.0247x10^26 kg\n");
		    printf("number of moon    : 8              \n");
		    printf("your weight       : %f           ",nep);
		}
	    }
	}


	for(i=344;i<=355;i++)
	{
	    for(j=98;j<=110;j++)
	    {
		if(x==i&&y==j&&cl==1)
		{
		    gotoxy(1,19);
		    printf("planet name       : pluto          \n");
		    printf("diameter          : 2,274 km       \n");
		    printf("rotation period   : 6 days 9 hrs   \n");
		    printf("revolution period : 247.7 years    \n");
		    printf("distance from sun : 590 crore km   \n");
		    printf("mass              : 1.27x10^22 kg  \n");
		    printf("number of moon    : 1              \n");
		    printf("your weight       : %f           ",plu);
		}
	    }
	}


    }while(!kbhit());


    getch();
}