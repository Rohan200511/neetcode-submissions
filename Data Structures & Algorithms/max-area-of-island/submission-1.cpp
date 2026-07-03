class Solution {
public:

    int n , m;

    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis , int i , int j){
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0 || vis[i][j]) return 0;

        vis[i][j] = true;

        int down = dfs(grid , vis , i + 1 , j);
        int up = dfs(grid , vis , i - 1 , j);
        int right = dfs(grid , vis , i , j + 1);
        int left = dfs(grid , vis , i , j - 1);

        return 1 + left + up + right + down;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<bool>>vis(n , vector<bool>(m , false));

        int ans = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    ans = max(ans , dfs(grid , vis , i , j));
                }
            }
        }
        return ans;
    }
};
