int rob(int* nums, int numsSize)
{
    if(numsSize==0)
        return 0;    
    if(numsSize==1)
        return nums[0];
    if(numsSize==2)
         return fmax(nums[0],nums[1]);
    int dp[numsSize+1];
    dp[0]=nums[0];
    dp[1]=fmax(nums[0],nums[1]);//求出前两位数的最大和放在第二位，方便前三位数最大和与第四位加上前两位最大和的比较
    for(int i=2;i<numsSize;i++)
        dp[i]=fmax(dp[i-2]+nums[i],dp[i-1]);//求出前i位数的最大和放在i位，方便前i+1位数最大和与第i+2加上前i位和的比较
    //实际就是不停移动且改变的三个数的比较，循环一直将前面所有数的最大和放在本位上
    return dp[numsSize-1];//返回最后一位数（所有数最大和）
}
