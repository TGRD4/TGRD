#include<stdio.h>
int i = 2;//非静态全局变量储存在静态区，作用域是整个源程序
void func()
{
    if(i != 0) 
    {
        //static修饰的静态局部变量仅在本文件中保留值(储存在静态区)
        static int m = 0;
        int n = 0;
        n++;
        m++;
        printf("m = %d, n = %d\n", m, n);
        i--;
        func();
    } 
    else 
        return;
}
int main(int argc, char *argv[]) 
{
    func();
    return 0;
}
/*m = 1, n = 1
  m = 2, n = 1*/