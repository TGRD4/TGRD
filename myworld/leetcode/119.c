int* getRow(int rowIndex, int* returnSize)
{
    *returnSize = rowIndex+1;//数组长度等于数组行数下标+1
    int *s = (int *)malloc(sizeof(int)*(*returnSize));//只为输出单行数组分配内存空间
    memset(s,0,sizeof(int)*(*returnSize));//将此行初始化为0
    s[0]=1;//数组开头数为0
    for(int i = 1; i <= *returnSize ; i++)
        for(int j = i; j > 0; j--)
            s[j]+=s[j-1];
    return s;
}