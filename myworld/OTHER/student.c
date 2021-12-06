#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int nandu,n,i;
	int a,b,o;
	char e1,e2,e3,e4,e5;
	e1='+';
	e2='-';
	e3='*';
	e4='/';
	e5='=';
	printf("请选择难度(1~4/加减乘除):");
	scanf("%d",&nandu);
	if (nandu==1)
	{
		printf("请输入要做的题数:");
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			srand((unsigned)time(NULL));
	        a=rand()%100+1;
         	b=rand()%100+1;
        	printf("%d%c%d%c\n",a,e1,b,e5);
     		scanf("%d",&o);
     		if(o==a+b) printf("rigth!\n");
     		else printf("wrong!\n");
		}
	}
	else if (nandu==2)
	{
		printf("请输入要做的题数:");
    	scanf("%d",&n);
    	for(i=1;i<=n;i++)
		{
			srand((unsigned)time(NULL));
	        a=rand()%100+1;
         	b=rand()%100+1;
        	printf("%d%c%d%c\n",a,e2,b,e5);
     		scanf("%d",&o);
     		if(o==a-b) printf("rigth!\n");
     		else printf("wrong!\n");
		}
	}
	else if (nandu==3)
	{
		printf("请输入要做的题数:");
     	scanf("%d",&n);
    	for(i=1;i<=n;i++)
		{
			srand((unsigned)time(NULL));
	        a=rand()%100+1;
         	b=rand()%100+1;
        	printf("%d%c%d%c\n",a,e3,b,e5);
     		scanf("%d",&o);
     		if(o==a*b) printf("rigth!\n");
     		else printf("wrong!\n");
		}
	}
	else if (nandu==4)
	{
		printf("请输入要做的题数:");
     	scanf("%d",&n);
    	for(i=1;i<=n;i++)
		{
			srand((unsigned)time(NULL));
	        a=rand()%100+1;
         	b=rand()%100+1;
        	printf("%d%c%d%c\n",a,e4,b,e5);
     		scanf("%d",&o);
     		if(o==a/b) printf("rigth!\n");
     		else printf("wrong!\n");
		}
	}
	else printf("输入错误!\n");
}