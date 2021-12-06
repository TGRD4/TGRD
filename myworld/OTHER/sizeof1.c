#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
   char str[20] = "hello world";
   char *s = (char *)malloc(20);
   strcpy(s, str);
   printf("strlen(str)=%d\n",strlen(str));//11
   printf("sizeof(str)=%d\n",sizeof(str));//20
   printf("strlen(s)=%d\n",strlen(s));//11
   printf("sizeof(s)=%d\n",sizeof(s));//8
   /*最后的sizeof计算的是指针(sizeof(char *)) 的大小*/
   free(s);
   return 0;
}