#include<stdio.h>
#include<stdlib.h>
int main(int argc,char*argv[])
{
    FILE *fp;
    double n,sum=0.0;
    int num=0;
    if(argc==1)
    {
        fp=stdin;
        printf("EOF to quit!\n");
    }
    else if(argc==2)
    {
        if(fp=(fopen(argv[1],"r")==NULL))//以第一个参数作为文件名
        {
            printf("can't find it!\n");
            exit(EXIT_FAILURE);
        }
        else 
        {
            printf("open it!\n");
            exit(EXIT_FAILURE);
        }
    }
    while(!feof(fp)&&(fscanf(fp,"%lf\n",&n)==1))
    {
        num++;
        sum+=n;
    }
    if(num>0) printf("the average is %.2lf",sum/num);
    else printf("there is no number!\n");
    return 0;
}

