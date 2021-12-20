int maxProfit(int* prices, int pricesSize)
{
    int min = prices[0],max = 0;
    for(int i = 0;i < pricesSize;i++)
    {
        if(min > prices[i])
            min = prices[i];//保留买入股票最便宜的价格
        if(prices[i] - min > max)
            max = prices[i] - min;//保留卖出股票最贵的价格
    }
    return max;
}