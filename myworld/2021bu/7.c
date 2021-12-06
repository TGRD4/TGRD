#include<string.h>
#include<stdio.h>
int main(int argc, char *argv[]) 
{
    char str[] = "XiyouLinuxGroup";
    char *p = str;
    char x[] = "XiyouLinuxGroup\t\106F\bamily";
    printf("%zu %zu %zu %zu\n", sizeof(str), 
    sizeof(p),sizeof(x), strlen(x));//16 8 25 24
    return 0;
}/*str数组所占实际空间大小16字节(char占一个字节)，
指针p在64位下是8个字节大小，sizeof比strlen多一个\0结束符,
在x中\t \106(三位八进制) \b分别占一个字节，相当于char类型*/