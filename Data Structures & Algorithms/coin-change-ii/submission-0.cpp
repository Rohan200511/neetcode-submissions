class Solution {
public:

    int n;
    vector<vector<int>>dp;

    int solve(vector<int>& nums , int amt , int i){
        if(amt == 0) return 1;
        if(amt < 0) return 0;
        if(i == n){
            if(amt == 0) return 1;
            return 0;
        }

        if(dp[i][amt] != -1) return dp[i][amt];

        int take = 0;
        if(amt >= nums[i]){
            take = solve(nums , amt - nums[i] , i);
        }

        int skip = solve(nums , amt , i + 1);

        return dp[i][amt] = take + skip;

    }

    int change(int amount, vector<int>& coins) {
        n = coins.size();
        dp.assign(n , vector<int>(amount + 1 , -1));
        return solve(coins , amount , 0);
    }
};
