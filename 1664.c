/*
每日打卡心情好：https://www.luogu.com.cn/problem/P1664
*/
#include<stdio.h>
#include<math.h>
int main()
{
    int n,t=0,a,d=0,m=0;//n天  t分数  a是否打卡  d是累计天数  m是累计未打卡天数
    scanf("%d",&n);
    for(int i=0;i<n;i++)//查看每一天的打卡情况
    {
        scanf("%d",&a);//输入有没有打卡
        if(a==1)
        {
            if(m>0) d-=pow(2,m-1);       //减去未打卡的天数
            if(d<0) d=0;                 //如果小于0就回到0
            m=0,d++,t++;                 //未打卡天数清0，打卡天数+1，积分+1
            if(d>=3) t++;                //如果打开天数超过3，积分额外+1
            if(d>=7) t++;                //如果打开天数超过7，积分额外+1
            if(d>=30) t++;               //如果打开天数超过30，积分额外+1
            if(d>=120) t++;              //以此类推
            if(d>=365) t++;
        }
        else m++;//如果未打卡，m++
    }
    printf("%d",t);
    return 0;
}