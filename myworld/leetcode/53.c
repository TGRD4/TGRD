int maxSubArray(int* nums, int numsSize)
{
    int max=nums[0];
    int sum=0;
    for(int i=0;i<numsSize;i++)
    {
        sum+=nums[i];
        if(nums[i]>sum)//当nums[i]大于前面子序加起来的和，num[i]则变为子序的第1项
            sum=nums[i];
        if(sum>max)
            max=sum;
    }
    return max;
}