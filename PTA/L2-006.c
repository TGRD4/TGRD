#include<stdio.h>
#include<string.h>
#include<math.h>
int is_prime(int n);//判断质数
int main() {
    int n=0;
    int cnt=0,max=0;
    int temp=0; //
    int baoliu=0;//保留连续最小数
    scanf("%d",&n);
    if(is_prime(n)) {
        printf("1\n%d",n);
    }
    else {
        for(int i=2;i<=sqrt(n);i++)  {
            cnt=0;
            temp=n;
            for(int j=i;j<=sqrt(n);j++) {
                if(temp%j==0) {
                    temp/=j;//连续因子乘积也必须是因子，所以引入temp来判断是否一次循环保留下来的连续因子的乘积等于n
                    cnt++;
                }
                else {
                    break;
                }
            }

            /* 不用数组来保留连续值，只需要知道连续最小值和连续个数即可 */
            if(max<cnt) {
                max=cnt;//连续个数
                baoliu=i;//连续最小值
            }
        }
        printf("%d\n",max);
        for(int i=baoliu;i<baoliu+max;i++) {
            printf("%d",i);
            if(i!=max+baoliu-1) {
                printf("*");
            }
        }
    }
    return 0;
}

int is_prime(int n)
{
    if(n==1) return 0;
    for(int i=2;i<sqrt(n);i++) {
        if(n%i==0) return 0;
    }
    return 1;
}
