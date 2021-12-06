/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes)
{
    *returnSize = numRows;//returnSize为二维数组的行数
    *returnColumnSizes = (int *)malloc(sizeof(int)*numRows);//returnColomnSizes为指向每一行数组的指针，数组元素为每一行数组元素个数
    int **s = (int **)malloc(sizeof(int*)*(*returnSize));//s是一个指针，指向由指针构成的数组，每个指针都指向对应的三角的一行数；s也是二维数组。
    for(int i=0;i<*returnSize;++i)
    {
        (*returnColumnSizes)[i] = i+1;//每行数组个数为i+1
        s[i] = (int *)malloc(sizeof(int)*((*returnColumnSizes)[i]));//为每一行分配内存空间

        s[i][0] = 1;//每行第一个数为1
        s[i][i] = 1;//每行最后数为1
    }
    for(int i = 2; i < numRows ; i++)
        for(int j = 1; j < i; j++)
            s[i][j] = s[i - 1][j - 1] + s[i - 1][j];
    return s;
}
