class Solution {
public:

    typedef tuple<int , int , int> T;
    vector<vector<int>>dirs = {{0,1} , {1,0} , {-1,0} , {0,-1}};

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<T , vector<T> , greater<T>>pq;
        vector<vector<bool>>vis(n , vector<bool>(m , false));

        pq.push({grid[0][0] , 0 , 0});
        while(!pq.empty()){
            auto [time , i , j] = pq.top();
            pq.pop();

            if(vis[i][j]) continue;
            vis[i][j] = true;

            if(i == n-1 && j == m-1) return time;

            for(auto& dir : dirs){
                int nr = i + dir[0];
                int nc = j + dir[1];

                if(nr < n && nr >= 0 && nc >= 0 && nc < m && !vis[nr][nc]){
                    int newTime = max(time , grid[nr][nc]);
                    pq.push({newTime , nr , nc});
                }
            }
        }
        return -1;
    }
};
