#include<stdio.h>
#include<ctype.h>
#define N 200
int words(char *s);
int upper(char *s);
int lower(char *s);
int punct(char *s);
int number(char*s);

int main(int argc,char *argv[])
{
    int s[N];
    int i=0;
    while((s[i++]=getchar())!=EOF)
    {
        if(i>=N)
        {
            printf("overflow!\n");
            break;
        }
    }
    printf("words:%d\n",words(s));
    printf("upper:%d\n",upper(s));
    printf("lower:%d\n",lower(s));
    printf("punct:%d\n",punct(s));
    printf("number:%d\n",number(s));
    return 0;
}

int words(char *s)
{
    int cnt=0;
    int start=0;
    while(*s!=EOF)
    {
        if(isalpha(*s)==0&&start==0)
            s++;
        else if(isalpha(*s)==0&&start==1)
        {
            s++;
            cnt++;
            start=0;
        }
        else if(isalpha(*s)!=0)
        {
            s++;
            start=1;
        }
    }
    if(start==1) cnt++;
    return cnt;
}

int upper(char *s)
{
    int cnt=0;
    while(*s!=EOF)
    {
        if(isupper(*s++)!=0)
            cnt++;
    }
    return cnt;
}

int lower(char *s)
{
    int cnt=0;
    while(*s!=EOF)
    {
        if(islower(*s++)!=0)
            cnt++;
    }
    return cnt;
}

int punct(char *s)
{
    int cnt=0;
    while(*s!=EOF)
    {
        if(ispunct(*s++)!=0)
            cnt++;
    }
    return cnt;
}

int number(char*s)
{
    int cnt=0;
    while(*s!=EOF)
    {
        if(isdigit(*s++)!=0)
            cnt++;
    }
    return cnt;
}
