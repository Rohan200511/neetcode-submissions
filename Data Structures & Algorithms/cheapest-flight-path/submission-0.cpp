class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int , int>>>adj(n);

        for(auto& fl : flights){
            int u = fl[0];
            int v = fl[1];
            int p = fl[2];

            adj[u].push_back({v , p});
        }
        vector<int>dist(n , INT_MAX);
        queue<pair<int , int>>q;
        q.push({0 , src});

        dist[src] = 0;
        int stops = 0;

        while(!q.empty() && stops <= k){
            int sz = q.size();

            while(sz--){
                auto[cost , node] = q.front();
                q.pop();

                    for(auto& v : adj[node]){
                        int nei = v.first;
                        int price = v.second;

                        if(dist[nei] > cost + price){
                            dist[nei] = cost + price;
                            q.push({cost + price , nei});
                        }
                    }
            }
            stops++;
        }

        return (dist[dst] == INT_MAX) ? -1 : dist[dst];
    }
};
