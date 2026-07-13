class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int>temp = {0 , 0 , 0};

        for(auto& t : triplets){
            if(t[0] <= target[0] && t[1] <= target[1] && t[2] <= target[2]){
                temp[0] = max(t[0] , temp[0]);
                temp[1] = max(t[1] , temp[1]);
                temp[2] = max(t[2] , temp[2]);
            }
        }
        return target == temp;
    }
};
