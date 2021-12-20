int lengthOfLIS(int* nums, int numsSize) 
{
    int dp[numsSize+1];
    int max = 0;//初始化max=0当numsSize为0时返回0
    for (int i = 0; i < numsSize; i++) 
    {
        dp[i] = 1;//最短是1（i=0时）/ 每次不满足递增时返回后再初始化长度是1
        for (int j = 0; j < i; j++) //判断当前位之前的所有位上的数字与本位的大小关系
        //每次判断时j都从0开始是因为题目要求不是连续递增而是在整个数列中存在递增即可
        {
            if (nums[i] > nums[j]) //当第j位小于本位(i)时记录更新最大长度
                dp[i] = fmax(dp[i], dp[j] + 1);//dp记录前i个数递增的数列最大长度
        }
        max = fmax(max, dp[i]);//保留前i,i-1,i-2...中的最大递增长度
    }
    return max;
}
