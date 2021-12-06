#include<stdio.h>
void why_me();
int main()
{
    printf("the file is %s.\n",__FILE__);//当前源代码文件名
    printf("the data is %s.\n",__DATE__);//当前日期
    printf("the time is %s.\n",__TIME__);//当前时间
    printf("the stdc is %d.\n",__STDC__);//C编译器通常用这个宏的值来表示编译器的实现是否和C标准一致(1)，C++11标准中这个宏是否定义以及定成什么值由编译器来决定
    printf("the hosted is %d.\n",__STDC_HOSTED__);//如果编译器的目标系统环境中包含完整的标准C库，那么这个宏就定义为1，否则宏的值为0
    printf("the version is %ld.\n",__STDC_VERSION__);//支持标准(201710=c18标准)
    printf("this is line %d.\n",__LINE__);//当前行数
    printf("this function is %s.\n",__func__);//当前函数作用(名字)
    why_me();
    return 0;
}
void why_me()
{
    printf("this function is %s.\n",__func__);
    printf("this is line %d.\n",__LINE__);
}