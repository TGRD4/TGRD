#include<stdio.h>
#include"names_st.h"//重复包含了.h文件会报错
#include"names_st.c"
int main(void)
{
    names s;
    get_names(&s);
    printf("welcome ");
    show_names(&s);
    printf(" to the show!\n");
    return 0;
}