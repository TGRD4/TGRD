

F.最长递增子序列

/*
https://leetcode-cn.com/problems/longest-increasing-subsequence/
*/
/*给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。
例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。*/

int lengthOfLIS(int* nums, int numsSize) 
{
    int dp[numsSize+1];
    int max = 0;//初始化max=0当numsSize为0时返回0
    for (int i = 0; i < numsSize; i++) {//一层循环遍历数组的每一项
        dp[i] = 1;//每次不满足递增时返回后 再初始化递增子序列长度是1
        for (int j = 0; j < i; j++) {//判断本位之前所有位上的数字与本位的大小关系

        //每次判断时j都从0开始是因为题目要求不是连续递增而是在整个数列中递增即可
            if (nums[i] > nums[j]) //当第j位小于本位时记录更新最大长度
                dp[i] = fmax(dp[i], dp[j] + 1);//dp保留前i个数递增的数列最大长度
        }
        max = fmax(max, dp[i]);//保留已遍历过的子序列中的最大递增长度
        //和第一题思路一致，可以选择只保留这一位 或者加上这一位 或者不保留这一位，三种情况
    }
    return max;
}
