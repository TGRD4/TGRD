#include<stdio.h>
#include<math.h>
int maxyin(int n,int m);
int main() {
    int fz=0;
    int fm=0;
    int fz_sum=0;
    int fm_sum=0;
    int n=0;
    int m=0;
    int flag=0;
    scanf("%d",&n);
    scanf("%d/%d",&fz,&fm);
    fz_sum=fz;
    fm_sum=fm;
    /* 先求出所有分数相加之和 */
    for(int i=1;i<n;i++) {
        scanf("%d/%d",&fz,&fm);
        fz_sum=fz*fm_sum+fm*fz_sum;
        fm_sum*=fm;
    }

    /* 一个为0则分数为0 */
    if(!fz_sum||!fm_sum) {
        printf("0\n");
        return 0;
    }

    /* 分子变正方便后续约分 */
    if(fz_sum<0) {
        flag=1;
        fz_sum=-fz_sum;
    }

    /* 找出最大公因数后约分*/
    if(fz_sum!=0) {
        int left=0;
        left=maxyin(fz_sum,fm_sum);
        fz_sum/=left;
        fm_sum/=left;
    }

    /* 提出整数 */
    if(fz_sum>fm_sum) {
        m=fz_sum/fm_sum;
        fz_sum=fz_sum%fm_sum;
    }

    if(flag) {
        printf("-");
    }
    if(m) {
        printf("%d",m);
    }
    
    if(fz_sum&&fm_sum) {
        if(m)
            printf(" %d/%d\n",fz_sum,fm_sum);
        else 
            printf("%d/%d\n",fz_sum,fm_sum);
    }
    return 0;
}

/* 求分子分母最大公因数约分 */
int maxyin(int n,int m) 
{
    if(n==0) {
        return m;//m除尽n则最大公因数是n
    }
    return maxyin(m%n,n);//一直循环到m除尽n找到最大公因数
}
