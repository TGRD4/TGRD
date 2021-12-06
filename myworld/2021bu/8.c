#include<stdio.h>
int add(int *x, int y) 
{
    return *x = (*x^y) + ((*x&y)<<1);//^或运算，&与运算，<<补码右移
    //每进函数一次a+1，b+1
}
int a;//全局变量初始化为0
int main(int argc, char *argv[]) 
{
    int b = 2020;
    if(add(&b, 1) || add(&a, 1))//进入
    {
        printf("XiyouLinuxGroup%d\n", b);
        printf("Waiting for y%du!\n", a);
        //printf("b=%d\n",b);//2021
        //printf("a=%d\n",a);//0
/*此处a=0说明add(&a,1)并没有被执行，在逻辑或时若满足第一个表达式
计算机则直接退出逻辑或并返回真值，而不会继续判断第二个条件，这样会提高计算机的运算效率*/
    }
    if(add(&b, 1) && a++)//逻辑和时add(&b,1)和a++都被执行
    //此处不会是进入因为a++表达式是先将a进行一次运算后再加1，在进行逻辑和的时候a还是0
    {
        printf("XiyouLinuxGroup%d\n", b);
        printf("Waiting for y%du!\n", a);
    }
    //printf("b=%d\n",b);//2022
    //printf("a=%d\n",a);//此处再输出a的值就是1
    return 0;
}
/*XiyouLinuxGroup2021
Waiting for y0u!*/