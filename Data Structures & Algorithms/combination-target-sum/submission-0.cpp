class Solution {
public:
    int n;

    void recurse(vector<int>& nums , int target , vector<int>& curr , vector<vector<int>>& ans , int i){
        
        if(target == 0){
            ans.push_back(curr);
            return;
        }

        if(target < 0 || i >= n) return;

        recurse(nums , target , curr , ans , i + 1);

        curr.push_back(nums[i]);
        recurse(nums , target - nums[i] , curr , ans , i);
        curr.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        n = nums.size();
        vector<vector<int>>ans;
        vector<int>curr;

        recurse(nums , target , curr , ans , 0);

        return ans;
    }
};
