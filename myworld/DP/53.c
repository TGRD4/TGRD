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
            max=sum;//更新最大值
    }
    return max;
}
int maxSubArray(int* nums, int numsSize) 
{
    int pre = 0, max = nums[0];
    for (int i = 0; i < numsSize; i++) 
    {
        pre = fmax(pre + nums[i], nums[i]);//保留前i位最大值为pre
        max = fmax(max, pre);//保留前i,i-1,i-2....位中最大的值
    }
    return max;//返回最大值
}
