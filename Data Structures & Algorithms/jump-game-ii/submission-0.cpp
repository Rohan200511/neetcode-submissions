class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0 , l = 0 , r = 0;
        
        while(r < n-1){
            int farthest = 0;
            for(int idx = l ; idx <= r ; idx++) farthest = max(idx + nums[idx] , farthest);

            l = r + 1;
            r = farthest;
            jumps++;
        }
        return jumps;
    }
};
