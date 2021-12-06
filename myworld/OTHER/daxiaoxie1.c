#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define N 44
char *convert(const char *s);
int main()
{
    char *str="XiyouLinux Group 2022";
    char *temp=convert(str);
    puts(temp);
    return 0;
}
char *convert(const char *s)
{
    char *k=(char*)malloc(N);
    char *t=s;
    char *q=k;//再用一个指针保留新分配的内存地址
    memset(k,0,N);
    for(;*s!='\0';*s++,k++)//通过指针的移动将数据储存在新地址上
    {
        if(*s>='a'&&*s<='z')
            *k=toupper(*s);
        else if(*s>='A'&&*s<='Z')
            *k=tolower(*s);
        else
            *k=*s;
    }
    t=q;//让原指向s的指针指向新地址
    return t;
}
//gcc -E daxiaoxie1.c -o daxiaoxie1.i//预编译后停下来，生成后缀为 .i 的预编译文件。
//gcc -c daxiaoxie1.c -o daxiaoxie1.o//编译后停下来，生成后缀为 .o 的目标文件。
//gcc -S daxiaoxie1.c -o daxiaoxie1.s//汇编后停下来，生成后缀为 .s 的汇编源文件。
//gcc daxiaoxie1.c -o daxiaoxie1//将生成的目标文件链接成可执行文件
//gcc daxiaoxie1.c -o daxiaoxie1 -save-temps//生成.i.o.s文件