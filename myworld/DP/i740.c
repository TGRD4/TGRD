I.删除并获得点数
/*
https://leetcode-cn.com/problems/delete-and-earn/
*/
/*给你一个整数数组 nums ，你可以对它进行一些操作。每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。
之后，你必须删除 所有 等于 nums[i] - 1 和 nums[i] + 1 的元素。开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数。
*/
int rob(int *nums, int numsSize);
int deleteAndEarn(int *nums, int numsSize) 
{
    int max = 0;
    for (int i = 0; i < numsSize; i++) 
        max = fmax(max, nums[i]);//循环求数组中最大值
    int *sum=(int*)calloc(sizeof(int),(max + 1));//所有数字初始化为0相当于一开始都不存在
    for (int i = 0; i < numsSize; i++) 
        sum[nums[i]] += nums[i];//从小到大寻找存在的数就相当于在新数组中进行排序（从小到大）
    return rob(sum, max + 1);//+1防溢出
}
int rob(int *nums, int numsSize) 
{
    /*因为已经排好序，要满足题目删除左右-1/+1的数，也就相当于隔一位取一位，
    此时就变成了经典的bp问题，解题思路和之前一样*/
    int first = nums[0], second = fmax(nums[0], nums[1]);//省内存的写法（不用申请一个数组）
    for (int i = 2; i < numsSize; i++) {
        int temp = second;
        second = fmax(first + nums[i], second);
        first = temp;
    }//和c题进阶写法相同
    return second;
}