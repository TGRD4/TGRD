#include<string.h>
int strStr(char * haystack, char * needle)
{
    int i,j;
    if(!(strlen(needle)))
        return 0;
    for(i=0;i<strlen(haystack)-strlen(needle);i++)
    {
        for(j=0;j<strlen(needle);j++)
        {
            if(haystack[i+j]!=needle[j])
                break;
        }
        if(j==strlen(needle)) return i;//返回needle第一次在haystack中出现的位置
    }
    return -1;
}
