/*
https://leetcode-cn.com/problems/min-cost-climbing-stairs/
*/
G.花费最小爬楼梯
/*数组的每个下标作为一个阶梯，第 i 个阶梯对应着一个非负数的体力花费值 cost[i]（下标从 0 开始）。
每当你爬上一个阶梯你都要花费对应的体力值，一旦支付了相应的体力值，你就可以选择向上爬一个阶梯或者爬两个阶梯。
请你找出达到楼层顶部的最低花费。在开始时，你可以选择从下标为 0 或 1 的元素作为初始阶梯。
*/
#define MAX 1001
int minCostClimbingStairs(int* cost, int costSize)
{
    int dp[MAX];//此时dp数组用来存放 跳到 每一位的最小体力耗费
    dp[0] = 0,dp[1] = 0;//因为这两个位置都可以直达（作为初始阶梯），所以耗费体力为0
    for (int i = 2; i <= costSize; i++) 
        dp[i] = fmin(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);//第 i 个位置可以从第 i-2 位置跳过来，也可以从 i-1 位置跳过来
        /*取从前面跳到i-1位置耗费的体力数(dp[i - 1])加上从i-1位置跳到当前位置耗费的体力数(cost[i - 1])
        和从前面跳到i-2位置耗费的体力数(dp[i - 2])加上从i-2位置跳到当前位置耗费的体力数(cost[i - 2])中的最小耗费体力值*/
    return dp[costSize];//返回储存在最后一位上的跳完所有阶梯所花费的最小体力值
}
/*此处不是[costSize-1]，是因为dp[costSize-1]保存的是 跳到 最后一个台阶所花费的体力值，
而还需要加上从最后一个台阶跳出去到终点的体力值储存在dp[costSize]中*/
