class Solution {
public:
    
    int n;

    void solve(vector<int>& nums, vector<vector<int>>& ans, int i){
        
        if(i == n){
            ans.push_back(nums);
            return;
        }

        for(int indx = i ; indx < n ; indx++){
            swap(nums[indx] , nums[i]);
            solve(nums, ans, i + 1);
            swap(nums[indx] , nums[i]);
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>>ans;
        solve(nums , ans, 0);

        return ans;
    }
};
