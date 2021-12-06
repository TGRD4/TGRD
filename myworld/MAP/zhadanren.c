#include<stdio.h>
struct node
{
    int x;
    int y;
};

char s[21][21];
int getnum(int i,int j)
{
    int sum,x,y;
    sum=0;
    x=i,y=j;
    while(s[x][y]!='#')
    {
        if(s[x][y]=='G')
        {
            sum++;
        }
        x++;
    }
    x=i,y=j;
    while(s[x][y]!='#')
    {
        if(s[x][y]=='G')
        {
            sum++;
        }
        y++;
    }
    x=i,y=j;
    while(s[x][y]!='#')
    {
        if(s[x][y]=='G')
        {
            sum++;
        }
        x--;
    }
    x=i,y=j;
    while(s[x][y]!='#')
    {
        if(s[x][y]=='G')
        {
            sum++;
        }
        y--;
    }
    return sum;
}

int main()
{
    struct node que[401];
    int sum;
    int book[21][21]={0};
    int k,mx,my,tx,ty;
    int sx,sy,head=1,tail=1;
    int n,m,max,i;
    int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    scanf("%d %d %d %d",&n,&m,&sx,&sy);
    for(i=0;i<n;i++)
    {
        scanf("%s",s[i]);
    }
    que[tail].x=sx;
    que[tail].y=sy;
    tail++;
    book[sx][sy]=1;
    mx=sx;
    my=sy;
    max=getnum(sx,sy);
    while(head<tail)
    {
        for(k=0;k<=3;k++)
        {
            tx=que[head].x+next[k][0];
            ty=que[head].y+next[k][1];
            if(tx>n-1||ty>m-1||tx<0||ty<0)
                    continue;
            if((s[tx][ty]=='.')&&(book[tx][ty]==0))
            {
                book[tx][ty]=1;
                que[tail].x=tx;
                que[tail].y=ty;
                tail++;
            }
            sum=getnum(tx,ty);
            if(sum>max)
            {
                max=sum;
                mx=tx;
                my=ty;
            }
        }
        head++;
    }
    printf("[%d,%d] %d\n",mx,my,max);
    return 0;
}
