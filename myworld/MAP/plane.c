#include<stdio.h>
int main()
{
	int e[101][101];
	int a, b, c,  n, m, i, j, k, max = 999999;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i == j) e[i][j] = 0;
			else e[i][j] = max;
		}
	}
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &a, &b,&c);
		e[a][b] = c;
	}
	for (k = 1; k <= n; k++)
		for (i = 1; i <= n; i++)
			for (j = 1; j <= m; j++)
				if (e[i][j] > e[k][j] + e[i][k]&&e[i][k]<max&&e[k][j]<max)
					e[i][j] = e[k][j] + e[i][k];
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
			printf("%10d", e[i][j]);
		printf("\n");
	}
	return 4;
}