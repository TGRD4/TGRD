/*
压缩技术：https://www.luogu.com.cn/problem/P1320
*/
#include <stdio.h>
#include <string.h>
int main()
{
    int i,len,num,sum;
    char text[40001],str[201];
    scanf("%s",str);//先读入一行字符串以计算出总行数
    len=strlen(str);
    strcat(text,str);//将第一行字符串放入暂时数组text中
    for(i=2;i<=len;i++)
    {
        scanf("%s",str);
        strcat(text,str);//将之后的n-1行都连接到第一行后面，将全部n行字符串看作一个整体，方便计算
    }
    printf("%d",len);//第一个字符串的长度就是总行数
    for(i=0,sum=0,num='0';i<=strlen(text);i++)//设刚开始目标字符为'0'
    {
        if(num==text[i])//当前字符与目标字符相等则+1
            sum++;
        else//若与目标字符不同
        {
            printf(" %d",sum);//输出0/1的总数后
            num=text[i];//改变目标字符为当前字符
            sum=1;//重置当前找到的连续目标字符总数
        }
    }
    return 0;
}