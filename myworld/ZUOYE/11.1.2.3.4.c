#include<stdio.h>
#define SIZE 40

/*1*/
char *read_char(char *st,int n)
{
    int i=0;
    do{
        st[i]=getchar();
    }while(st[i]!=EOF&&++i<n);
    return st;
}

/*2*/
char *read_char(char *st,int n)
{
    int i=0;
    do{
        st[i]=getchar();
        if(st[i]=='\n'||st[i]==' '||st[i]=='\t')
            break;
    }while(st[i]!=EOF&&++i<n);
    return st;
}

/*3*/
char *get_char(char*st)
{
    char input[SIZE];
    char *in=input;
    printf("input a string:");
    fgets(input,SIZE,stdin);
    while((*in=='\n'||*in=='\t'||*in==' ')&&*in!='\0')
        in++;
    while(*in!='\n'&&*in!='\t'&&*in!=' '&&*in!='\0')
        in++;st++;
    return st;
}

/*4*/
char *get_char(char *st,int n)
{
    int i=0;
    char out[SIZE];
    char *in=out;
    printf("input a string:");
    fgets(out,SIZE,stdin);
    while((*in=='\n'||*in=='\t'||*in==' ')&&*in!='\0')
        in++;
    while(*in!='\n'&&*in!='\t'&&*in!=' '&&*in!='\0'&&i<n)
    {
        *out+=*in++;
        i++;
    }
    return out;
}

