class Solution {
public:
    int n, sum;
    vector<vector<int>> dp;

    int solve(vector<int>& nums, int i, int target) {
        if (target < -sum || target > sum)
            return 0;

        if (i == n)
            return target == 0;

        if (dp[i][target + sum] != -1)
            return dp[i][target + sum];

        int add = solve(nums, i + 1, target - nums[i]);
        int sub = solve(nums, i + 1, target + nums[i]);

        return dp[i][target + sum] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        sum = 0;

        for (int x : nums)
            sum += x;

        if (abs(target) > sum)
            return 0;

        dp.assign(n, vector<int>(2 * sum + 1, -1));

        return solve(nums, 0, target);
    }
};