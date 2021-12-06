#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define N 80
#define NUMBER 4

void Menu(void);
void Input(char st[][N]);
void Output1(char st[][N]);
void Output2(char st[][N]);
void Output3(char st[][N]);
void Output4(char st[][N]);
void Sort(int str[][2]);
int Length(char *str);

int main()
{
    char s[NUMBER][N];
    int choice;
    Input(s);
    Menu();
    scanf("%d",&choice);
    while(choice!=5)
    {
        switch(choice)
        {
            case 1:Output1(s);break;
            case 2:Output2(s);break;
            case 3:Output3(s);break;
            
            case 4:Output4(s);break;
            case 5:break;
            default:printf("please make the rigth choice!\n");break;
        }
        getchar();getchar();
        Menu();
        scanf("%d",&choice);
    }
    printf("all done!\n");
}

void Input(char st[][N])//输入
{
    printf("please input 4 strings by enter:\n");
    for(int i=0;i<NUMBER;i++)
        fgets(st[i],N,stdin);
}

void Output1(char st[][N])//直接输出
{
    for(int i=0;i<NUMBER;i++)
        printf("%d.%s\n",i+1,st[i]);
}

void Output2(char st[][N])//ascii排序
{
    int str[NUMBER][2];
    for(int i=0;i<NUMBER;i++)
    {
        str[i][0]=i;
        str[i][1]=st[i][0];
    }
    Sort(str);
    for(int i=0;i<NUMBER;i++)
        printf("%d.%s\n",i+1,st[str[i][0]]);
}

void Output3(char st[][N])//数组长度排序
{
    int str[NUMBER][2];
    for(int i=0;i<NUMBER;i++)
    {
        str[i][0]=i;
        str[i][1]=strlen(st[i]);
    }
    Sort(str);
    for(int i=0;i<NUMBER;i++)
        printf("%d.%s\n",i+1,st[str[i][0]]);
}

void Output4(char st[][N])//单词长度排序
{
    int str[NUMBER][2];
    for(int i=0;i<NUMBER;i++)
    {
        str[i][0]=i;
        str[i][1]=Length(st[i]);
    }
    Sort(str);
    for(int i=0;i<NUMBER;i++)
        printf("%d.%s\n",i+1,st[str[i][0]]);
}

void Sort(int str[][2])//排序
{
    int temp[2];
    for(int i=0;i<NUMBER-1;i++)
    {
        for(int j=0;j<NUMBER-1-i;j++)
        {
            if(str[j][1]>str[j+1][1])
            {
                temp[0]=str[j][0];
                temp[1]=str[j][1];
                str[j][0]=str[j+1][0];
                str[j][1]=str[j+1][1];
                str[j+1][0]=temp[0];
                str[j+1][1]=temp[1];
            }
        }
    }
}

int Length(char *str)//计算单词长度
{
    char *p=str;
    int len=0;
    while(isalpha(*p)==0) p++;
    while(isalpha(*p)!=0)
    {
        p++;
        len++;
    }
    return len;
}

void Menu(void)
{
    printf("1.print strings.\n");
    printf("2.print strings by ascii.\n");
    printf("3.print strings by length.\n");
    printf("4.print strings by word length.\n");
    printf("5.quit.\n");
    printf("make the choice:");
}