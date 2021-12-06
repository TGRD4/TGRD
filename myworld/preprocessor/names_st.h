#include<string.h>
#ifndef NAMES_H_//避免文件被重复包含(如果NAMES未被定义过(第一次调用该文件)则定义endif前的所有内容)
    #define NAMES_H_
    #define N 32
    typedef struct names_st
    {
        char first[N];
        char last[N];
    }names;

    void get_names(names*);
    void show_names(names*);
    char*s_gets(char*st,int n);
#endif
