int maxSubArray(int* nums, int numsSize) 
{
    int pre = 0, max = nums[0];
    for (int i = 0; i < numsSize; i++) 
    {
        pre = fmax(pre + nums[i], nums[i]);//保留前i位最大值为pre
        max = fmax(max, pre);//保留前i,i-1,i-2....位中最大的值
    }
    return max;//返回最大值
}
int minSubArray(int* nums, int numsSize) 
{
    int pre = 0, min = nums[0];
    for (int i = 1; i < numsSize-1; i++) 
    {
        pre = fmin(pre + nums[i], nums[i]);
        min = fmin(min, pre);
    }
    return min;
}
int maxSubarraySumCircular(int* nums, int numsSize)
{
    if(numsSize==1) return nums[0];
    int max,min,sum=0;
    max=maxSubArray(nums,numsSize);
    min=minSubArray(nums,numsSize);
    for(int i=0;i<numsSize;i++)
        sum+=nums[i];
    return fmax(sum-min,max);//比较无环和有环的情况求出最大和
}

/*
环形子数组的最大和具有两种可能，一种是不使用环的情况，另一种是使用环的情况
不使用环的情况时，直接通过53题的思路，逐步求出整个数组中的最大子序和即可
【重点】使用到了环，则必定包含 A[n-1]和 A[0]两个元素且说明从A[1]到A[n-2]这个子数组中必定包含负数
否则只通过一趟最大子序和就可以的=得出结果
因此只需要把A[1]-A[n-2]间这些负数的最小和求出来
用整个数组的和 sum减掉这个负数最小和即可实现原环型数组的最大和
最后再比较直接通过53题思路求出无环子序列和用sum-min的有环子序列比较大小求出整个数组的最大值即可！
*/