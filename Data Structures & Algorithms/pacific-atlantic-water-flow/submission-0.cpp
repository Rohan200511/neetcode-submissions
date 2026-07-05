class Solution {
public:
    int n , m;
    vector<vector<int>>dirs = {{1 , 0} , {0 , 1} , {-1 , 0} , {0 , -1}};

    void dfs(vector<vector<int>>& heights , vector<vector<bool>>& vis , int i , int j , int prevVal){
        if(i >= n || i < 0 || j >= m || j < 0 || vis[i][j] == true || heights[i][j] < prevVal) return;

        vis[i][j] = true;

        for(auto& dir : dirs){
            int nx = i + dir[0];
            int ny = j + dir[1];

            dfs(heights , vis , nx , ny , heights[i][j]);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();

        vector<vector<bool>>pVis(n , vector<bool>(m , false));
        vector<vector<bool>>aVis(n , vector<bool>(m , false));

        for(int i = 0 ; i < m ; i++){
            dfs(heights , pVis , 0 , i , INT_MIN);
            dfs(heights , aVis , n - 1 , i , INT_MIN);
        }

        for(int j = 0 ; j < n ; j++){
            dfs(heights , pVis , j , 0 , INT_MIN);
            dfs(heights , aVis , j , m - 1  , INT_MIN);
        }

        vector<vector<int>>ans;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(pVis[i][j] && aVis[i][j]) ans.push_back({i , j});
            }
        }
        return ans;
    }
};
