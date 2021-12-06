#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int n,i;
    printf("how many words do you want to input?");
    scanf("%d",&n);
    printf("input now:");
    char **p=(char**)malloc(sizeof(char*)*n);//每个数组元素都是指针
    for(i=0;i<n;i++)
    {
        char temp[100];
        scanf("%s",temp);
        int len=strlen(temp);
        char *pp=(char*)malloc(sizeof(char)*len);
        strcpy(pp,temp);
        *(p+i)=pp;
    }
    for(i=0;i<n;i++)
        printf("%s\n",*(p+i));
    free(p);
    printf("done!\n");
    return 0;
}