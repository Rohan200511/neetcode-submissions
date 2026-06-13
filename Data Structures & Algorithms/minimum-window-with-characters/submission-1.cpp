class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();

        if(n < m) return "";
        if(m == 0) return "";

        unordered_map<char , int>mp;
        int reqd = m;
        int minWind = INT_MAX;
        int start_i = -1;

        for(char c : t) mp[c]++;

        int l = 0;

        for(int r = 0 ; r < n ; r++){
            if(mp[s[r]] > 0) reqd--;

            mp[s[r]]--;

            while(reqd == 0){
                if(minWind > r - l + 1){
                    minWind = r - l + 1;
                    start_i = l;
                }

                mp[s[l]]++;
                if(mp[s[l]] > 0) reqd++;
                l++;
            }
        }
        if(minWind == INT_MAX) return "";
        return s.substr(start_i , minWind);
    }
};
