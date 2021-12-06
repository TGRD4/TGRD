#include<stdio.h>
#include<string.h>
int main(int argc, char *argv[]) 
{
    char str[1121];
    int key;
    char t;
    fgets(str, 1121, stdin);//从键盘获取标准输入读取1121个字符存储到数组str中，返回字符串中第一个字符的地址
    for(int i = 0; i < strlen(str) - 1; i++) //冒泡实现字典排序
    {
        key = i;
        for(int j = i + 1; j < strlen(str); j++) 
        {
            if(str[key] > str[j]) 
            {
                key = j;//key保留需要交换的字符的下标
            }
        }
        t = str[key];
        str[key] = str[i];
        str[i] = t;
    }
    puts(str);//输出排序后的结果
    return 0;
} 
/*
原型  char *  fgets(char * s, int n,FILE *stream);
    参数：
        s: 字符型指针，指向存储读入数据的缓冲区的地址。
        n: 从流中读入n-1个字符
        stream ： 指向读取的流。
*/
/*
fget() 函数中的 size 如果小于字符串的长度，那么字符串将会被截取；
如果 size 大于字符串的长度则多余的部分系统会自动用 ‘\0’ 填充。
所以假如你定义的字符数组长度为 n，那么 fgets() 中的 size 就指定为 n–1，留一个给 ‘\0’ 就行了。

但是需要注意的是，如果输入的字符串长度没有超过 n–1，那么系统会将最后输入的换行符 ‘\n’ 保存进来，
保存的位置是紧跟输入的字符，然后剩余的空间都用 ‘\0’ 填充。//
所以此时输出该字符串时 printf 中就不需要加换行符 ‘\n’ 了，因为字符串中已经有了。
*/

