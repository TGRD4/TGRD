#include<stdio.h>
int sum;
int main()
{
    int n,m=0,cnt=0;
    scanf("%d",&n);
    int s[n+1];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
        m+=s[i];//总质量
    }
    if(m%2!=0)
    {
        printf("no!\n");//单数必不能均分
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        sum+=s[i];
        if(sum==m/2)//若找到总质量为一半的蛋糕数直接退出
        {
            printf("ok!\n");
            return 0;
        }
/*因为此题说的是质量不相同的蛋糕，所以(sum>m/2)时只用回溯一位就可以，若是质量有重复的蛋糕就不一定只回溯一位*/
        else if(sum>m/2)//若总质量数大于一半则回退一个蛋糕数再从下一个寻找
        {
            sum-=s[i];
        }
        else//若总质量数不够一半则继续找
        {
            continue;
        }
    }
    printf("no!\n");//若循环结束还未找到质量为一半的组合则说明不存在这样的组合
    return 0;
}