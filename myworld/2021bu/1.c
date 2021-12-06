#include<stdio.h>
int main(int argc,char*argv[])
{
    unsigned char a=255;
    char ch=128;
    a-=ch;
    printf("a=%d\nch=%d\n",a,ch);//127 -128
    return 0;
}
/*
unsigned char型范围是0～256
(signed) char 范围是-128~127
所以a=a-ch=255-128=127
(在进行运算的时候会把ch转换为整数进行计算所以它的值就是128不变，
而输出-128是在输出结果的时候进行了类型转换将他转换为了char类型)
而ch超出char型范围再从-127开始计数，超出一位相当于就是-127
*/