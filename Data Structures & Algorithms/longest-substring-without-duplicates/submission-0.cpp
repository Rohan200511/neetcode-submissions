class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int l = 0;
        unordered_set<int>mp;
        int ans = 0;

        for(int r = 0 ; r < n ; r++){
            while(mp.find(s[r]) != mp.end()){
                mp.erase(s[l]);
                l++;
            }
            mp.insert(s[r]);
            ans = max(ans , r - l + 1);
        }
        return ans;
    }
};
