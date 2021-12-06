#include<stdio.h>
#include<time.h>
long int fb(unsigned int n)
{
	long int f;
	if(n==1||n==2) f=1;
	else f=fb(n-1)+fb(n-2);
	return(f);
}
int main()
{
	unsigned int m;
    double  duration;
	scanf("%d",&m);
    clock_t start, finish;
    start = clock();
	if(m<=0) printf("ERROR!\n");
	printf("%ld\n",fb(m));
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "%f seconds\n", duration );
	return 0;
}


