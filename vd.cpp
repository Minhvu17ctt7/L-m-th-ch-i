#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <conio.h>
#include "console.h"
#include <time.h>
#include <stdlib.h>
enum trangthai {down,up,left,right};
struct toado
{
	int x, y;
};
struct snake
{
	toado td[100];
	int n;
	trangthai tt;
};
struct moi
{
	toado td;
};
void khoitao(snake &a,moi &b)
{
	b.td.x = 10;
	b.td.y = 10;
	a.n = 1;
	a.td[0].x = 10;
	a.td[0].y = 5;
	a.tt = right;
}
void hienthi(snake a,moi b)
{
	clrscr();
	TextColor(12);
	for (int i = 0; i < 30; i++)
	{
		gotoXY(70, i);
		printf("%c", 179);
	}
	TextColor(14);
	for (int i = 1; i <= 28; i++)
	{
		gotoXY(5, i);
		printf("%c", 179);
		gotoXY(65, i);
		printf("%c", 179);
	}
	for (int i = 5; i <= 65; i++)
	{
		gotoXY(i, 1);
		printf("%c", 196);
		gotoXY(i, 28);
		printf("%c", 196);
	}
	TextColor(8+rand()%8);
	gotoXY(b.td.x, b.td.y);
	putchar(235);
	TextColor(10);
	gotoXY(a.td[0].x, a.td[0].y);
	putchar('0');
	for (int i = 1; i < a.n; i++)
	{
		gotoXY(a.td[i].x, a.td[i].y);
		putchar('o');
	}
}
void run(snake &a)
{
		for (int i = a.n-1; i >0; i--)
		{
			a.td[i].x = a.td[i - 1].x;
			a.td[i].y = a.td[i - 1].y;
		}
		if (_kbhit())
		{
			char key = _getch();
			if (key == 'a' || key == 'A')
			{
				a.tt = left;
			}
			else if (key == 's' || key == 'S')
			{
				a.tt = down;
			}
			else if (key == 'd' || key == 'D')
			{
				a.tt = right;
			}
			else if (key == 'w' || key == 'W')
			{
				a.tt = up;
			}
		}
		if (a.tt == up)
		{
			a.td[0].y--;
		}
		else if (a.tt == down)
		{
			a.td[0].y++;
		}
		else if (a.tt == left)
		{
			a.td[0].x--;
		}
		else if (a.tt == right)
		{
			a.td[0].x++;
		}
}
int anmoi(snake &a, moi &b)
{
	if (a.td[0].x < 5 || a.td[0].x > 65 || a.td[0].y < 2 || a.td[0].y > 29)
	{
		return -1;
	}
	for (int i = 1; i < a.n; i++)
	{
		if (a.td[0].x == a.td[i].x && a.td[0].y == a.td[i].y)
		{
			return -1;
		}
	}
	if (a.td[0].x == b.td.x && a.td[0].y == b.td.y)
	{
		for (int i = a.n; i > 0; i--)
		{
			a.td[i].x = a.td[i - 1].x;
			a.td[i].y = a.td[i - 1].y;
		}
		a.n++;
		if (a.tt == up)
		{
               a.td[0].y--;
		}
		else if (a.tt == down)
		{
			 a.td[0].y++;
		}
		else if (a.tt == left)
		{
			a.td[0].x--;
		}
		else if (a.tt == right)
		{
			a.td[0].x++;
		}
		b.td.x =6+ rand() % 50;
		b.td.y =3+  rand() % 25;
	}
	return 0;
}
int main()
{
	snake a;
	moi b;
	srand(time(NULL));
	khoitao(a,b);
	while (1)
	{
		hienthi(a,b);
		run(a);
		int kt=anmoi(a, b);
		if (kt == -1)
		{
			gotoXY(85, 12);
			printf("GAM OVER!!!");
			while(_getch()!=13)
			{
			}
			break;
		}
		Sleep(150);
	}
	return 0;
}