int fib(int n){
    long *dp = (long *)malloc(101*sizeof(long));
    dp[0] = 0;
    dp[1] = 1;
    for (int i=2;i<=n;i++)
        dp[i] = (dp[i-1] + dp[i-2]) % 1000000007;//取模否则会超出时间限制
    return dp[n];
}
