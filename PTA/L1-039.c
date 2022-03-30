#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main() {
    int line;
    scanf("%d",&line);
    getchar();
    char s[1001]={};
    fgets(s,sizeof(s),stdin);//fgets格式错误（需要gets(s)）--> 在PTA上
    char pb[1001][1001]={};
    memset(pb,' ',sizeof(pb));//初始化pb为空格否则会因s长度不够而出现格式错误
    int len=strlen(s);
    int low=len/line;
    int cnt=0;
    if(len%line!=0) low++;//如果不能刚好除尽（刚好形成一个正方形），则加上一列

        /*画出来就很简单*/
    for(int i=low-1;i>=0;i--) {
        for(int j=0;j<line;j++) {
            pb[j][i]=s[cnt++];
            if(cnt==strlen(s)) {
                break;
            }
        }
    }
    for(int i=0;i<line;i++) {
        for(int j=0;j<low;j++) {
            printf("%c",pb[i][j]);
        }
        putchar('\n');
    }
    return 0;
}