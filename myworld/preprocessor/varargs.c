#include<stdio.h>
#include<stdarg.h>
double sum(int,...);
int main()
{
    double s,t;
    s=sum(3,1.1,2.5,13.3);
    t=sum(6,1.1,2.1,13.1,4.1,5.1,6.1);
    printf("return value for sum(3,1.1,2.5,13.3):                %g\n",s);
    printf("return value for sum(6,1.1,2.1,13.1,4.1,5.1,6.1):    %g\n",t);
    return 0;
}

double sum(int lim,...)//lim表示参数列表的项数
{
    va_list ap;//声明ap为存储参数类型
    double tot=0;
    va_start(ap,lim);//将ap初始化为参数列表
    for(int i=0;i<lim;i++)
        tot+=va_arg(ap,double);//检索参数列表中的每一项(类型需要相同不然会出错,不会自动转换类型)
    va_end(ap);//清理工作,相当于free释放内存
    return tot; 
}