#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void sig_handler(int signo)
{
}
unsigned int mysleep(unsigned int seconds)
{
    struct sigaction new,old;
    unsigned int unslept = 0;
    new.sa_handler = sig_handler;
    sigemptyset(&new.sa_mask);
    new.sa_flags = 0;
    sigaction(SIGALRM, &new, &old);

    alarm(seconds);
    pause();
    unslept = alarm(0);
    sigaction(SIGALRM, &old, NULL);
    return unslept;
}
int main()
{
    while(1)
    {
        printf("Hello, world\n");
        mysleep(1);
    }
    return 0;
}