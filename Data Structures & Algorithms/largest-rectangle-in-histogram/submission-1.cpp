class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;
        int area = 0;

        vector<int> PSE(n , 0) , NSE(n , 0);

        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();

            PSE[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n - 1 ; i >= 0 ; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();

            NSE[i] = (st.empty()) ? n : st.top();
            st.push(i);
        }

        for(int i = 0 ; i < n ; i++){
            int width = NSE[i] - PSE[i] - 1;

            area = max(area , (width * heights[i]));
        }
        return area;
    }
};

