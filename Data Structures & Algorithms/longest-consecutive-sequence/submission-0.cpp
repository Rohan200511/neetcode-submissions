class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        int res = 0;
        for(int num : nums) st.insert(num);

        for(int val : nums){
            if(st.find(val) != st.end() && st.find(val-1) == st.end()){
                int curr = val , cnt = 0;

                while(st.find(curr) != st.end()){
                    st.erase(curr);
                    curr++;
                    cnt++;
                }
                res = max(res , cnt);
            }
        }
        return res;
    }
};
