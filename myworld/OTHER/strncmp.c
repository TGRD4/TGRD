/*
头文件：#include <string.h>
strncmp() 用来比较两个字符串的前n个字符，区分大小写，其原型为：
    int strncmp ( const char * str1, const char * str2, size_t n );

【参数】str1, str2 为需要比较的两个字符串，n为要比较的字符的数目。

字符串大小的比较是以ASCII 码表上的顺序来决定，此顺序亦为字符的值。
strncmp()首先将s1 第一个字符值减去s2 第一个字符值，若差值为0 则再继续比较下个字符，直到字符结束标志'\0'，若差值不为0，则将差值返回。
例如字符串"Ac"和"ba"比较则会返回字符"A"(65)和'b'(98)的差值(-33)。

注意：要比较的字符包括字符串结束标志'\0'，而且一旦遇到'\0'就结束比较，无论n是多少，不再继续比较后边的字符。


【返回值】若str1与str2的前n个字符相同，则返回0；若s1大于s2，则返回大于0的值；若s1 若小于s2，则返回小于0的值。
注意：如果两个字符不同，GCC返回该字符对应的ASCII码的差值，VC返回-1或1。但是让人为难的是，strnicmp()、strcmp()、stricmp()在GCC和VC下都返回-1或1，而不是ASCII的差值。
*/
#include<stdio.h>
#include<string.h>
int main(void){
    char* s1 = "http://see.xidian.edu.cn/cpp/u/xitong/";
    char* s2 = "HTTP://see.xidian.edu.cn/cpp/u/xitong/";
    char* s3 = "abc";
    char* s4 = "abcxyz";
    char* s5 = "123456";
    char* s6 = "123";
    printf("s1-s2=%d\n", strncmp(s1, s2, 20));  // 是否区分大小写
    printf("s3-s4=%d\n", strncmp(s3, s4, 100));  // s3的长度小于s4
    printf("s5-s6=%d\n", strncmp(s5, s6, 100));  // s5的长度大于s6
    return 0;
}
/*
s1-s2=32
s3-s4=-120
s5-s6=52
*/