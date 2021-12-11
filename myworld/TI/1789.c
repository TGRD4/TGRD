/*
【Mc生存】插火把：https://www.luogu.com.cn/problem/P1789
*/
#include<stdio.h>
int main()
{
	int a[1001][1001];//定义一个坐标 
	int n,m,k,x,y,ans=0;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&x,&y);//输入火把的坐标 
		for(int j=x-1;j<=x+1;j++)
			for(int k=y-1;k<=y+1;k++)
				a[j][k]=1;//火把周围一格围成的一圈可以被照亮
		a[x-2][y]=1,a[x+2][y]=1,a[x][y-2]=1,a[x][y+2]=1;//最外圈只有正上正下正左正右可以被照亮
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d %d",&x,&y);//输入萤石的坐标 
		for(int j=x-2;j<=x+2;j++)
			for(int k=y-2;k<=y+2;k++)
				a[j][k]=1;//萤石周围两格都可以被照亮
	} 
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(a[i][j]==0)	ans++;//搜索如果有没亮的格子会刷怪
	printf("%d",ans);
	return 0;
}