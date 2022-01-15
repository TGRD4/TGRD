/*
头文件：#include <string.h>

定义函数：char * strtok(char *s, const char *delim);

函数说明：strtok()用来将字符串分割成一个个片段。参数s 指向欲分割的字符串，参数delim 则为分割字符串，
当strtok()在参数s 的字符串中发现到参数delim 的分割字符时则会将该字符改为\0 字符。
在第一次调用时，strtok()必需给予参数s 字符串，往后的调用则将参数s 设置成NULL。
每次调用成功则返回下一个分割后的字符串指针。

返回值：返回下一个分割后的字符串指针，如果已无从分割则返回NULL。

*/
#include<string.h>
#include<stdio.h>
int main() {
    char s[] = "ab-cd : ef;gh :i-jkl;mnop;qrs-tu: vwx-y;z"; 
    char *delim = "-: ";
    char *p;
    printf("%s ", strtok(s, delim));
    while((p = strtok(NULL, delim))) {
        printf("%s ", p);
    }
    printf("\n");
    return 0;
}
/*
执行结果：
ab cd ef;gh i jkl;mnop;qrs tu vwx y;z     //－与:字符已经被\0 字符取代
*/