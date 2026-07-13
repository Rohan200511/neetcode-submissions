class Solution {
public:
    typedef pair<int , int> P;
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();

        sort(intervals.begin() , intervals.end());

        vector<P>q(queries.size());

        for(int i = 0 ; i < queries.size() ; i++){
            q[i] = {queries[i] , i};
        }

        sort(q.begin() , q.end());

        vector<int>ans(queries.size() , -1);

        priority_queue<P , vector<P> , greater<P>>pq;

        int i = 0;

        for(auto& [val , ind] : q){

            while(i < intervals.size() && intervals[i][0] <= val){
                int l = intervals[i][0];
                int r = intervals[i][1];

                int len = r - l + 1;

                pq.push({len , r});
                i++;
            }

            while(!pq.empty() && pq.top().second < val) pq.pop();

            if(!pq.empty()) ans[ind] = pq.top().first;
        }
        return ans;
    }
};
