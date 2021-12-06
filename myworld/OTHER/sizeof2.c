char* s = "0123456789";
sizeof(s);     //结果 4    ＝＝＝》s是指向字符串常量的字符指针
sizeof(*s);    //结果 1    ＝＝＝》*s是第一个字符
strlen(s);     //结果 10   ＝＝＝》有10个字符，strlen是个函数内部实现是用一个循环计算到\0为止之前
strlen(*s);     //结果 10   ＝＝＝》错误


char s[] = "0123456789";
sizeof(s);     //结果 11   ＝＝＝》s是数组，计算到\0位置，因此是10＋1
strlen(s);     //结果 10   ＝＝＝》有10个字符，strlen是个函数内部实现是用一个循环计算到\0为止之前
sizeof(*s);    //结果 1    ＝＝＝》*s是第一个字符

char s[100] = "0123456789";
sizeof(s);     //结果是100 ＝＝＝》s表示在内存中的大小 100×1
strlen(s);     //结果是10  ＝＝＝》strlen是个函数内部实现是用一个循环计算到\0为止之前

int s[100] = "0123456789";
sizeof(s);     //结果 400  ＝＝＝》s表示再内存中的大小 100×4
strlen(s);     //错误      ＝＝＝》strlen的参数只能是char* 且必须是以‘\0‘结尾的

char q[]="abc";
char p[]="a\n";
sizeof(q),sizeof(p),strlen(q),strlen(p);\\结果是 4 3 3 2

char p[] = {'a','b','c','d','e','f','g','h'};
char q[] = {'a','b','c','d,'\0','e','f','g'};
sizeof(p);     //结果是8 ＝＝＝》p表示在内存中的大小 8×1
strlen(p);     //为一个随机值，结果与编译器有关，不同编译器结果一般不同
sizeof(q);     //结果是8 ＝＝＝》p表示在内存中的大小 8×1
strlen(q);     //结果为4 ＝＝＝》存在'\0',遇到'\0'计算停止。




struct Stu
{
int i;//4
int j;//4
char k;//1
};
Stu stu;
printf（"%d\n",sizeof(Stu));  //结果 12  ＝＝＝》内存补齐（4/8）
printf（"%d\n",sizeof(stu));;  //结果 12  ＝＝＝》内存补齐  