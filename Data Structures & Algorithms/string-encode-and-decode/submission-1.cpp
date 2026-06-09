class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";

        for(string& s : strs){
            res += to_string(s.length());
            res += "%";
            res += s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string>ans;

        int j = 0;
        while(j < s.length()){
            string temp = "";
            int sz = 0;

            while(s[j] != '%'){
                sz = sz * 10 + (s[j]-'0');
                j++;
            }

            j++;

            temp += s.substr(j , sz);
            ans.push_back(temp);
            j += sz;
        }
        return ans;
    }
};
