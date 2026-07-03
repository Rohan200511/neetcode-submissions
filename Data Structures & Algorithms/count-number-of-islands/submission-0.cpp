class Solution {
public:

    int n , m;
    
    void dfs(vector<vector<char>>& grid , vector<vector<bool>>& vis , int i , int j){
        if(i >= n || i < 0 || j < 0 || j >= m || vis[i][j] || grid[i][j] - '0' == 0)    
            return ;
        
        vis[i][j] = true;
        dfs(grid , vis , i + 1 , j);
        dfs(grid , vis , i - 1 , j);
        dfs(grid , vis , i , j + 1);
        dfs(grid , vis , i , j - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<bool>>vis(n , vector<bool>(m , false));

        int islands = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] - '0' == 1 && !vis[i][j]){
                    dfs(grid , vis , i , j);
                    islands++;
                }
            }
        }
        return islands;
    }
};
