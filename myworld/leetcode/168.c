void reverse(char* str, int strSize)//反转数组
{
    int left = 0, right = strSize - 1;
    while (left < right) 
    {
        char tmp = str[left];//左右交换
        str[left] = str[right], str[right] = tmp;
        left++;
        right--;
    }
}
char* convertToTitle(int columnNumber) 
{
    char* ans = malloc(sizeof(char) * 44);//为新数组分配空间
    int ansSize = 0;//数组长度
    while (columnNumber > 0) 
    {
        columnNumber--;//原数组长度
        ans[ansSize++] = columnNumber % 26 + 'A';//转换为字母相当于进行二十六进制转换(1=A)
        columnNumber /= 26;
    }
    ans[ansSize] = '\0';//截断防止出现乱码
    reverse(ans, ansSize);
    return ans;
}