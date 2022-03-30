#include <stdio.h>
#include <math.h>
int main() {
    int l,n;
    scanf("%d %d",&l,&n);
    n--;    //因为是倒数所以要-1

    for(int i=1;i<=l;i++) {
        int k=pow(26,l-i);  //先输出靠前的字母，排序更多，确定下来后最后一位字母就只有一种情况所以k=pow(26,0)=1
        int r=n/k;  //排序除以该位所有情况的整数就是此位上的字母
        printf("%c",'z'-r);//因为是倒序所以要用最后一个字母'z'减去此位字母 r
        n%=k;//经典用余数来缩小范围
    }
    
    return 0;
}