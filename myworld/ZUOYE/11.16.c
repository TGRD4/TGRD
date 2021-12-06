#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define N 200

void str(char*s);
void upper_str(char*s);
void lower_str(char*s);

int main(int argc,char*argv[])
{
    char c;
    if(argc<2)
        c='p';
    c=argv[1][1];//不可重定义
    char t[N];
    printf("enter a string:");
    fgets(t,N,stdin);
    switch(c)
    {
        case 'p':
        case 'P':str(t);break;//相当于一种情况
        case 'u':
        case 'U':upper_str(t);break;
        case 'L':
        case 'l':lower_str(t);break;
    }
    return 0;
}


void str(char*s)
{
    printf("str:%s\n",s);
}

void upper_str(char*s)
{
    while(*s!=EOF&&*s!='\0')
        putchar(toupper(*s++));
}

void lower_str(char*s)
{
     while(*s!=EOF&&*s!='\0')
        putchar(tolower(*s++));
}
