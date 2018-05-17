#include <stdio.h>
#include <conio.h>
#include "console.h"
#include <time.h>
enum trangthai {down,up,left,right};
struct toado
{
	int x, y;
};
struct snake
{
	toado td[30];
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
	a.td[0].x = 5;
	a.td[0].y = 3;
	a.tt = right;
}
void hienthi(snake a,moi b)
{
	for (int i = 0; i < 30; i++)
	{
		gotoXY(60, i);
		printf("%c", 179);
	}
	for (int i = 2; i <= 28; i++)
	{
		gotoXY(5, i);
		printf("%c", 179);
		gotoXY(55, i);
		printf("%c", 179);
	}
	for (int i = 4; i <= 56; i++)
	{
		gotoXY(i, 2);
		printf("%c", 196);
		gotoXY(i, 28);
		printf("%c", 196);
	}
	gotoXY(b.td.x, b.td.y);
	printf("$");
	for (int i = 0; i < a.n; i++)
	{
		gotoXY(a.td[i].x, a.td[i].y);
		printf("*");
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
			a.td[0].x = a.td[0].y--;
		}
		if (a.tt == down)
		{
			a.td[0].x = a.td[0].y++;
		}
		if (a.tt == left)
		{
			a.td[0].x = a.td[0].x--;
		}
		if (a.tt == right)
		{
			a.td[0].x = a.td[0].x++;
		}
		b.td.x =5+ rand() % 55;
		b.td.y =2 +rand() % 26;
	}
	if (a.td[0].x <= 4 || a.td[0].x >= 56 || a.td[0].y <= 2 || a.td[0].y >= 26)
	{
		return -1;
	}
	for (int i = 0; i < a.n; i++)
	{
		if (b.td.x == a.td[i].x && b.td.y == a.td[i].y)
		{
			return -1;
		}
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
		clrscr();
		hienthi(a,b);
		run(a);
		int kt=anmoi(a, b);
		if (kt == -1)
		{
			gotoXY(85, 12);
			printf("GAM OVER!!!");
			_getch();
			break;
		}
		Sleep(200);
	}
	return 0;
}