#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <stdio.h>
#include <graphics.h>

void main()
{
     start:

     clrscr();

     char move;
     float x=2,y=2;

     green:

     gotoxy (x,y);
     do
     {

     cin>>move;

     if(move=='w')
     {
     --y;
     gotoxy (x,y);
     textcolor(GREEN);
     textbackground(GREEN);
     cprintf("X");
     textcolor(BLACK);
     textbackground(BLACK);
     }

     else if(move=='s')
     {
     ++y;
     gotoxy (x,y);
     textcolor(GREEN);
     textbackground(GREEN);
     cprintf("X");
     textcolor(BLACK);
     textbackground(BLACK);
     }

     else if(move=='a')
     {
     --x;
     gotoxy (x,y);
     textcolor(GREEN);
     textbackground(GREEN);
     cprintf("X");
     textcolor(BLACK);
     textbackground(BLACK);
     }

     else if(move=='d')
     {
     ++x;
     gotoxy (x,y);
     textcolor(GREEN);
     textbackground(GREEN);
     cprintf("X");
     textcolor(BLACK);
     textbackground(BLACK);
     }

     else if(move=='W')
     {
     --y;
     gotoxy (x,y);
     textcolor(BLACK);
     textbackground(BLACK);
     cprintf(" ");
     textcolor(BLACK);
     textbackground(BLACK);
     }

     else if(move=='S')
     {
     ++y;
     gotoxy (x,y);
     textcolor(BLACK);
     textbackground(BLACK);
     cprintf(" ");
     textcolor(BLACK);
     textbackground(BLACK);
     }

     else if(move=='A')
     {
     --x;
     gotoxy (x,y);
     textcolor(BLACK);
     textbackground(BLACK);
     cprintf(" ");
     textcolor(BLACK);
     textbackground(BLACK);
     }

     else if(move=='D')
     {
     ++x;
     gotoxy (x,y);
     textcolor(BLACK);
     textbackground(BLACK);
     cprintf(" ");
     textcolor(BLACK);
     textbackground(BLACK);
     }

     else if(move=='r'|| move=='R')
     {
     goto start;
     }

     if(move=='z')
     {

     while(move!='q')
     {
     cin>>move;

     if(move=='w')
     {
     --y;
     gotoxy (x,y);
     textcolor(RED);
     textbackground(RED);
     cprintf("X");
     textcolor(BLACK);
     textbackground(BLACK);
     }

     else if(move=='s')
     {
     ++y;
     gotoxy (x,y);
     textcolor(RED);
     textbackground(RED);
     cprintf("X");
     textcolor(BLACK);
     textbackground(BLACK);
     }

     else if(move=='a')
     {
     --x;
     gotoxy (x,y);
     textcolor(RED);
     textbackground(RED);
     cprintf("X");
     textcolor(BLACK);
     textbackground(BLACK);
     }

     else if(move=='d')
     {
     ++x;
     gotoxy (x,y);
     textcolor(RED);
     textbackground(RED);
     cprintf("X");
     textcolor(BLACK);
     textbackground(BLACK);
     }

     else if(move=='W')
     {
     --y;
     gotoxy (x,y);
     textcolor(BLACK);
     textbackground(BLACK);
     cprintf(" ");
     textcolor(BLACK);
     textbackground(BLACK);
     }

     else if(move=='S')
     {
     ++y;
     gotoxy (x,y);
     textcolor(BLACK);
     textbackground(BLACK);
     cprintf(" ");
     textcolor(BLACK);
     textbackground(BLACK);
     }

     else if(move=='A')
     {
     --x;
     gotoxy (x,y);
     textcolor(BLACK);
     textbackground(BLACK);
     cprintf(" ");
     textcolor(BLACK);
     textbackground(BLACK);
     }

     else if(move=='D')
     {
     ++x;
     gotoxy (x,y);
     textcolor(BLACK);
     textbackground(BLACK);
     cprintf(" ");
     textcolor(BLACK);
     textbackground(BLACK);
     }

     else if(move=='r')
     {
     goto start;
     }

     else if(move=='x')
     {
     goto green;
     }

     }

     }

     }while(move!='q');

getch();
}
