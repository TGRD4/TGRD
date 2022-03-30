#include<stdio.h>
#include<string.h>
int main() {
    int cnt_year=0;
    int cnt_number=0;
    int year=0,number=0;
    int cnt_s=0;
    scanf("%d %d",&year,&number);
    for(int i=year;;i++) {
        cnt_number=0;
        int temp=i;
        int s[11]={0};//注意数组范围
        memset(s,0,sizeof(s));
        while(temp) {
            int r=temp%10;
            temp/=10;
            if(s[r]==0) {
                s[r]=1;
                cnt_number++;
            }
        }
        if(i<1000&&s[0]==0) {   //年份小于1000，前几位是0且后几位不存在0则总数+1
            cnt_number++;
        }
        if(cnt_number==number) {
            cnt_year=i;
            break;
        }
    }
    printf("%d %04d",cnt_year-year,cnt_year);
    return 0;
}