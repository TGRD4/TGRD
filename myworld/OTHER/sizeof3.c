#include<stdio.h>
#include<string.h>
int main()
{
    char *c="abcdef";
    char d[]="abcdef";
    char e[]={'a','b','c','d','e','f'};
    printf("%d %d\n",sizeof(c),strlen(c));//8 6
    printf("%d %d\n",sizeof(d),strlen(d));//7 6
    printf("%d %d\n",sizeof(e),strlen(e));//6 (0,8,9,10,11,12)
    printf("char=%d\n",sizeof(char));  //1
    printf("int=%d\n",sizeof(int)); //4
    printf("char*=%d\n",sizeof(char*)); //8
    printf("int*=%d\n",sizeof(int*)); //8
    printf("long=%d\n",sizeof(long)); //8
    printf("long*=%d\n",sizeof(long*)); //8
    printf("double=%d\n",sizeof(double)); //8
    printf("double*=%d\n",sizeof(double*)); //8
    /*指针长度都是8*/
    return 0;
}