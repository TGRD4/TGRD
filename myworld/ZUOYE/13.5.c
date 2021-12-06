#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 44
int main(int argc,char*argv[])
{
    FILE *fp;
    char s[N];
    char ch;
    if(argc!=3)
    {
        printf("can't fine it!\n");
        exit(EXIT_FAILURE);
    }
    else 
    {
        if(strlen(argv[1])!=1)
        {
            printf("you should input a char!\n");
            exit(EXIT_FAILURE);
        }
        if((fp=fopen(argv[2],"r"))==NULL)
        {
            printf("can't open this file!\n");
            exit(EXIT_FAILURE);
        }
    }
    ch=argv[1][0];
    while(fgets(s,N,fp)!=NULL)
    {
        char*p=s;
        while(*p!='\0')
        {
            if(*p++==ch)
            {
                printf("found it!\n");
                break;
            }
        }
    }
    return 0;
}