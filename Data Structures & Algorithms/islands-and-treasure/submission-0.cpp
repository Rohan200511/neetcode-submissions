class Solution {
public:

    #define INF 2147483647;

    vector<vector<int>>dirs = {{0 , 1} , {1 , 0} , {0 , -1} , {-1 , 0}};
    int bfs(vector<vector<int>>& grid , int i , int j , int n , int m){

        vector<vector<bool>>vis(n , vector<bool>(m , false));
        int steps = 0;
        queue<pair<int , int>>q;
        q.push({i , j});
        vis[i][j] = true;

        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(grid[x][y] == 0) return steps;

                for(auto& dir : dirs){
                    int nx = x + dir[0];
                    int ny = y + dir[1];

                    if(nx < n && nx >= 0 && ny < m && ny >= 0 && !vis[nx][ny] && grid[nx][ny] != -1){
                        q.push({nx , ny});
                        vis[nx][ny] = true;
                    }
                }
            }
            steps++;
        }

        return INF;
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 0) grid[i][j] = 0;
                else if(grid[i][j] == -1) grid[i][j] = -1;
                else grid[i][j] = bfs(grid , i , j , n , m);
            }
        }
    }
};
