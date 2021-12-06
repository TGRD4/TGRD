#include<stdio.h>
#define N 80
char *string_char(char*st,char c);
int main()
{
    char source[N];
    char dest=' ';
    char *position;
    printf("enter a string:");
    fgets(source,N,stdin);//从缓冲中读取N个字符作为source数组内容
    while(dest!=EOF)
    {
        printf("enter a char to find(EOF for Quit):");
        while((dest=getchar())=='\n') continue;
        if((position=string_char(source,dest))!=NULL)
            printf("found the char %c in the %p!\n",*position,position);
        else
            printf("char %c not found! try another?\n",dest);
    }
    return 0;
}

char *string_char(char*st,char c)
{
    while(*st!='\0')
    {
        if(*st==c)
            return st;
        else
            st++;
    }
    return NULL;
}