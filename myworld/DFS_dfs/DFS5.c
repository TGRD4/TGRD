/*给出一张小岛的地图，从降落点开始，计算小岛总面积，0代表海洋，
其余数字都代表小岛，且每一个数字都代表面积加1*/

#include<stdio.h>
int book[51][51],s[51][51];
int n,m,sum;
void dfs(int x,int y);
int main()
{
    int i,j,sx,sy;
    scanf("%d %d %d %d",&n,&m,&sx,&sy);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&s[i][j]);
    book[sx][sy]=1;
    sum=1;//标记降落点(一定是陆地)走过且面积+1
    dfs(sx,sy);
    printf("%d\n",sum);
    return 0;
}
void dfs(int x,int y)
{
    int tx,ty,k;
    int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}}; 
    for(k=0;k<4;k++)
    {
        tx=x+next[k][0];
        ty=y+next[k][1];
        if(tx<0||ty<0||tx>n-1||ty>m-1)
            continue;
        if(book[tx][ty]==0&&s[tx][ty]!=0)
        {
            sum++;
            book[tx][ty]=1;
            dfs(tx,ty);
            //此处也不用返回因为面积也是每一步都计算的
        }
    }
    return;
}

/*
10 10 6 8
1 2 1 0 0 0 0 0 2 3
3 0 2 0 1 2 1 0 1 2
4 0 1 0 1 2 3 2 0 1
3 2 0 0 0 1 2 4 0 0
0 0 0 0 0 0 1 5 3 0
0 1 2 1 0 1 5 4 3 0
0 1 2 3 1 3 6 2 1 0
0 0 3 4 8 9 7 5 0 0
0 0 0 3 7 8 6 0 1 2
0 0 0 0 0 0 0 0 1 0
*/