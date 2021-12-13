/*Floyd-Warshall算法用于寻找任意两点之间的最短路径*/
#include<stdio.h>
#define MAX 0x3f3f3f3f//无穷
#define N 101
int main()
{
    int  e[N][N]={0},n,m,a,b,c;
    scanf("%d %d",&n,&m);
    /*初始化图*/
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j) e[i][j]=MAX;
    /*初始化网*/
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d %d",&a,&b,&c);//图加带权(c)边=网
        e[a][b]=c;//有向网
    }

    /*核心算法（三个循环(O3)）*/
    for(int k=1;k<=n;k++)//将每个顶点都作为中转点(k)进行松弛
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(e[i][j]>e[i][k]+e[k][j])
                /*若从先从i到k的距离加上再从k->j的距离小于从i直接到j的距离(s)，
                那么就对这条边松弛，则(s)i->j = (s)i->k + (s)k->j */
                    e[i][j]=e[i][k]+e[k][j];
    putchar('\n'),putchar('\n');
    for(int i=1;i<=n;i++)//输出存放最短距离的邻接矩阵
    {
        for(int j=1;j<=n;j++)
            printf("%d ",e[i][j]);
        putchar('\n');
    }
    return 0;
}
/*
4 8
1 2 2
1 3 6
1 4 4
2 3 3
3 1 7
3 4 1
4 1 5
4 3 12
*/
