#include <graphics.h>		
#include <conio.h>
#include <iostream>
#include <stack>
#include <array>
#include<sstream>
using namespace std;
struct chess
{
	int x;
	int y;
	bool empty = false;
	bool failure(chess p[33])
	{
		int n = 0; bool flag = true;
		for (int i = 0; i < 33; ++i)
		{
			if (p[i].empty == false) // 如果该位置有棋子
			{
				++n;
			}
		}
		if (n == 1 && p[16].empty == false) { return true; }
		if (n == 1 && p[16].empty == true) { return false; }
		for (int i = 8; i <= 10; ++i)
		{
			if (p[i].empty == false && (p[i - 5].empty == false || p[i - 1].empty == false || p[i + 1].empty == false || p[i + 7].empty == false))
			{
				flag = false; break;
			}
		}
		for (int i = 15; i <= 17; ++i)
		{
			if (p[i].empty == false && (p[i - 7].empty == false || p[i + 7].empty == false || p[i - 1].empty == false || p[i + 1].empty == false))
			{
				flag = false; break;
			}
		}
		for (int i = 22; i <= 24; ++i)
		{
			if (p[i].empty == false && (p[i - 7].empty == false || p[i + 5].empty == false || p[i - 1].empty == false || p[i + 1].empty == false))
			{
				flag = false; break;
			}
		}
		if (p[0].empty == false && p[1].empty == false && p[2].empty == false && p[3].empty == true && p[4].empty == true && p[5].empty == true && flag == true) { return false; }
		if (p[30].empty == false && p[31].empty == false && p[32].empty == false && p[27].empty == true && p[28].empty == true && p[29].empty == true && flag == true) { return false; }
		if (p[6].empty == false && p[13].empty == false && p[20].empty == false && p[7].empty == true && p[14].empty == true && p[21].empty == true && flag == true) { return false; }
		if (p[12].empty == false && p[19].empty == false && p[26].empty == false && p[11].empty == true && p[18].empty && p[25].empty == true && flag == true) { return false; }
		if (p[0].empty == false && (p[1].empty == false || p[3].empty == false)) { return true; }
		else if (p[1].empty == false && (p[0].empty == false || p[2].empty == false || p[4].empty == false)) { return true; }
		else if (p[2].empty == false && (p[1].empty == false || p[5].empty == false)) { return true; }
		else if (p[3].empty == false && (p[0].empty == false || p[4].empty == false || p[6].empty == false)) { return true; }
		else if (p[4].empty == false && (p[1].empty == false || p[3].empty == false || p[5].empty == false || p[9].empty == false)) { return true; }
		else if (p[5].empty == false && (p[2].empty == false || p[4].empty == false || p[10].empty == false)) { return true; }
		else if (p[6].empty == false && (p[7].empty == false || p[13].empty == false)) { return true; }
		else if (p[7].empty == false && (p[6].empty == false || p[8].empty == false || p[14].empty == false)) { return true; }
		else if (p[8].empty == false && (p[3].empty == false || p[7].empty == false || p[9].empty == false || p[15].empty == false)) { return true; }
		else if (p[9].empty == false && (p[4].empty == false || p[8].empty == false || p[10].empty == false || p[16].empty == false)) { return true; }
		else if (p[10].empty == false && (p[5].empty == false || p[9].empty == false || p[11].empty == false || p[17].empty == false)) { return true; }
		else if (p[11].empty == false && (p[10].empty == false || p[12].empty == false || p[18].empty == false)) { return true; }
		else if (p[12].empty == false && (p[11].empty == false || p[19].empty == false)) { return true; }
		else if (p[13].empty == false && (p[6].empty == false || p[14].empty == false || p[20].empty == false)) { return true; }
		else if (p[14].empty == false && (p[7].empty == false || p[13].empty == false || p[15].empty == false || p[21].empty == false)) { return true; }
		else if (p[15].empty == false && (p[8].empty == false || p[14].empty == false || p[16].empty == false || p[22].empty == false)) { return true; }
		else if (p[16].empty == false && (p[9].empty == false || p[15].empty == false || p[17].empty == false || p[23].empty == false)) { return true; }
		else if (p[17].empty == false && (p[10].empty == false || p[16].empty == false || p[18].empty == false || p[24].empty == false)) { return true; }
		else if (p[18].empty == false && (p[11].empty == false || p[17].empty == false || p[19].empty == false || p[25].empty == false)) { return true; }
		else if (p[19].empty == false && (p[12].empty == false || p[18].empty == false || p[26].empty == false)) { return true; }
		else if (p[20].empty == false && (p[13].empty == false || p[21].empty == false)) { return true; }
		else if (p[21].empty == false && (p[14].empty == false || p[20].empty == false || p[22].empty == false)) { return true; }
		else if (p[22].empty == false && (p[15].empty == false || p[21].empty == false || p[23].empty == false || p[27].empty == false)) { return true; }
		else if (p[23].empty == false && (p[16].empty == false || p[22].empty == false || p[24].empty == false || p[28].empty == false)) { return true; }
		else if (p[24].empty == false && (p[17].empty == false || p[23].empty == false || p[25].empty == false || p[29].empty == false)) { return true; }
		else if (p[25].empty == false && (p[18].empty == false || p[24].empty == false || p[26].empty == false)) { return true; }
		else if (p[26].empty == false && (p[19].empty == false || p[25].empty == false)) { return true; }
		else if (p[27].empty == false && (p[22].empty == false || p[28].empty == false || p[30].empty == false)) { return true; }
		else if (p[28].empty == false && (p[23].empty == false || p[27].empty == false || p[29].empty == false || p[31].empty == false)) { return true; }
		else if (p[29].empty == false && (p[24].empty == false || p[28].empty == false || p[32].empty == false)) { return true; }
		else if (p[30].empty == false && (p[27].empty == false || p[31].empty == false)) { return true; }
		else if (p[31].empty == false && (p[28].empty == false || p[30].empty == false || p[32].empty == false)) { return true; }
		else if (p[32].empty == false && (p[29].empty == false || p[31].empty == false)) { return true; }
		else { return false; }
	}
	void initialize0(chess first[33])
	{
		first[0].x = 125; first[0].y = 175; first[0].empty = false;
		first[1].x = 125; first[1].y = 225; first[1].empty = false;
		first[2].x = 125; first[2].y = 275; first[2].empty = false;
		first[3].x = 175; first[3].y = 175; first[3].empty = false;
		first[4].x = 175; first[4].y = 225; first[4].empty = false;
		first[5].x = 175; first[5].y = 275; first[5].empty = false;
		first[6].x = 225; first[6].y = 75; first[6].empty = false;
		first[7].x = 225; first[7].y = 125; first[7].empty = false;
		first[8].x = 225; first[8].y = 175; first[8].empty = false;
		first[9].x = 225; first[9].y = 225; first[9].empty = false;
		first[10].x = 225; first[10].y = 275; first[10].empty = false;
		first[11].x = 225; first[11].y = 325; first[11].empty = false;
		first[12].x = 225; first[12].y = 375; first[12].empty = false;
		first[13].x = 275; first[13].y = 75; first[13].empty = false;
		first[14].x = 275; first[14].y = 125; first[14].empty = false;
		first[15].x = 275; first[15].y = 175; first[15].empty = false;
		first[16].x = 275; first[16].y = 225; first[16].empty = true;
		first[17].x = 275; first[17].y = 275; first[17].empty = false;
		first[18].x = 275; first[18].y = 325; first[18].empty = false;
		first[19].x = 275; first[19].y = 375; first[19].empty = false;
		first[20].x = 325; first[20].y = 75; first[20].empty = false;
		first[21].x = 325; first[21].y = 125; first[21].empty = false;
		first[22].x = 325; first[22].y = 175; first[22].empty = false;
		first[23].x = 325; first[23].y = 225; first[23].empty = false;
		first[24].x = 325; first[24].y = 275; first[24].empty = false;
		first[25].x = 325; first[25].y = 325; first[25].empty = false;
		first[26].x = 325; first[26].y = 375; first[26].empty = false;
		first[27].x = 375; first[27].y = 175; first[27].empty = false;
		first[28].x = 375; first[28].y = 225; first[28].empty = false;
		first[29].x = 375; first[29].y = 275; first[29].empty = false;
		first[30].x = 425; first[30].y = 175; first[30].empty = false;
		first[31].x = 425; first[31].y = 225; first[31].empty = false;
		first[32].x = 425; first[32].y = 275; first[32].empty = false;
	}
	void initialize1(chess first[33])
	{
		first[0].x = 125; first[0].y = 175; first[0].empty = true;
		first[1].x = 125; first[1].y = 225; first[1].empty = true;
		first[2].x = 125; first[2].y = 275; first[2].empty = true;
		first[3].x = 175; first[3].y = 175; first[3].empty = true;
		first[4].x = 175; first[4].y = 225; first[4].empty = false;
		first[5].x = 175; first[5].y = 275; first[5].empty = true;
		first[6].x = 225; first[6].y = 75; first[6].empty = true;
		first[7].x = 225; first[7].y = 125; first[7].empty = true;
		first[8].x = 225; first[8].y = 175; first[8].empty = false;
		first[9].x = 225; first[9].y = 225; first[9].empty = true;
		first[10].x = 225; first[10].y = 275; first[10].empty = false;
		first[11].x = 225; first[11].y = 325; first[11].empty = false;
		first[12].x = 225; first[12].y = 375; first[12].empty = true;
		first[13].x = 275; first[13].y = 75; first[13].empty = true;
		first[14].x = 275; first[14].y = 125; first[14].empty = false;
		first[15].x = 275; first[15].y = 175; first[15].empty = true;
		first[16].x = 275; first[16].y = 225; first[16].empty = false;
		first[17].x = 275; first[17].y = 275; first[17].empty = true;
		first[18].x = 275; first[18].y = 325; first[18].empty = true;
		first[19].x = 275; first[19].y = 375; first[19].empty = true;
		first[20].x = 325; first[20].y = 75; first[20].empty = true;
		first[21].x = 325; first[21].y = 125; first[21].empty = true;
		first[22].x = 325; first[22].y = 175; first[22].empty = false;
		first[23].x = 325; first[23].y = 225; first[23].empty = true;
		first[24].x = 325; first[24].y = 275; first[24].empty = true;
		first[25].x = 325; first[25].y = 325; first[25].empty = true;
		first[26].x = 325; first[26].y = 375; first[26].empty = true;
		first[27].x = 375; first[27].y = 175; first[27].empty = true;
		first[28].x = 375; first[28].y = 225; first[28].empty = true;
		first[29].x = 375; first[29].y = 275; first[29].empty = true;
		first[30].x = 425; first[30].y = 175; first[30].empty = true;
		first[31].x = 425; first[31].y = 225; first[31].empty = true;
		first[32].x = 425; first[32].y = 275; first[32].empty = true;
	}
	void initialize2(chess first[33])
	{
		first[0].x = 125; first[0].y = 175; first[0].empty = true;
		first[1].x = 125; first[1].y = 225; first[1].empty = true;
		first[2].x = 125; first[2].y = 275; first[2].empty = true;
		first[3].x = 175; first[3].y = 175; first[3].empty = true;
		first[4].x = 175; first[4].y = 225; first[4].empty = false;
		first[5].x = 175; first[5].y = 275; first[5].empty = true;
		first[6].x = 225; first[6].y = 75; first[6].empty = true;
		first[7].x = 225; first[7].y = 125; first[7].empty = false;
		first[8].x = 225; first[8].y = 175; first[8].empty = true;
		first[9].x = 225; first[9].y = 225; first[9].empty = true;
		first[10].x = 225; first[10].y = 275; first[10].empty = false;
		first[11].x = 225; first[11].y = 325; first[11].empty = true;
		first[12].x = 225; first[12].y = 375; first[12].empty = true;
		first[13].x = 275; first[13].y = 75; first[13].empty = false;
		first[14].x = 275; first[14].y = 125; first[14].empty = false;
		first[15].x = 275; first[15].y = 175; first[15].empty = true;
		first[16].x = 275; first[16].y = 225; first[16].empty = true;
		first[17].x = 275; first[17].y = 275; first[17].empty = true;
		first[18].x = 275; first[18].y = 325; first[18].empty = true;
		first[19].x = 275; first[19].y = 375; first[19].empty = true;
		first[20].x = 325; first[20].y = 75; first[20].empty = false;
		first[21].x = 325; first[21].y = 125; first[21].empty = true;
		first[22].x = 325; first[22].y = 175; first[22].empty = true;
		first[23].x = 325; first[23].y = 225; first[23].empty = true;
		first[24].x = 325; first[24].y = 275; first[24].empty = false;
		first[25].x = 325; first[25].y = 325; first[25].empty = true;
		first[26].x = 325; first[26].y = 375; first[26].empty = true;
		first[27].x = 375; first[27].y = 175; first[27].empty = false;
		first[28].x = 375; first[28].y = 225; first[28].empty = false;
		first[29].x = 375; first[29].y = 275; first[29].empty = true;
		first[30].x = 425; first[30].y = 175; first[30].empty = true;
		first[31].x = 425; first[31].y = 225; first[31].empty = true;
		first[32].x = 425; first[32].y = 275; first[32].empty = true;
	}
	void initialize3(chess first[33])
	{
		first[0].x = 125; first[0].y = 175; first[0].empty = false;
		first[1].x = 125; first[1].y = 225; first[1].empty = false;
		first[2].x = 125; first[2].y = 275; first[2].empty = true;
		first[3].x = 175; first[3].y = 175; first[3].empty = true;
		first[4].x = 175; first[4].y = 225; first[4].empty = false;
		first[5].x = 175; first[5].y = 275; first[5].empty = false;
		first[6].x = 225; first[6].y = 75; first[6].empty = false;
		first[7].x = 225; first[7].y = 125; first[7].empty = false;
		first[8].x = 225; first[8].y = 175; first[8].empty = true;
		first[9].x = 225; first[9].y = 225; first[9].empty = false;
		first[10].x = 225; first[10].y = 275; first[10].empty = true;
		first[11].x = 225; first[11].y = 325; first[11].empty = false;
		first[12].x = 225; first[12].y = 375; first[12].empty = true;
		first[13].x = 275; first[13].y = 75; first[13].empty = false;
		first[14].x = 275; first[14].y = 125; first[14].empty = false;
		first[15].x = 275; first[15].y = 175; first[15].empty = true;
		first[16].x = 275; first[16].y = 225; first[16].empty = false;
		first[17].x = 275; first[17].y = 275; first[17].empty = true;
		first[18].x = 275; first[18].y = 325; first[18].empty = true;
		first[19].x = 275; first[19].y = 375; first[19].empty = true;
		first[20].x = 325; first[20].y = 75; first[20].empty = false;
		first[21].x = 325; first[21].y = 125; first[21].empty = true;
		first[22].x = 325; first[22].y = 175; first[22].empty = true;
		first[23].x = 325; first[23].y = 225; first[23].empty = true;
		first[24].x = 325; first[24].y = 275; first[24].empty = true;
		first[25].x = 325; first[25].y = 325; first[25].empty = true;
		first[26].x = 325; first[26].y = 375; first[26].empty = true;
		first[27].x = 375; first[27].y = 175; first[27].empty = false;
		first[28].x = 375; first[28].y = 225; first[28].empty = true;
		first[29].x = 375; first[29].y = 275; first[29].empty = true;
		first[30].x = 425; first[30].y = 175; first[30].empty = true;
		first[31].x = 425; first[31].y = 225; first[31].empty = false;
		first[32].x = 425; first[32].y = 275; first[32].empty = false;
	}
	bool win(chess first[33])
	{
		int count = 0;
		for (int i = 0; i < 33; ++i)
		{
			if (first[i].empty == false)
			{
				count++;
			}
		}
		if (count == 1 && first[16].empty == false)
			return true;
		else
			return false;
	}
	void screen_background()
	{
		setbkcolor(RGB(255, 255, 255));
		cleardevice();
		settextstyle(20, 0, _T("宋体"));
		settextcolor(RGB(0, 0, 0));
		outtextxy(100, 500, _T("孔明棋 game,created by 陈远卓 2452459"));
	}
	void beginning_page()
	{
		setbkcolor(RGB(255, 255, 255));
		/*cleardevice();*/
		settextstyle(50, 0, _T("宋体"));
		settextcolor(RGB(0, 0, 0));
		outtextxy(90, 70, _T("欢迎来到孔明棋游戏！"));
		settextstyle(30, 0, _T("宋体"));
		outtextxy(200, 150, _T("1. 正常对局"));
		outtextxy(200, 200, _T("2. 残局模式(初级)"));
		outtextxy(200, 250, _T("3. 残局模式(中级)"));
		outtextxy(200, 300, _T("4. 残局模式(高级)"));
		outtextxy(200, 350, _T("5. 退出游戏"));
		outtextxy(900, 100, _T("背景1"));
		outtextxy(900, 150, _T("背景2"));
		setlinecolor(RGB(0, 0, 255));
		rectangle(180, 140, 500, 190);//选项1
		rectangle(180, 190, 500, 240);//选项2
		rectangle(180, 240, 500, 290);//选项3
		rectangle(180, 290, 500, 340); //选项4
		rectangle(180, 340, 500, 390); //选项5
		rectangle(890, 90, 980, 140); //背景1
		rectangle(890, 140, 980, 190); //背景2
		settextstyle(20, 0, _T("宋体"));
		settextcolor(RGB(0, 0, 0));
		outtextxy(100, 500, _T("孔明棋 game,created by 陈远卓 2452459"));

	}
	void chessboard_figure(int choice)
	{
		if (choice == 1)
		{
			IMAGE bg1;
			loadimage(&bg1, _T("background1.jpg"), 1600, 800);
			putimage(0, 0, &bg1);
		}
		else if (choice == 2)
		{
			IMAGE bg2;
			loadimage(&bg2, _T("background2.jpg"), 1600, 800);
			putimage(0, 0, &bg2);
		}
		setlinecolor(RGB(0, 0, 0));
		rectangle(100, 150, 450, 300);
		rectangle(200, 50, 350, 400);
		line(100, 200, 450, 200);
		line(100, 250, 450, 250);
		line(200, 100, 350, 100);
		line(200, 350, 350, 350);
		line(150, 150, 150, 300);
		line(250, 50, 250, 400);
		line(300, 50, 300, 400);
		line(400, 150, 400, 300);
		rectangle(800, 200, 890, 250);
		settextstyle(35, 0, _T("宋体"));
		outtextxy(810, 210, _T("退出"));
		rectangle(800, 300, 890, 350);
		outtextxy(810, 310, _T("悔棋"));
	}
	void circle_print(chess p[33], int selected = -1)
	{
		for (int i = 0; i < 33; i++)
		{
			if (p[i].empty == false)
			{
				if (i == selected)
					setfillcolor(RGB(255, 0, 0));
				else
					setfillcolor(RGB(0, 0, 255));
				fillcircle(p[i].x, p[i].y, 20);
			}
		}
	}

	void play_game(chess p[33], int choice)
	{
		int selected = -1;
		std::stack<std::array<chess, 33>> history; // 用堆栈保存历史
		while (true)
		{
			ExMessage M = getmessage(EX_MOUSE);
			if (M.message == WM_LBUTTONDOWN)
			{
				if (M.x >= 800 && M.x <= 900 && M.y >= 300 && M.y <= 350)
				{
					if (!history.empty()) {
						auto prev = history.top();
						for (int i = 0; i < 33; ++i)
							p[i] = prev[i];
						history.pop();
					}
					cleardevice();
					chessboard_figure(choice);
					circle_print(p, -1);
					continue;
				}
				if (M.x >= 800 && M.x <= 900 && M.y >= 200 && M.y <= 250)
				{
					cleardevice();
					return;
				}
				int X = static_cast<int>(M.x / 50) * 50 + 25;
				int Y = static_cast<int>(M.y / 50) * 50 + 25;
				int idx = -1;
				for (int i = 0; i < 33; ++i)
				{
					if (p[i].x == X && p[i].y == Y)
					{
						idx = i;
						break;
					}
				}
				if (selected == -1 && idx != -1 && !p[idx].empty)
				{
					selected = idx;
					cleardevice();
					chessboard_figure(choice);
					circle_print(p, selected);
				}
				else if (selected != -1 && idx != -1 && p[idx].empty)
				{
					int Xm = (p[selected].x + p[idx].x) / 2;
					int Ym = (p[selected].y + p[idx].y) / 2;
					int mid = -1;
					for (int i = 0; i < 33; ++i)
					{
						if (p[i].x == Xm && p[i].y == Ym && !p[i].empty)
						{
							mid = i;
							break;
						}
					}
					if (mid != -1 &&
						((abs(p[selected].x - p[idx].x) == 100 && p[selected].y == p[idx].y) ||
							(abs(p[selected].y - p[idx].y) == 100 && p[selected].x == p[idx].x)))
					{
						std::array<chess, 33> temp;
						for (int i = 0; i < 33; ++i)
							temp[i] = p[i];
						history.push(temp);

						p[selected].empty = true;
						p[mid].empty = true;
						p[idx].empty = false;
					}
					selected = -1;
					cleardevice();
					chessboard_figure(choice);
					circle_print(p, selected);
				}
				else
				{
					selected = -1;
					cleardevice();
					chessboard_figure(choice);
					circle_print(p, selected);
				}
			}
			if (!p[16].failure(p))
			{
				settextstyle(50, 0, _T("宋体"));
				settextcolor(RGB(255, 0, 0));
				outtextxy(500, 300, _T("通关失败！"));
				settextstyle(35, 0, _T("宋体"));
				outtextxy(500, 400, _T("点击重新开始！"));
				setlinecolor(RGB(0, 0, 0));
				rectangle(490, 390, 750, 450);
				ExMessage M = getmessage(EX_MOUSE);
				if (M.message == WM_LBUTTONDOWN)
				{
					if (M.x >= 490 && M.x <= 750 && M.y >= 390 && M.y <= 450)
					{
						cleardevice();
						selected = -1;
						return;
					}
				}
			}
			if (p[0].win(p))
			{
				settextstyle(50, 0, _T("宋体"));
				settextcolor(RGB(255, 0, 0));
				outtextxy(500, 300, _T("通关成功！"));
				settextstyle(35, 0, _T("宋体"));
				outtextxy(500, 400, _T("点击重新开始！"));
				setlinecolor(RGB(0, 0, 0));
				rectangle(490, 390, 750, 450);
				ExMessage M = getmessage(EX_MOUSE);
				if (M.message == WM_LBUTTONDOWN)
				{
					if (M.x >= 490 && M.x <= 750 && M.y >= 390 && M.y <= 450)
					{
						cleardevice();
						selected = -1;
						return;
					}
				}
			}
			int n = 0;
			for (int i = 0; i < 33; ++i)
			{
				if (p[i].empty == false)
				{
					++n;
				}
			}
			TCHAR s[20];
			_stprintf_s(s, _T("当前剩余棋子数量：%d"), n);
			outtextxy(100, 650, s);
		}
	}
};
////  背景
//void screen_background()
//{
//	setbkcolor(RGB(255, 255, 255));
//    cleardevice();
//    settextstyle(20, 0, _T("宋体"));
//    settextcolor(RGB(0, 0, 0));
//    outtextxy(100, 500, _T("孔明棋 game,created by 陈远卓 2452459"));
//}
//
////  界面
//void beginning_page()
//{
//	settextstyle(50, 0, _T("宋体"));
//	settextcolor(RGB(0, 0, 0));
//	outtextxy(90, 70, _T("欢迎来到孔明棋游戏！"));
//	settextstyle(30, 0, _T("宋体"));
//	outtextxy(200, 150, _T("1. 正常对局"));
//	outtextxy(200, 200, _T("2. 残局模式(初级)"));
//	outtextxy(200, 250, _T("3. 残局模式(中级)"));
//	outtextxy(200, 300, _T("4. 残局模式(高级)"));
//	outtextxy(200, 350, _T("5. 退出游戏"));
//	outtextxy(900, 100, _T("背景1"));
//	outtextxy(900, 150, _T("背景2"));
//	setlinecolor(RGB(0, 0, 255));
//	rectangle(180, 140, 500, 190);//选项1
//	rectangle(180, 190, 500, 240);//选项2
//	rectangle(180, 240, 500, 290);//选项3
//	rectangle(180, 290, 500, 340); //选项4
//	rectangle(180, 340, 500, 390); //选项5
//	rectangle(890, 90, 980, 140); //背景1
//	rectangle(890, 140, 980, 190); //背景2
//	settextstyle(20, 0, _T("宋体"));
//	settextcolor(RGB(0, 0, 0));
//	outtextxy(100, 500, _T("孔明棋 game,created by 陈远卓 2452459"));
//
//}
//
//
////  棋盘图案
//void chessboard_figure(int choice)
//{
//	if (choice == 1)
//	{
//		IMAGE bg1;
//		loadimage(&bg1, _T("background1.jpg"), 1600, 800);
//		putimage(0, 0, &bg1);
//	}
//	else if (choice == 2)
//	{
//		IMAGE bg2;
//		loadimage(&bg2, _T("background2.jpg"), 1600, 800);
//		putimage(0, 0, &bg2);
//	}
//	setlinecolor(RGB(0, 0, 0));
//	rectangle(100, 150, 450, 300);
//	rectangle(200, 50, 350, 400);
//	line(100, 200, 450, 200);
//	line(100, 250, 450, 250);
//	line(200, 100, 350, 100);
//	line(200, 350, 350, 350);
//	line(150, 150, 150, 300);
//	line(250, 50, 250, 400);
//	line(300, 50, 300, 400);
//	line(400, 150, 400, 300);
//	rectangle(800, 200, 890, 250);
//	settextstyle(35, 0, _T("宋体"));
//	outtextxy(810, 210, _T("退出"));
//	rectangle(800, 300, 890, 350);
//	outtextxy(810, 310, _T("悔棋"));
//}
//
////棋子绘制
//void circle_print(chess p[33], int selected = -1)
//{
//	for (int i = 0; i < 33; i++)
//	{
//		if (p[i].empty == false)
//		{
//			if (i == selected)
//				setfillcolor(RGB(255, 0, 0)); // 选中为红色
//			else
//				setfillcolor(RGB(0, 0, 255)); // 普通为蓝色
//			fillcircle(p[i].x, p[i].y, 20);
//		}
//	}
//}
//
//void play_game(chess p[33],int choice)
//{
//	int selected = -1;
//	std::stack<std::array<chess, 33>> history; // 用堆栈保存历史
//	while (true)
//	{
//		ExMessage M = getmessage(EX_MOUSE);
//		if (M.message == WM_LBUTTONDOWN)
//		{
//			if (M.x >= 800 && M.x <= 900 && M.y >= 300 && M.y <= 350)
//			{
//				if (!history.empty()) {
//					auto prev = history.top();
//					for (int i = 0; i < 33; ++i)
//						p[i] = prev[i];
//					history.pop();
//				}
//				cleardevice();
//				screen_background();
//				chessboard_figure(choice);
//				circle_print(p, -1);
//				continue;
//			}
//			if (M.x >= 800 && M.x <= 900 && M.y >= 200 && M.y <= 250)
//			{
//				cleardevice();
//				screen_background();
//				return;
//			}
//			int X = static_cast<int>(M.x / 50) * 50 + 25;
//			int Y = static_cast<int>(M.y / 50) * 50 + 25;
//			int idx = -1;
//			for (int i = 0; i < 33; ++i)
//			{
//				if (p[i].x == X && p[i].y == Y)
//				{
//					idx = i;
//					break;
//				}
//			}
//			if (selected == -1 && idx != -1 && !p[idx].empty)
//			{
//				selected = idx;
//				cleardevice();
//				screen_background();
//				chessboard_figure(choice);
//				circle_print(p, selected);
//			}
//			else if (selected != -1 && idx != -1 && p[idx].empty)
//			{
//				int Xm = (p[selected].x + p[idx].x) / 2;
//				int Ym = (p[selected].y + p[idx].y) / 2;
//				int mid = -1;
//				for (int i = 0; i < 33; ++i)
//				{
//					if (p[i].x == Xm && p[i].y == Ym && !p[i].empty)
//					{
//						mid = i;
//						break;
//					}
//				}
//				if (mid != -1 &&
//					((abs(p[selected].x - p[idx].x) == 100 && p[selected].y == p[idx].y) ||
//						(abs(p[selected].y - p[idx].y) == 100 && p[selected].x == p[idx].x)))
//				{
//					// 保存当前棋盘到堆栈
//					std::array<chess, 33> temp;
//					for (int i = 0; i < 33; ++i)
//						temp[i] = p[i];
//					history.push(temp);
//
//					p[selected].empty = true;
//					p[mid].empty = true;
//					p[idx].empty = false;
//				}
//				selected = -1;
//				cleardevice();
//				screen_background();
//				chessboard_figure(choice);
//				circle_print(p, selected);
//			}
//			else
//			{
//				selected = -1;
//				cleardevice();
//				screen_background();
//				chessboard_figure(choice);
//				circle_print(p, selected);
//			}
//		}
//		if (!p[16].failure(p))
//		{
//			settextstyle(50, 0, _T("宋体"));
//			settextcolor(RGB(255, 0, 0));
//			outtextxy(500, 300, _T("通关失败！"));
//			settextstyle(35, 0, _T("宋体"));
//			outtextxy(500, 400, _T("点击重新开始！"));
//			setlinecolor(RGB(0, 0, 0));
//			rectangle(490, 390, 750, 450);
//			ExMessage M = getmessage(EX_MOUSE);
//			if (M.message == WM_LBUTTONDOWN)
//			{
//				if (M.x >= 490 && M.x <= 750 && M.y >= 390 && M.y <= 450)
//				{
//					cleardevice();
//					selected = -1;
//					return;
//				}
//			}
//		}
//		if (p[0].win(p))
//		{
//			settextstyle(50, 0, _T("宋体"));
//			settextcolor(RGB(255, 0, 0));
//			outtextxy(500, 300, _T("通关成功！"));
//			settextstyle(35, 0, _T("宋体"));
//			outtextxy(500, 400, _T("点击重新开始！"));
//			setlinecolor(RGB(0, 0, 0));
//			rectangle(490, 390, 750, 450);
//			ExMessage M = getmessage(EX_MOUSE);
//			if (M.message == WM_LBUTTONDOWN)
//			{
//				if (M.x >= 490 && M.x <= 750 && M.y >= 390 && M.y <= 450)
//				{
//					cleardevice();
//					selected = -1;
//					return;
//				}
//			}
//		}
//	}
//}


//  游戏主函数
//void play_game(chess p[33])
//{
//	int selected = -1; // 当前选中的棋子索引，-1表示未选中
//	while (true)
//	{
//		ExMessage M = getmessage(EX_MOUSE);
//		if (M.message == WM_LBUTTONDOWN)
//		{
//			if (M.x >= 800 && M.x <= 900 && M.y >= 200 && M.y <= 250)
//			{
//				// 点击了退出按钮
//				cleardevice();
//				screen_background();
//				return; // 退出游戏
//			}
//			int X = static_cast<int>(M.x / 50) * 50 + 25;
//			int Y = static_cast<int>(M.y / 50) * 50 + 25;
//			int idx = -1;
//			for (int i = 0; i < 33; ++i)
//			{
//				if (p[i].x == X && p[i].y == Y)
//				{
//					idx = i;
//					break;
//				}
//			}
//			if (selected == -1 && idx != -1 && !p[idx].empty)
//			{
//				// 第一次点击，选中棋子
//				selected = idx;
//				cleardevice();
//				screen_background();
//				chessboard_figure();
//				circle_print(p, selected);
//			}
//			else if (selected != -1 && idx != -1 && p[idx].empty)
//			{
//				// 第二次点击，且目标点为空
//				int Xm = (p[selected].x + p[idx].x) / 2;
//				int Ym = (p[selected].y + p[idx].y) / 2;
//				int mid = -1;
//				for (int i = 0; i < 33; ++i)
//				{
//					if (p[i].x == Xm && p[i].y == Ym && !p[i].empty)
//					{
//						mid = i;
//						break;
//					}
//				}
//				// 判断是否为合法跳跃（两点距离为100且中间有棋子）
//				if (mid != -1 &&
//					((abs(p[selected].x - p[idx].x) == 100 && p[selected].y == p[idx].y) ||
//						(abs(p[selected].y - p[idx].y) == 100 && p[selected].x == p[idx].x)))
//				{
//					p[selected].empty = true;
//					p[mid].empty = true;
//					p[idx].empty = false;
//				}
//				// 取消选中
//				selected = -1;
//				cleardevice();
//				screen_background();
//				chessboard_figure();
//				circle_print(p, selected);
//			}
//			else
//			{
//				// 其他情况，取消选中
//				selected = -1;
//				cleardevice();
//				screen_background();
//				chessboard_figure();
//				circle_print(p, selected);
//			}
//		}
//		if (!p[16].failure(p)) // 检查游戏是否结束
//		{
//			settextstyle(50, 0, _T("宋体"));
//			settextcolor(RGB(255, 0, 0));
//			outtextxy(500, 300, _T("通关失败！"));
//			settextstyle(35, 0, _T("宋体"));
//			outtextxy(500, 400, _T("点击重新开始！"));
//			setlinecolor(RGB(0, 0, 0));
//			rectangle(490, 390, 750, 450);
//			ExMessage M = getmessage(EX_MOUSE);
//			if (M.message == WM_LBUTTONDOWN)
//			{
//				if (M.x >= 490 && M.x <= 750 && M.y >= 390 && M.y <= 450)
//				{
//					// 清除屏幕并重新开始游戏
//					cleardevice();
//					selected = -1; // 重置选中状态
//					return;
//				}
//			}
//		}
//		if (p[0].win(p))
//		{
//			settextstyle(50, 0, _T("宋体"));
//			settextcolor(RGB(255, 0, 0));
//			outtextxy(500, 300, _T("通关成功！"));
//			settextstyle(35, 0, _T("宋体"));
//			outtextxy(500, 400, _T("点击重新开始！"));
//			setlinecolor(RGB(0, 0, 0));
//			rectangle(490, 390, 750, 450);
//			ExMessage M = getmessage(EX_MOUSE);
//			if (M.message == WM_LBUTTONDOWN)
//			{
//				if (M.x >= 490 && M.x <= 750 && M.y >= 390 && M.y <= 450)
//				{
//					// 清除屏幕并重新开始游戏
//					cleardevice();
//					selected = -1; // 重置选中状态
//					return;
//				}
//			}
//		}
//	}
//}