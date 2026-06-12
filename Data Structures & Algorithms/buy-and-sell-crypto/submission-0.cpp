class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        int minBuy = prices[0];

        for(int i = 0 ; i < n ; i++){
            profit = max(profit , prices[i] - minBuy);

            minBuy = min(minBuy , prices[i]);
        }
        return profit;
    }
};
