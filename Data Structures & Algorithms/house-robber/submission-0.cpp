class Solution {
public:
    int n;
    vector<int>dp;
    int solve(vector<int>& nums , int i){
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int skip = solve(nums , i+1);
        int take = nums[i] + solve(nums , i+2);

        return dp[i] = max(skip , take);
    }

    int rob(vector<int>& nums) {
        n = nums.size();
        dp.assign(n+1 , -1);
        return solve(nums , 0);
    }
};
