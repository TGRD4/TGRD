int maxDistance(int* colors, int colorsSize)
{
    int ans = 0;
    for (int i = 0; i < colorsSize; i++) /*双重循环，假设确定最前面的房子必定被选上（贪心），
    再从最后向前找到与最前面color不一样的房子，一次循环中只保留第一次找到的房子（距离最远），
    每次循环保留最大值*/
    {
        for (int j = colorsSize - 1; j > i; j--) {
            if (colors[i] != colors[j]) {
                ans = fmax(ans, j - i);
                break;
            }
        }
    }
    return ans;
}


int maxDistance(int* colors, int colorsSize)
{
    int n = colorsSize;
    if (colors[0] != colors[n - 1]) //一号和最后一样恰好颜色不一样
        return n - 1;

    /* 求最左边颜色不同的房子 */
    int left = 1;
    while (colors[left] == colors[0]) 
        left++;//left此时是距离1号房子 最近 的不相同颜色的房子

    /* 求最右边颜色不同的房子 */
    int right = n - 2;
    while (colors[right] == colors[n - 1]) 
        right--;//right此时是距离最后房子 最近 的不同颜色的房子

    return fmax(right, (n - 1)-left);//返回最大值（选择一个）
}
