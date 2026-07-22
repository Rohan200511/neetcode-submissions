class Solution {
public:

    int n;
    vector<vector<int>>dp;

    int solve(vector<int>& nums , int amount , int i){
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;

        if(i == n){
            return INT_MAX;
        }

        if(dp[i][amount] != -1) return dp[i][amount];

        int take = INT_MAX;

        if (amount >= nums[i]) {
            take = solve(nums, amount - nums[i], i);
            if (take != INT_MAX)
                take++;
        }

        int skip = solve(nums , amount , i + 1);

        return dp[i][amount] = min(take , skip);
    }

    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        dp.assign(n , vector<int>(amount + 1 , -1));
        int ans = solve(coins , amount , 0);

        return ans ==  INT_MAX ? -1 : ans;
    }
};
