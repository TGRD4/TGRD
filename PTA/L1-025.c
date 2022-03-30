#include<stdio.h>
#include<string.h>
int main()
{
    char s1[1001]={};
    char s2[1001]={};
    scanf("%s",&s1);
    gets(s2);    //因为两个字符串输出在同一行，所以使用gets来接受空格(相当于s2[0]==' ')
    int flag1=1;
    int flag2=1;
    int x=1;
    int sum1=0;
    int sum2=0;
    for(int i=strlen(s1)-1;i>=0;i--) {
        if(s1[i]-'0'<=9&&s1[i]-'0'>=0) {
            sum1+=(s1[i]-'0')*x;
            x*=10;
            if(sum1>1000||s1[0]-'0'==0) {//注意题目所给范围
                flag1=0;
            }
        }
        else {
            flag1=0;
        }
    }
    x=1;//重置x=1;
    for(int j=strlen(s2)-1;j>=1;j--) {//注意MIN(j)=1
        if(s2[j]-'0'<=9&&s2[j]-'0'>=0) {
            sum2+=(s2[j]-'0')*x;
            x*=10;
            if(sum2>1000||s2[1]-'0'==0) {//注意s2[1]不是s2[0]!
                flag2=0;
            }
        }
        else {
            flag2=0;
        }
    }
	if (flag1&&flag2)
		printf("%d + %d = %d",sum1,sum2,sum1+sum2);
	else if (flag1)
		printf("%d + ? = ?",sum1);
	else if (flag2)
		printf("? + %d = ?",sum2);
	else
		printf("? + ? = ?");
    return 0;
}