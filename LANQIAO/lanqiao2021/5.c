#include<stdio.h>
int M[3001][3001];
int main(){

    int n;
    scanf("%d",&n);     //目标数字

    for(int i=1;i<=n+1&&i<=3000;i++) {
        M[i][i]=1;  //杨辉三角初始化
        M[i][1]=1;  //前两行都是1
    }

    for(int i=3;i<=n+1&&i<=3000;i++) {
        for(int j=2;j<i;j++) {  //计算杨辉三角（从第三行第二列开始）
            M[i][j]=M[i-1][j]+M[i-1][j-1];
        }
    }
    
    int num=1;
    for(int i=1;i<=n+1&&i<=3000;i++) {
        for(int j=1;j<=i;j++) {
            if(M[i][j]==n) {    //寻找指定数字
                printf("%d",num);
                return 0;
            }
            else {
                num++;
            }
        }
    }
    return 0;
}

