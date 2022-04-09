#include<stdio.h>
#include<stdlib.h>
#define MAX 0x3f3f3f3f
int map[2022][2022];
int gcd(int x,int y);
int main() {   
    //初始化图
    for(int i=1;i<=2021;i++) {
        for(int j=1;j<=2021;j++) {
            if(i==j) {
                map[i][j]=0;
                map[j][i]=0;
            }
            else if(abs(j-i)>21) {
                map[i][j]=MAX;
                map[j][i]=MAX;          //无向图
            }
            else {
                map[i][j]=i*j/gcd(i,j);
                map[j][i]=i*j/gcd(i,j); //最小公倍数等于两数之积除以最小公因数
            }
        }
    }
    // Floyd 找到每两个点之间的最短路径
    for(int k=1;k<=2021;k++) {
        for(int i=1;i<=2021;i++) {
            for(int j=1;j<=2021;j++) {
                if(map[i][k]!=MAX&&map[k][j]!=MAX&&map[i][j]>map[i][k]+map[k][j]) {
                    map[i][j]=map[i][k]+map[k][j];
                    map[j][i]=map[i][k]+map[k][j];
                }
            }
        }
    }
    printf("%d\n",map[1][2021]);
    return 0;
}
int gcd(int x,int y) {
    if(y==0) return x;
    return gcd(y,x%y);
}