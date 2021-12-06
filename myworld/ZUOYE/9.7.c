#include<stdio.h>
void Input(void);
int panduan(char ch);
int main()
{
    Input();
    return 0;
}
void Input()
{
    char ch;
    printf("enter the chars(end by EOF):\n");
    while((ch=getchar())!=EOF)
    {
        if((ch=getchar())=='\n') continue;
        if(panduan(ch)!=-1)
            printf("the char %c's position in alphabet is %d.\n",ch,panduan(ch));
        else 
            printf("the char is not a alpha.\n");
    }
}

int panduan(char c)
{
    if(c>='a'&&c<='z') return (c-'a'+1);
    else if(c>='A'&&c<='Z') return (c-'A'+1);
    return -1;
}