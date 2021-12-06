#include<stdio.h>
int main()
{
    int e[11][11]={0},book[11]={0},dis[11];
    int inf=0x3f3f3f3f,min;//无穷大
    int i,j,k,t,n,m,a,b,c;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(i!=j)
                e[i][j]=inf;
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        e[a][b]=c;
    }
    book[1]=1;
    for(i=1;i<=n;i++)
        dis[i]=e[1][i];

        
    for(i=1;i<=n-1;i++)
    {
        min=inf;
        /*确定1到某一点的最短路径并且使该点成为源点*/
        for(j=1;j<=n;j++)
        {
            if(dis[j]<min&&book[j]==0)//从dis数组中选定最小值//该值就是从源点到改值对应顶点的最短路径//并且把该点加入已知最短路径的集合中
            {
                min=dis[j];
                t=j;        
            }
        }
        //把源点加入到已知最短路径点集合中（book=1）



        /*确定该源点到目标点的最短路径*/
        for(k=1;k<=n;k++)//需要知道新加入的源点是否可以通过(成为源点说明已经确定了1到其的最短路径)加上该点到其他路径长度比从源点直接到达短
        {
            if(e[t][k]<inf)//首先这个点必须是可以达到的
            {
                if(e[t][k]+dis[t]<dis[k])//如果比从源点直接到达短则替换（点k）
                    dis[k]=e[t][k]+dis[t];//dis[t]表示从1到达选定源点的距离,e[t][k]表示从源点到达目标点k的距离
                    //如果通过源点的转换使得1到k点的距离变短了则进行最短距离的替换
            }
        }
        book[t]=1;
    }
    for(i=1;i<=n;i++)
        printf("%d ",dis[i]);
    return 0;       
}
/*
6 9
1 2 1
1 3 12
2 3 9
2 4 3
3 5 5
4 3 4
4 5 13
4 6 15 
5 6 4
*/