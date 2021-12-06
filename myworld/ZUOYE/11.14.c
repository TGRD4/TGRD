#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
    if(argc!=3)
    {
        printf("error! retry!\n");
        return 1;
    }
    float f=atof(argv[1]);//将str转换为float
    int i=atoi(argv[2]);//将str转换为int
    float result=1;
    for(int k=0;k<i;k++)//整数次幂
        result =result*f;
    printf("the %g's %d power is %g\n",f,i,result);
    return 0;
}