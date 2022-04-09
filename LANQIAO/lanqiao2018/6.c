#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int s[10001][3];
int cnt[10001];
int main() {
    int N=0,D=0,K=0;
    scanf("%d %d %d",&N,&D,&K);
    for(int i=0;i<N;i++) {
        scanf("%d %d",&s[i][0],&s[i][1]);
    }
    for(int i=0;i<N;i++) {
        for(int j=i;j<N-i-1;j++) {
            if(s[j][1]>s[j+1][1]) {
                int temp=s[j][1];       //交换编号
                s[j][1]=s[j+1][1];
                s[j+1][1]=temp;
                int tempp=s[j][0];      //记得替换时刻
                s[j][0]=s[j+1][0];
                s[j+1][0]=tempp;
            }
        }
    }
    for(int i=0;i<N;i++) {
        for(int j=i;j<N-i-1;j++) {      //时刻排序以便于后续找出满足时刻内的编号
            if(s[j][1]==s[j+1][1]&&s[j][0]>s[j+1][0]) {
                int temp=s[j][0];
                s[j][0]=s[j+1][0];
                s[j+1][0]=temp;
            }
        }
    }
    for(int i=0;i<N-1;i++) {
        int cnt=0;
        while(s[i][1]==s[i+1][1]) {         //在相同编号内一直寻找
            int len=abs(s[i+1][0]-s[i][0]);
            if(s[i][0]==s[i+1][0]) {        //考虑点赞发生时刻相同的情况
                cnt++;
            }
            if(len<D) {                     //在时刻内热度+1
                cnt++;
            }
            if(cnt==K) {                    //达到热贴要求则热度+1
                printf("%d\n",s[i][1]);
            }
            i++;                            //保证循环能退出
        }
    }
    return 0;
}
/*
7 10 2
0 1
0 10
10 10
10 1
9 1
100 3
100 3
*/