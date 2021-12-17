int rob(int *nums, int numsSize) 
{
    /*因为已经排好序，要满足题目删除左右-1/+1的数，也就是要隔一位取一位，
    此时就变成了经典bp问题，解题思路和之前一样*/
    int first = nums[0], second = fmax(nums[0], nums[1]);//省内存的写法（不用申请一个数组）
    for (int i = 2; i < numsSize; i++) 
    {
        int temp = second;
        second = fmax(first + nums[i], second);
        first = temp;
    }
    return second;
}
int deleteAndEarn(int *nums, int numsSize) 
{
    int max = 0;
    for (int i = 0; i < numsSize; i++) 
        max = fmax(max, nums[i]);//循环求最大值
    int *sum=(int*)calloc(sizeof(int),(max + 1));//为出现的数字初始化为0相当于不存在也就不能计算入最大总和
    for (int i = 0; i < numsSize; i++) 
        sum[nums[i]] += nums[i];//相当于在新数组中进行排序（从小到大）
    return rob(sum, max + 1);//+1防溢出
}
