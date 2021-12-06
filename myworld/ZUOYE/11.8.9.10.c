#include<stdio.h>
#include<string.h>
#define N 80
char *string_in(char*st,char*s);
char *invert_st(char*st);
int main()
{
    char str[N],sub[N];//下标
    char *p=NULL;
    printf("enter a string as main string:");
    fgets(str,N,stdin);
    printf("enter a sub:");
    fgets(sub,N,stdin);
    while(*str!='\n')
    {
        p=string_in(str,sub);
        printf("the position is %p\n",p);
        printf("try again? enter a string as main string:");
        fgets(str,N,stdin);
        printf("enter a sub:");
        fgets(sub,N,stdin);
    }
    return 0;
}

/*.8*/
char *string_in(char*st,char*s)
{
    int cnt=0;
    int len=strlen(s);
    while(*st!='\0'&&cnt<len)
    {
        if(*(st+cnt)==*(s+cnt))
            cnt++;
        else 
        {
            cnt=0;
            st++;
        }
    }
    if(cnt==len) return st;
    else return NULL;
}

/*.9*/
char *invert_st(char*st)
{
    int len=strlen(st);
    char invert[len];//临时存储区
    for(int i=0;i<len;i++)
        *(invert+i)=*(st+len-1-i);
    for(int i=0;i<len;i++)
        *(st+i)=*(invert+i);//覆盖原函数
    return st;
}

/*10*/
char*str(char*st)
{
    char*head=st;
    int cnt=0;
    while(*st!='\0')
    {
        if(*st!=' ')
            *head++=*st++;
        else{
            cnt++;
            st++;
        }
    }
    while(cnt--) *head++='\0';
    return st;
}