#include<stdio.h>
#include<string.h>
#include<math.h>
int main() {
    int N=0,M=0;
    char s[1001]={};
    int flag=1;
    scanf("%d %d",&N,&M);
    getchar();//接受空格
    while(N--) {
        gets(s);
        if(strstr(s,"qiandao")||strstr(s,"easy"));//比较存在字符串
        else {
            if(M) {
                M--;
            }
            else {//若无匹配字符串且已完成题目不够则此题未完成
                puts(s);
                flag=0;
            }
        }
    }
    if(flag) { 
        printf("Wo AK le");
    }
    return 0;
}