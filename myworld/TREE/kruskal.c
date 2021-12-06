#include<stdio.h>
struct edge
{
    int u;
    int v;//两个城市
    int w;//路径
};
struct edge e[101];//存图
int f[101]={0},n,m,sum,cnt;


void init(void);
int merge(int v,int u);
void qsort(int left,int right);
int catch(int v);


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

/*从小到大排序以找到最短路径*/
void qsort(int left,int right)
{
    int i,j;
    struct edge t;//结构体暂存交换值
    if(left>right)
        return;
    i=left;
    j=right;

    while(i!=j)
    {
        while(e[j].w>=e[left].w&&i<j)//先从右往左找
            j--;
        while(e[i].w<=e[left].w&&i<j)//只比较结构体中的路径长度
            i++;
        if(i<j)
        {
            t=e[i];
            e[i]=e[j];
            e[j]=t;
        }
    }
    t=e[left];
    e[left]=e[i];
    e[i]=t;//最后交换的是整个结构体(包括两个城市名称)

    qsort(left,i-1);
    qsort(i+1,right);
    return ;
}

int main()
{
    scanf("%d %d",&n,&m);//总城市数,总道路数
    for(int i=1;i<=m;i++)
        scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
    qsort(1,m);//对路径长度进行排序
    init();
    for(int i=1;i<=m;i++)//遍历每一条路径
    {
        if(merge(e[i].u,e[i].v))//如果两条路径未连通,则找出最短路径(前面qsort已经将最短路径放在最前面)将两地相连
        {
            cnt++;
            sum+=e[i].w;
        }
        if(cnt==n-1)//直到选用了n-1条边后(全部连通)退出
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