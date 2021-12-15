char Change(char a) 
{
    if (a == '}') return '{';
    if (a == ']') return '[';
    if (a == ')') return '(';
    return '0';
}
bool isValid(char* s) 
{
    int len = strlen(s);
    char ch;
    int st[len + 1], top = 0,i;
    if (len % 2 == 1)//括号配对必须是偶数个
        return false;
    for (i = 0; i < len; i++) 
    {
        ch = Change(s[i]);
        if (ch!='0')//遇到右括号出栈
        {
            if (top == 0 || st[top - 1] != ch) //若右括号在开头或者与出栈的左括号不匹配则返回false
                return false;
            top--;
        }
        else //左括号入栈
            st[top++] = s[i];
    }
    return top == 0;
}
