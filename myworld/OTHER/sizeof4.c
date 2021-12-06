/*
sizeof(数组名)：求取的是数组的整体大小
&数组名：求取的是数组的整体大小
其他情况均为数组首元素的地址
*/
#include <stdio.h>
#include <string.h>
int main()
{
    int a[] = {1,2,3,4};
    printf("%d ",sizeof(a));        //16  放的四个整型所以是4*4=16。
    printf("%d ",sizeof(a+0));      //8   第一个元素的地址。
    printf("%d ",sizeof(*a));       //4   第一个元素
    printf("%d ",sizeof(a+1));      //8   第二个元素的地址。
    printf("%d ",sizeof(a[1]));     //4   第二个元素。
    printf("%d ",sizeof(&a));       //8   数组的地址。
    printf("%d ",sizeof(&a+1));     //8   数组末尾再后面空间的地址。
    printf("%d ",sizeof(&a[0]));    //8   第一个元素的地址。
    printf("%d ",sizeof(&a[0]+1));  //8   第二个元素的地址。
    printf("%d\n\n",sizeof(*&a));   //16  &a取出来的是整个数组的地址，对数组的地址进行* 就成了整个数组了。

    int b[3][4] = {0};          
    printf("%d ",sizeof(b));        //48  整个二维数组的大小(3*4*4)=48
    printf("%d ",sizeof(b[0][0]));  //4   下标为a[0][0]的长度，也就是第一行第一个元素的大小
    printf("%d ",sizeof(b[0]));     //16  第1行的大小 第一行有四个每个又为整型 所以为16
    printf("%d ",sizeof(b[0]+1));   //8   第一行第二个元素的地址   
    printf("%d ",sizeof(b+1));      //8   第二行的地址   
    printf("%d ",sizeof(&b[0]+1));  //8   第1行的地址的长度
    printf("%d ",sizeof(*b));       //16  第0行的长度
    printf("%d\n\n",sizeof(b[3]));  //16  越界了但是还是会计算出第三行的长度。
    return 0;
}
