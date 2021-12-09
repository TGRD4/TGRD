/*最少转机问题，求从起始城市到目标城市之间的最少转机数（不考虑时间和路径）：
5 7 1 5//城市总数，路径数，起始城市，目标城市
1 2//注意此处是双向图，表示从1号城市和二号城市之间可以互相到达
1 3 
2 3
2 4
3 4
3 5
4 5
同样使用邻接矩阵表示（注意是双向到达），这里可以相通的两个城市间的距离都用1表示：
*///bfs
#include<stdio.h>
struct bfs{
    int x;//当前城市编号
    int s;//当前转机次数
};
int main()
{
    struct bfs que[2501];
    int e[51][51]={0},book[51]={0};
    int head,tail;
    int n,m,a,b,cur,start,end,flag=0;
    scanf("%d %d %d %d",&n,&m,&start,&end);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j) e[i][j]=0x3f3f3f3f;
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        e[a][b]=1;
        e[b][a]=1;//创建无向图
    }
    //初始化队列
    head=1,tail=1;
    que[tail].x=start;
    que[tail].s=0;
    tail++;
    book[start]=1;

    while(head<tail)
    {
        cur=que[head].x;//cur表示当前城市
        for(int i=1;i<=n;i++)//扩展与当前城市连通的所有城市
        {
            if(e[cur][i]!=0x3f3f3f3f&&book[i]==0)
            {
                que[tail].x=i;//将满足条件的城市入队
                que[tail].s=que[head].s+1;//转机次数+1
                tail++;
                book[i]=1;
            }
            if(que[tail-1].x==end)//找到通向目标城市的路径
            {
                flag=1;
                break;
            }
        }
        if(flag)
            break;
        head++;//已扩展完的城市出队
    }
    printf("%d\n",que[tail-1].s);//输出最少转机次数
    return 0;
}
/*
5 7 1 5
1 2 
1 3 
2 3
2 4
3 4
3 5
4 5
*/