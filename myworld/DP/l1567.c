 
L. 乘积为正数的最长子数组长度
/*
https://leetcode-cn.com/problems/maximum-length-of-subarray-with-positive-product/
*/
/*给你一个整数数组 nums ，请你求出乘积为正数的最长子数组的长度。
一个数组的子数组是由原数组中零个或者更多个连续数字组成的数组。
请你返回乘积为正数的最长子数组长度。*/


/*两种情况：负数是偶数个，负数是奇数个，分别判断即可*/
int getMaxLen(int* nums, int numsSize){
    // neg负、pos正数个数 第一个负数出现的位置first
    int neg = 0, pos = 0, fisrt = -1, max = 0;
    for (int i = 0; i < numsSize; i++) 
    {
        if (nums[i] == 0) {
            // 遇到0所有标记初始化
            pos = 0;
            neg = 0;
            fisrt = -1;
        } 
        else if (nums[i] > 0) //计正数加一
            pos++;
        else {
            // 记录该段第一个负数出现的位置
            if (fisrt == -1) 
                fisrt = i;
            neg++;//负数加一
        }
        if (neg % 2 == 0) //若负数是偶数个，正数总长度为负数加正数总数
            // 该段所有负数乘积为正
            max = fmax(max, pos + neg);//乘积是正数的总长度为负数加正数总数
        else //负数为单数（不能转换为正数）
            // 从第一个负数出现的位置后面 到当前位置的乘积为正（舍去第一个负数）
            max = fmax(max, i - fisrt);//max保留已遍历过的子序列中乘积是正数的最大子序列长度
    }
    return max;//返回最大长度
}