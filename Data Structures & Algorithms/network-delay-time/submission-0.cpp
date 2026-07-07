class Solution {
public:

    typedef pair<int , int> P;

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<P>>adj(n + 1);

        for(auto& t : times){
            int u = t[0];
            int v = t[1];
            int tt = t[2];

            adj[u].push_back({v , tt});
        }

        priority_queue<P , vector<P> , greater<P>>pq;
        vector<int>time(n + 1 , INT_MAX);

        pq.push({0 , k});
        time[k] = 0;

        while(!pq.empty()){
            auto [waqt , node] = pq.top();
            pq.pop();

            if (waqt > time[node])
                continue;
            
            for(auto& nei : adj[node]){
                int v = nei.first;
                int ttime = nei.second;

                if(time[v] > ttime + waqt){
                    time[v] = ttime + waqt;
                    pq.push({ttime + waqt , v});
                }
            }
        }

        int ans = -1;

        for (int i = 1; i <= n; i++) {
            if (time[i] == INT_MAX)
                return -1;
            ans = max(ans, time[i]);
        }

        return  ans;
    }
};
