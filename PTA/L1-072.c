#include<stdio.h>
int main() {
    int ticket[3][3]={0};
    int x=0,y=0;
    int sum=0;
    int money[26]={0,0,0,0,0,0,10000,36,720,360,80,252,108,72,
                  54,180,72,180,119,36,306,1080,144,1800,3600};
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            scanf("%d",&ticket[i][j]);
            if(ticket[i][j]==0) {
                x=i,y=j;
            }
            sum+=ticket[i][j];
        }
    }

    ticket[x][y]=45-sum;//获得已知数字
    int xx=0,yy=0;
    for(int i=0;i<3;i++) {
        scanf("%d %d",&xx,&yy);
        printf("%d\n",ticket[xx-1][yy-1]);
    }
    int choice=0;
    int cnt=0;
    int k=0;
    scanf("%d",&choice);

    /*计算出选择列的所有数字之和*/
    switch(choice) {
        case 1:for(;k<3;k++) {
            cnt+=ticket[0][k];
        }
        case 2:for(;k<3;k++) {
            cnt+=ticket[1][k];
        }
        case 3:for(;k<3;k++) {
            cnt+=ticket[2][k];
        }
        case 4:for(;k<3;k++) {
            cnt+=ticket[k][0];
        }
        case 5:for(;k<3;k++) {
            cnt+=ticket[k][1];
        }
        case 6:for(;k<3;k++) {
            cnt+=ticket[k][2];
        }
        case 7:for(int o=0;k<3&&o<3;k++,o++) {
            cnt+=ticket[o][k];
        }
        case 8:for(int o=2;k<3;k++,o--) {
            cnt+=ticket[k][o];
        }
    }
    /*在给定金额表里对应到每一个和的对应奖金*/
    printf("%d\n",money[cnt]);
    return 0;
}