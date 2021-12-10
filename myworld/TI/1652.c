/*
圆：https://www.luogu.com.cn/problem/P1652
*/
#include<stdio.h>
#include<math.h>
int x[51],y[51],r[51];
double dist(int x1,int y1,int x2,int y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));//计算给定点到圆心的距离
}
int main()
{
	int n,x1,y1,x2,y2,cnt=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&x[i]);
	for(int i=0;i<n;i++) scanf("%d",&y[i]);
	for(int i=0;i<n;i++) scanf("%d",&r[i]);
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	for(int i=0;i<n;i++)//遍历每个圆
		if((dist(x1,y1,x[i],y[i])<r[i])!=(dist(x2,y2,x[i],y[i]))<r[i]) //当点不同在这一个圆内时(一个距离大于圆的半径一个小于)
			cnt++;//穿过的圆数+1
	printf("%d",cnt);
	return 0;
}
