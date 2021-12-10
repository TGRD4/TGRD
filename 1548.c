/*
棋盘问题：https://www.luogu.com.cn/problem/P1548
*/
#include<stdio.h>
int main()
{
    int m,n,z,c,i,j,k,l;  
	scanf("%d %d",&m,&n);  
	//枚举法        
	for(i=0;i<=m;i++)//枚举每一行
		for(j=0;j<=n;j++)//枚举每一列 
			for(k=i+1;k<=m;k++)//枚举当前行的下一行
				for(l=j+1;l<=n;l++)//枚举当前列的下一列
					if(k-i==l-j) z++;//如果行列相等则是正方形     
					else c++;//否则就是长方形           
	printf("%d %d",z,c);   
}