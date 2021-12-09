/*DFS  C题*/
#include<stdio.h>
struct bfs{
    int x;
    int y;//结构体记录当前操作点的横纵坐标
    int s;//和已扩展完的结点数
};
int main()
{
    int head,tail,flag=0;//flag用来标记是否能到达目标点
    int n,m,sx,sy,ex,ey,tx,ty;
    struct bfs que[2501];//对于整张迷宫的队列扩展（结点数不超过50*50=2500）
    int book[51][51]={0},s[51][51];
    int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&s[i][j]);
    scanf("%d %d %d %d",&sx,&sy,&ex,&ey);

    //初始化队列
    head=1,tail=1;//刚开始时没有点入队所以队首等于队尾
    que[tail].x=sx;
    que[tail].y=sy;//待扩展的点（起始点）入队
    que[tail].s=0;//刚开始无一个点被扩展（步数为0）
    tail++;//准备让下一个满足要求扩展点入队，tail标记队尾（最后一位）的下一个位置
    book[sx][sy]=1;//标记起始点为走过

    while(head<tail)//当存在可扩展的点时（队列不为空的时候）一直进行扩展
    {
        for(int k=0;k<4;k++)
        {
            tx=que[head].x+next[k][0];
            ty=que[head].y+next[k][1];//向四个方向分别进行扩展
            if(tx>n||ty>m||ty<1||tx<1)//判断越界
                continue;
            if(s[tx][ty]==0&&book[tx][ty]==0)
            {
                book[tx][ty]=1;
                que[tail].x=tx;
                que[tail].y=ty;//被扩展的点入队作为待扩展的点
                que[tail].s=que[head].s+1;//步数+1
                tail++;//准备让下一个满足要求的点入队
            }
            /*和dfs很相似，但此处不同于bfs不用返回去寻找未被遍历的点
            (对每个点进行扩展的时候就已经把满足要求的所有点都入队了)*/

            if(tx==ex&&ty==ey)//如果到达目的地
            {
                flag=1;//标记路径存在
                break;
            }
        }
        if(flag==1)//如果路径存在则退出输出长度
            break;
        head++;//head++让已扩展完的点出队，要不队列不可能为空而造成无限循环
    }
    printf("%d",que[tail-1].s);//tail是指队尾的下一个位置，所以要-1
    return 0;
}
/*
5 4
0 0 1 0
0 0 0 0
0 0 1 0
0 1 0 0
0 0 0 1
1 1 4 3
*/
