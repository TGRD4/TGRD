bool canJump(int* nums, int numsSize){
    int x = 0;
    for (int r = 0; x < numsSize && x <= r; ++x) 
        r = fmax(r, x + nums[x]);
    return x >= numsSize;
}
/*
用max记录前面的点能跳到的最大的位置——比如说某个点，从起点经过一系列跳跃之后能到达这个点，那么在这个点能跳到的最大位置就是这个点的索引加上这个点的值，
然后前面的点能跳到的最大位置可能就已经超过这个点能跳到的最大位置了（这个位置保存在max中），所以，每次max更新要比较当前最大位置跟已有max值，取较大值
如果某个点的索引值超过了max，那说明前面的点无论怎么跳，都到不了当前位置，那后面的位置就更到不了了，肯定也到不了终点，直接返回false就好
如果循环结束了，也没有找到到不了的点，那就返回true
*/
bool canJump(int* nums, int numsSize)
{
    if (numsSize <= 0) 
        return false;
    int endReachable = numsSize - 1;
    for (int i = numsSize - 1; i >= 0; i--) 
        if (nums[i] + i >= endReachable) 
            endReachable = i;
    return endReachable == 0;
}