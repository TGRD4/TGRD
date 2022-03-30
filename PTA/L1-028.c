#include<stdio.h>
#include<math.h>
int main() {
    int sum=0;
    int number=0;
    scanf("%d",&sum);
    if(sum<0||sum>10) return 0;
    for(int i=0;i<sum;i++) {
        scanf("%d",&number);
        if(number==1) {//1不是素数
            printf("No\n");
        }
        else {  
            int j=2;
            for(;j<=sqrt(number);j++) { //注意sqrt(number)取得到
                if(number%j==0) {
                    break;
                }
            }
            if(j>sqrt(number)){ //j>sqrt(number)说明不存在number&j==0后退出
                printf("Yes\n");
            }
            else {
                printf("No\n");
            }
        }
    }
    return 0;
}