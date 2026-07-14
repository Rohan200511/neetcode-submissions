class Solution {
public:
    int n;

    void solve(vector<int>& nums , vector<int>& curr , vector<vector<int>>& ans , int i){

        if(i == n){
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        solve(nums , curr , ans , i + 1);
        curr.pop_back();

        while(i + 1 < n && nums[i] == nums[i + 1]) i++;

        solve(nums , curr , ans , i + 1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();

        sort(nums.begin() , nums.end());

        vector<vector<int>>ans;
        vector<int>curr;

        solve(nums , curr , ans , 0);

        return ans;
    }
};
