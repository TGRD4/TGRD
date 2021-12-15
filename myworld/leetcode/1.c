int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) 
{
    for (int i = 0; i < numbersSize; ++i) 
    {
        for(int j=i+1;j<numbersSize;++j)
        {
            if (numbers[i] == target - numbers[j]) 
            {
                int* ret = (int*)malloc(sizeof(int) * 2);
                *returnSize = 2;
                ret[0] = i + 1, ret[1] = j+ 1;
                return ret;
            }
        }
    }
    int* ret = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    ret[0] = -1, ret[1] = -1;
    return ret;
}
//二分法
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) 
{
    int* ret = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;//返回数组长度为两个下标，长度为2
    for (int i = 0; i < numbersSize; i++) 
    {
        int low = i + 1, high = numbersSize - 1;//加数被加数不能相同
        while (low <= high) 
        {
            int mid = (high - low) / 2 + low;
            if (numbers[mid] == target - numbers[i]) 
            {
                ret[0] = i + 1, ret[1] = mid + 1;
                return ret;
            }
            else if (numbers[mid] > target - numbers[i]) //二分法只适用于递增递减数列
                high = mid - 1;
            else //从第一个数开始作为被加数，后续数列中的中间数作为加数，若两数相加大于目标数则加数向前取一位若小于则加数向后移一位
                low = mid + 1;
        }
    }
    ret[0] = -1, ret[1] = -1;
    return ret;
}