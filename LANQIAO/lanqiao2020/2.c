#include<stdio.h>
int main() {
    int sum=0;
    int week=6;
    int months[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    for(int i=2000;i<=2020;i++) {   //年份
        if((i%4==0&&i%100!=0)||(i%400==0)) {    //改变闰年二号天数
            months[2]=29;
        }
        else {
            months[2]=28;
        }
        for(int j=1;j<=12;j++) {    //月份
            for(int k=1;k<=months[j];k++) {  //天数
                sum++;
                if(week==8) {       //重置星期
                    week=1;
                }
                if(k==1||week==1) { //每月一号或者周一
                    sum++;
                }
                week++;
                if(i==2020&&j==10&&k==1) {
                    printf("%d\n",sum);
                }
            }
        }
    }
    return 0;
}