#define MAX 1001
int minCostClimbingStairs(int* cost, int costSize)
{
    // 第 i 个位置可以从 第 i - 2 位置跳过来，也可以从 i - 1 位置跳过来
    // 所以 dp[i] = fmin(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1])
    // dp[0] = 0, dp[1] = 0 因为这两个位置都可以直达
    int dp[MAX];
    dp[0] = 0,dp[1] = 0;
    for (int i = 2; i <= costSize; i++) 
        dp[i] = fmin(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        //求跳到i-1位置的总耗费体力数加上从i-1位置跳到i（当前）位置和从i-2跳过来的体力数耗费最小值
    return dp[costSize];
}
