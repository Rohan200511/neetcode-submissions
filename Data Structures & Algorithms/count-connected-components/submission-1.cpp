class Solution {
public:

    void dfs(int u , unordered_map<int , vector<int>>& adj , vector<bool>& vis){
        vis[u] = true;

        for(auto& v : adj[u]){
            if(!vis[v])
                dfs(v , adj , vis);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int , vector<int>>adj;

        for(auto& e : edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int count = 0;

        vector<bool>vis(n , false);

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i , adj , vis);
                count++;
            }
        }

        return count;
    }
};
