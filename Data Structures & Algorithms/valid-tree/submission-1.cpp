class Solution {
public:

    bool isCycle(int u , int par , unordered_map<int , vector<int>>& adj , vector<bool>& vis){
        vis[u] = true;

        for(int& v : adj[u]){
            if(!vis[v]){
                if(isCycle(v , u , adj , vis)) return true;
            }
            else if(v != par) return true;
        }
        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int , vector<int>>adj;

        for(auto& e : edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>vis(n , false);
    
        if(isCycle(0 , -1 , adj , vis) == true) return false;

        for(bool x : vis){
            if(!x) return false;
        }

        return true;
    }
};
