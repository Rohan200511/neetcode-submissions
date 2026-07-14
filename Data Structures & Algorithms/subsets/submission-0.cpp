class Solution {
public:
    int n;

    void recurse(vector<int>& nums , vector<int>& curr , vector<vector<int>>& ans , int i){
        if(i == n){
            ans.push_back(curr);
            return;
        }

        recurse(nums , curr , ans , i + 1);
        curr.push_back(nums[i]);
        recurse(nums , curr , ans , i + 1);
        curr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>>ans;
        vector<int>curr;

        recurse(nums , curr , ans , 0);

        return ans;
    }
};
