int robRange(int* nums, int start, int end) 
{
    int first = nums[start], second = fmax(nums[start], nums[start + 1]);
    for (int i = start + 2; i < end; i++) 
    {
        int temp = second;
        second = fmax(first + nums[i], temp);
        first = temp;
    }
    return second;
}
int robRange(int* nums, int start, int end) 
{
    int *dp=(int*)malloc(sizeof(int)*1001);
    dp[start] = nums[start], dp[start+1] = fmax(nums[start], nums[start + 1]);
    for (int i = start + 2; i < end; i++) 
        dp[i] = fmax(dp[i-2] + nums[i], dp[i-1]);
    return dp[end-1];//内存占用较大
}
int rob(int* nums, int numsSize) 
{
    if (numsSize == 1) 
        return nums[0];
    else if (numsSize == 2) 
        return fmax(nums[0], nums[1]);
    /*把环形看作两个单向，一个从0开始取不到最后一个，另一个从1开始可以取到最后一个，
    再对这两个获得的最大数取最大值，返回最大值*/
    return fmax(robRange(nums, 0, numsSize - 1), robRange(nums, 1, numsSize));
}
