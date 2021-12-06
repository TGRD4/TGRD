int maxSubArray(int* nums, int numsSize)
{
    int i;
    int sum=0;
    int tmp=0;
    int count=0;
    int max=nums[0];
    for(i=0;i<numsSize;i++)
    {
        if(max<nums[i])
        {
            max=nums[i];
        }
        if(nums[i]<0)
        {
            count++;
        }
        if(count==numsSize)
        {
            return max;//max和count仅用来判断全是负数的情况
        }

        sum+=nums[i];
        if(sum<0)//若加成负数则再从0开始加
        {
            sum=0; 
        }
        if(tmp<sum)//保留最大值
        {
            tmp=sum;
        }
    }
    return tmp;
}
