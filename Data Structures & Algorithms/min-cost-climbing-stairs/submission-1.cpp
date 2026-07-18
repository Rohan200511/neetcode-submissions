class Solution {
public: 
    int n;
    vector<int>dp;
    int solve(vector<int>& cost , int i){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] =  cost[i] + min(solve(cost , i + 1) , solve(cost , i + 2));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        dp.assign(n + 1 , -1);
        return min(solve(cost , 0) , solve(cost , 1));
    }
};
