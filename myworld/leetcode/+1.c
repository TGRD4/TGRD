int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    for(int i = digitsSize - 1;i >= 0;i--)
    {
        if(digits[i] == 9)
            digits[i] = 0;//是9就进位(默认+1)
        else
        {
            digits[i]++;//只要有一位进不了更前面的位都进不了总位数也进不了
            *returnSize = digitsSize;
            return digits;
       }
    }
    *returnSize = digitsSize + 1;//返回数组长度+1
    int *s = (int*)malloc(sizeof(int)*(digitsSize + 1));//为要返回的新数组分配空间
    memset(ret,0,sizeof(int)*(digitsSize + 1));//若最高位都进了一位那么只有一种情况999....+1=1000.....
    s[0] = 1;//仅开头为1其它位均为0
    return s;
}
