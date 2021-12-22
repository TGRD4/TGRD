/*最短跳跃次数*/
E.
/*
https://leetcode-cn.com/problems/jump-game-ii/
*/

/*
给你一个非负整数数组 nums ，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
你的目标是使用最少的跳跃次数到达数组的最后一个位置。
假设你总是可以到达数组的最后一个位置。
*/

/*基本思路都相同*/
int jump(int* nums, int numsSize)
{
    int cnt = 0, k = 0, max = 0;//设置最大跳跃距离max,跳跃次数cnt,暂存变量k
    for (int i = 0; i < numsSize - 1; i++) {//位置一位位增加
        max = fmax(max ,nums[i] + i);
/*与上题一致，比较从每一点跳到下一点的最大位置与从前一点能跳到的最大位置，保留最大值*/
        if (i == k) {/*当位置加到与保留的最大跳跃距离k一致时
                    将k更新为下次的最大跳跃距离max并且跳跃次数加一*/
            k = max;
            cnt++;
        }
    }
    return cnt;//到达结尾输出跳跃次数
}