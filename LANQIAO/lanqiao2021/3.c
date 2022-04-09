#include<stdio.h>
int main() {
    long long int time=0;
    scanf("%lld",&time);
    time/=1000;//秒数
    time%=(60*24*60);//天数
    printf("%lld\n",time);
    int ss=time%60;
    time/=60;
    int mm=time%60;
    time/=60;
    int hh=time%60;
    time/=60;
    printf("%02d:%02d:%02d",hh,mm,ss);
    return 0;

}