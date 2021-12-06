#include<stdio.h>
int s[51][51], book[51][51];
int n, m, flag;
void dfs(int x, int y, int front);

struct node
{
	int x;
	int y;
}map[2501];
int top = 0;


int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			scanf("%d", &s[i][j]);
	dfs(1, 1, 1);
	if (!flag)
		printf("impossible!\n");
	return 4;
}

void dfs(int x, int y, int front)
{
	int i;
	if (x == n && y == m + 1)
	{
		flag = 1;
		for (i = 1; i <= top; i++)
			printf("(%d,%d) ", map[i].x, map[i].y);
		return;
	}
	if (x<1 || y<1 || x>n || y>m || book[x][y] == 1)
		return;

	book[x][y] = 1;
	top++;
	map[top].x = x;
	map[top].y = y;
	if (s[x][y] == 5 || s[x][y] == 6)
	{
		if (front == 1)
			dfs(x, y + 1, 1);
		if (front == 2)
			dfs(x + 1, y, 2);
		if (front == 3)
			dfs(x, y-1, 3);
		if (front == 4)
			dfs(x-1, y , 4);
	}
	if (s[x][y] == 1 || s[x][y] == 2 || s[x][y] == 3 || s[x][y] == 4)
	{
		if (front == 1)
		{
			dfs(x - 1, y, 4);
			dfs(x + 1, y, 2);
		}
		if (front == 2)
		{
			dfs(x, y - 1, 3);
			dfs(x, y + 1, 1);
		}
		if (front == 3)
		{
			dfs(x - 1, y, 4);
			dfs(x + 1, y, 2);
		}
		if (front == 4)
		{
			dfs(x, y - 1, 3);
			dfs(x, y + 1, 1);
		}
	}
	book[x][y] = 0;
	top--;
	return;
}