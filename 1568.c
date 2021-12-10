/*
赛跑：https://www.luogu.com.cn/problem/P1568
*/
#include<stdio.h>
const int MAXSIZE = 1000100;
int main()
{
	int m, n, i, speed, time;
    scanf("%d %d",&n,&m);
	int a[MAXSIZE], b[MAXSIZE];
	
	int t=0;
	//直接在循环中计算两人每个时间单位的路程并记录在以时间作为下标的数组中 
	while (n--)
    {
		scanf("%d %d",&speed,&time);
		for (i = 1; i <= time; i++)
			a[t + i] = a[t + i - 1] + speed;
		t += time;
	}
	t = 0;
	while (m--) 
    {
		scanf("%d %d",&speed,&time);
		for (i = 1; i <= time; i++)
			b[t + i] = b[t + i - 1] + speed;
		t += time;//两人所用时间相同
	}

	int cnt = 0, record = 0;//记录之前的排名
	int sign;//记录当下的排名
	for (i = 1; i<=t; i++) 
    {
		if (a[i]>= b[i]) sign = 1;
		else if (a[i] < b[i]) sign = 2;
		if (sign!=record) cnt++;//与之前排名不一样说明出现超越的情况
		record = sign;//记录上一次的排名
	}
	printf("%d",cnt-1);//减1，去除刚开始跑步由相等变成A/B第一的情况（不叫反超）
	return 0;
}
