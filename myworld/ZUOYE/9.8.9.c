#include<stdio.h>
double power(double n,int p);
int main(void)
{
    double x,pow;
    int k;
    printf("please enter a number and a interger:");
    while(scanf("%lf %d",&x,&k)==2)
    {
        pow=power(x,k);
        printf("%.3lf to the power %d is %.5lf\n",x,k,pow);
        printf("press 'q' to quit!\n");
    }
    return 0;
}

double power(double n,int p)
{
    double pow=1;
    int i;
    if(n==0&&p==0) return 1;
    if(n==0) return 0;
    if(p==0) return 1;
    if(p>0)
    {
        for(i=1;i<=p;i++)
            pow*=n;
        return pow;
    }
    else
    {
        for(i=1;i<=-p;i++)
            pow*=n;
        return (1/pow);
    }
}

/*9*/
if(p>0)
{
    return (n*power(n,p-1));
}
else
{
    return (power(n,p+1)/n);
}
