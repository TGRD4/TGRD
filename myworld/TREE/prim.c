#include<stdio.h>
int main()
{
    int n,m,i,j,k,min,t1,t2,t3;
    int e[10][10]={0},book[10]={0},dis[10];
    int inf=0x3f3f3f3f;
    int cnt=0,sum=0;
    scanf("%d %d",&n,&m);

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(i!=j) e[i][j]=inf;//初始化图

    for(i=1;i<=m;i++)//m为边数
    {
        scanf("%d %d %d",&t1,&t2,&t3);
        e[t1][t2]=t3;
        e[t2][t1]=t3;//无向图
    }

    /*初始化dis数组*/
    for(i=1;i<=n;i++)//n为顶点数
        dis[i]=e[1][i];//此时生成树上只有1号顶点,所以初始化最短距离为所有点与1号顶点的距离
    book[1]=1;//将1号加到生成树
    cnt++;//顶点数加1

    /*prim核心*/
    while(cnt<n)
    {
        min=inf;
        for(i=1;i<=n;i++)
        {
            if(book[i]==0&&dis[i]<min)
            {
                min=dis[i];//保留最短路径
                j=i;//保留生成树新结点序号
            }
        }
        book[j]=1;//上树
        cnt++;
        sum+=dis[j];//加入总路径.

        for(k=1;k<=n;k++)
        {
            if(book[k]==0&&dis[k]>e[j][k])//dijkstra松弛
                dis[k]=e[j][k];//但不用加上原距离而是用新距离替换,因为生成树上多了新的顶点
                //dis记录的是生成树(任意一点)到各点的距离
        }
    }
    printf("sum = %d\n",sum);
    return 0;
}

/*
6 9
2 4 11
3 5 13
4 6 3
5 6 4
2 3 6
4 5 7
1 2 1
3 4 9
1 3 2
*/
