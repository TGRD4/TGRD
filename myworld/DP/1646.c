int getMaximumGenerated(int n) {
    if (n == 0) 
        return 0;
    else if(n == 1)
        return 1;
    int nums[n + 1];
    int max = 1;
    nums[1] = 1;
    for (int i = 2; i <= n; i++) {
        nums[i] = (nums[i / 2]) + (i % 2 * nums[i / 2 + 1]);
        max = fmax(max, nums[i]);
    }
    return max;
}
