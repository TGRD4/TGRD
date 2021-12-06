#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10
#define LENGTH 1000
int main()
{
    int data,s[SIZE+1]={0},i,seed;
    for(seed=1;seed<=SIZE;seed++)
        srand(seed);
    for(i=1;i<=LENGTH;i++)
    {
        data=rand()%10+1;
        s[data]++;
    }
    for(i=1;i<=SIZE;i++)
        printf("%d ",s[i]);
    return 0;
}