int massage(int* nums, int numsSize)
{
    int t1 = 0, t2 = 0;
    for (int i=0; i<numsSize; i++) {
        int t = fmax(t1+nums[i], t2);//对比前(i-2)最大值 + (i)当前位的和 与 前i-1的最大值，保留最大值（不能连续）
        t1 = t2;//t1暂存前i-2位最大值
        t2 = t;//t2保留前i位最大值
    }
    return t2;//整个数列最大值
}