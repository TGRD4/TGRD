
#line 1000//重置行号为1000
#line 10 "cool.c" //重置行号为10并且重置文件名为"cool.c"

#if __STDC_VERSION__!=201112L
#error Not C11//编译失败说明不支持C11标准
/*error指令让预处理器发出一条错误信息，该信息包含指令中的文本，编译中断*/
#endif
