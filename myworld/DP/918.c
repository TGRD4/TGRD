#define MAX(A, B) ((A) > (B) ? (A) : (B))
int maxSubarraySumCircular(int* A, int ASize){
    int i;
    int j = 0;
    int minCnt = 0;
    int sum = 0;
    int dp[ASize];
    int result = A[0];
    dp[0] = A[0];
    for (i = 1; i < ASize; i++) {
        dp[i] = MAX(dp[i - 1] + A[i], A[i]);
        result = MAX(dp[i], result);
    }
    if (i != 1) {
        dp[0] = A[0];
        sum = A[0];
        for (i = 1; i < ASize; i++) {
            sum += A[i];
            dp[i] = MAX(sum, dp[i - 1]);
        }
        sum = 0;
        for (j = ASize - 1; j > 0; j--) { 
            sum += A[j];
            result = MAX(result, dp[j - 1] + sum);
        }
    }
    return result;
}
