

#include<stdio.h>
int main()
{
        printf("hello");
        //fflush(stdout);清空缓冲区
        int i = 0;
        for(;i<10;i++)
        {
                putchar('.');
                sleep(1);
        }
        return 0;
}//一行完了全部输出

/*
一般情况下，由键盘输入的字符并没有直接送入程序，而是被存储在一个缓冲区当中。缓冲又分为两种，行缓冲和完全缓冲。
对于完全缓冲来说，缓冲区满时被清空(内容被发送到指定的目的地)。这种缓冲通常出现在文件输入中。
对于行缓冲来说，遇到一个换行符，则清空缓冲区，键盘输入是标准的行缓冲，因此，按下换行键的时候才会清空缓冲区。
*/

/*
#include<stdio.h>
#include<unistd.h>
int main()
{
    fprintf(stderr,"hello");
    int i=0;
    for(;i<10;i++)
    {
        fprintf(stderr,".");
        sleep(1);
    }
    return 0;
}//一秒输出一个.
*/
