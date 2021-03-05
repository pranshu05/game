//Author:- Pranshu Patel....developer of http://youngcoder.great-site.net
#include<stdio.h>
#include<conio.h>
void main()
{
	  int cx = 3, cy = 1,bx = 6,by = 25;
	  char ch;
	  int score = 0;
	  int lives = 5;
	  int level = 1;
	  int random= 20;
	  int limit = 5;
	  int d = 0;
start:
	  clrscr();
	  gotoxy(34,1);
	  textcolor(GREEN);
	  cprintf("Level: %d",level);
	  gotoxy(34,3);
	  textcolor(GREEN);
	  cprintf("Score: %d",score);
	  gotoxy(34,2);
	  textcolor(GREEN);
	  cprintf("Lives: %d",lives);
	  gotoxy(cx,cy);
	  textcolor(YELLOW);
	  cprintf("#");
	  gotoxy(bx-2,by-1);
	  cprintf("*");
	  gotoxy(bx+2,by-1);
	  cprintf("*");
	  gotoxy(bx-2,by);
	  cprintf("*****");
	  if(kbhit())
	  {
		    ch = getch();
		    switch(ch)
		    {

			     case 'a':
			     bx--;
			     break;

			     case 'd':
			     bx++;
			     break;

			     case 'x':
			     exit(0);
			     break;
		      }
	   }
	   cy++;
	   if(cy == 25)
	   {
		  d = cx - bx;
		  if(-1 <= d && d <=1)
		  {
			 sound(600);
			 delay(300);
			 nosound();
			 score++;
			 if(score == limit)
			 {
			 sound(400);
			 delay(800);
			 score = 0;
			 level++;
			 random++;
			 lives = 5;
			 limit++;
			  }
		  }
		  else
		  {
			 lives--;
			 sound(100);
			 delay(200);
			 sound(200);
			 delay(200);
			 nosound();
			 if(lives == 0)
			 {
				clrscr();
				gotoxy(34,13);
				textcolor(RED);
				cprintf("GAME OVER :(");
				gotoxy(29,14);
				textcolor(BLUE);
				cprintf("Press any key to exit");
				getch();
				exit(0);
			  }
			  if(level == 81)
			  {
			  clrscr();
			  gotoxy(25,13);
			  textcolor(BLUE);
			  cprintf("CONGRATULATIONS GAME OVER");
			  getch();
			}
		  }
		  cy = 1;
		  cx = rand()%random +1;
	}
	delay(150);
goto start;
}
