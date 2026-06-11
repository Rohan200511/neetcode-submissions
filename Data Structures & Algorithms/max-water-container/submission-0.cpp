class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int ans = 0;
        int l = 0;
        int r = n-1;


        while(l < r){
            int temp = min(heights[l] , heights[r]) * (r - l);

            ans = max(ans , temp);

            if(heights[l] < heights[r]) l++;
            else r--;
        }
        return ans;
    }
};
