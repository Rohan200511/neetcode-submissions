class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;
 
        queue<pair<pair<int , int> , int>>q;
        vector<vector<bool>>vis(n , vector<bool>(m , false));

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2){
                    q.push({{i , j} , 0});
                    vis[i][j] = true;
                }
            }
        }

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;

            q.pop();

            ans = max(ans , time);

            if(col - 1 >= 0 && grid[row][col-1] == 1 && !vis[row][col-1]){
                vis[row][col-1] = true;
                q.push({{row , col - 1} , time + 1});
            }

            if(col + 1 < m && grid[row][col+1] == 1 && !vis[row][col+1]){
                vis[row][col+1] = true;
                q.push({{row , col + 1} , time + 1});
            }

            if(row - 1 >= 0 && grid[row-1][col] == 1 && !vis[row-1][col]){
                vis[row-1][col] = true;
                q.push({{row-1 , col} , time + 1});
            }

            if(row + 1 < n && grid[row+1][col] == 1 && !vis[row+1][col]){
                vis[row+1][col] = true;
                q.push({{row+1 , col} , time + 1});
            }
        }


        for(int i = 0 ; i < n  ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1 && !vis[i][j]) return -1;
            }
        }
        return ans;
    }
};
