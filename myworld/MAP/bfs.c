#include<stdio.h>
struct node {
	int x;
	int y;
};
int main()
{
	int s[51][51], book[51][51] = { 0 };
	int n, m, sum, i, j, k;
	int tx, ty, sx, sy;
	struct node map[2501];
	int head, tail;
	int next[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
	scanf("%d %d %d %d", &n, &m, &sx, &sy);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			scanf("%d", &s[i][j]);
	head = 1;
	tail = 1;
	map[tail].x = sx;
	map[tail].y = sy;
	tail++;
	book[sx][sy] = 1;
	sum = 1;
	while (head < tail)
	{
		for (k = 0; k < 4; k++)
		{
			tx = map[head].x + next[k][0];
			ty = map[head].y + next[k][1];
			if (tx<1 || ty<1 || tx>n || ty>m )
				continue;
			if (s[tx][ty] > 0 && book[tx][ty] == 0)
			{
				sum++;
				book[tx][ty] = 1;
				map[tail].x = tx;
				map[tail].y = ty;
				tail++;
			}
		}
		head++;
	}
	printf("%d\n", sum);
	return 4;
}