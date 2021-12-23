/*贪心算法（在当前做出最好选择，而不从整体考虑）*/
int maxProfit(int* prices, int pricesSize) 
{
    int ans = 0;
    for (int i = 1; i < pricesSize; ++i) 
        ans += fmax(0, prices[i] - prices[i - 1]); /*每一天要么没赚钱要么赚了钱
（以两天作为一组）如果第二天价格高于第一天，加上利润；若第二天价格低于第一天，不赚钱加零*/
    return ans;
}
