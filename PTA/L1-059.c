#include <stdio.h>
#include <string.h>
int main()
{
	int n,i,j;
	int len,flagA,flagB;
	int count,pos;
	char s[101];
	scanf("%d",&n);
	getchar();	 
	for(i=0;i<n;i++)
    {
		len=0,flagA=0,flagB=0,count=0;
		gets(s);
		len=strlen(s);	
        
        /*判断押韵情况*/
		for(j=0;j<len;j++)
        {
			if(s[j]==','&&s[j-3]=='o'&&s[j-2]=='n'&&s[j-1]=='g')
				flagA=1;
			if(s[j]=='.'&&s[j-3]=='o'&&s[j-2]=='n'&&s[j-1]=='g')
				flagB=1;
		}
        
		/*若都押*/
		if(flagA==1&&flagB==1)
        {
			for(j=len-1;j>=0;j--)
            {	
				if(s[j]==' ')		
					count++;
				if(count==3)
                {
					pos=j;	//通过数空格定位到敲笨钟的位置
					break;
				}
			}
			for(j=0;j<=pos;j++)
				printf("%c",s[j]);
			printf("qiao ben zhong.\n");
		}
        
		/*有一个不押*/
        else
			printf("Skipped\n");
	}
	return 0;
} 
