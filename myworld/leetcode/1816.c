/*截断句子，保留前k个单词*/
char * truncateSentence(char * s, int k)
{
    char*p = s;
    while(*p)
    {
        if(*p==' '&&--k==0)
        //若出现空格,k--的同时判断满不满足截断条件
        {
            *p='\0';
            return s;
        }
        ++p;
    }
    return s;
}

