void swap(int *a, int *b) 
{
    int t = *a;
    *a = *b, *b = t;
}
void moveZeroes(int *nums, int numsSize) 
{
    int left = 0, right = 0;
    while (right < numsSize) 
    {
        if (nums[right]) //若不是0则不用删除
        {
            swap(nums + left, nums + right);
            left++;//left++去除掉前面的0
        }
        right++;//若是0则只加right
    }
}


void moveZeroes(int* nums, int numsSize)
{
    int k=0, temp;                                 
    for(int i=0; i<numsSize; i++)
    {         
        if(!nums[i]) k++;//记录0的个数                            
        else
        {                             
            temp = nums[i];                 
            nums[i] = nums[i-k];//交换0的个数次数
            nums[i-k] = temp;
        }
    }
}

