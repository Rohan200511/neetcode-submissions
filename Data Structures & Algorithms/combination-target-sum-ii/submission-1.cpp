class Solution {
public:
    int n;

    void recurse(vector<int>& nums , vector<int>& curr , vector<vector<int>>& ans , int target , int i){
        
        if(target == 0){
            ans.push_back(curr);
            return;
        }

        if(target < 0 || i >= n) return;

        curr.push_back(nums[i]);
        recurse(nums , curr , ans , target - nums[i] , i + 1);
        curr.pop_back();

        while(i + 1 < n && nums[i] == nums[i + 1]) i++;

        recurse(nums , curr , ans , target , i + 1);

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();
        
        sort(candidates.begin() , candidates.end());

        vector<vector<int>>ans;
        vector<int>curr;
        recurse(candidates , curr , ans , target , 0);

        return ans;
    }
};
