#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include <stdbool.h>

bool isPalindrome(char * s)//默认返回整数值1/0A
{
    int n=strlen(s);
    for(int i=0;i<n;)
    {
        if(!isalnum(s[i]))//判断是字符或者十进制数字
        {
            i++;
            continue;
        }
        if(!isalnum(s[n]))
        {
            n--;
            continue;
        }
        if(tolower(s[i])!=tolower(s[n]))//不考虑大小写情况
            return false;
        i++;
        n--;
    }
    return true;
}
int main()
{
    char s[100];
    gets(s);
    if(isPalindrome(s)) printf("ture!\n");
    else printf("false!\n");
    return 0;
}
