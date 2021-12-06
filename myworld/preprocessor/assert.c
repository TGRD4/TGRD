#include<stdio.h>
#include<math.h>
/*在"assert.h"前加入  #define NDEBUG  来禁用所有assert语句(若程序确定没有任何问题)*/
#include<assert.h>//辅助调试的断言库
int main()
{
    double x,y,z;
    puts("enter a pair of numbers(0 0 to quit):");
    while(scanf("%lf %lf",&x,&y)==2&&(x!=0&&y!=0))
    {
        z=x*x-y*y;
        assert(z>=0);//若不满足括号内的表达式则返回错误信息提示(z>=0)不满足(直接中止程序)
        printf("the sum is %.2lf\n",sqrt(z));//使用gcc 文件名 -lm运行<math.h>
        /*sqrt()只接受double和float类型的值*/
        puts("the next pairs:");
    }
    puts("Done!");
    return 0;
}