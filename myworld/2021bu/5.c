#include<stdio.h>
int main(int argc, char *argv[]) 
{
    int a[2][2];
    int b[2][2];
    printf("  &a = %p\t  &a[0] = %p\t  &a[0][0] = %p\n", 
            &a, &a[0],&a[0][0]);
    printf("&a+1 = %p\t&a[0]+1 = %p\t&a[0][0]+1 = %p\n", 
            &a+1,&a[0]+1, &a[0][0]+1);
    printf("  &b = %p\t  &a[1] = %p\t  &a[0][1] = %p\n",
            &b,&a[1],&a[0][1]);//此行与上行相等证明结论正确
    return 0;
}/*&a = 0x7fffffffdbd0    &a[0] = 0x7fffffffdbd0    &a[0][0] = 0x7fffffffdbd0
 &a+1 = 0x7fffffffdbe0  &a[0]+1 = 0x7fffffffdbd8  &a[0][0]+1 = 0x7fffffffdbd4
   &b = 0x7fffffffdbe0    &a[1] = 0x7fffffffdbd8    &a[0][1] = 0x7fffffffdbd4*/
/*  
&a，&a[0]，&a[0][0]地址都相同，但是&a表示整个数组的地址，&a[0]表示数组第一行的地址，&a[0][0]表示第一行第一列的地址（也就是首元素的地址）
&a+1表示整个数组的地址加上2*2*int（一个数组）类型大小的地址（相当于&b）
&a[0]+1表示第一行地址加上一个2*int（一行）类型大小的地址（相当于&a[1]）
&a[0][0]+1表示首元素地址加上一个int类型的大小的地址（相当于&a[0][1]）
*/
