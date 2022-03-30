#include<stdio.h>
int main() {
    int k=1;
    int sum=0;
    int cnt=0;
    int number=0;
    scanf("%d",&number);//number保证是奇数（才能乘为光棍数）

    /* 相当于把一个较大的k分解成两个小k进行计算 */
    while(k<number) {
        k=10*k+1;    //保证k一直是光棍数(1,11,111.....)
        cnt++;  //记录k的位数-1
    }

    /*  一位位打出来可以省去数组，并且用 long long int 会运行超时 */
    while(1) {
        
        printf("%d",k/number);
        k%=number;//算一位打印一位
        
        cnt++;
        if(k==0) break; //每一次都要判断number是否能被整除从而找到最小k
        k=10*k+1;    //k = 1111,11111,111111.....
    }
    printf("% d\n",cnt);
    return 0;
}