#include<stdio.h>
#include<math.h>
int main() {
    int n=0;
    char ch=' ';
    scanf("%d %c",&n,&ch);
    int line=0;
    int cnt=0;
    line=sqrt((n+1)/2);//行数
    /* 上层 */
    for(int i=0;i<line;i++) {
        for(int j=0;j<i;j++) 
            printf(" ");
        for(int j=i;j<line*2-i-1;j++) {
            printf("%c",ch);
            cnt++;
        }
        printf("\n");
    }
    /* 下层 */
    for(int i=2;i<=line;i++) {
        for(int j=0;j<line-i;j++) 
            printf(" ");
        for(int j=0;j<2*i-1;j++) {
            printf("%c",ch);
            cnt++;
        }
        printf("\n");
    }
    printf("%d",n-cnt);//剩余数
}
