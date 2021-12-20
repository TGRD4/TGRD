int getMaxLen(int* nums, int numsSize){
    // 负、正数个数 第一个负数出现的位置
    int neg = 0, pos = 0, fisrt = -1, ans = 0;
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
        if (neg % 2 == 0) 
            // 该段所有负数乘积为正
            ans = fmax(ans, pos + neg);//正数总长度为负数加正数总数
        else //负数为单数（不能转换为正数）
            // 从第一个负数出现的位置后面到当前位置的乘积为正
            ans = fmax(ans, i - fisrt);
    }
    return ans;
}