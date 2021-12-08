/*炸弹人小游戏，给一张图，找出能到达的且消灭敌人数最多的敌人的点
在一个点放置炸弹，上下左右四个方向上的敌人都会被炸到，但炸弹炸不烂墙
'#'是墙，'G'是敌人，'.'是空地*/

#include<stdio.h>
char s[21][21];
int book[21][21];
int n,m,max,mx,my;//此处将sum设为全局变量可以不用getnum带回返回值(void getnum())
void dfs(int x,int y);
int getnum(int x,int y);//用于计算每个点的击杀数
int main()
{
    int i,sx,sy;
    scanf("%d %d %d %d",&n,&m,&sx,&sy);
    for(i=0;i<n;i++)
        scanf("%s",s[i]);
    book[sx][sy]=1;//标记当前坐标走过
    max=getnum(sx,sy);//初始化max为起始点的击杀数(可以省略)
    mx=sx;
    my=sy;//初始化mx,my坐标(可省)
    dfs(sx,sy);
    printf("[%d,%d] %d\n",mx,my,max);//输出消灭敌人最多的坐标和消灭敌人数
    return 0;
}
void dfs(int x,int y)
{
    int tx,ty,sum,k;
    int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}}; 
    sum=getnum(x,y);//计算当前坐标可以消灭敌人的数量
    if(sum>max)
    {
        max=sum;
        mx=x;
        my=y;//保留最大点的坐标等信息
    }
    for(k=0;k<4;k++)
    {
        tx=x+next[k][0];
        ty=y+next[k][1];
        if(tx<0||ty<0||tx>n-1||ty>m-1)//不超过边界(与之前题不一样因为这次输入的图从(0,0)开始)
            continue;
        if(book[tx][ty]==0&&s[tx][ty]=='.')//不能写s[tx][ty]!='#'因为不能在敌人身上放炸弹
        {
            book[tx][ty]=1;
            dfs(tx,ty);
            //这里无需再重置book[tx][ty]=0，因为不需要重复计算一个点的击杀数
        }
    }
    return;
}
int getnum(int x,int y)//计算每点击杀数
{
    int i,j,sum;
    sum=0;//每次计算前都将sum重置为0
    i=x;j=y;//不改变x,y的值用i,j代替
    while(s[i][j]!='#')//当遇到障碍物之前
    {
        if(s[i][j]=='G')//遇到敌人则击杀数加1
            sum++;
        i--;//向上走
    }
    i=x;j=y;
    while(s[i][j]!='#')
    {
        if(s[i][j]=='G')
            sum++;
        i++;//向下走
    }
    i=x;j=y;
    while(s[i][j]!='#')
    {
        if(s[i][j]=='G')
            sum++;
        j--;//向左走
    }
    i=x;j=y;
    while(s[i][j]!='#')
    {
        if(s[i][j]=='G')
            sum++;
        j++;//向右走
    }
    return sum;//返回此点的总击杀数
}

/*
13 13 3 3
#############
#GG.GGG#GGG.#
###.#G#G#G#G#
#.......#..G#
#G#.###.#G#G#
#GG.GGG.#.GG#
#G#.#G#.#.#.#
##G...G.....#
#G#.#G###.#G#
#...G#GGG.GG#
#G#.#G#G#.#G#
#GG.GGG#G.GG#
#############
*/