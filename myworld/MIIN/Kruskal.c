/*  Kruskal算法思想是先将所有结点边的权按照从小到大排序，从小到大连接路径，
同时判断下两个结点之间是否已经连通（是否在一个并查集里），若没有连通（不在同一个集合里），
则连通两个结点，直到连接了n-1条边后查找结束  */
#include<stdio.h>
#include<stdlib.h>
typedef struct edge//用结构体储存两个城市之间的距离
{
    int u;
    int v;//两个城市
    int w;//距离
}edge;
edge e[101];//存图
int f[101],n,m,sum,cnt;

/*并查集所用函数*/
void init(void);
int merge(int v,int u);
int catch(int v);
int cmp(const void*x,const void*y);

void init()
{
    for(int i=1;i<=n;i++)
        f[i]=i;
    return;
}
int catch(int v)
{
    if(f[v]==v) 
        return v;
    else
    {
        f[v]=catch(f[v]); 
        //若两个结点属于一个集合说明这两个结点可以连通
        return f[v];
    }
}
int merge(int v,int u)
{
    int t1,t2;
    t1=catch(v);
    t2=catch(u);
    if(t1!=t2)
    {
        f[t2]=t1;
        return 1;
    }
    return 0;//如果两条路径已经连通返回0
}

/*结构体排序（强制类型转换）*/
int cmp(const void*x,const void*y)
{
    edge *p1=(edge*)x;
    edge *p2=(edge*)y;
    return p1->w-p2->w;
}
int main()
{
    scanf("%d %d",&n,&m);//总城市数,总道路数
    for(int i=1;i<=m;i++)
        scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
    qsort((void*)e,m+1,sizeof(edge),cmp);//对路径长度进行排序(从1开始，长度要加1)
    init();//并查集初始化
    for(int i=1;i<=m;i++)//遍历每一条路径(前面qsort已经将最短路径依次放在最前面)
    {
        if(merge(e[i].u,e[i].v))//如果两条路径未连通,则找出最短路径(已排序)将两地相连
        {
            cnt++;//统计已连接的顶点数
            sum+=e[i].w;//统计总路程
        }
        if(cnt==n-1)//直到选用了n-1条边后(n个顶点全部连通需要n-1条边)退出
            break;
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
