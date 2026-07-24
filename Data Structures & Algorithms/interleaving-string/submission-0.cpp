class Solution {
public:
    int n, m;
    vector<vector<int>> dp;

    bool solve(string &s1, string &s2, string &s3, int i, int j) {
        if (i == n && j == m)
            return true;

        if (dp[i][j] != -1)
            return dp[i][j];

        bool ans = false;

        if (i < n && s1[i] == s3[i + j])
            ans = solve(s1, s2, s3, i + 1, j);

        if (j < m && s2[j] == s3[i + j])
            ans = solve(s1, s2, s3, i, j + 1);

        return dp[i][j] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        n = s1.size();
        m = s2.size();

        if (n + m != s3.size())
            return false;

        dp.assign(n + 1, vector<int>(m + 1, -1));

        return solve(s1, s2, s3, 0, 0);
    }
};