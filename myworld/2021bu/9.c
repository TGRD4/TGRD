#include<stdio.h>
int main()
{
    int a = 2020;
    unsigned long c;
    printf("%p\n", &a);//得到a的地址
    printf("我们想要修改的地址：");
    scanf("%lx", &c);//取a地址赋值给c（lx为长整型十六进制）
    printf("请随便输入一个数字：");
    scanf("%d", (int *)c);
/*输入一个整数在 被强制转换为指针类型c 所指向的地址中（就是&a，也是c），
而因为原本c就是a的地址（c=&a），相当于(int*)c指向a的地址并且赋值c，就是a=c*/
    printf("a = %d\n", a);
    return 0;
}