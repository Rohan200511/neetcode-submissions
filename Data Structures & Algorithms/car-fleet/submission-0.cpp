class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int,double>>vec;

        for(int i = 0 ; i < n ; i++){
            double time = (double)(target - position[i]) / speed[i];
            vec.push_back({position[i] , time});
        }

        sort(begin(vec) , end(vec) , [](auto& a , auto& b){
            return a.first > b.first;
        });

        int ans = 1;
        double prevTime = vec[0].second;

        for(int i = 1 ; i < n ; i++){
            if(vec[i].second > prevTime){
                ans++;
                prevTime = vec[i].second;
            }
        }
        return ans;
    }
};
