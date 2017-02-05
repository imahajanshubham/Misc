#include <graphics.h>
#include <stdio.h>
  
int main() {
        int gd=DETECT,gm,i,y=0,x=0,y1=0;
        initgraph(&gd, &gm, NULL);
        
        /*Printing Convas.*/
        setcolor(DARKGRAY);
        for(i=0;i<480;i++)
        {
                line(750,y,0,y);
                y++;
        }
        outtextxy(225,15,"PLANNING - TARGET/ACTUAL");
        
       /*Printing y-axis.*/
        setcolor(WHITE);
        line(50,35,50,440);
        line(50,35,45,45);
        line(50,35,55,45);
        
        /*Printing x-axis.*/
        y=440;
        setcolor(WHITE);
        line(550,y,50,y);
        line(550,y,540,y-5);
        line(550,y,540,y+5);
        
        /*Printing 1st Bar.*/
        y=50;
        setcolor(YELLOW);
        for(i=0;i<50;i++)
        {
                line(520,y,75,y);
                delay(10);
                y++;
        }
        outtextxy(530,70,"520 | Target");
        
        /*Printing 2nd Bar.*/
        y=y+5;
        setcolor(LIGHTGRAY);
        for(i=0;i<50;i++)
        {
                line(425,y,75,y);
                delay(10);
                y++;
        }
        outtextxy(435,130,"425 | Actual");
        
        /*Printing 3rd Bar.*/
        y=y+25;
        setcolor(YELLOW);
        for(i=0;i<50;i++)
        {
                line(475,y,75,y);
                delay(10);
                y++;
        }
        outtextxy(485,200,"475 | Target");
        
        /*Printing 4th Bar.*/
        y=y+5;
        setcolor(LIGHTGRAY);
        for(i=0;i<50;i++)
        {
                line(350,y,75,y);
                delay(10);
                y++;
        }
        outtextxy(360,255,"350 | Actual");
        
        /*Printing 5th Bar.*/
        y=y+25;
        setcolor(GREEN);
        for(i=0;i<50;i++)
        {
                line(275,y,75,y);
                delay(10);
                y++;
        }
        outtextxy(285,330,"275 | Target");
        
        /*Printing 6th Bar.*/
        y=y+5;
        setcolor(RED);
        for(i=0;i<50;i++)
        {
                line(125,y,75,y);
                delay(10);
                y++;
        }
        outtextxy(135,385,"125 | Actual");
        
        delay(500);
        outtextxy(560,440,"X - Axis");
        outtextxy(15,15,"Y - Axis");
        
        /*Printing the Data for Y-Axis.*/
        outtextxy(25,70,"2");
        outtextxy(25,90,"0");
        outtextxy(25,110,"1");
        outtextxy(25,130,"7");
        outtextxy(25,205,"2");
        outtextxy(25,225,"0");
        outtextxy(25,245,"1");
        outtextxy(25,265,"6");
        outtextxy(25,340,"2");
        outtextxy(25,360,"0");
        outtextxy(25,380,"1");
        outtextxy(25,400,"5");
        
        delay(60000);
        closegraph();
        
        return 0;
}
