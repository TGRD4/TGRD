/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize){
    *returnSize=n+1;
    int *result=(int*)malloc(sizeof(int)*(*returnSize));
    result[0] = 0;//正数符号为是0
    for(int i = 1; i <= n; i++)
    {
        if(i % 2 == 1)
            result[i] = result[i-1] + 1;//奇数的1的个数比前一个偶数多1
        else
            result[i] = result[i/2];//偶数的1等于本身/2
    }
    return result;
}
