#include<stdio.h>
int main()
{
    puts(

    （char*)(int const[])
    {
        0X6F796958,0X6E694C75,0X72477875,
        0X3270756F,0X313230,0X00000A
    }//把十六进制数组转换为字符串输出

    );
}//XiyouLinuxGroup2021

/*
1.当不加int const[]时出现（initialization of ‘char *’ from ‘int’ makes pointer from integer without a cast）
出现这个警告的原因是在使用函数之前没有对函数进行声明，而未经声明的函数原型一律默认为返回int值。
这样就相当于你调用了返回值为int的函数，并将其赋给了char*变量，而puts内的参数又过多，所以会出现警告。
*/

/*
2.不加char*时出现（传递‘puts’的第 1 个参数时在不兼容的指针类型间转换），
提示：需要类型‘const char *’，但实参的类型为‘const int *’，extern int puts (const char *__s)

根本原因： 数组不是指针！
数组和指针是不同的。 数组是特定类型的一系列连续元素。 指针是一个小对象，它保存另一个对象的地址。
要使函数接受指向数组的指针(而不是指向指针的指针)。 
当你将一个数组传递给一个函数时，它将指向其第一个元素的指针。
而在二维数组的情况下，第一个元素是一个单维数组本身，所以你需要一个指向数组的指针而不是双指针。 
*/