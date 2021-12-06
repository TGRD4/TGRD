#include<stdio.h>
int n,m,sum,s[1001];
void init(void);
void merge(int x,int y);
int catchs(int v);
int main()
{
    int i,x,y;
    scanf("%d %d",&n,&m);
    init();
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&x,&y);
        merge(x,y);
    }
    for(i=1;i<=n;i++)
    {
        if(s[i]==i)
            sum++;
    }
    printf("sum=%d\n",sum);
    return 0;
}
void init(void)
{
    for(int i=1;i<=n;i++)
        s[i]=i;//初始化使每个数组中的数都是自己的下标
    return;
}
int catchs(int v)
{
    if(s[v]==v)
        return v;
    else
    {
        s[v]=catchs(s[v]);//递归找首
        return s[v];
    }
}
void merge(int x,int y)
{
    int t1,t2;
    t1=catchs(x);
    t2=catchs(y);//用两个待查集的首进行一个并
    if(t1!=t2)
    {
        s[t2]=t1;
    }
    return;
}
/*
11 10
1 2
3 4
5 2
4 6
2 6
7 11
8 7
9 7
9 11
1 6
*/