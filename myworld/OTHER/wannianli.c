#include<stdio.h>

/*计算是否是闰年*/
int leapyear(int y)
{
	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
		return 1;
	else
		return 0;
}

/*计算输入的年月天数*/
int getmonth(int y, int m)
{
	int days;
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		days = 31;
	if (m == 4 || m == 6 || m == 9 || m == 11)
		days = 30;
	if (m == 2)
	{
		if (leapyear(y))
			days = 29;
		else
			days = 28;
	}
	return days;
}

/*计算输入的年月天数距1900.1.1的相隔天数*/
int totalday(int y, int m)
{
	int totaldays = 0;
	int i;
	for (i = 1900; i < y; i++)//不计入输入年份的天数
		if (leapyear(i))
			totaldays += 366;
		else
			totaldays += 365;
	for (i = 1; i < m; i++)//不计算输入月份的天数
		totaldays += getmonth(y, i);
	return totaldays;
}

/*确定输入月份的第一天是周几*/
int startday(int y, int m)
{
	int startdays;
	startdays = (totalday(y, m)+1) % 7;//若取1900.1.1则天数为0而取到0(周天)所以应该+1(周一)
	return startdays;
}

/*打印日历*/
int calendar(int y, int m)
{
	int dayss;
	int start;
	int i;
	dayss = getmonth(y, m);
	start = startday(y, m);
	for (i = 0; i < start; i++)//打印此月第一天前的空格
		printf("    ");
	for (i = 1; i <= dayss; i++)//打印此月的天数
	{
		printf("%4d", i);
		start++;
		if (!(start % 7))
			printf("\n");
	}
	printf("\n-----------------------------\n\n\n");
}

/*打印日历标题*/
int title(int y, int m)
{
	printf("\n\t%d年%d月\n", y, m);
	printf("-----------------------------\n");
	printf("  日  一  二  三  四  五  六\n");
}


int main()
{
	int y, m;
	int flag = 1;
	do
	{
		printf("----------");
	    printf("   万年历   ");
		printf("----------");
		printf("\n1.万年历\n");
		printf("0.退出\n");
		printf("请选择:");
		scanf("%d", &flag);
		if (flag == 1)
		{
			printf("\n请输入年份(1900后):");
			scanf("%d", &y);
			printf("请输入月份:");
			scanf("%d", &m);
			title(y, m);//标题
			calendar(y, m);//内容
		}
		else break;
	} while (flag == 1);//为假时退出	
}

