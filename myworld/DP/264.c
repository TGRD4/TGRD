/*给你一个整数 n ，请你找出并返回第 n 个 丑数 。
丑数 就是只包含质因数 2、3 和/或 5 的正整数。
*/
int nthUglyNumber(int n) { 
    int dp[n + 1];
    dp[1] = 1;
    int p2 = 1, p3 = 1, p5 = 1;
    for (int i = 2; i <= n; i++) {
        int num2 = dp[p2] * 2, num3 = dp[p3] * 3, num5 = dp[p5] * 5;
        dp[i] = fmin(fmin(num2, num3), num5);
        if (dp[i] == num2) 
            p2++;
        if (dp[i] == num3) 
            p3++;
        if (dp[i] == num5) 
            p5++;
    }
    return dp[n];
}
