#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 40
int mycomp(const void *p1,const void *p2);
void showarray(const double s[],int n);
void fillarray(double s[],int n);
int main()
{
    double s[N];
    fillarray(s,N);
    puts("random list:");
    showarray(s,N);
    qsort(s,N,sizeof(double),mycomp);
    /*qsort第一个参数是一个指向待排序的数组的指针,第二个参数是数组的项数,第三个参数是每个元素的大小(类型),最后一个是指向一个函数的指针)*/
    printf("the result is:\n");
    showarray(s,N);
    return 0;
}

int mycomp(const void *p1,const void *p2)//此函数接受所有类型的数组指针
{
    const double *ps1=(const double *)p1;//需要强制转换指针类型为数组类型
    const double *ps2=(const double *)p2;
    if(*ps1>*ps2) return 1;
    else if(*ps1==*ps2) return 0;
    return -1;//与strcmp作用类似
}

void showarray(const double s[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",s[i]);
        if((i+1)%8==0)
            printf("\n");
    }
}

void fillarray(double s[],int n)
{
    for(int i=0;i<n;i++)
    {
        s[i]=(double)rand()/((double)rand()+0.1);//随即数组元素
    }
}