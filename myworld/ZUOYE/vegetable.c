#include<stdio.h>
#include <curses.h>
#define Choice {\
STAR();\
printf("a.洋蓟\t\t");\
printf("b.甜菜\n");\
printf("c.胡萝卜\t");\
printf("f.finished\n");\
printf("q.exit\n");\
STAR();\
printf("make the choice:\n");\
}

double a = 0.0;
double m = 0.0;
double k = 0.0;
int ij = 1;

double SUM(double vgtble);
void STAR(void);
void HENG(void);
void PRINTF(double sum);

int main()
{
	char ch = '$';
	double vgtble;
	double sum = 0.0;
	int ok = 1;
	while (ch != 'q')
	{
		if (ok)
		{
			Choice;
			scanf("%c", &ch);
			ok = 0;
		}
		if (ch == 'q' || ch == 'f')
		{
			printf("\nexit!\n");
			break;
		}
		while (ch != 'f' && ch != 'q')
		{
			if (ok)
			{
				Choice;
				scanf("%c", &ch);
			}
			switch (ch)
			{
			case 'a':vgtble = 2.05;
				sum = SUM(vgtble);
				break;
			case 'b':vgtble = 1.15;
				sum = SUM(vgtble);
				break;
			case 'c':vgtble = 1.09;
				sum = SUM(vgtble);
				break;
			case 'f':printf("\nfinished!\n\n");
				PRINTF(sum);
				a = 0.0;
				m = 0.0;
				k = 0.0;
				getchar();
				break;
			case 'q':printf("\nexit!\n"); break;
			default:printf("please input the right answer!\n\n");
				break;
			}
			ok = 1;
			getchar();
		}
	}
}


double SUM(double vgtble)
{
	double w, fee = 0.0;
	printf("请输入磅数:");
	scanf("%lf", &w);
	printf("\n");
	if (w > 0)
	{
		m += (w * vgtble);
		a += w;
		if (a <= 5.0 && a > 0.0)
			fee = 6.5;
		else if (a > 5.0 && a <= 20.0)
			fee = 14.0;
		else
			fee = 14.0 + ((a - 20.0) / 2.0);
		k = fee;
		return  (m + fee);
	}
	else
		printf("please input the right number!\n");
	return 0;
}


void STAR(void)
{
	printf("* * * * * * * * * * * * *\n");
}

void HENG(void)
{
	printf(" ---------------------------\n");
}

void PRINTF(double sum)
{
	HENG();
	printf("|   洋蓟今日单价 : 2.05 $   |\n");
	printf("|   甜菜今日单价 : 1.15 $   |\n");
	printf("|  胡萝卜今日单价 : 1.09 $  |\n");
	HENG();
	if (m >= 100.0)
	{
		m *= 0.95;
		ij = 0;
	}
	printf("weight = %.2lf磅\n", a);
	printf("vegetable = %.2lf元\n", m);
	printf("packing and delivering = %.2lf元\n", k);
	if (!ij)
	{
		printf("sum = %.2lf\n\n", sum - (m * 0.05));
		printf("您已享受折扣!\n");
		ij = 1;
	}
	else
		printf("sum = %.2lf元\n\n\n", sum );
	printf("please press any key to continue!\n");
}

