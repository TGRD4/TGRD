int waysToStep(int n){
    unsigned int dp[n+3];
    dp[1]=1,dp[2]=2,dp[3]=4;
    for(int i=4;i<=n;i++){
        dp[i]=dp[i-3]+dp[i-2]+dp[i-1];//规律n
        dp[i]%=1000000007;//对结果取模
    }
    return dp[n];
}
