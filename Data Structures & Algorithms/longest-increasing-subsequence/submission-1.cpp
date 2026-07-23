#include<cstring>
class Solution {
public:
    int n;
    long long t[2501][2501];

    long long solve(vector<int>& nums , int n , int i , int prev){
        if(i >= n) return 0;

        if(prev != -1 && t[i][prev] != -1) return t[i][prev];

        long long take = 0;
        if(prev == -1 || nums[i] > nums[prev])
            take = 1 + solve(nums , n , i + 1 , i);

        long long skip = solve(nums , n , i + 1 , prev);
        
        if(prev != -1) t[i][prev] = max(take , skip);

        return max(take , skip); 
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        memset(t , -1 , sizeof(t));
        return solve(nums , n , 0 , -1);
    }
};