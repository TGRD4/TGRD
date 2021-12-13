/*并查集用于寻找若干个数据是否属于一个集合，
这里将数据作为每个山贼，每个山贼一开始都是各自为战（相当于自己是自己的老大），
现在给出若干个两个山贼之间的从属关系，判断这些山贼一共属于几个大集团（一个集团只有一个大boss）
这里规定给出的两个山贼之间的关系是第二个山贼归属于第一个山贼*/

#include<stdio.h>
int f[1001]={0},n,m,sum;
/*数组初始化*/
void init()
{
    for(int i=1;i<=n;i++)
        f[i]=i;//刚开始每个人都是自己的boss
    return;
}

/*擒贼先擒王*/
int catch(int v)
{
    if(f[v]==v) //找到boss
        return v;
    else
    {
        /*此处是路径压缩,将每级递归返回时路上的人都改为boss的直属手下（提高查找效率）*/
        f[v]=catch(f[v]);//递归一直找到最高领导人
        return f[v];
    }
}

/*合并两个个体*/
void merge(int v,int u)
{
    int t1,t2;
    t1=catch(v);
    t2=catch(u);//分别找出两个个体的boss才能进行交谈
    if(t1!=t2)//如果两个个体不是同一个boss(不在一个集团)
        f[t2]=t1;//t2合并到t1中(靠左原则)
    return;
}

int main()
{
    int x,y;
    scanf("%d %d",&n,&m);//总人数和总关系数
    init();//必须初始化（确定初始每个人的从属情况）
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d",&x,&y);
        merge(x,y);//合并所有人之间的关系
    }
    for(int i=1;i<=n;i++)//找出总集团数(遍历所有人n查看其boss情况)
    {
        if(f[i]==i)//就是找一共有多少个boss
            sum++;
    }
    printf("sum = %d\n",sum);
    return 0;
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
