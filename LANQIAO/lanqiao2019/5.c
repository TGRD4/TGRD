#include<stdio.h>
#include<stdlib.h>          //abs()
int s[100001];
int gcd(int x,int y);
int main() {
    int min=0x3f3f3f3f;     //无穷
    int number=0;
    scanf("%d",&number);
    for(int i=1;i<=number;i++) {
        scanf("%d",&s[i]);
    }
    /*对原数组排序以便更方便找出公差*/
    for(int i=1;i<=number;i++) {
        for(int j=i;j<=number-i-1;j++) {
            if(s[j]>s[j+1]) {
                int temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
    /*找出最小公差*/
    //错误！！！！（若是2，4，7）最小公差为2,但实际应该是1
    /*
    for(int i=1;i<=number;i++) {
        int r=abs(s[i]-s[i+1]);
        if(min>r) {
            min=r;
        }
    }
    */
    /*所以要寻找的是排序后所有相邻两个数的最大公因数，如下*/
    for(int i=1;i<number;i++) {
        int r=gcd(s[i],s[i+1]);
        if(r<min) {
            min=r;
        }
    }
    /*新数组最短个数为 (原数组最后一位-原数组第一位)/2+1 */
    printf("%d\n",(s[number]-s[1])/min+1);
    return 0;
}
int gcd(int x,int y) {
    if(y==0) return x;
    return gcd(y,x%y);
}