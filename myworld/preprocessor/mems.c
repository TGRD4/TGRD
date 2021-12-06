#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 10
void showarray(const int s[],int n);
int main()
{
    int value[N]={1,2,3,4,5,6,7,8,9,10};
    int target[N];
    double curious[N/2]={2.0,2.0e5,2.0e10,2.0e20,5.0e30};

    puts("values(origin data):");
    showarray(value,N);
    memcpy(target,value,N*sizeof(int));//copy value中所有元素到target(无重叠范围)
    puts("target(copy of values):");
    showarray(target,N);

    puts("\nusing memmove() withg overlapping ranges:");//在memmove中使用重叠范围
    memmove(value+2,value,5*sizeof(int));
    puts("values--elements 0-4 copied to 2-6:");//value中0-4的数copy到2-6的位置(因为地址重合所以覆盖)
    showarray(value,N);

    puts("\nusing memcpy() to copy doubel to int:");//将double类型的数组元素copy到int类型的数组中
    memcpy(target,curious,(N/2)*sizeof(double));
    /*memcpy不关心数据类型,只负责从一个位置把一些字节copy到另一个位置(并且copy过程不会进行数据类型转化),
    若循环赋值则进行类型转换*/

    puts("target--5 doubles into 10 int positions:");
    showarray(target,N/2);
    showarray(target+5,N/2);

    return 0;
}

void showarray(const int s[],int n)
{
    for(int i=0;i<n;i++)
        printf("%d ",s[i]);//转换后的输出都是int类型
    putchar('\n');
}