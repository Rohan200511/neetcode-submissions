class Solution {
public:

    typedef pair<int , int>P;

    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        vector<vector<P>>adj(V);

        for(int i = 0 ; i < V ; i++){
            for(int j = 0 ; j < V ; j++){
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int d = (abs(x1 - x2) + abs(y1 - y2));

                adj[i].push_back({j , d});
                adj[j].push_back({i , d});
            }
        }

        priority_queue<P , vector<P> , greater<P>>pq;

        vector<bool>vis(V , false);
        int ans = 0;

        pq.push({0 , 0});

        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(vis[node]) continue;

            vis[node] = true;
            ans += dis;

            for(auto& v : adj[node]){
                int nei = v.first;
                int wt = v.second;

                if(!vis[nei]){
                    pq.push({wt , nei});
                }
            }
        }
        return ans;
    }
};
