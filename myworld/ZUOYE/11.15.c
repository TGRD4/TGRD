#include<stdio.h>
#include<ctype.h>
#include<string.h>

int Atoi(char *s);
int main(int argc,char*argv[])
{
    char s[101];
    printf("enter a int :");
    scanf("%s",s);
    printf("%d\n",Atoi(s));
    return 0;
}

int Atoi(char*s)
{
    int oc=0;
    int flag=1;
    int len=strlen(s);
    for(int i=len;i>0;i--)
    {
        if(isdigit(*(s+i-1))==0)
        {
            printf("error!\n");
            return 0;
        }
        oc+=(*(s+i-1)-'0')*flag;
        flag*=10;
    }
    return oc;
}