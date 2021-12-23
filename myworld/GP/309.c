int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 0) 
        return 0;
    int f0 = -prices[0], f1 = 0, f2 = 0;
    for (int i = 1; i < pricesSize; ++i) {
        int newf0 = fmax(f0, f2 - prices[i]);
        int newf1 = f0 + prices[i];
        int newf2 = fmax(f1, f2);
        f0 = newf0, f1 = newf1, f2 = newf2;
    }
    return fmax(f1, f2);
}