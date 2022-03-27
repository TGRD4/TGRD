#include<stdio.h>
int main()
{
	int a_max,b_max;  //甲乙的酒量变量
	scanf("%d %d",&a_max,&b_max);
	int n;	
	scanf("%d",&n);
	int a1,b1,a2,b2,a_n=0,b_n=0;

	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&a1,&a2,&b1,&b2);
		if(a2==a1+b1&&b2!=a1+b1)//通过同时判断另一个让人的输赢直接忽略平局的情况
			a_n++;
		if(b2==a1+b1&&a2!=a1+b1)
			b_n++;
		if(a_n==a_max+1||b_n==b_max+1)//喝醉了直接退出
			break;
	}

	if(a_n==a_max+1)
	{
		printf("A\n");
		printf("%d",b_n);
	}
	else
	{
		printf("B\n");
		printf("%d",a_n);
	}
	
	return 0;
} 
