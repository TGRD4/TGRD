#include<stdio.h>
#include<time.h>
int num(int n)
{
	int num1=0;
	while(n>0)
	{
		n/=10;
		num1++;
	}
	return num1;
}
int main()
{
    double  duration;
    clock_t start, finish;
    start = clock();
	int i,n,t,t1,t2;
	t1=0;
	t2=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		t=t1+t2;
		t1=t2;
		t2=t;
	}
    printf("%d\n",t1);
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "%f seconds\n", duration );
	return 0;
}
