/*水管游戏：
给定一张未联通的水管图，1～4表示弯管，5～6表示直管：
1.上右；2.下右；3.下左；4.上左；5.左右；6.上下
设定进水口在左边为进水口1（1就代表从左边进水）,顺时针编号：上为进水口2，右为进水口3，下为进水口4
输出所有能使水管联通的路径（从(1，1)到(n,m)），设定刚开始进水口是1(左边)，最后进水口也是1。
*/
#include<stdio.h>
int s[11][11], book[11][11];
int n, m, flag;
void dfs(int x, int y, int front);//front为进水口的位置
struct node
{
	int x;
	int y;//记录路径
}map[101];
int top = 0;//top是路径下标（也是总和），一开始没有路径所以是0
int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			scanf("%d", &s[i][j]);
	dfs(1, 1, 1);//第一个水管在(1,1)且进水口在左边
	if (!flag)//若找不到有效路径
		printf("impossible!\n");
    putchar('\n');
	return 0;
}
void dfs(int x, int y, int front)
{
	int i;
	if (x == n && y == m + 1)//若坐标达到目标位说明成功联通
    //y=m+1是因为最后联通口在右边的墙上
	{
		flag = 1;//记录路径成功
		for (i = 1; i <= top; i++)
			printf("(%d,%d) ", map[i].x, map[i].y);//输出记录的全部路径
		return;
	}
	if (x<1 || y<1 || x>n || y>m || book[x][y] == 1)
		return;
	book[x][y] = 1;//记录此处管道转动过了
	top++;//路径+1
	map[top].x = x;
	map[top].y = y;//将当前位置坐标记录在数组中
	if (s[x][y] == 5 || s[x][y] == 6)//如果管道是直管的情况
	{
		if (front == 1)//进水口在左边
			dfs(x, y + 1, 1);//相当于向右移动一步
		if (front == 2)
			dfs(x + 1, y, 2);
		if (front == 3)
			dfs(x, y-1, 3);
		if (front == 4)
			dfs(x-1, y , 4);
	}
	if (s[x][y] == 1 || s[x][y] == 2 || s[x][y] == 3 || s[x][y] == 4)//弯管
	{
		if (front == 1)//进水口在左边，弯管可以向上也可以向下两种情况
		{
			dfs(x - 1, y, 4);//向上弯曲相当于向上移动一步横坐标减1(x-1)，对于下一个水管来说相当于进水口在下面(4)
			dfs(x + 1, y, 2);//向下弯曲相当于向下移动一部横坐标加1(x+1)，对于下一个水管来说相当于进水口在上面(2)
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
	book[x][y] = 0;//退一步重置路径标记
	top--;//路径长度减1(直到遍历完所有情况)
	return;
}
/*
5 4 
5 3 5 3
1 5 3 0
2 3 5 1
6 1 1 5
1 5 5 4
*/
