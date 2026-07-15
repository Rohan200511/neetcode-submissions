class Solution {
public:
    int n;

    void solve(string& digits , string mp[] , int i , vector<string>& ans , string curr){
        if(i == n){
            ans.push_back(curr);
            return;
        }

        int num = digits[i] - '0';

        for(char c : mp[num]){
            curr.push_back(c);
            solve(digits , mp , i + 1 , ans , curr);
            curr.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {
        
        if(digits.empty()) return {};

        n = digits.size();

        string mp[10] = {" " , " " , "abc" , "def" , "ghi" , "jkl" , "mno",
                        "pqrs" , "tuv" , "wxyz"};

        vector<string>ans;

        solve(digits , mp , 0 , ans , "");

        return ans;
    }
};
