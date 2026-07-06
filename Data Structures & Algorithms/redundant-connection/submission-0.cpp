class DSU{
public:
    int n;
    vector<int>parent;
    vector<int>rank;
    DSU(int n){
        this->n = n;
        parent.resize(n + 1);
        rank.assign(n + 1 , 0);

        for(int i = 0 ; i <= n ; i++){
            parent[i] = i;
        }
    }

    int find(int u){
        if(parent[u] == u) return u;

        return parent[u] = find(parent[u]);
    }

    void unite(int u , int v){
        int uP = find(u);
        int vP = find(v);

        if(rank[uP] < rank[vP]) parent[uP] = vP;

        else if(rank[uP] > rank[vP]) parent[vP] = uP;

        else{
            rank[uP]++;
            parent[vP] = uP;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>ans;
        DSU dsu(n);

        for(auto& e : edges){
            int u = e[0];
            int v = e[1];

            int uP = dsu.find(u);
            int vP = dsu.find(v);

            if(uP == vP){
                if(ans.empty()){
                    ans.push_back(u);
                    ans.push_back(v);
                }
                else{
                    ans.clear();
                    ans.push_back(u);
                    ans.push_back(v);
                }
            }
            else{
                dsu.unite(u , v);
            } 
        }
        return ans;
    }
};
