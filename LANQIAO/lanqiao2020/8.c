#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int a[1001],b[1001];
double x[1001],y[1001];
int jd(int n) {         //求第i条直线与前i+1条直线的交点个数
    int num=1;          //没有直线的时候也有一个空间
    if(n==1) return 2;  //如果是第一条直线，直接返回2


    else {
        for(int i=1;i<n;i++) {          //依次判断与前n-1条直线的交点个数
            if(a[i]!=a[n]) {            //不平行时有交点

                /*计算交点坐标*/
                x[i]=(b[n]-b[i])*0.1/(a[i]-a[n]);   
                y[i]=a[n]*x[i]+b[n];    //y=ax+b

                int flag=0;
                for(int j=1;j<i;j++) {  //依次判断与前i-1个交点是否相同
                    if(((x[i]-x[j])<0.00001&&(x[i]-x[j])>-0.00001)&&
                    ((y[i]-y[j])<0.00001&&(y[i]-y[j])>-0.00001)) {
                        flag++;
                    }
                }
                if(flag==0) {
                    num++;              //如果不相同，空间num+1
                }
            }
        }
    }

    //所有都平行相当于加1个空间，num=1
    return num;
}
int main() {
    int n,sum=0;
    scanf("%d",&n);
    int i,j;
    for(i=1;i<=n;i++) {     //依次输入N条直线
        scanf("%d %d",&a[i],&b[i]);
        int flag=0;
        for(j=1;j<i;j++) {  //排除相同的直线
            if(a[j]==a[i]&&b[j]==b[i]) {
                flag=1;
            }
        }
        /*计算不同直线划分的空间*/
        if(flag==0) {
            sum+=jd(i);
        } 
    }
    printf("%d",sum);
    return 0;
}