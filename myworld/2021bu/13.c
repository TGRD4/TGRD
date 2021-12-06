#include<stdio.h>
#include<string.h>
int a[1001][1001];/*二维数组第一维记录第几个数 
                    第二维记录这一个数的位数*/
int main()
{
    int m,i,k,c,l;
    scanf("%d",&m);
    while(m>0)//输入非正整数退出
    {
        l=1;
        a[1][0]=1;a[2][0]=1;
        for(i=3;i<=m;i++)
        {
            for(k=0,c=0;k<l;k++)
            {
                a[i][k]=a[i-1][k]+a[i-2][k]+c;
                c=a[i][k]/10;
                a[i][k]%=10;
            }
            while(c>0)
            {
                a[i][k++]=c%10;
                c=c/10;
            }
            l=k;//k记录总位数
        }
        for(i=l-1;i>=0;i--)
            printf("%d",a[m][i]);
        printf("\n");
        scanf("%d",&m);
    }
    return 0;
}