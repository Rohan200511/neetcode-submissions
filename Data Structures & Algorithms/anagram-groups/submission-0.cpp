class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string , vector<string>>mp;

        for(auto& x : strs){
            string temp = x;
            sort(temp.begin(), temp.end());

            if(mp.find(temp) != mp.end()){
                mp[temp].push_back(x);
            }
            else mp[temp].push_back(x);
        }

        for(auto& it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};