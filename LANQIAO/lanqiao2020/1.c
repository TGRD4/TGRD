#include<stdio.h>
int main() {
    int s[41][41]={0};  //范围设大
    int number=1;
    int x=0,y=0;
    //从1开始的好处是可以更好的判断是奇数斜线还是偶数斜线
    for(int i=1;i<40;i++) {    //20*20一共有40条斜线，而因为第一个数计算过了就是1,所以39即可
    /*创建蛇形数列*/
        if(i%2==1) {    //奇数斜线
            for(x=i,y=1;x>=1&&y<=i;x--,y++)
                s[x][y]=number++;
        }
        else {  //偶数斜线（记住x变大即可）
            for(x=1,y=i;x<=i&&y>=1;x++,y--)
                s[x][y]=number++;
        }
    }
    
    printf("%d\n",s[20][20]);
    return 0;
}
