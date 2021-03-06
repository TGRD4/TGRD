/*
https://leetcode-cn.com/problems/house-robber/
*/
B.
/*你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，
影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
*/
/*相当于就是最大不连续子序列和*/
int rob(int* nums, int numsSize)
{
    if(numsSize==0)//没有房屋
        return 0;    
    if(numsSize==1)//一间房屋
        return nums[0];
    if(numsSize==2)//两间房屋只能偷一间
         return fmax(nums[0],nums[1]);

    /*下方用数组下标代替每一间房屋的位置*/
    
    int dp[numsSize+1];//引入dp数组 来在每一位上存放（此位前的最大不连续子序列和）和（此位）的最大和
    dp[0]=nums[0];//第一位前没有子序列所以其最大子序列和就是本位
    dp[1]=fmax(nums[0],nums[1]);/*求出前两位数的最大和放在第二位，
    方便前三位数最大和(dp[2]) 与 第四位(nums[3])加上第二位最大和(dp[1])的比较*/
    
    //进入循环比较
    for(int i=2;i<numsSize;i++){
        dp[i]=fmax(dp[i-2]+nums[i],dp[i-1]);//求出前i位数的最大和放在i位，方便前i+1位数最大和与第i+2加上前i位和的比较
    }
    //循环一直将本位前面所有数的最大和放在本位上
    return dp[numsSize-1];//返回最后一位数（就是所有数最大和）
}

/*不连续子序列和连续的不同就在于若取了此位，前一位就不能取。
所以这里的核心思想就是：
在遍历每一位时，把前几位的数列最大和放在此位上，后对每一间房屋进行判断，
比较此位加上前第两位(i-2)的偷窃最大值 和 前第一位(i-1)位的偷窃最大值，保留其中的最大值（因为不能连续偷窃）
*/
