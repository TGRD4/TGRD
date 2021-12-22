J.环形子数组的最大和

/*
https://leetcode-cn.com/problems/maximum-sum-circular-subarray/
*/
/*给定一个由整数数组 A 表示的环形数组 C，求 C 的非空子数组的最大可能和。
在此处，环形数组意味着数组的末端将会与开头相连呈环状。（形式上，当0 <= i < A.length 时 C[i] = A[i]，且当 i >= 0 时 C[i+A.length] = C[i]）
此外，子数组最多只能包含固定缓冲区 A 中的每个元素一次。（形式上，对于子数组 C[i], C[i+1], ..., C[j]，不存在 i <= k1, k2 <= j 其中 k1 % A.length = k2 % A.length）*/


/*分别求出数列最大最小子序列值（和a题相同）*/
int maxSubArray(int* nums, int numsSize) 
{
    int pre = 0, max = nums[0];
    for (int i = 0; i < numsSize; i++) {
        pre = fmax(pre + nums[i], nums[i]);
        max = fmax(max, pre);
    }
    return max;//返回最大值
}
int minSubArray(int* nums, int numsSize) 
{
    int pre = 0, min = nums[0];
    for (int i = 1; i < numsSize-1; i++) {
        pre = fmin(pre + nums[i], nums[i]);
        min = fmin(min, pre);
    }
    return min;//返回最小值
}
int maxSubarraySumCircular(int* nums, int numsSize)
{
    if(numsSize==1) return nums[0];
    int max,min,sum=0;
    max=maxSubArray(nums,numsSize);//最小子序列和
    min=minSubArray(nums,numsSize);//最大子序列和
    for(int i=0;i<numsSize;i++)//求出整个数组的和
        sum+=nums[i];
    return fmax(sum-min,max);//比较无环和有环的情况求出最大和
}

/*
环形子数组的最大和具有两种可能，一种是不使用环的情况，另一种是使用环的情况
不使用环的情况时，直接通过a题的思路，逐步求出整个数组中的最大子序和即可

使用到了环，则必定包含 A[n-1]和 A[0]两个元素且说明从A[1]到A[n-2]这个子数组中必定包含负数，
否则只通过一趟最大子序和就可以得出结果
因此只需要把A[1]-A[n-2]间这些负数的最小和求出来，
用整个数组的和减掉这个负数最小和即可以得到有环子序列的最大和
最后再比较 无环子序列和有环子序列的大小 求出整个数组的最大值
*/