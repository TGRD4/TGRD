int jump(int* nums, int numsSize)
{
    int cnt = 0;
    for(int cur = 0,r = 1;r < numsSize;cnt++)//跳一次次数加1,直到最后一位是numsSize-1退出
    {
        int max = r;//max保留上一个点能到达的最大位置
        for(;cur < r;cur++)
            max = fmax(max,cur + nums[cur] + 1);//更新最大位置为（上一个点能达到的最大位置）与（这一个点的位置加上从这一点能跳到的最大位置）的较大值
        r = max;//保留这一个点能达到的最大位置
    }
    return cnt;//输出跳跃次数
}
