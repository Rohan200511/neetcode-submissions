class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>>dp(n + 1 , vector<int>(amount + 1 , INT_MAX));

        for(int i = 0 ; i < n ; i++){
            dp[i][0] = 0;
        }

        for(int j = n - 1 ; j >= 0 ; j--){
            for(int a = 1 ; a <= amount ; a++){
                
                dp[j][a] = dp[j + 1][a];

                if(a >= coins[j] && dp[j][a - coins[j]] != INT_MAX){
                    dp[j][a] = min(dp[j][a] , dp[j][a - coins[j]] + 1);
                }
            }
        }
        return dp[0][amount] == INT_MAX ? -1 : dp[0][amount];
    }
};
