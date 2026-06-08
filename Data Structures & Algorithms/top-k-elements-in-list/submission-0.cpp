class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        
        for(int x : nums){
            freq[x]++;
        }

        vector<pair<int,int>> vec(freq.begin(), freq.end());
        
        sort(vec.begin(), vec.end(), [&](auto& a, auto& b){
            return a.second > b.second;
        });
        

        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(vec[i].first);
        }
        
        return ans;
    }
};
