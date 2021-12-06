#include<stdio.h>
#include<stdlib.h>
#define N 1121
int* get_array() 
{
    int*array=(int*)malloc(sizeof(int)*N);//在内存中分配一段空间并让指针array指向它
    //此处用另一个指针指向这个指针使两个指针都指向同一位置从而保存此段内存空间的地址
    int*t=array;
    for (int i = 0; i < sizeof(int)*N / sizeof(int); i++,array++) 
    {
        *array = i;/*利用指针在空间中的移动来改变原本储存在这段空间的值
        （若没有用将新分配的内存空间中的值置为0(memset)则其中存储的都是不确定的值）
        也可以使用calloc在分配内存的时候就初始化为0*/
    }
    return t;//原此处显示错误为：函数返回局部变量的地址
}/*该函数原意是想返回指向数组array的指针从而输出array数组中的值
但是array在函数作用完后会自动释放内存从而带不回返回值
（找不到此数组的地址），从而使p成为野指针*/
int main(int argc, char *argv[]) 
{
    int *p = get_array();
    for(int i=0;i<N;i++,p++)//指针在内存空间上移动以输出
        printf("%d ",*p);//修改后输出结果为0～1120
    putchar('\n');
    return 0;
}