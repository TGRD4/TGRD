/*小偷进阶版*/
C.
/*
https://leetcode-cn.com/problems/house-robber-ii/
*/
/*房屋是一个环围在一起的，不管从那开始偷，都要满足相隔房屋不能偷的条件*/

/*
把环化成直线就成为了和前一道题一样的解法，那么怎么化成直线呢？

环有两种情况，一种是偷第一家，一种是不偷第一家，
偷第一家的话最后一家就不能偷，因为第一家和最后一家是连在一起的，
不偷第一家可能可以偷最后一家
此时环就变成了两条直线：

一条不偷第一家（start=1)，一条偷第一家（start=0）
分别对两条线路取最大值，再在最后比较两条线路的最大值，取得总最大值
*/

int robRange(int* nums, int start, int end) /*对每一条线路取最大值
                                        （用start的不同代表第一间房屋的偷窃情况）*/
{
    int *dp=(int*)malloc(sizeof(int)*1001);//还是用dp数组来保留前几位不连续子序列最大和在本位上
    dp[start] = nums[start], dp[start+1] = fmax(nums[start], nums[start + 1]);//初始化dp前两位

    //下方是和无环型最大不连续子序列一样的求值法
    for (int i = start + 2; i < end; i++) 
        dp[i] = fmax(dp[i-2] + nums[i], dp[i-1]);
    return dp[end-1];//返回最后一位上保留的所有子序列最大值
}
int rob(int* nums, int numsSize) 
{
    if(numsSize==0) 
        return 0;
    if (numsSize == 1) 
        return nums[0];
    else if (numsSize == 2) 
        return fmax(nums[0], nums[1]);
    return fmax(robRange(nums,0,numsSize-1),robRange(nums,1,numsSize));//返回两条线路最大值中的最大值
}


/*上面的robRange函数还可以这样写，不用引入数组，节省空间，思路相同*/
int robRange(int* nums, int start, int end) 
{
    int first = nums[start], second = fmax(nums[start], nums[start + 1]);
    for (int i = start + 2; i < end; i++) {
        int temp = second;//用temp暂存当前最大值
        second = fmax(first + nums[i], temp);//更新最大值
        first = temp;//将之前最大值赋值给first
    }
    return second;//返回更新后的最大值
}