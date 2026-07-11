class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dist(n , INT_MAX);
        dist[src] = 0;
        for(int i = 0 ; i <= k ; i++){
            vector<int>temp = dist;

            for(auto& fl : flights){
                int u = fl[0];
                int v = fl[1];
                int wt = fl[2];

                if(dist[u] != INT_MAX){
                    temp[v] = min(temp[v] , dist[u] + wt);
                }
            }
            dist = temp;
        }

        return (dist[dst] == INT_MAX) ? -1 : dist[dst];
    }
};
