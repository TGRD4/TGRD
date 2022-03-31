#include<stdio.h>
int main() {
    int a1=0,a2=0,n=0;
    int cnt=2;
    int s[2021]={0};//注意范围
    scanf("%d %d %d",&a1,&a2,&n);
    s[0]=a1,s[1]=a2;
    for(int i=0,j=1;i<n&&j<n;i++,j++) {
        int sum=s[i]*s[j];
        if(sum<10) {
            s[cnt++]=sum;
        }        
        else {
            s[cnt++]=sum/10;
            sum%=10;
            s[cnt++]=sum;
        }
    }
    for(int i=0;i<n;i++) {
        printf("%d",s[i]);
        if(i!=n-1) putchar(' ');
    }
    return 0;
}