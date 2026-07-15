class Solution {
public:

    int n;

    bool isPalindrome(string s , int start , int end){
        while(start <= end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }

    void solve(string& s , vector<string>& curr , vector<vector<string>>& ans , int i){
        if(i == n){
            ans.push_back(curr);
            return;
        }

        for(int j = i ; j < n ; j++){
            if(isPalindrome(s , i , j)){
                curr.push_back(s.substr(i , j - i + 1));
                solve(s , curr , ans , j + 1);
                curr.pop_back();
            }
        }
    }


    vector<vector<string>> partition(string s) {
        n = s.length();
        vector<string> curr;
        vector<vector<string>>ans;
        solve(s , curr , ans , 0);

        return ans;
    }
};
