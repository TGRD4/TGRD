#include<stdio.h>
#include"names_st.h"
void get_names(names*p)
{
    printf("please input your first name:");
    s_gets(p->first,N);
    printf("please input your last name:");
    s_gets(p->last,N);
}

void show_names(names*p)
{
    printf("%s %s",p->first,p->last);
}

char*s_gets(char*st,int n)
{
    char *s;
    char *find;
    s=fgets(st,n,stdin);
    if(s)
    {
        find=strchr(st,'\n');
        if(find)
            *find='\0';
        else
        {
            while(getchar()!='\n')
                continue;
        }
    }
    return s;
}
