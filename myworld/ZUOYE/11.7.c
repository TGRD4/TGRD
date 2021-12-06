#include<stdio.h>
#include<string.h>
#define N 80
char *mystrncpy(char *dest,char *st,int n);
int main()
{
    char destination[N],source[N];
    int i=0;
    printf("enter a string as a source(blank to quit):");
    fgets(source,N,stdin);
    printf("enter a number or char you need to copy:");
    scanf("%d",&i);
    while(*source!='\n')
    {
        mystrncpy(destination,source,i);
        printf("done!now the dest string is:");
        puts(destination);
        while(getchar()!='\n') break;
        printf("another? enter a string as a source(blank to quit):");
        fgets(source,N,stdin);
        printf("enter a number or char you need to copy:");
        scanf("%d",&i);
    }
    return 0;
}

char *mystrncpy(char *dest,char *st,int n)
{
    int cnt=0;
    while(*st!='\0'&&cnt<n)
        *(dest+cnt++)=*st++;
    if(cnt<n)
    {
        while(cnt<n)
            *(dest+cnt++)='\0';
    }
    return dest;
}