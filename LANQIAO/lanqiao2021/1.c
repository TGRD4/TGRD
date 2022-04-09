#include<stdio.h>
int s[11];
int del(int number);
int main() {
    int cnt=0;
    int number=1;
    for(int i=0;i<=9;i++) {     //设置0～9数字个数都为2021
        s[i]=2021;
    }
    while(1) {                  //设置初始数字为1，开始无限向上加，直到保存的数字个数为0，则没有数字再可以使用
        if(del(number)==1) {
            cnt++;
            number++;
        }
        else {
            printf("%d\n",cnt); //别直接输出number,应该从cnt=0开始加
            break;
        }
    }
    return 0;
}
int del(int number) {
    while(number) {             //减去每一位上的数字
        int r=number%10;
        if(s[r]==0) {
            return 0;
        }
        s[r]--;
        number/=10;
    }
    return 1;
}
