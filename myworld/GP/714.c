int maxProfit(int* prices, int pricesSize, int fee) {
    int sell = 0, buy = -prices[0];//一开始只能买入（无利益）
    for (int i = 1; i < pricesSize; ++i) {
        sell = fmax(sell, buy + prices[i] - fee);
        buy = fmax(buy, sell - prices[i]);
    }
    return sell;
}
