class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size() + 1;

        intervals.push_back(newInterval);

        sort(begin(intervals) , end(intervals));

        vector<vector<int>>ans;

        for(int i = 0 ; i < n ; i++){
            if(ans.empty() || ans.back()[1] < intervals[i][0]){
                ans.push_back(intervals[i]);
            }
            else{
                ans.back()[1] = max(ans.back()[1] , intervals[i][1]);
            }
        }
        return ans;
    }
};
