int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int mn = INT_MAX, profit = 0;
    for (int ele : prices)
    {
        mn = min(mn, ele);
        profit = max(profit, ele - mn);
    }
    return profit;
}