class Solution {
public:
    typedef pair<long long , pair<int , int>>P;

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<P>pq;
        vector<vector<int>>ans;

        for(auto& point : points){
            int x = point[0];
            int y = point[1];

            long long d = (long long)(x * x) + (long long)(y * y);

            pq.push({d , {x , y}});

            if(pq.size() > k) pq.pop();
        }

        while(!pq.empty()){
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            ans.push_back({x , y});
        }

        return ans;
    }
};
