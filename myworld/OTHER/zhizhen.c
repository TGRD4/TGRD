#include<stdio.h>
#include<string.h>
int main()
{
    char* ss = "0123456789"; 
    printf("sizeof=%d\n",sizeof(ss));//返回指针大小8(64位)
    printf("sizeof=%d\n",sizeof(*ss));//sizeof获得的是首元素所占的空间1
    printf("strlen=%d\n",strlen(ss));//10
    /*printf("strlen=%d\n",strlen(*ss));/*传递指向数组首元素的指针，编译器不知道数组的实际大小*/
    return 0;
}