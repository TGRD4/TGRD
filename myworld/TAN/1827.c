int minOperations(int* nums, int numsSize)
{
    int cnt=0;
    for(int i=1;i<numsSize;i++)
    {
        if(nums[i]<=nums[i-1])
        {
            cnt+=(nums[i-1]-nums[i]+1);
            nums[i]+=(nums[i-1]-nums[i]+1);
        }
    }
    return cnt;
}