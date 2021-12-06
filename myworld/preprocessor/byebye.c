#include<stdio.h>
#include<stdlib.h>
void sign_off(void);
void too_bad(void);

int main()
{
    int n;
    /*sign_off作为参数*/
    atexit(sign_off);//注册sign_off函数(在退出调用它的函数前输出)
    puts("enter a integer:");
    if(scanf("%d",&n)!=1)
    {
        printf("that's not a integer!\n");
        atexit(too_bad);//不是数字先执行too_bad再执行sign_off(exit(退出函数)之前)
        exit(EXIT_FAILURE);//当调用exit函数时执行atexit中注册的函数(最先注册的函数最后执行)
    }
    printf("%d is %s.\n",n,(n%2==0)?"even":"odd");
    return 0;
}

void sign_off(void)
{
    puts("sign_off done!");//puts自动换行
}

void too_bad(void)
{
    puts("too_bad done!");
}