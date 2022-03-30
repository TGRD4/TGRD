#include<stdio.h>
#include<string.h>
int main() {
    int label[1001][1001]={0};  //注意范围否则段错误
    int flag[1001]={0};
    memset(flag,0,sizeof(flag));
    int line=0;
    int keep=0;
    int max=0;
    scanf("%d",&line);
    for(int i=0;i<line;i++) {
        scanf("%d",&label[i][0]);
        for(int j=1;j<=label[i][0];j++) {   //注意j从1开始
            scanf("%d",&label[i][j]);
            flag[label[i][j]]++;
            if(max<flag[label[i][j]]||(max==flag[label[i][j]]&&keep<label[i][j])) {//出现次数多 和 序号大及出项次数相同
                max=flag[label[i][j]];
                keep=label[i][j];
            }
        }
    }
    printf("%d %d",keep,max);
}