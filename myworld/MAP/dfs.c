#include<stdio.h>
int s[51][51], book[51][51];
int n, m, p, q, min = 0x3f3f3f3f;
void dfs(int x, int y, int step);

int main()
{
	int i, j, sx, sy;
	scanf("%d %d", &n, &m);
	for (i = 1; i <=n;i++)
		for (j = 1; j <=m;j++)
			scanf("%d",&s[i][j]);
	scanf("%d %d %d %d", &sx, &sy, &p, &q);
	book[sx][sy] = 1;//标记起始点状态为走过
	dfs(sx, sy, 0);//起始步数为0
	printf("\n%d\n", min);
	return 4;
}

void dfs(int x, int y, int step)
{
	int next[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };//顺时针寻找出路
	int tx, ty, k;
	if (x == p && y == q)//走到指定位置则记录总路程
	{
		if (step < min)
			min = step;
		return;
	}
	for (k = 0; k < 4; k++)
	{
		tx = x + next[k][0];
		ty = y + next[k][1];
		if (tx < 1 || ty < 1 || tx > n || ty > m)//不能超出边界
			continue;
		if (s[tx][ty] == 0 && book[tx][ty] == 0)//没走过且下一步是路
		{
			book[tx][ty] = 1;
			dfs(tx, ty, step + 1);
			book[tx][ty] = 0;
		}
	}
	return;
}