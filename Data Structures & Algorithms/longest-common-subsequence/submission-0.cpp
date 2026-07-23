class Solution {
public:

    int n , m;

    vector<vector<int>>dp;

    int solve(string& text1 , string& text2 , int i , int j){
        if(i >= n || j >= m) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(text1[i] == text2[j]) return dp[i][j] =  1 + solve(text1 , text2 , i + 1 , j + 1);

        return dp[i][j] = max(solve(text1 , text2 , i + 1 , j) , solve(text1 , text2 , i , j + 1));
    }

    int longestCommonSubsequence(string text1, string text2) {
        n = text1.length();
        m = text2.length();
        dp.assign(n , vector<int>(m , -1));
        return solve(text1 , text2 , 0 , 0);
    }
};
