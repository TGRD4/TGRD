#include<limits.h>
#include<stdio.h>
_Static_assert(CHAR_BIT==8,"8-bit char falsely assumed");//第一个表达式为假(0)则执行第二个表达式
/*静态断言(被视为声明)是在程序执行前就判断,若不满足则直接不通过编译(编译期就求值从而提高效率)*/
int main()
{
    puts("char is 8 bits.");//正确
    return 0;
}