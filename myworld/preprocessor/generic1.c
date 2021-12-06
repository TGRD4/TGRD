#include<stdio.h>
/*  '/'将宏定义扩大到下一行  */
#define MYTYPE(X) _Generic((X),\ 
    int: "int",\
    float: "float",\
    double: "double",\
    default: "other"\
)
/*  X的类型匹配哪一个标签,整个表达式的值就是该标签后面的值  */

int main()
{
    int d=5;
    printf("%s\n",MYTYPE(d));//int 
    printf("%s\n",MYTYPE(2.0*d));//float
    printf("%s\n",MYTYPE(3L));//long int 
    printf("%s\n",MYTYPE(&d));//int*
    return 0;
}
