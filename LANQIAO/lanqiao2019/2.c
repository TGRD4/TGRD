#include<stdio.h>
int check(int num);
int main() {
    int sum=0;
    for(int i=1;i<2019;i++) {
        if(check(i)) {                      //判断每一个加数满足条件再继续，缩短运行时间
            for(int j=i+1;j<2019;j++) {     //只要一开始保证加数到被加数是升序的就可以避免重复的情况
                if(check(j)) {
                    int k=2019-i-j;
                    if(check(k)&&k>j) {     //此处一定要注意保证升序(k>j)，否则一定会有重复
                        sum++;
                    }
                }
            }
        }
    }
    printf("%d\n",sum);
    return 0;
}
int check(int num) {
    while(num) {
        int r=num%10;
        if(r==4||r==2) {
            return 0;
        }
        num/=10;
    }
    return 1;
}