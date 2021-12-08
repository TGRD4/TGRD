/*再来一道类似的题目：用九张牌1～9组成xxx+xxx=xxx的组合，每种牌只有一张。*/
/*与第一题相比：满足输出条件的要求不一样，牌和箱子数不一样*/

#include<stdio.h>
int s[10],book[10],sum;
void dfs(int step);
int main()
{
    dfs(1);
    printf("\nsum=%d\n",sum/2);/*输出所有满足条件的组合，
    需要除以2是因为没有规定被加数一定比加数小而造成输出重复*/
    return 0;
}
void dfs(int step)
{
    int i;
    if(step>9)//一共九张牌
    {
        if(s[1]*100+s[2]*10+s[3]+s[4]*100+s[5]*10+s[6]==s[7]*100+s[8]*10+s[9])//新增一个返回条件
        {
            sum++;//记录组合数
            printf("%d%d%d + %d%d%d = %d%d%d\n",s[1],s[2],s[3],s[4],s[5],s[6],s[7],s[8],s[9]);
            return;
        }
    }
    for(int i=1;i<=9;i++)
    {
        if(book[i]==0)
        {
            s[step]=i;
            book[i]=1;
            dfs(step+1);
            book[i]=0;
        }
    }
    return;
}
