#include<stdio.h>
int main() {
    int n=0;
    int number[4][100001]={0};
    scanf("%d",&n);
    for(int i=0;i<3;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&number[i][j]);
        }
    }
    int sign[4][100001]={0};                    //标记计算过的每行合适的数
    int sum=1;
    int cnt[4]={0};
    for(int i=0;i<n;i++) {                      //循环第二行的数
        for(int j=0;j<n;j++) {                  //循环第一行的数找到小于第二行当前列的数
            if(number[1][i]>number[0][j]) {
                for(int k=0;k<n;k++) {          //循环第三行的数找到大于第二行当前列的数
                    if(number[1][i]<number[2][k]) {

                        if(sign[1][i]==0) {     //当前序号满足条件且没被标记过
                            cnt[1]++;
                            sign[1][i]=1;
                        }
                        if(sign[0][j]==0) {
                            cnt[0]++;
                            sign[0][j]=1;
                        }
                        if(sign[2][k]==0) {
                            cnt[2]++;
                            sign[2][k]=1;
                        }

                    }
                }
            }
        }
    }
    for(int i=0;i<3;i++) {                      //每行满足条件的个数相乘就是最后所有满足的结果
        sum*=cnt[i];
    }
    printf("%d\n",sum);
    return 0;
}