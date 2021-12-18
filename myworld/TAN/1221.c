int balancedStringSplit(char* s) 
{
    int cnt = 0, d = 0;
    for (int i = 0; s[i]; i++) 
    {
        s[i] == 'L' ? d++ : d--;//遇到L入栈，是R则出栈与L进行匹配
        if (!d)//栈空说明匹配成功
            cnt++;
    }
    return cnt;
}
