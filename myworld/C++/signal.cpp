/* 信号处理 */
#include <iostream>
#include <csignal>
#include <unistd.h>
//#include <cstdlib>                    // 使用EXIT_FAILURE/EXIT_SUCCESS等时要带上
using namespace std;

/* 接收到信号时进行处理的函数 */
void signalHandler(int signum) {        // 参数是输入信号的编号
    /* 接收到ctrl+c结束信号后开始执行 */
    cout << "Interrupt signal (" << signum << ") received.\n";
    // 清理并关闭
    // 终止程序  
    exit(signum);                       // 退出程序编码号signum(0表示成功终止)
/*
当遇到 main 函数中的 return 语句时，C++ 程序将停止执行，但其他函数结束时，程序并不会停止，程序的控制将返回到函数调用之后的位置
然而，有时候会出现一些非常少见的情况，使得程序有必要在 main 以外的函数中终止，要实现这一点，可以使用 exit 函数
当调用 exit 函数时，无论是哪个函数包含了该调用，都将导致程序停止
*/
}

/*
signal(registered signal, signal handler)
这个函数接收两个参数：第一个参数是一个整数，代表了信号的编号；第二个参数是一个指向信号处理函数的指针

不管您想在程序中捕获什么信号，您都必须使用 signal 函数来注册信号，并将其与信号处理程序相关联
*/
int main() {
    int i=0;
    // 注册信号 SIGINT 和信号处理程序
    signal(SIGINT, signalHandler);      // SIGINT是程序终止(interrupt)信号，使用signal()函数捕获SIGINT信号
    while(++i) {
        cout << "Going to sleep...." << endl;
        if(i == 3) {                    // i=3的时候自动生成结束信号而退出
          raise(SIGINT);                // raise() 生成信号，该函数带有一个整数信号编号作为参数
        }
        sleep(1);                       // 挂起1秒
    }
    return 0;
}
