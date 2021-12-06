#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char * reverseWords(char * s)
{
    int len = strlen(s);                                 //字符串长度
    int top = 0;                                         //栈顶指针
    int n = 0;
    if(len == 0)                                         //字符串为空
        return s;
    char *res = (char*)malloc(sizeof(char) * (len + 1)); //为输出数组分配空间
    res[len] = '\0';
    char *stack =(char*)malloc(sizeof(char) * (len + 1));//为栈分配空间
    for(int i=len-1; i >= 0; i--){                       //遍历字符串
        while(i >= 0 && s[i] == ' '){                    //遇到空格跳过
            i--;
        }
        while(i >= 0 && s[i] != ' '){                    //将字符串压入栈
            stack[top] = s[i];
            top++;
            i--;
        }
        while(top > 0){                                  //从栈中取出字符
            res[n] = stack[top-1];
            top--;
            n++;
        }
        res[n] = ' ';                                    //每个单词间隔一个空格
        n++;
    }
    n--;
    while(n >= 0 && res[n] == ' ')                  //输出字符串末尾会有空格，循环去除
        n--;
    res[n+1] = '\0';                                     //输出字符串结束
    return res;
}
int main()
{
    char s[101];
    gets(s);
    printf("%s\n",reverseWords(s));
    return 0;
}