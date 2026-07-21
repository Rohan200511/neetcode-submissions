class Solution {
public:
    int n;
    vector<vector<int>> dp;

    bool solve(vector<int>& nums , int i , int target){
        if(target == 0) return true;
        if (target < 0) return false;
        if(i >= n) return target == 0;
        
        if(dp[i][target] != -1) return dp[i][target];

        bool pick = solve(nums , i + 1, target - nums[i]);
        bool not_pick = solve(nums , i + 1 , target);

        return dp[i][target] = pick || not_pick;
    }

    bool canPartition(vector<int>& nums) {
        n = nums.size();
        int sum = accumulate(nums.begin() , nums.end() , 0);

        if(sum % 2 == 1) return false;

        dp.assign(n, vector<int>((sum / 2) + 1, -1));

        return solve(nums , 0 , sum / 2);
    }
};
