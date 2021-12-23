/*
如果一个数列 至少有三个元素 ，并且任意两个相邻元素之差相同，则称该数列为等差数列。
例如，[1,3,5,7,9]、[7,7,7,7] 和 [3,-1,-5,-9] 都是等差数列。
给你一个整数数组 nums ，返回数组 nums 中所有为等差数组的 子数组 个数。
子数组 是数组中的一个连续序列。
*/
int numberOfArithmeticSlices(int* nums, int numsSize) {
    if (numsSize <= 2) 
        return 0;
    int d = nums[0] - nums[1], t = 0;
    int sum = 0;
    // 因为等差数列的长度至少为 3，所以可以从 i=2 开始枚举
    for (int i = 2; i < numsSize; i++) {
        if (nums[i - 1] - nums[i] == d) 
            t++;
        else {
            d = nums[i - 1] - nums[i];
            t = 0;
        }
        sum += t;
    }
    return sum;
}
