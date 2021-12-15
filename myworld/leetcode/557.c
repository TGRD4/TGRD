char * reverseWords(char * s)
{
    int len=strlen(s);
    char *a=(char*)calloc(sizeof(char),(len+1));//初始化为0否则空时返回随机值
    int i=0;
    while(i<len)//总长度0~(len-1)
    {
        int k=i;//k表示每次单词开头位置（上个单词结尾位置）
        while(i<len&&s[i]!=' ')
            i++;//i记录单词长度
        for(int j=k;j<i;j++)//i是单词结尾位置
            a[j]=s[k+i-j-1];//将单词长度的字符串加入a[]中（//从s[i-1]开始回退到s[k]输出字符进a[j]）
        while(i<len&&s[i]==' ')//可能不止一个空格
        {
            a[i]=' ';
            i++;//i加上空格长度
        }
        //i就是总长度
    }
    return a;
}