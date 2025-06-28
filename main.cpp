#include <graphics.h>		
#include <conio.h>
#include <iostream>
#include <stack>
#include <array>
#include"kmqbycyz.h"	
using namespace std;

int main()
{
	initgraph(1600, 800); 
	setbkcolor(RGB(255, 255, 255));
	chess first[33]; 
	int choice = 0;
	ExMessage MESSAGE;
	first[0].screen_background();
	while (true)
	{
		first[0].beginning_page();
		MESSAGE = getmessage(EX_MOUSE);
		switch (MESSAGE.message)
		{
		case WM_LBUTTONDOWN: 
			if (MESSAGE.x >= 180 && MESSAGE.x <= 500 && MESSAGE.y >= 140 && MESSAGE.y <= 190) 
			{
				first[0].initialize0(first);
				cleardevice();        
				first[0].chessboard_figure(choice);
				first[0].circle_print(first,-1);
				first[0].play_game(first,choice);
			}
			else if (MESSAGE.x >= 180 && MESSAGE.x <= 500 && MESSAGE.y >= 190 && MESSAGE.y <= 240) 
			{
				first[0].initialize1(first);
				cleardevice();
				first[0].chessboard_figure(choice);
				first[0].circle_print(first, -1);
				first[0].play_game(first,choice);
			}
			else if (MESSAGE.x >= 180 && MESSAGE.x <= 500 && MESSAGE.y >= 240 && MESSAGE.y <= 290) 
			{
				first[0].initialize2(first);
				cleardevice();
				first[0].chessboard_figure(choice);
				first[0].circle_print(first, -1);
				first[0].play_game(first,choice);
			}
			else if (MESSAGE.x >= 180 && MESSAGE.x <= 500 && MESSAGE.y >= 290 && MESSAGE.y <= 340) 
			{
				first[0].initialize3(first);
				cleardevice();
				first[0].chessboard_figure(choice);
				first[0].circle_print(first, -1);
				first[0].play_game(first,choice);
			}
			else if (MESSAGE.x >= 180 && MESSAGE.x <= 500 && MESSAGE.y >= 340 && MESSAGE.y <= 390)
			{
				exit(0); 
			}
			else if (MESSAGE.x >= 890 && MESSAGE.x <= 980 && MESSAGE.y >= 100 && MESSAGE.y <= 140)
			{
				IMAGE bg1;
				loadimage(&bg1, _T("background1.jpg"), 1600, 800);
				putimage(0, 0, &bg1);
				settextstyle(20, 0, _T("ËÎÌå"));
				settextcolor(RGB(0, 0, 0));
				outtextxy(100, 500, _T("¿×Ã÷Æå game,created by ³ÂÔ¶×¿ 2452459"));
				choice = 1;
			}
			else if (MESSAGE.x >= 890 && MESSAGE.x <= 980 && MESSAGE.y >= 150 && MESSAGE.y <= 190)
			{
				IMAGE bg2;
				loadimage(&bg2, _T("background2.jpg"), 1600, 800);
				putimage(0, 0, &bg2);
				settextstyle(20, 0, _T("ËÎÌå"));
				settextcolor(RGB(0, 0, 0));
				outtextxy(100, 500, _T("¿×Ã÷Æå game,created by ³ÂÔ¶×¿ 2452459"));
				choice = 2;
			}

		}
	}
	closegraph();
	return 0;
}