#include<stdio.h>
void sort(int number[],int n,int flag);
int main() {
    int number[100001]={0};
    int num=0,sum=0;
    scanf("%d %d",&num,&sum);
    for(int i=1;i<=num;i++) {
        number[i]=i;
    }
    int c1=0,c2=0;
    for(int i=1;i<=sum;i++) {
        scanf("%d %d",&c1,&c2);
        if(c1==1) {
            sort(&number[i-1],num-c2+1,1);//传入不同参数
        }
        else {
            sort(number,c2,0);
        }
    }
    for(int i=1;i<=num;i++) {
        printf("%d ",number[i]);
    }
    return 0;
}
void sort(int number[],int n,int flag) {    //排序
    for(int i=1;i<=n-1;i++) {
        for(int j=1;j<=n-i;j++) {
            if(flag==1&&number[j]>number[j+1]) {
                int temp=number[j];
                number[j]=number[j+1];
                number[j+1]=temp;
            }
            else if(flag==0&&number[j]<number[j+1]) {
                int temp=number[j];
                number[j]=number[j+1];
                number[j+1]=temp;
            }
        }
    }
    return ;
}