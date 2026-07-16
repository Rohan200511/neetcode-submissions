class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();

        priority_queue<int>pq;

        for(int x : stones){
            pq.push(x);
        }

        while(pq.size() > 1){
            int x = pq.top();
            pq.pop();

            int y = pq.top();
            pq.pop();

            if(x == y) continue;

            else if(x < y){
                y = y - x;
                pq.push(y);
            }
            else pq.push(x - y);
        }

        if(pq.empty()) return 0;
        return pq.top();
    }
};
