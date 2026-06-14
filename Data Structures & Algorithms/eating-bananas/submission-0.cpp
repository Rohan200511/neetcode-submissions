class Solution {
public:

    bool possible(vector<int>& piles , int gTime , int h){
        long long timeTaken = 0;

        for(int i = 0 ; i < piles.size() ; i++){
            timeTaken += (piles[i] + gTime - 1) / gTime;
        }
        return timeTaken <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        
        int beg = 1;
        int end = *max_element(piles.begin() , piles.end());

        int ans;

        while(beg <= end){
            int mid = beg + ((end - beg) / 2);

            if(possible(piles , mid , h)){
                ans = mid;
                end = mid - 1;
            }
            else beg = mid + 1;
        }
        return ans;
    }
};
